<?php
/**
 * @file
 * opendeals_role_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function opendeals_role_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration menu
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: access administration pages
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: access all views
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: access all webform results
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: access checkout
  $permissions['access checkout'] = array(
    'name' => 'access checkout',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
      2 => 'anonymous user',
      3 => 'authenticated user',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: access comments
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: access content
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
      2 => 'anonymous user',
      3 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: access contextual links
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: access dashboard
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: access overlay
  $permissions['access overlay'] = array(
    'name' => 'access overlay',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'overlay',
  );

  // Exported permission: access own webform results
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: access own webform submissions
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: access rules debug
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: access site in maintenance mode
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: access site reports
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: access user profiles
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer actions
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer admin paths
  $permissions['administer admin paths'] = array(
    'name' => 'administer admin paths',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'admin_path',
  );

  // Exported permission: administer blocks
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: administer checkout
  $permissions['administer checkout'] = array(
    'name' => 'administer checkout',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: administer comments
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: administer commerce_customer_profile entities
  $permissions['administer commerce_customer_profile entities'] = array(
    'name' => 'administer commerce_customer_profile entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: administer commerce_order entities
  $permissions['administer commerce_order entities'] = array(
    'name' => 'administer commerce_order entities',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: administer commerce_product entities
  $permissions['administer commerce_product entities'] = array(
    'name' => 'administer commerce_product entities',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: administer content types
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: administer customer profile types
  $permissions['administer customer profile types'] = array(
    'name' => 'administer customer profile types',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: administer features
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: administer filters
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: administer google analytics
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: administer image styles
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: administer line item types
  $permissions['administer line item types'] = array(
    'name' => 'administer line item types',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_line_item',
  );

  // Exported permission: administer line items
  $permissions['administer line items'] = array(
    'name' => 'administer line items',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_line_item',
  );

  // Exported permission: administer menu
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: administer module filter
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: administer modules
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer nodes
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: administer page manager
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: administer pathauto
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: administer payment methods
  $permissions['administer payment methods'] = array(
    'name' => 'administer payment methods',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: administer payments
  $permissions['administer payments'] = array(
    'name' => 'administer payments',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: administer permissions
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer product pricing
  $permissions['administer product pricing'] = array(
    'name' => 'administer product pricing',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_product_pricing_ui',
  );

  // Exported permission: administer product types
  $permissions['administer product types'] = array(
    'name' => 'administer product types',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: administer rules
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: administer search
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: administer site configuration
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer software updates
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer string overrides
  $permissions['administer string overrides'] = array(
    'name' => 'administer string overrides',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'stringoverrides',
  );

  // Exported permission: administer taxes
  $permissions['administer taxes'] = array(
    'name' => 'administer taxes',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_tax_ui',
  );

  // Exported permission: administer taxonomy
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer url aliases
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: administer users
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer views
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: administer xmlsitemap
  $permissions['administer xmlsitemap'] = array(
    'name' => 'administer xmlsitemap',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'xmlsitemap',
  );

  // Exported permission: block IP addresses
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: bypass node access
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: bypass rules access
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: cancel account
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: change own username
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: configure store
  $permissions['configure store'] = array(
    'name' => 'configure store',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce',
  );

  // Exported permission: create article content
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create commerce_customer_profile entities
  $permissions['create commerce_customer_profile entities'] = array(
    'name' => 'create commerce_customer_profile entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: create commerce_customer_profile entities of bundle billing
  $permissions['create commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'create commerce_customer_profile entities of bundle billing',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: create commerce_order entities
  $permissions['create commerce_order entities'] = array(
    'name' => 'create commerce_order entities',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: create commerce_order entities of bundle commerce_order
  $permissions['create commerce_order entities of bundle commerce_order'] = array(
    'name' => 'create commerce_order entities of bundle commerce_order',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: create commerce_product entities
  $permissions['create commerce_product entities'] = array(
    'name' => 'create commerce_product entities',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create commerce_product entities of bundle product
  $permissions['create commerce_product entities of bundle product'] = array(
    'name' => 'create commerce_product entities of bundle product',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create deal content
  $permissions['create deal content'] = array(
    'name' => 'create deal content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create page content
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create payments
  $permissions['create payments'] = array(
    'name' => 'create payments',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: create store content
  $permissions['create store content'] = array(
    'name' => 'create store content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create url aliases
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: create webform content
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete all webform submissions
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: delete any article content
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any deal content
  $permissions['delete any deal content'] = array(
    'name' => 'delete any deal content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any page content
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any store content
  $permissions['delete any store content'] = array(
    'name' => 'delete any store content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any webform content
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own article content
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own deal content
  $permissions['delete own deal content'] = array(
    'name' => 'delete own deal content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own page content
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own store content
  $permissions['delete own store content'] = array(
    'name' => 'delete own store content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own webform content
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own webform submissions
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: delete payments
  $permissions['delete payments'] = array(
    'name' => 'delete payments',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: delete revisions
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: display drupal links
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: edit all webform submissions
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: edit any article content
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any commerce_customer_profile entity
  $permissions['edit any commerce_customer_profile entity'] = array(
    'name' => 'edit any commerce_customer_profile entity',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: edit any commerce_customer_profile entity of bundle billing
  $permissions['edit any commerce_customer_profile entity of bundle billing'] = array(
    'name' => 'edit any commerce_customer_profile entity of bundle billing',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: edit any commerce_order entity
  $permissions['edit any commerce_order entity'] = array(
    'name' => 'edit any commerce_order entity',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: edit any commerce_order entity of bundle commerce_order
  $permissions['edit any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'edit any commerce_order entity of bundle commerce_order',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: edit any commerce_product entity
  $permissions['edit any commerce_product entity'] = array(
    'name' => 'edit any commerce_product entity',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any commerce_product entity of bundle product
  $permissions['edit any commerce_product entity of bundle product'] = array(
    'name' => 'edit any commerce_product entity of bundle product',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any deal content
  $permissions['edit any deal content'] = array(
    'name' => 'edit any deal content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any store content
  $permissions['edit any store content'] = array(
    'name' => 'edit any store content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any webform content
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own article content
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own comments
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: edit own commerce_customer_profile entities
  $permissions['edit own commerce_customer_profile entities'] = array(
    'name' => 'edit own commerce_customer_profile entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: edit own commerce_customer_profile entities of bundle billing
  $permissions['edit own commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'edit own commerce_customer_profile entities of bundle billing',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: edit own commerce_order entities
  $permissions['edit own commerce_order entities'] = array(
    'name' => 'edit own commerce_order entities',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: edit own commerce_order entities of bundle commerce_order
  $permissions['edit own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'edit own commerce_order entities of bundle commerce_order',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: edit own commerce_product entities
  $permissions['edit own commerce_product entities'] = array(
    'name' => 'edit own commerce_product entities',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own commerce_product entities of bundle product
  $permissions['edit own commerce_product entities of bundle product'] = array(
    'name' => 'edit own commerce_product entities of bundle product',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own deal content
  $permissions['edit own deal content'] = array(
    'name' => 'edit own deal content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own page content
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own store content
  $permissions['edit own store content'] = array(
    'name' => 'edit own store content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own webform content
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own webform submissions
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: flush caches
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: manage features
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: notify of path changes
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: opt-in or out of tracking
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: post comments
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: revert revisions
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: search content
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: select account cancellation method
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: skip comment approval
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: update payments
  $permissions['update payments'] = array(
    'name' => 'update payments',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: use PHP for tracking visibility
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: use advanced search
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: use page manager
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: use text format filtered_html
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
      2 => 'anonymous user',
      3 => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format full_html
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: view any commerce_customer_profile entity
  $permissions['view any commerce_customer_profile entity'] = array(
    'name' => 'view any commerce_customer_profile entity',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: view any commerce_customer_profile entity of bundle billing
  $permissions['view any commerce_customer_profile entity of bundle billing'] = array(
    'name' => 'view any commerce_customer_profile entity of bundle billing',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: view any commerce_order entity
  $permissions['view any commerce_order entity'] = array(
    'name' => 'view any commerce_order entity',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: view any commerce_order entity of bundle commerce_order
  $permissions['view any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'view any commerce_order entity of bundle commerce_order',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: view any commerce_product entity
  $permissions['view any commerce_product entity'] = array(
    'name' => 'view any commerce_product entity',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
			2 => 'anonymous user',
 	 		3 => 'authenticated user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view any commerce_product entity of bundle product
  $permissions['view any commerce_product entity of bundle product'] = array(
    'name' => 'view any commerce_product entity of bundle product',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_customer_profile entities
  $permissions['view own commerce_customer_profile entities'] = array(
    'name' => 'view own commerce_customer_profile entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: view own commerce_customer_profile entities of bundle billing
  $permissions['view own commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'view own commerce_customer_profile entities of bundle billing',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: view own commerce_order entities
  $permissions['view own commerce_order entities'] = array(
    'name' => 'view own commerce_order entities',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: view own commerce_order entities of bundle commerce_order
  $permissions['view own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'view own commerce_order entities of bundle commerce_order',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: view own commerce_product entities
  $permissions['view own commerce_product entities'] = array(
    'name' => 'view own commerce_product entities',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_product entities of bundle product
  $permissions['view own commerce_product entities of bundle product'] = array(
    'name' => 'view own commerce_product entities of bundle product',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own unpublished content
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: view payments
  $permissions['view payments'] = array(
    'name' => 'view payments',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: view revisions
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: view the administration theme
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      0 => 'Manager',
      1 => 'administrator',
    ),
    'module' => 'system',
  );

  return $permissions;
}
