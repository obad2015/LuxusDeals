<?php
/**
 * @file
 * opendeals_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function opendeals_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'all_deals';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All Deals';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Deals';
  $handler->display->display_options['css_class'] = 'boxExtraDealMulti sidebarBoxMain';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Relationship: Content: Referenced product */
  $handler->display->display_options['relationships']['field_product_product_id']['id'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['table'] = 'field_data_field_product';
  $handler->display->display_options['relationships']['field_product_product_id']['field'] = 'field_product_product_id';
  /* Relationship: Content: Available at (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_deal_image']['id'] = 'field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['table'] = 'field_data_field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['field'] = 'field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_deal_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_deal_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_deal_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_city_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'deal' => 'deal',
  );
  /* Filter criterion: Content: End Date (field_timending) */
  $handler->display->display_options['filters']['field_timending_value']['id'] = 'field_timending_value';
  $handler->display->display_options['filters']['field_timending_value']['table'] = 'field_data_field_timending';
  $handler->display->display_options['filters']['field_timending_value']['field'] = 'field_timending_value';
  $handler->display->display_options['filters']['field_timending_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_timending_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_timending_value']['default_date'] = 'now';

  /* Display: All Deals */
  $handler = $view->new_display('page', 'All Deals', 'page');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'three_up';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'all_deals:block_1';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Referenced product */
  $handler->display->display_options['relationships']['field_product_product_id']['id'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['table'] = 'field_data_field_product';
  $handler->display->display_options['relationships']['field_product_product_id']['field'] = 'field_product_product_id';
  /* Relationship: Content: Available at (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '30';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_deal_image']['id'] = 'field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['table'] = 'field_data_field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['field'] = 'field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_deal_image']['label'] = '';
  $handler->display->display_options['fields']['field_deal_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_deal_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_deal_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_deal_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_deal_image']['settings'] = array(
    'image_style' => '268x160_upscale',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="deal down clearfix">
  <div class="image">
    <div class="inner">
      <a href="node/[nid]">
        [field_deal_image]
      </a>
    </div>
  </div>
  <div class="info">
    <div class="title">
      <div class="price-tag"></div>
        <a href="node/[nid]">[title]</a>
      <div class="line"></div>
    </div>
    <div class="view-deal-button">
      <a href="node/[nid]" class="buttons small">View This Deal</a>
    </div>
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'all-deals';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'extradeals';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="sidebarheader">More Great Deals <a href="all-deals">See all</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Referenced product */
  $handler->display->display_options['relationships']['field_product_product_id']['id'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['table'] = 'field_data_field_product';
  $handler->display->display_options['relationships']['field_product_product_id']['field'] = 'field_product_product_id';
  /* Relationship: Content: Available at (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'extradescription';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = '';
  $handler->display->display_options['fields']['commerce_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['commerce_price']['alter']['text'] = '<span class="priceIcon"></span>[commerce_price]';
  $handler->display->display_options['fields']['commerce_price']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['commerce_price']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['commerce_price']['element_type'] = 'div';
  $handler->display->display_options['fields']['commerce_price']['element_class'] = 'price';
  $handler->display->display_options['fields']['commerce_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['type'] = 'opendeals_formatted_amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  /* Field: Commerce Product: Original Price */
  $handler->display->display_options['fields']['field_or_price']['id'] = 'field_or_price';
  $handler->display->display_options['fields']['field_or_price']['table'] = 'field_data_field_or_price';
  $handler->display->display_options['fields']['field_or_price']['field'] = 'field_or_price';
  $handler->display->display_options['fields']['field_or_price']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_or_price']['label'] = '';
  $handler->display->display_options['fields']['field_or_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_or_price']['alter']['text'] = '<span>[field_or_price]</span> value';
  $handler->display->display_options['fields']['field_or_price']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_or_price']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_or_price']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_or_price']['element_class'] = 'value';
  $handler->display->display_options['fields']['field_or_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_or_price']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_or_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_or_price']['type'] = 'opendeals_formatted_amount';
  $handler->display->display_options['fields']['field_or_price']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'View It!';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nothing_1']['alter']['link_class'] = 'buttons buy_btn small';
  $handler->display->display_options['fields']['nothing_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'extraview';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_deal_image']['id'] = 'field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['table'] = 'field_data_field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['field'] = 'field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_deal_image']['label'] = '';
  $handler->display->display_options['fields']['field_deal_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_deal_image']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_deal_image']['alter']['link_class'] = 'jSideDeal';
  $handler->display->display_options['fields']['field_deal_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_deal_image']['element_class'] = 'extraimage';
  $handler->display->display_options['fields']['field_deal_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_deal_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_deal_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_deal_image']['settings'] = array(
    'image_style' => '124x75_upscale',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_3']['label'] = '';
  $handler->display->display_options['fields']['nothing_3']['alter']['text'] = '<div class="wrapper"></div>';
  $handler->display->display_options['fields']['nothing_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_city_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';

  /* Display: First item from all-deals Block */
  $handler = $view->new_display('block', 'First item from all-deals Block', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'one-up';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There are no deals in this category.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_deal_image']['id'] = 'field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['table'] = 'field_data_field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['field'] = 'field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_deal_image']['label'] = '';
  $handler->display->display_options['fields']['field_deal_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_deal_image']['alter']['text'] = '[field_deal_image]';
  $handler->display->display_options['fields']['field_deal_image']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_deal_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_deal_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_deal_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_deal_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Commerce Product: A few words */
  $handler->display->display_options['fields']['field_few_words']['id'] = 'field_few_words';
  $handler->display->display_options['fields']['field_few_words']['table'] = 'field_data_field_few_words';
  $handler->display->display_options['fields']['field_few_words']['field'] = 'field_few_words';
  $handler->display->display_options['fields']['field_few_words']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_few_words']['label'] = '';
  $handler->display->display_options['fields']['field_few_words']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_few_words']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_few_words']['hide_alter_empty'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="deal clearfix">
  <div class="image">
    <div class="inner">
      <a href="node/[nid]">
        [field_deal_image]
      </a>
    </div>
  </div>
  <div class="info">
    <div class="title">
      <div class="price-tag"></div>
      <a href="node/[nid]">[title]</a>
    </div>
    <div class="description">[field_few_words]</div>
    <div class="view-deal-button"><a href="node/[nid]" class="buttons medium">View Deal</a></div>
    <div class="line"></div>
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_city_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'First item from all-deals';

  /* Display: Past Deals */
  $handler = $view->new_display('page', 'Past Deals', 'page_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'three_up';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'all_deals:block_3';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Referenced product */
  $handler->display->display_options['relationships']['field_product_product_id']['id'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['table'] = 'field_data_field_product';
  $handler->display->display_options['relationships']['field_product_product_id']['field'] = 'field_product_product_id';
  /* Relationship: Content: Available at (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '30';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_deal_image']['id'] = 'field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['table'] = 'field_data_field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['field'] = 'field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_deal_image']['label'] = '';
  $handler->display->display_options['fields']['field_deal_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_deal_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_deal_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_deal_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_deal_image']['settings'] = array(
    'image_style' => '268x160_upscale',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="deal down clearfix">
  <div class="image">
    <div class="inner">
      <a href="node/[nid]">
        [field_deal_image]
      </a>
    </div>
  </div>
  <div class="info">
    <div class="title">
      <div class="price-tag"></div>
        <a href="node/[nid]">[title]</a>
      <div class="line"></div>
    </div>
    <div class="view-deal-button">
      <a href="node/[nid]" class="buttons small">View This Deal</a>
    </div>
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_city_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'deal' => 'deal',
  );
  /* Filter criterion: Content: End Date (field_timending) */
  $handler->display->display_options['filters']['field_timending_value']['id'] = 'field_timending_value';
  $handler->display->display_options['filters']['field_timending_value']['table'] = 'field_data_field_timending';
  $handler->display->display_options['filters']['field_timending_value']['field'] = 'field_timending_value';
  $handler->display->display_options['filters']['field_timending_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_timending_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_timending_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'past-deals';

  /* Display: First item from past-deals */
  $handler = $view->new_display('block', 'First item from past-deals', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Past Deals';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'one-up';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There are no deals in this category.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_deal_image']['id'] = 'field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['table'] = 'field_data_field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['field'] = 'field_deal_image';
  $handler->display->display_options['fields']['field_deal_image']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_deal_image']['label'] = '';
  $handler->display->display_options['fields']['field_deal_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_deal_image']['alter']['text'] = '[field_deal_image]';
  $handler->display->display_options['fields']['field_deal_image']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_deal_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_deal_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_deal_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_deal_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Commerce Product: A few words */
  $handler->display->display_options['fields']['field_few_words']['id'] = 'field_few_words';
  $handler->display->display_options['fields']['field_few_words']['table'] = 'field_data_field_few_words';
  $handler->display->display_options['fields']['field_few_words']['field'] = 'field_few_words';
  $handler->display->display_options['fields']['field_few_words']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_few_words']['label'] = '';
  $handler->display->display_options['fields']['field_few_words']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_few_words']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_few_words']['hide_alter_empty'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="deal clearfix">
  <div class="image">
    <div class="inner">
      <a href="node/[nid]">
        [field_deal_image]
      </a>
    </div>
  </div>
  <div class="info">
    <div class="title">
      <div class="price-tag"></div>
      <a href="node/[nid]">[title]</a>
    </div>
    <div class="description">[field_few_words]</div>
    <div class="view-deal-button"><a href="node/[nid]" class="buttons medium">View Deal</a></div>
    <div class="line"></div>
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'deal' => 'deal',
  );
  /* Filter criterion: Content: End Date (field_timending) */
  $handler->display->display_options['filters']['field_timending_value']['id'] = 'field_timending_value';
  $handler->display->display_options['filters']['field_timending_value']['table'] = 'field_data_field_timending';
  $handler->display->display_options['filters']['field_timending_value']['field'] = 'field_timending_value';
  $handler->display->display_options['filters']['field_timending_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_timending_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_timending_value']['default_date'] = 'now';
  $handler->display->display_options['block_description'] = 'First item from past-deals';
  $export['all_deals'] = $view;

  $view = new view();
  $view->name = 'cities_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Cities List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cities List';
  $handler->display->display_options['css_class'] = 'cities-select';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '';
  $handler->display->display_options['style_plugin'] = 'jump_menu';
  $handler->display->display_options['style_options']['hide'] = TRUE;
  $handler->display->display_options['style_options']['path'] = 'tid';
  $handler->display->display_options['style_options']['choose'] = '- All -';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="headerCityCaption">Choose City:</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['text'] = 'all-deals/[tid]';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['hide_alter_empty'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'deals-by-city/[name]';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'cities' => 'cities',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['block_description'] = 'Cities List';
  $export['cities_list'] = $view;

  $view = new view();
  $view->name = 'deals_management';
  $view->description = 'This view is the main dashboard for deals management. Intented to be used by site administrators.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Deals Management';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Deals Management';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title_1' => 'title_1',
    'field_product' => 'field_product',
    'status' => 'status',
    'field_store_refer' => 'field_store_refer',
    'field_city' => 'field_city',
    'field_timending' => 'field_timending',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_product' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_store_refer' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_city' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_timending' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Add new deal</h2>
<table>
  <thead>
    <tr>
    <th>1st Step:</th>
    <th>2nd Step:</th>
    <th>3rd Step:</th>
    </tr>
  </thead>
  <tbody>
    <tr class="odd">
    <td>First, you need to add a product.</td>
    <td>Then, you should add a new store. If the product you want to add is from a<br />store that already exists, then you can skip this step.</td>
    <td>Finally, you have to relate the product to the store<br />by adding a new deal and select the end date. </td>
    </tr>
    <tr class="even">
    <td><form class="views-exposed-form" method="link" action="admin/commerce/products/add/product"><input class="form-submit" type="submit" value="Add a product"></form></td>
    <td><form class="views-exposed-form" method="link" action="node/add/store"><input class="form-submit" type="submit" value="Add a Store"></form></td>
    <td><form class="views-exposed-form" method="link" action="node/add/deal"><input class="form-submit" type="submit" value="Create the Deal"></form></td>
    </tr>
  </tbody>
</table>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'id';
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = FALSE;
  /* Field: Content: Product */
  $handler->display->display_options['fields']['field_product']['id'] = 'field_product';
  $handler->display->display_options['fields']['field_product']['table'] = 'field_data_field_product';
  $handler->display->display_options['fields']['field_product']['field'] = 'field_product';
  $handler->display->display_options['fields']['field_product']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_product']['type'] = 'commerce_product_reference_sku_link';
  $handler->display->display_options['fields']['field_product']['settings'] = array(
    'show_quantity' => 0,
    'default_quantity' => '1',
    'combine' => 1,
    'line_item_type' => 0,
  );
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Store */
  $handler->display->display_options['fields']['field_store_refer']['id'] = 'field_store_refer';
  $handler->display->display_options['fields']['field_store_refer']['table'] = 'field_data_field_store_refer';
  $handler->display->display_options['fields']['field_store_refer']['field'] = 'field_store_refer';
  $handler->display->display_options['fields']['field_store_refer']['hide_alter_empty'] = FALSE;
  /* Field: Content: Available at */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = 'City';
  $handler->display->display_options['fields']['field_city']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_city']['delta_offset'] = '0';
  /* Field: Content: End Date */
  $handler->display->display_options['fields']['field_timending']['id'] = 'field_timending';
  $handler->display->display_options['fields']['field_timending']['table'] = 'field_data_field_timending';
  $handler->display->display_options['fields']['field_timending']['field'] = 'field_timending';
  $handler->display->display_options['fields']['field_timending']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_timending']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'deal' => 'deal',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Available at (field_city) */
  $handler->display->display_options['filters']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['filters']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['filters']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['filters']['field_city_tid']['group'] = 0;
  $handler->display->display_options['filters']['field_city_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_city_tid']['expose']['operator_id'] = 'field_city_tid_op';
  $handler->display->display_options['filters']['field_city_tid']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_city_tid']['expose']['operator'] = 'field_city_tid_op';
  $handler->display->display_options['filters']['field_city_tid']['expose']['identifier'] = 'field_city_tid';
  $handler->display->display_options['filters']['field_city_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_city_tid']['vocabulary'] = 'cities';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'deals-management';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Deals Management';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['deals_management'] = $view;

  $view = new view();
  $view->name = 'frontpage';
  $view->description = 'Emulates the default Drupal front page; you may set the default home page path to this view to make it your front page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Front page';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Content: Available at (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  /* Relationship: Content: Store (field_store_refer) */
  $handler->display->display_options['relationships']['field_store_refer_nid']['id'] = 'field_store_refer_nid';
  $handler->display->display_options['relationships']['field_store_refer_nid']['table'] = 'field_data_field_store_refer';
  $handler->display->display_options['relationships']['field_store_refer_nid']['field'] = 'field_store_refer_nid';
  $handler->display->display_options['relationships']['field_store_refer_nid']['delta'] = '-1';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_product_ref_nid';
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_city_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'deal' => 'deal',
  );
  /* Filter criterion: Content: End Date (field_timending) */
  $handler->display->display_options['filters']['field_timending_value']['id'] = 'field_timending_value';
  $handler->display->display_options['filters']['field_timending_value']['table'] = 'field_data_field_timending';
  $handler->display->display_options['filters']['field_timending_value']['field'] = 'field_timending_value';
  $handler->display->display_options['filters']['field_timending_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_timending_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_timending_value']['default_date'] = 'now';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'frontpage';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Front page feed';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'rss.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['sitename_title'] = '1';
  $export['frontpage'] = $view;

  return $export;
}
