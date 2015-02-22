<?php

/**
 * @file
 * template.php
 */


function luxusdeals_preprocess_page(&$vars) {
  if (isset($GLOBALS['top_bar_image'])) {
    $path = drupal_get_path('theme', 'luxusdeals') . '/images/' . $GLOBALS['top_bar_image'] . '.jpg';

    if (file_exists($path)) {
      $vars['top_image'] = $path;
    }
    else {
      if (function_exists('dpm')) {
        dpm('image path: ' . $path);
      }
    }
  }
}