<?php
/**
 * Implementation of hook_profile_form_alter().
 */
function opendeals_form_alter(&$form, $form_state, $form_id) {
  // Add an additional submit handler. 
  if ($form_id == 'install_configure_form' || $form_id == 'node_admin_content') {
    $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
    $form['#submit'][] = 'opendeals_configure_form_submit';
  }
}

/**
 * Custom form submit handler for configuration form.
 *
 * Drops all data from existing database, imports database dump, and restores
 * values entered into configuration form.
 */
function opendeals_configure_form_submit($form, &$form_state) {
  $account = user_load(1);
  user_save($account, array('roles' => $account->roles + array( 4 => 'administrator' )));
}

/**
 * Implements hook_install_tasks().
 */
function opendeals_install_tasks($install_state) {
  return array(
    // Just a hidden task callback.
    'opendeals_profile_setup' => array(),
  );
}

/**
 * Installer task callback.
 */
function opendeals_profile_setup() {
	variable_set('date_first_day','1');
	variable_set('date_format_long','l, F j, Y - H:i');
	variable_set('date_format_medium','D, Y-m-d H:i');
	variable_set('date_format_short','Y-m-d H:i');
	variable_set('googleanalytics_account','UA-26074760-1');

	// create city list
	opendeals_create_taxonomy_term('Athens', 1);
	opendeals_create_taxonomy_term('London', 1);
	opendeals_create_taxonomy_term('New York', 1);
	opendeals_create_taxonomy_term('Paris', 1);

	// create demo content (nodes/products)
  opendeals_create_demo_deals();
  
  // create Footer Menu Items
  opendeals_create_demo_footer_menu_items();

	// create demo blocks and configure blocks from views, system, menu
	block_flush_caches();
	
	opendeals_insert_custom_blocks();
  opendeals_update_block_position('system','main','content');
  opendeals_update_block_position('system','help','help');
  opendeals_update_block_position('system','user-menu','navigation', 0, '<none>');
	$expages = "all-deals\nall-deals/*\npast-deals\npast-deals/*\nnode/21\ncart\ncart/*\ncheckout\ncheckout/*";
  opendeals_update_block_position('views','all_deals-block','sidebar', 0, '<none>', $expages);
  opendeals_update_block_position('views','cities_list-block','top', 0, '<none>');
  opendeals_update_block_position('menu','menu-footer-menu','footer_bottom', -10, 'Company');
  opendeals_update_block_position('menu','menu-footer-menu-middle','footer_bottom', -8, 'Get Help');
  opendeals_update_block_position('menu','menu-footer-menu-right','footer_bottom', -5, 'Work With Us');
  opendeals_update_block_position('opendeals_module','support','content', 20, '', 'deals-management', 'rubik', 1);
  opendeals_update_block_position('opendeals_module','support','content', 20, '', 'deals-management', 'seven', 1);
  opendeals_update_block_position('system','main','content', 0, '', '', 'rubik');
  opendeals_update_block_position('system','main','content', 0, '', '', 'seven');
  opendeals_update_block_position('system','help','help', 0, '', '', 'rubik');
  opendeals_update_block_position('system','help','help', 0, '', '', 'seven');
  opendeals_update_block_position('user','login','content', 10, '', '', 'rubik');
  opendeals_update_block_position('user','login','content', 10, '', '', 'seven');

  opendeals_update_commerce_panes();
}

/**
 * Updates commerce panes
 */
function opendeals_update_commerce_panes(){
	db_truncate('commerce_checkout_pane')->execute();
	db_insert('commerce_checkout_pane')->fields(array(
		'pane_id' => 'account',
    'page' => 'checkout',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => -19,
    'enabled' => 1,
    'review' => 1,
  ))->execute();
  db_insert('commerce_checkout_pane')->fields(array(
		'pane_id' => 'cart_contents',
    'page' => 'checkout',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => -20,
    'enabled' => 1,
    'review' => 1,
  ))->execute();
  db_insert('commerce_checkout_pane')->fields(array(
		'pane_id' => 'checkout_completion_message',
    'page' => 'complete',
    'fieldset' => 0,
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => 0,
    'enabled' => 1,
    'review' => 1,
  ))->execute();
  db_insert('commerce_checkout_pane')->fields(array(
		'pane_id' => 'checkout_review',
    'page' => 'disabled',
    'fieldset' => 0,
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => 0,
    'enabled' => 0,
    'review' => 1,
  ))->execute();
  db_insert('commerce_checkout_pane')->fields(array(
		'pane_id' => 'commerce_payment',
    'page' => 'checkout',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => -17,
    'enabled' => 1,
    'review' => 1,
  ))->execute();
  db_insert('commerce_checkout_pane')->fields(array(
		'pane_id' => 'customer_profile_billing',
    'page' => 'checkout',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => -18,
    'enabled' => 1,
    'review' => 1,
  ))->execute();
  db_insert('commerce_checkout_pane')->fields(array(
		'pane_id' => 'commerce_payment_redirect',
    'page' => 'payment',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => 0,
    'enabled' => 1,
    'review' => 1,
  ))->execute();
}

/*
 * Updates custom blocks positions.
 */
function opendeals_update_block_position($module, $delta, $region, $weight = 0, $title = '', $pages = '', $theme = 'opendeals_theme', $visibility = 0){
	db_update('block')
  	->fields(array(
    	'status' => 1, 
      'weight' => $weight, 
      'region' => $region,
    ))
			->condition('module', $module)
      ->condition('delta', $delta)
      ->condition('theme', $theme)
      ->execute();
	db_update('block')
  	->fields(array(
      'title' => $title,
      'pages' => $pages,
      'visibility' => $visibility,
    ))
			->condition('module', $module)
      ->condition('delta', $delta)
      ->execute();
}


/*
 * Creates demo content blocks.
 */
function opendeals_insert_custom_blocks(){
	$filename = 'profiles/opendeals/demo_content/blocks.txt';
	$contents = trim(file_get_contents($filename));
	if (!$contents) {
    return null;
  }
  $rows = explode("\n", $contents);
  foreach($rows as $row){
  	$item = explode("|", $row);
  	$block = array();
  	$block = array(
  		'body' => array(
  			'value' => $item[3],
  			'format' => $item[4],
  		),
  		'info' => $item[1],
  		'visibility' => (int)$item[5],
  		'pages' => str_replace("!$","\n",$item[6]),
  		'custom' => 0,
  		'module' => 'block',
  		'roles' => array(),
  		'regions' => array('opendeals_theme' => $item[0]),
  		'title' => $item[2],
  		'weight' => $item[7],
  	);
  	opendeals_create_custom_block($block);
  }
  cache_clear_all();
}


/*
 * Create custom block.
 */
function opendeals_create_custom_block($block){
	$delta = db_insert('block_custom')
    ->fields(array(
    'body' => $block['body']['value'], 
    'info' => $block['info'], 
    'format' => $block['body']['format'],
  ))
    ->execute();
  // Store block delta to allow other modules to work with new block.
  $block['delta'] = $delta;

  $query = db_insert('block')->fields(array('visibility', 'pages', 'custom', 'title', 'module', 'theme', 'status', 'weight', 'delta', 'cache'));
  $query->values(array(
  	'visibility' => (int) $block['visibility'], 
    'pages' => trim($block['pages']), 
    'custom' => (int) $block['custom'], 
    'title' => $block['title'], 
    'module' => $block['module'], 
    'theme' => 'opendeals_theme', 
    'status' => 0, 
    'weight' => $block['weight'],
    'delta' => $delta, 
    'cache' => DRUPAL_NO_CACHE,
	));
  $query->execute();

  // Store regions per theme for this block
  foreach ($block['regions'] as $theme => $region) {
    db_merge('block')
      ->key(array('theme' => $theme, 'delta' => $delta, 'module' => $block['module']))
      ->fields(array(
      'region' => ($region == BLOCK_REGION_NONE ? '' : $region), 
      'pages' => trim($block['pages']), 
      'status' => (int) ($region != BLOCK_REGION_NONE),
    ))
      ->execute();
  }
}

/*
 * Create taxonomy terms.
 */
function opendeals_create_taxonomy_term($name, $vid) {
  $term = new stdClass();
  $term->name = $name;
  $term->vid = $vid;
  taxonomy_term_save($term);
  return $term->tid;
}


/*
 * Creates demo deals.
 */
function opendeals_create_demo_deals(){
  $stores = opendeals_create_demo_stores();
  $products = opendeals_create_demo_products();
  $alt_stores = array();

  $filename = 'profiles/opendeals/demo_content/deals.txt';
  $contents = trim(file_get_contents($filename));
  if (!$contents) {
    return null;
  }
  $rows = explode("\n", $contents);
  $i = 0;
  foreach ($rows as $row) {
    $item = explode("|", $row);
    $newnode = new stdClass();
    $newnode->language = LANGUAGE_NONE;
    $newnode->type = 'deal';
    $newnode->uid = 1;
    $newnode->title = $item[0];
    foreach (explode("!$",$item[2]) as $tag) {
      $newnode->field_city[$newnode->language][]['tid'] = $tag;
    }
    $newnode->field_product[$newnode->language][0]['product_id'] = $item[1];
    if (!empty($stores)) {
      $store = array_shift($stores);
      $alt_stores[] = $store;
    }
    else {
      $store = array_shift($alt_stores);
    }
    $newnode->field_store_refer[$newnode->language][0]['nid'] = $store;
    if ($i > 6) {
      $newnode->field_timending[$newnode->language][0]['value'] = date('Y-m-d H:i:s', time() - 60 * 60 * rand(2, 10));
    }
    else {
      $newnode->field_timending[$newnode->language][0]['value'] = date('Y-m-d H:i:s', time()+ 60 * 60 * 24 * 20);
    }
    $newnode = node_submit($newnode);
    node_save($newnode);
    $i++;
  }
}

/*
 * Creates demo stores.
 */
function opendeals_create_demo_stores(){
	$filename = 'profiles/opendeals/demo_content/stores.txt';
	$contents = trim(file_get_contents($filename));
	if (!$contents) {
    return null;
  }
	$rows = explode("\n", $contents);
	$ids = array();
  foreach($rows as $row){
  	$item = explode("|", $row);
		$newnode = new stdClass();
		$newnode->language = LANGUAGE_NONE;
  	$newnode->type = 'store';
		$newnode->uid = 1;

  	$file = new StdClass();
		$file->uid = 1;
		$file->uri = DRUPAL_ROOT.'/profiles/opendeals/demo_content/'.$item[1];
		$file->filemime = file_get_mimetype($file->uri);
		$file->status = 1;
		$name = $item[1];
		$dest = file_default_scheme() . '://'.$name;
		$file = file_copy($file, $dest);
		$newnode->field_store_image[LANGUAGE_NONE][0] = (array)$file;

  	$newnode->title = $item[0];
  	$newnode->body[$newnode->language][0]['value'] = $item[2];
  	$newnode->body[$newnode->language][0]['format'] = 'filtered_html';

  	foreach(explode('!$',$item[3]) as $address){
			$newnode->field_store_location[$newnode->language][]['value'] = $address;
		}
		$newnode->field_store_site[LANGUAGE_NONE][0]['value'] = $item[4];

		$newnode = node_submit($newnode);
  	node_save($newnode);
  	$ids[] = $newnode->nid;
	}
	return $ids;
}


/*
 * Creates demo products.
 */
function opendeals_create_demo_products(){
	$filename = 'profiles/opendeals/demo_content/products.txt';
	$contents = trim(file_get_contents($filename));
	if (!$contents) {
    return null;
  }
  $rows = explode("\n", $contents);
  $ids = array();
  foreach($rows as $row){
  	$item = explode("|", $row);
  	$product = array();
		$product['sku'] = $item[1];
		$product['uid'] = 1;
		$product['title'] = $item[2];
		$product['price'] = $item[3];
		$product['field_or_price'] = $item[5];
		$product['status'] = 1;
		$product['field_few_words'] = $item[7];
		$product['field_details'] = $item[8];
		$product['image_path'] = DRUPAL_ROOT.'/profiles/opendeals/demo_content/'.$item[9];
		$ids[] = opendeals_create_product('product', $product, $product);
	}
	return $ids;
}

/**
 * Create a product programmatically.
 *
 * @param $product_type
 *   (string) The name of the product type for which products should be created.
 * @param $values
 *   Keyed array with
 *   - 'price' => actual amount owed on this installment; decimal text like '1.50'
 *   - 'amount_paid' => price amount already paid as a decimal text like '1.50';
 *   - 'original_order' => order id of the original order
 *   - 'original_line_item' => line item id of original line item
 *   - 'original_product => product id of the original product from which the
 *     new product is being created.
 * @param $extras
 *   An array for the values of  'extra fields' defined for the product type
 *   entity, or patterns for these. Recognized keys are:
 *   - status
 *   - uid
 *   - sku
 *   - title
 *   Note that the values do NOT come in the form of complex arrays (as they
 *   are not translatable, and can only have single values).
 * @return
 *   The ID of the created product.
 */
function opendeals_create_product($product_type, $values, $extras) {
  $form_state = array();
  $form_state['values'] = $values;
  $form = array();
  $form['#parents'] = array();

  // Generate a new product object
  $new_product = commerce_product_new($product_type);

  $new_product->status = $extras['status'];
  $new_product->uid = $extras['uid'];

  $new_product->sku = $extras['sku'];
  $new_product->title = $extras['title'];
  $new_product->created = $new_product->changed = time();
  $new_product->language = LANGUAGE_NONE;

  //commerce_price[und][0][amount]
  $price = array(LANGUAGE_NONE => array(0 => array(
    'amount' => $values['price'],
    'currency_code' => commerce_default_currency(),
  )));
  $form_state['values']['commerce_price'] = $price;

  // field_or_price[und][0][value][amount]
  $field_or_price = array(LANGUAGE_NONE => array(0 => array('amount' => $values['field_or_price'], 'currency_code' => commerce_default_currency())));
  $form_state['values']['field_or_price'] = $field_or_price;
  
  // field_few_words[und][0][value][amount]
  $field_few_words = array(LANGUAGE_NONE => array(0 => array('value' => $values['field_few_words'], 'format' => 'full_html')));
  $form_state['values']['field_few_words'] = $field_few_words;
  
  // field_details[und][0][value][amount]
  $field_details = array(LANGUAGE_NONE => array(0 => array('value' => $values['field_details'], 'format' => 'full_html')));
  $form_state['values']['field_details'] = $field_details;
  
  // commerce_sales[und][0][value][amount]
  $commerce_sales = array(LANGUAGE_NONE => array(0 => array('value' => rand(0,10))));
  $form_state['values']['commerce_sales'] = $commerce_sales;
  
	$file = new StdClass();
	$file->uid = 1;
	$file->uri = $values['image_path'];
	$file->filemime = file_get_mimetype($file->uri);
	$file->status = 1;
	$name = array_pop(explode('/',$values['image_path']));
	$dest = file_default_scheme() . '://'.$name;
	$file = file_copy($file, $dest);
	$form_state['values']['field_deal_image'][LANGUAGE_NONE][0] = (array)$file;

	// Need to set alt and title to prevent error message in image formatter.
	$form_state['values']['field_deal_image'][LANGUAGE_NONE][0]['alt'] = '';
	$form_state['values']['field_deal_image'][LANGUAGE_NONE][0]['title'] = '';

  // Notify field widgets to save their field data
  field_attach_submit('commerce_product', $new_product, $form, $form_state);

  commerce_product_save($new_product);
  return $new_product->product_id;
}


/*
 * Creates footer menu items.
 */
function opendeals_create_demo_footer_menu_items(){

  // Exported menu: menu-footer-menu
  $menus['menu-footer-menu'] = array(
    'menu_name' => 'menu-footer-menu',
    'title' => 'Footer Menu Left',
    'description' => '',
  );
  // Exported menu: menu-footer-menu-middle
  $menus['menu-footer-menu-middle'] = array(
    'menu_name' => 'menu-footer-menu-middle',
    'title' => 'Footer Menu Middle',
    'description' => '',
  );
  // Exported menu: menu-footer-menu-right
  $menus['menu-footer-menu-right'] = array(
    'menu_name' => 'menu-footer-menu-right',
    'title' => 'Footer Menu Right',
    'description' => '',
  );

	foreach($menus as $menu){
		menu_save($menu);
	}

	opendeals_create_demo_menu_item('menu-footer-menu', 'Home', 1);
	opendeals_create_demo_menu_item('menu-footer-menu', 'About', 2);
	opendeals_create_demo_menu_item('menu-footer-menu', 'Blog', 3);

	opendeals_create_demo_menu_item('menu-footer-menu-middle', 'Customer Support', 1);
	opendeals_create_demo_menu_item('menu-footer-menu-middle', 'FAQ', 2);
	opendeals_create_demo_menu_item('menu-footer-menu-middle', 'Privacy Statement', 3);
	opendeals_create_demo_menu_item('menu-footer-menu-middle', 'Return Policy', 4);
	opendeals_create_demo_menu_item('menu-footer-menu-middle', 'Terms of Use', 5);

	opendeals_create_demo_menu_item('menu-footer-menu-right', '1st element', 1);
	opendeals_create_demo_menu_item('menu-footer-menu-right', '2nd element', 2);
	opendeals_create_demo_menu_item('menu-footer-menu-right', '3rd element', 3);
	opendeals_create_demo_menu_item('menu-footer-menu-right', '4th element', 4);
}

/*
 * Creates menu link.
 */
function opendeals_create_demo_menu_item($menu_name, $link_title, $weight = 0){
	$form_state = array(
		'values' => array(
    	'menu_name'  => $menu_name,
    	'weight'     => $weight,
    	'link_title' => $link_title,
    	'link_path'  => 'node/22',
    	'module'     => 'menu',
    	'mlid'       => 0,
		),
  );

	// Save the item to database.
	menu_link_save($form_state['values']);
}