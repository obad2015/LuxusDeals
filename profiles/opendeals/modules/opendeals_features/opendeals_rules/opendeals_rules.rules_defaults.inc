<?php
/**
 * @file
 * opendeals_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function opendeals_rules_default_rules_configuration() {
  $items = array();
  $items['rules_add_to_cart'] = entity_import('rules_config', '{ "rules_add_to_cart" : {
      "LABEL" : "Add to cart",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "commerce_cart" ],
      "ON" : [ "commerce_cart_product_add" ],
      "DO" : [ { "redirect" : { "url" : "checkout" } } ]
    }
  }');
  $items['rules_empty_cart_from_previously_added_products'] = entity_import('rules_config', '{ "rules_empty_cart_from_previously_added_products" : {
      "LABEL" : "Empty Cart from Previously Added Products",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "commerce_cart" ],
      "ON" : [ "commerce_cart_product_prepare" ],
      "DO" : [
        { "commerce_cart_empty" : { "commerce_order" : [ "commerce_order" ] } }
      ]
    }
  }');
  return $items;
}
