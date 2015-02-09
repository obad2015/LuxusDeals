<?php
/**
 * @file
 * opendeals_contact.features.content.inc
 */

/**
 * Implements hook_content_defaults().
 */
function opendeals_contact_content_defaults() {
$content = array();
$content['contact'] = (object)array(
  'exported_path' => 'contact',
  'link' => array(
    'menu_name' => 'main-menu',
    'link_path' => 'node-name/contact',
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
    'identifier' => 'main-menu:node-name/contact',
  ),
  'webform' => array(
    'confirmation' => '',
    'confirmation_format' => 'filtered_html',
    'redirect_url' => 'node/13',
    'status' => '1',
    'block' => '0',
    'teaser' => '0',
    'allow_draft' => '0',
    'auto_save' => '0',
    'submit_notice' => '0',
    'submit_text' => 'Send',
    'submit_limit' => '10',
    'submit_interval' => '3600',
    'record_exists' => TRUE,
    'roles' => array(
      0 => '1',
      1 => '2',
    ),
    'emails' => array(
      1 => array(
        'nid' => '23',
        'eid' => '1',
        'email' => variable_get('site_mail'),
        'subject' => 'default',
        'from_name' => '1',
        'from_address' => '2',
        'template' => 'default',
        'excluded_components' => array(),
        'html' => '0',
        'attachments' => '0',
      ),
    ),
    'components' => array(
      0 => array(
        'pid' => '0',
        'form_key' => 'full_name',
        'name' => 'Full Name',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'title_display' => 'before',
          'private' => 0,
          'disabled' => 0,
          'unique' => 0,
          'conditional_operator' => '=',
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'description' => '',
          'attributes' => array(),
          'conditional_component' => '',
          'conditional_values' => '',
        ),
        'mandatory' => '1',
        'weight' => '0',
        'page_num' => 1,
      ),
      1 => array(
        'pid' => '0',
        'form_key' => 'e_mail',
        'name' => 'E-Mail',
        'type' => 'email',
        'value' => '',
        'extra' => array(
          'title_display' => 'before',
          'private' => 0,
          'disabled' => 0,
          'unique' => 0,
          'conditional_operator' => '=',
          'width' => '',
          'description' => '',
          'attributes' => array(),
          'conditional_component' => '',
          'conditional_values' => '',
        ),
        'mandatory' => '1',
        'weight' => '1',
        'page_num' => 1,
      ),
      2 => array(
        'pid' => '0',
        'form_key' => 'message',
        'name' => 'Message',
        'type' => 'textarea',
        'value' => '',
        'extra' => array(
          'title_display' => 0,
          'private' => 0,
          'resizable' => 0,
          'disabled' => 0,
          'conditional_operator' => '=',
          'cols' => '',
          'rows' => '',
          'description' => '',
          'attributes' => array(),
          'conditional_component' => '',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'weight' => '2',
        'page_num' => 1,
      ),
    ),
  ),
  'title' => 'Contact',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'webform',
  'language' => 'und',
  'created' => '1318675275',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'contact',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<h2>Contact us</h2><p>You may contact us via the following form:</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<h2>Contact us</h2>
<p>You may contact us via the following form:</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
return $content;
}
