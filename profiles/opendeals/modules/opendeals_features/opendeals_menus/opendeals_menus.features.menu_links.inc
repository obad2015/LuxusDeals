<?php
/**
 * @file
 * opendeals_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function opendeals_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Day Offer',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: main-menu:all-deals
  $menu_links['main-menu:all-deals'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'all-deals',
    'router_path' => 'all-deals',
    'link_title' => 'All Deals',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: main-menu:past-deals
  $menu_links['main-menu:past-deals'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'past-deals',
    'router_path' => 'past-deals',
    'link_title' => 'Past Deals',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('All Deals');
  t('Day Offer');
  t('Past Deals');


  return $menu_links;
}
