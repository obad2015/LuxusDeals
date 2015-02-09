<?php

/**
 * @file
 * Default rule configurations for Commerce Sales Reports.
 */
function commerce_sales_default_rules_configuration() {
  $rules_increment_sales_completing_order = '{ "rules_increment_sales_completing_order" : {
      "LABEL" : "Increment sales when completing the order process",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "commerce_sales", "commerce_checkout" ],
      "ON" : [ "commerce_checkout_complete" ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "commerce_order:commerce-line-items" ] },
            "DO" : [
              { "commerce_sales_increase_by_line_item" : { "commerce_line_item" : [ "list-item" ] } }
            ]
          }
        }
      ]
    }
  }';
  $configs['rules_increment_sales_completing_order'] = rules_import($rules_increment_sales_completing_order);

  return $configs;
}
