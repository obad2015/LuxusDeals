Commerce Sales Reports
=====================

This module provides reports on products and sales for Drupal Commerce

It currently does these things:

1. Provides a UI at admin/commerce/config/sales that lets you determine which
   product types should have sales reporting. If you turn on sales reporting
   a sales field is added to the product type.
2. A default rule is provided that increments the sales value when the order
   is completed. If you want to alter it at a different time, you can 
   change the rule or provide your own.

To configure:
-------------

1. Install and enable the module.
2. Enable sales reporting on the products types you want it on by visiting
   admin/commerce/config/sales.
3. Set the starting value of sales on each product, using the product edit form,
   commerce_feeds, commerce_migrate, VBO, or whatever works ussually to 0.

If you would like a rule other than the default rule for updating stock levels,
you can edit or replace the default rule.
