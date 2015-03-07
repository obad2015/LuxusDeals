<?php

/**
 * @file
 * template.php
 */


function luxusdeals_preprocess_html(&$vars) {
  if (user_access('get discount')) {
    $vars['classes_array'][] = 'premium-user';
  }
}

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

  if (user_access('get discount')) {
    $vars['premium_user'] = TRUE;
  }
  else {
    $vars['premium_user'] = FALSE;
    $vars['subscribe_button'] = misc_add_product_to_cart_button(9);
  }
}


/**
 * Implements hook_preprocess_node().
 */
function luxusdeals_preprocess_node(&$vars) {
  /* Additional node teaser templates */
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__' . $vars['view_mode'];

  if ($vars['node']->type == 'deal' && $vars['view_mode'] == 'full') {

  }
}

/**
 * Theme the subscribe button.
 *
 * Overrides theme_button().
 */
function luxusdeals_button($vars) {
  if ($vars['element']['#value'] == 'nav_bar_subscribe_button') {
    $element = $vars['element'];
    element_set_attributes($element, array('id', 'name', 'value', 'type'));

    // Add in the button type class.
    $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
    $element['#attributes']['class'][] = 'btn-success pull-right call-to-action';

    // This line break adds inherent margin between multiple buttons.
    return '<button' . drupal_attributes($element['#attributes']) . '>' . '<i
              class="fa fa-user-plus"></i> Tilmeld. <span>Spar +15%</span>' . "</button>\n";
  }

  return bootstrap_button($vars);
}
