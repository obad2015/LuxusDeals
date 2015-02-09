<?php
/**
 * @file
 * Views integration
 */


/**
 * Implements hook_views_data().
 */
function opendeals_module_views_data() {
  // Define a handler for an area used to summarize a set of line items.
  $data['commerce_order']['order_total_discount'] = array(
    'title' => t('Total Discount'),
    'help' => t('Displays the order total discount'),
    'area' => array(
      'handler' => 'opendeals_module_handler_area_order_total_discount',
    ),
  );

  return $data;
}

class opendeals_module_handler_area_order_total_discount extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    // TODO: Update with option definitions if the display formatter itself
    // gets support for them.

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    unset($form['empty']);

    // TODO: Update with option form elements if the display formatter itself
    // gets support for them.
  }

  function render($empty = FALSE) {
    if (!$empty) {
      // First look for an order_id argument.
      foreach ($this->view->argument as $name => $argument) {
        if ($argument instanceof commerce_order_handler_argument_order_order_id) {
          // If it is single value...
          if (count($argument->value) == 1) {
            // Load the order.
            $order = commerce_order_load(reset($argument->value));

            $line_items = entity_metadata_wrapper('commerce_order', $order)->commerce_line_items->value();

            $html = '<div class="showDiscount"><span class="line1">You</span><span class="line2">Earn</span><span class="line3">';

            foreach ($line_items as $line_item) {
              $product = entity_metadata_wrapper('commerce_line_item', $line_item)->commerce_product->value();
              $price_initial = field_get_items('commerce_product', $product, 'field_or_price');
              $price_final = field_get_items('commerce_product', $product, 'commerce_price');
              $disc = (1-($price_final[0]['amount'] / $price_initial[0]['amount'])) * 100;
              $html .= number_format($disc, 0) . '%';
            }

            $html .= '</span></div><div class="wrapper"></div>';
            return $html;
          }
        }
      }
    }

    return '';
  }
}
