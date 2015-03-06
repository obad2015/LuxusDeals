<?php

/**
 * @file
 * template.php
 */


function luxusdeals_preprocess_page(&$vars) {
  if (isset($GLOBALS['top_bar_image'])) {
    $path = drupal_get_path('theme', 'luxusdeals') . '/images/' . $GLOBALS['top_bar_image'] . '.jpg';

    if (file_exists($path)) {
      $vars['top_image'] = '/' . $path;
    }
    else {
      if (function_exists('dpm')) {
        dpm('image path: ' . $path);
      }
    }
  }

  if ($node = menu_get_object()) {
    if (isset($node->nid) && $node->type == 'deal') {
      // TODO add category from source node
      $vars['related_deals'] = views_embed_view('ld_deals', 'related_deals');
    }
  }
}


/**
 * Implements hook_preprocess_node().
 */
function luxusdeals_preprocess_node(&$vars) {
  /* Additional node teaser templates */
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__' . $vars['view_mode'];

  if ($vars['node']->type == 'deal' && $vars['view_mode'] == 'full') {
    //dpm($vars);
  }
}