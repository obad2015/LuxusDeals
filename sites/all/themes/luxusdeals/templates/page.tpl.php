<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>


<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">

  <div id="top-header">
    <div class="container">
      <ul class="pull-right">
        <li><a href="/handelsbetingelser">Handelsbetingelser</a></li>
        <li><a href="/om-luxusdeal">Om Luxusdeal</a></li>
        <li><a href="https://www.facebook.com/luxusdeal" target="_blank">Følg os på Facebook</a></li>
        <?php if($logged_in): ?>
          <li><a href="user">Min profil</a></li>
          <li><a href="user/logout?destination=<?php print current_path(); ?>">Log ud</a></li>
        <?php else: ?>
          <li><a href="user/login?destination=<?php print current_path(); ?>">Log ind</a></li>
        <?php endif; ?>
      </ul>
    </div>
  </div>
  <div class="container">
    <div class="navbar-header">
      <?php if ($logo): ?>
        <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>"
           title="<?php print t('Home'); ?>">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
        </a>
      <?php endif; ?>

      <?php if (!empty($site_name)): ?>
        <a class="name navbar-brand" href="<?php print $front_page; ?>"
           title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
      <?php endif; ?>

      <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
      <button type="button" class="navbar-toggle" data-toggle="collapse"
              data-target=".navbar-collapse">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
    </div>

    <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
      <div class="navbar-collapse collapse">
        <nav role="navigation">
          <?php if (!empty($primary_nav)): ?>
            <?php print render($primary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($secondary_nav)): ?>
            <?php print render($secondary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($page['navigation'])): ?>
            <?php print render($page['navigation']); ?>
          <?php endif; ?>
          <?php if (!$premium_user): ?>
            <?php if(!empty($subscribe_button)): ?>
              <?php print drupal_render($subscribe_button); ?>
            <?php endif; ?>
          <?php endif; ?>
        </nav>
      </div>
    <?php endif; ?>
  </div>
</header>

<div class="container-fluid">
  <div class="content-image content-image-region" id="content_image">
    <?php print render($page['content_image']); ?>

  </div>
</div>

<div class="container-fluid slide">
  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php if (!empty($top_image)): ?>
      <div class="cover-image"
           style="background-image: url('<?php print $top_image; ?>');">
      </div>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header>
</div>

<div class="main-container container">

  <!-- /#page-header -->

  <div class="row">

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section<?php print $content_column_class; ?>>
      <?php if (!empty($page['highlighted'])): ?>
        <div
          class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif; ?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>
  </div>
</div>


<?php if (!empty($related_deals)): ?>
  <div id='related-deals' class="container-fluid">
    <div class="container">
      <?php print $related_deals; ?>
    </div>
  </div>
<?php endif; ?>

<div class="partners">
  <div class="container">
    <h3 class="text-center">
      Vi samarbejder med de bedste virksomheder over
      hele landet for at levere dig Danmarks mest luksuriøse deals.
      <span class="membership">Gør et kup! Tilmeld dit medlemskab idag og <b>få
          yderligere +15% i rabat på
          regningen</b>, når du handler hos os.</span>
    </h3>
  </div>
</div>

<footer class="footer container-fluid">
  <?php print render($page['footer']); ?>
</footer>


<?php if (!$premium_user): ?>
<!-- Modal -->
  <div class="modal fade" id="subscribe-modal" role="dialog" tabindex="-1"
       aria-hidden="true">
    <div class="modal-dialog vertical-align-center" role="document">
      <div class="vertical-alignment-helper">
        <div class="modal-content" style="-webkit-border-radius: 0px !important;
          -moz-border-radius: 0px !important; border-radius: 0px !important; ">
          <!-- modal body -->
          <div class="modal-body" >
            <img src="/sites/all/themes/luxusdeals/images/cover.png"
                 class="img-responsive" alt="Responsive image">
          </div>
        </div>
      </div>
    </div>
  </div>

  <script type="text/javascript">
    jQuery(document).ready(function() {
      // Only show popup if it isn't already seen.
      if(jQuery.cookie('popup-seen') == null || jQuery.cookie('popup-seen') == "")
      {
        jQuery('#subscribe-modal').modal('show');
        // Don't show the popup again for a month.
        jQuery.cookie('popup-seen', true, { expires: 30, path: '/' });
      }
    });

  </script>
<?php endif; ?>
