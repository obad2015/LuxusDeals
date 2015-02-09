<?php
/**
 * @file
 * opendeals_defaults.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function opendeals_defaults_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_path';
  $strongarm->value = array(
    'node/*/webform' => TRUE,
    'node/*/webform/*' => TRUE,
    'node/*/webform-results' => TRUE,
    'node/*/webform-results/*' => TRUE,
    'node/*/submission/*' => TRUE,
    'node/*/edit' => TRUE,
    'node/*/delete' => TRUE,
    'node/*/revisions' => TRUE,
    'node/*/revisions/*/revert' => TRUE,
    'node/*/revisions/*/delete' => TRUE,
    'node/add' => TRUE,
    'node/add/*' => TRUE,
    'overlay/dismiss-message' => TRUE,
    'admin' => TRUE,
    'admin/*' => TRUE,
    'batch' => TRUE,
    'taxonomy/term/*/edit' => TRUE,
    'user/*/cancel' => TRUE,
    'user/*/edit' => TRUE,
    'user/*/edit/*' => TRUE,
    'devel/*' => TRUE,
    'node/*/devel' => TRUE,
    'node/*/devel/*' => TRUE,
    'comment/*/devel' => TRUE,
    'comment/*/devel/*' => TRUE,
    'user/*/devel' => TRUE,
    'user/*/devel/*' => TRUE,
    'taxonomy/term/*/devel' => TRUE,
    'taxonomy/term/*/devel/*' => TRUE,
    'deals-management' => TRUE,
    'admin/structure/block/demo/*' => FALSE,
    'admin/reports/status/php' => FALSE,
  );
  $export['admin_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'block_cache';
  $strongarm->value = 1;
  $export['block_cache'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache';
  $strongarm->value = 1;
  $export['cache'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_lifetime';
  $strongarm->value = '86400';
  $export['cache_lifetime'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_privacy_donottrack';
  $strongarm->value = 0;
  $export['googleanalytics_privacy_donottrack'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_cache_maximum_age';
  $strongarm->value = '86400';
  $export['page_cache_maximum_age'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_compression';
  $strongarm->value = 1;
  $export['page_compression'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_pattern';
  $strongarm->value = '[node:title]';
  $export['pathauto_node_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'preprocess_css';
  $strongarm->value = 1;
  $export['preprocess_css'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'preprocess_js';
  $strongarm->value = 1;
  $export['preprocess_js'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'frontpage';
  $export['site_frontpage'] = $strongarm;

  return $export;
}
