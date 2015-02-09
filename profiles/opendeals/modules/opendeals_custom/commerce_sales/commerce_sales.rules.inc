<?php

/**
 * @file
 * Rules integration for Commerce Sales Reports.
 */

/**
 * Implements hook_rules_action_info().
 *
 * Provides an action to adjust sales level of a certain product
 * by a certain quantity.
 */
function commerce_sales_rules_action_info() {
  $actions = array();
/*
  $actions['commerce_sales_adjust'] = array(
    'label' => t('Adjust the product sales level by a set amount'),
    'group' => t('Commerce Sales Reports'),
    'parameter' => array(
      'commerce_product' => array(
        'type' => 'commerce_product',
        'label' => t('Product'),
        'save' => TRUE //save the changes after executing the rule
      ),
      'amount' => array(
        'type' => 'integer',
        'label' => t('Amount')
      ),
    ),
  );

  $actions['commerce_sales_adjust_by_order'] = array(
    'label' => t('Adjust the product sales level, given an order'),
    'group' => t('Commerce Sales Reports'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Order')
      ),
    ),
  );
*/
  $actions['commerce_sales_decrease_by_line_item'] = array(
    'label' => t('Decrease the product sales level, given a line item'),
    'group' => t('Commerce Sales Reports'),
    'parameter' => array(
      'commerce_line_item' => array(
        'type' => 'commerce_line_item',
        'label' => t('Line item')
      ),
    ),
  );

  $actions['commerce_sales_increase_by_line_item'] = array(
    'label' => t('Increase the product sales level, given a line item'),
    'group' => t('Commerce Sales Reports'),
    'parameter' => array(
      'commerce_line_item' => array(
        'type' => 'commerce_line_item',
        'label' => t('Line item')
      ),
    ),
  );

  return $actions;
}

/**
 * TODO finish
function commerce_sales_adjust_by_order($order) {
watchdog('commerce_sales',var_export($order,true));
 */
//loop order line items

//commerce_order
//each (product) line item, adjust sales

//}

/**
 * If the line item is sales-enabled, subtract the sold amount in a line item
 * from sales. Used when an order is invalidated
 *
 * @param $line_item
 *   A line item object.
 */
function commerce_sales_decrease_by_line_item($line_item) {
  if ($line_item->type == 'product') {
    // The product SKU that will have its sales level adjusted.
    $sku = $line_item->line_item_label;
    $product = commerce_product_load_by_sku($sku);
    if (commerce_sales_product_type_enabled($product->type)) {
      $qty = (int) $line_item->quantity;
      // Subtract the sold amount from the available sales level.
      commerce_sales_adjust($product, -$qty);
    }
  }
}

/**
 * If the line item is sales-enabled, add the sold amount in a line item
 * to sales.
 *
 * @param $line_item
 *   A line item object.
 */
function commerce_sales_increase_by_line_item($line_item) {
  if ($line_item->type == 'product') {
    // The product SKU that will have its sales level adjusted.
    $sku = $line_item->line_item_label;
    $product = commerce_product_load_by_sku($sku);
    if (commerce_sales_product_type_enabled($product->type)) {
      $qty = (int) $line_item->quantity;
      commerce_sales_adjust($product, $qty);
    }
  }
}

/**
 * Adjusts a particular product SKU by a certain value.
 * A positive integer will add to sales, a negative integer will remove from
 * sales. 
 *
 * @param $product
 *   The product for which to change the sales level.
 * @param $qty
 *   The quantity to add to the sales level.
 */
function commerce_sales_adjust($product, $qty) {
  if (!commerce_sales_product_type_enabled($product->type)) {
    return;
  }
  $product->commerce_sales['und'][0]['value'] += intval($qty);
  $result = commerce_product_save($product);
  if ($result) {
    watchdog('commerce_sales', 'Modified sales level of product %sku by %amount', array('%sku' => $product->sku, '%amount' => $qty));
  } else {
    watchdog('commerce_sales', 'Failed attempt to modify sales level of product %sku by %amount', array('%sku' => $product->sku, '%amount' => $qty), WATCHDOG_ERROR);
  }
}

/**
 * Implements hook_rules_condition_info().
 */
function commerce_sales_rules_condition_info() {
  $conditions = array();

  $conditions['commerce_sales_order_has_any_sales'] = array(
    'label' => t('Order has products that have never been sold before'),
    'parameter' => array(
      'order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
      ),
    ),
    'group' => t('Commerce Sales Reports'),
    'callbacks' => array(
      'execute' => 'commerce_sales_rules_order_has_any_sales',
    ),
  );
  $conditions['commerce_sales_sales_enabled_on_line_item'] = array(
    'label' => t('Line item has a product of product type that has sales reporting enabled'),
    'parameter' => array(
      'type' => 'commerce_line_item',
      'label' => t('Product'),
    ),
    'group' => t('Commerce Sales Reports'),
    'callbacks' => array(
      'execute' => 'commerce_sales_line_item_product_enabled',
    ),
  );

  return $conditions;
}

/**
 * Rules condition: checks to see if the given order is in a cart status.
 */
function commerce_sales_rules_order_has_any_sales($order) {
  return commerce_sales_order_has_any_sales($order);
}
