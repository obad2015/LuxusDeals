<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */

// Entity metadata wrapper for the node
$wrapper = entity_metadata_wrapper('node', $node);

// We hide the comments and links now so that we can render them later.
hide($content['comments']);
hide($content['links']);
hide($content['field_product']);
hide($content['product:field_deal_image']);
hide($content['product:field_few_words']);
hide($content['product:field_details']);
hide($content['product:field_or_price']);
hide($content['product:commerce_price']);
hide($content['product:field_timeending']);
hide($content['field_store_refer']);

// create discount element
$discount = isset($content['product:field_or_price']['#items'][0]['amount']) ? ((100 * $content['product:field_or_price']['#items'][0]['amount']) - (100 * $content['product:commerce_price']['#items'][0]['amount'])) / $content['product:field_or_price']['#items'][0]['amount'] : '';
$currency = commerce_currency_load($content['product:commerce_price']['#items'][0]['currency_code']);
$discount = !empty($discount) ? commerce_currency_round(abs($discount), $currency) : '';

// create savings element
$savings = isset($content['product:field_or_price']['#items'][0]['amount']) ? $content['product:field_or_price']['#items'][0]['amount'] - $content['product:commerce_price']['#items'][0]['amount'] : '';
$savings = isset($content['product:field_or_price']['#items'][0]['amount']) ? opendeals_currency_format($savings, $content['product:commerce_price']['#items'][0]['currency_code']) : '';

$this_url = 'http://' . $_SERVER['HTTP_HOST'] . request_uri();
?>

<div id="fb-root"></div>
<script>(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) {return;}
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/en_GB/all.js#xfbml=1&appId=239333519451879";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));</script>


<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?> >

  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <h2 id="nodedealtitle"<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
  <div class="submitted">
    <?php print $submitted; ?>
  </div>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>

  <div id="nodeboxleftcontainer">
    <div id="nodedealbuybox" class="nodeboxleft nodeblue">
      <div class="priceTag">
        <?php if(opendeals_module_is_active($node)):?>
          <div class="btn btnBuy"><?php print render($content['field_product']);?></div>
        <?php else:?>
          <div class="btn btnBuy"><div class="btn btnDisabled"><?php echo t('Sold out')?></div></div>
        <?php endif;?>
      </div>

      <span class="price">
        <?php echo t('Only at')?>: <span class="noWrap"><?php echo render($content['product:commerce_price']);?></span>
      </span>

      <table width="100%" border="0" cellspacing="0" cellpadding="0" class="savings">
        <tbody>
          <tr class="row1">
            <td class="col1"><?php echo t('Value')?></td>
            <td class="col1"><?php echo t('Discount')?></td>
            <td><?php echo t('You save')?></td>
          </tr>
          <tr class="row2">
            <td class="col1">
              <?php echo render($content['product:field_or_price']);?>
            </td>
            <td class="col1"><?php if ($discount) echo $discount . '%';?></td>
            <td class="col2"><?php if ($savings) echo $savings;?></td>
          </tr>
        </tbody>
      </table>

    </div>

    <?php if(opendeals_module_is_active($node)):?>
    <div class="nodedownbox nodeboxleft nodegreen" style="display:block;">
      <div class="nodeheadline"><?php echo t('Time left to buy')?>:</div>
      <?php
        $time_timestamp = strtotime($content['field_timending']['#items'][0]['value']);
        $nodays = (($time_timestamp-time()-24*60*60)<=0);
      ?>
      <div class="counter jst_timer<?php echo $nodays?' counter-no-days':''?>">
        <span style="display:none;" class="datetime"><?php echo ($content['field_timending']['#items'][0]['value']) ?></span>
        <span class="format_txt" style="display:none;">
          <ul>
            <li<?php echo $nodays?' class="disabled"':'';?>>%days%</li>
            <li>%hours%</li>
            <li>%mins%</li>
            <li>%secs%</li>
          </ul>
        </span>
      </div>
      <div class="label"><ul<?php echo $nodays?' class="counter-labels-no-days"':'';?>><li<?php echo $nodays?' class="disabled"':'';?>><?php echo t('Days')?></li><li><?php echo t('Hours')?></li><li><?php echo t('Min.')?></li><li><?php echo t('Sec.')?></li></ul></div>
      <div class="wrapper"></div>
    </div>
    <?php endif;?>

    <div id="nodedealstatusbox" class="nodeboxleft nodegreen">
      <?php if(!opendeals_module_is_active($node)):?>
        <div class="soldOutContainer"><div class="soldOutBanner"><?php echo t('Sold out')?></div></div>
      <?php endif;?>

      <div class="soldAmount"><span id="&quot;jDealSoldAmount&quot;"><?php echo ($content['product:commerce_sales']['#items'][0]['value']) ?></span> <?php echo t('purchases!')?></div>
        <div class="dealSuccessful">
          <?php if(opendeals_module_is_active($node)):?>
            <span id="dealTakePlace"><?php echo t('The offer is active')?></span>
          <?php else:?>
            <span id="dealTookPlace"><?php echo t('The offer is over!')?></span>
          <?php endif;?>
        </div>
    </div>

    <div id="nodedealrecommbox" class="nodeboxleft nodegreen lastitem">
      <div class="addnewsfeed">
        <div class="nodeheadline"><?php echo t('Share to friends!')?></div>
          <!-- AddThis Button BEGIN -->
          <div class="addthis_toolbox addthis_default_style " style="padding:10px 0 0;">
            <a class="addthis_button_tweet" style="width:100px;"></a>
            <a class="addthis_button_facebook_like" fb:like:layout="button_count" style="width:90px;"></a>
            <a class="addthis_button_google_plusone" g:plusone:size="medium" style="clear:both; padding:5px 2px 0; width:64px;"></a>
            <a class="addthis_counter addthis_pill_style" style="padding:5px 2px 0;"></a>
          </div>
          <script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#pubid=xa-4eb3ceb71872c6fa"></script>
          <!-- AddThis Button END -->
        <div class="wrapper"></div>
      </div>
    </div>
  </div> <!-- end of .content -->

  <div id="nodeboxrightcontainer">
    <div id="nodedealdescr">
      <?php print render($content['product:field_deal_image']);?>
        <div class="viewHalfWidthSize">
          <?php print render($content['product:field_few_words']);?>
        </div>
        <div class="viewHalfWidthSize">
          <?php print render($content['product:field_details']);?>
        </div>
    </div>
  </div>

  </div>
</div>
  <div class="wrapper"></div>
  <div id="stores" class="nodeboxnormal nodeboxnormaltwocol">
    <div class="boxmid nodedealdata">
      <div class="nodeboxnormalright">
        <div class="storecontact">
          <?php print render($content['field_store_refer'][0]['field_store_image']);?>
          <h2 class="nodeheadline"><?php echo $wrapper->field_store_refer->title->value(); ?></h2>
          <?php print render($content['field_store_refer'][0]['field_store_location']); ?>
          <a href="<?php print render($content['field_store_refer'][0]['field_store_site'][0]['#markup']); ?>"><?php print render($content['field_store_refer'][0]['field_store_site'][0]['#markup']); ?></a>
        </div>
      </div>
      <div class="nodeboxnormalleft">
        <h3 class="nodeheadline"><?php print $title; ?></h3>
        <?php echo ($content['field_store_refer'][0]['body']['#items'][0]['value']);?>
      </div>
      <div class="wrapper"></div>
    </div>
    <div class="wrapper"></div>
  </div>
