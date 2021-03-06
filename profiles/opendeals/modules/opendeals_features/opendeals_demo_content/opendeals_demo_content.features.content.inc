<?php
/**
 * @file
 * opendeals_demo_content.features.content.inc
 */

/**
 * Implements hook_content_defaults().
 */
function opendeals_demo_content_content_defaults() {
$content = array();
$content['faq'] = (object)array(
  'exported_path' => 'faq',
  'link' => array(
    'menu_name' => 'main-menu',
    'link_path' => 'node-name/faq',
    'router_path' => 'node/%',
    'link_title' => 'FAQ',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
    'identifier' => 'main-menu:node-name/faq',
  ),
  'title' => 'FAQ',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1318431321',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'faq',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<h3>About Open Deals</h3><p>Open Deals is a Free Deals Site distribution, based on Drupal 7, Drupal Commerce and other modules. You can use the distribution for you or your clients and you can modify it at will. Netstudio, a <a href="http://www.netstudio.gr/en" target="_blank">drupal development services</a> agency in Greece is behind the distribution and you can ask for paid support if you need help installing, setting up, hosting or modifying your site. We hope that the distribution will be beneficial and useful for you. We\'ll be glad to listen to your comments and feedback.</p><h3>Installation and setup instructions</h3><p>1. Install as you would install Drupal.</p><p>2. Do any modification you see fit to make your site work as expected. Most probably, you will want to:<br>a) Change the logo and / or the colors of your site. We propose that you do a subtheme and not alter the main theme.<br>b) Add and setup your payment methods and checkout process.<br>c) Change the texts of the site to make it unique.<br>d) Update the links to Facebook, Twitter etc. to yours.<br>e) Insert your own Google Analytics ID and setup your Google Analytics account to accept e-commerce data.</p><h3>How to Create new deals</h3><p>We have prepared the "Deals management" view that will show all deals and has links to the steps you need to take in order to create a new one. Is is the first (left) menu item on the admin menu. The link is <a href="deals-management">/deals-management</a>.</p><h3>Limitations</h3><p>Currently, the installation profile works only with MySQL databases. In order to make it work with other databases, you will have to import the db.sql file manually.</p><h3>Customizations</h3><p>The Open Deals distribution is open source and free to use.</p><p>You may customize it at will for you or your clients without paying any license fees.</p><h3>Feedback and bug reports</h3><p>If something is not working as expected, you can contact netstudio at <a href="http://www.netstudio.gr/en/contact" target="_blank">www.netstudio.gr/en/contact</a> or open an issue at the project\'s issue queue: <a href="http://drupal.org/project/opendeals" target="_blank">http://drupal.org/project/opendeals</a>.</p><h3>Professional Support</h3><p>If you need additional features, customization, drupal optimized hosting, <a href="http://www.userfeel.com" target="_blank">usability testing</a> or full site integration, you can get professional support by netstudio, at <a href="http://www.netstudio.gr/en/contact" target="_blank">www.netstudio.gr/en/contact</a>, by phone at +30 210 8004447 or by Skype at yannis75.</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<h3>About Open Deals</h3>
<p>Open Deals is a Free Deals Site distribution, based on Drupal 7, Drupal Commerce and other modules. You can use the distribution for you or your clients and you can modify it at will. Netstudio, a <a href="http://www.netstudio.gr/en" target="_blank">drupal development services</a> agency in Greece is behind the distribution and you can ask for paid support if you need help installing, setting up, hosting or modifying your site. We hope that the distribution will be beneficial and useful for you. We\'ll be glad to listen to your comments and feedback.</p>
<h3>Installation and setup instructions</h3>
<p>1. Install as you would install Drupal.</p>
<p>2. Do any modification you see fit to make your site work as expected. Most probably, you will want to:<br />a) Change the logo and / or the colors of your site. We propose that you do a subtheme and not alter the main theme.<br />b) Add and setup your payment methods and checkout process.<br />c) Change the texts of the site to make it unique.<br />d) Update the links to Facebook, Twitter etc. to yours.<br />e) Insert your own Google Analytics ID and setup your Google Analytics account to accept e-commerce data.</p>
<h3>How to Create new deals</h3>
<p>We have prepared the "Deals management" view that will show all deals and has links to the steps you need to take in order to create a new one. Is is the first (left) menu item on the admin menu. The link is <a href="http://localhost:8888/opendeals/deals-management">/deals-management</a>.</p>
<h3>Limitations</h3>
<p>Currently, the installation profile works only with MySQL databases. In order to make it work with other databases, you will have to import the db.sql file manually.</p>
<h3>Customizations</h3>
<p>The Open Deals distribution is open source and free to use.</p>
<p>You may customize it at will for you or your clients without paying any license fees.</p>
<h3>Feedback and bug reports</h3>
<p>If something is not working as expected, you can contact netstudio at <a href="http://www.netstudio.gr/en/contact" target="_blank">www.netstudio.gr/en/contact</a> or open an issue at the project\'s issue queue: <a href="http://drupal.org/project/opendeals" target="_blank">http://drupal.org/project/opendeals</a>.</p>
<h3>Professional Support</h3>
<p>If you need additional features, customization, drupal optimized hosting, <a href="http://www.userfeel.com" target="_blank">usability testing</a> or full site integration, you can get professional support by netstudio, at <a href="http://www.netstudio.gr/en/contact" target="_blank">www.netstudio.gr/en/contact</a>, by phone at +30 210 8004447 or by Skype at yannis75.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_img' => array(
    'und' => array(
      0 => array(
        'alt' => '',
        'title' => '',
        'width' => '265',
        'height' => '74',
        'filename' => 'logo_3.png',
        'uri' => 'public://logo_3.png',
        'filemime' => 'image/png',
        'filesize' => '2000',
        'status' => '1',
        'rdf_mapping' => array(),
        'image' => '�PNG

' . "\0" . '' . "\0" . '' . "\0" . 'IHDR' . "\0" . '' . "\0" . '	' . "\0" . '' . "\0" . '' . "\0" . 'J' . "\0" . '' . "\0" . '' . "\0" . '�Q ' . "\0" . '' . "\0" . '' . "\0" . 'tEXtSoftware' . "\0" . 'Adobe ImageReadyq�e<' . "\0" . '' . "\0" . 'hiTXtXML:com.adobe.xmp' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '<?xpacket begin="﻿" id="W5M0MpCehiHzreSzNTczkc9d"?> <x:xmpmeta xmlns:x="adobe:ns:meta/" x:xmptk="Adobe XMP Core 5.0-c061 64.140949, 2010/12/07-10:57:01        "> <rdf:RDF xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"> <rdf:Description rdf:about="" xmlns:xmpMM="http://ns.adobe.com/xap/1.0/mm/" xmlns:stRef="http://ns.adobe.com/xap/1.0/sType/ResourceRef#" xmlns:xmp="http://ns.adobe.com/xap/1.0/" xmpMM:OriginalDocumentID="xmp.did:F77F1174072068118C14E675C3E93DFC" xmpMM:DocumentID="xmp.did:C3BC22A1EF4011E0B757DA6A8F621A76" xmpMM:InstanceID="xmp.iid:C3BC22A0EF4011E0B757DA6A8F621A76" xmp:CreatorTool="Adobe Photoshop CS5.1 Macintosh"> <xmpMM:DerivedFrom stRef:instanceID="xmp.iid:018011740720681188C6826150A64974" stRef:documentID="xmp.did:F77F1174072068118C14E675C3E93DFC"/> </rdf:Description> </rdf:RDF> </x:xmpmeta> <?xpacket end="r"?>P� *' . "\0" . '' . "\0" . '' . "\0" . '0PLTE���������BBBjjj�����֮����任�OOO]]]xxx������444�o��' . "\0" . '' . "\0" . '�IDATx��۶� ��D����h�(�S[��f���)��HB���ր	"A$�� D�H	"A$�� D�H	"A$�� D�H���x��I��2�v0\\����hf�ߕ�0���p݂�f�$$����zy?��R����Y.\'!�e���������_�Q\\MB�@,�.l]q�㗁8nE��	��$�f1w"�D��m�uq2v����]r�wc�z��r`�j/��n�*�\\7�K�i��k�z��՞]f�cF��#�1v N"�mj�=S�Z��GHn��lf1V�eA����6{���J���$<�ئ-�ĩ�H6"0��h(gl�zM�,��.���D�
N���М��' . "\0" . 'c��R&&��\\�$!s����
	���-	ٺ�ܕ�\'�9�-X�7ū����?}�ڂG�\\�F��
�H��#��D%O
�ǆ�ݽIS[&�6-�I��9��g$�����e' . "\0" . '�g��O����0f���^Hl���(:���NS#���O�z�@"�c�j�e�����?�!��t�E�x4���$�9о+Eo����I��j8	�D"���`\'���ꨅ�蒘Ǵa�?����1=N¢{B&�4�j�#E �H���������6S���' . "\0" . 've8F�󔩡j&�!�ه�����e���E�f��� ��U�y��HΝ�D":��>�뷃E��u:-��ʓ�j��Du�"��t�Yq_U�L!qd�F)a��}��\\�bsWm�N�2�dv�f�IJ�N=�m��=�w���.�{�D٘��jM��S��o�i$��Ԁ��]��3o���DM�W�����M$Yi���Wq;k��\'Bz|����+�ڜ
F&��U�w�$^\'����Q��rb�i3�>�m%%6��<&�wT�}۫-=���F������S����iO+ެ	"A$�� D�w$��F$�� D�H	"A$�� W�?' . "\0" . '��^<$�@�' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . 'IEND�B`�',
      ),
    ),
  ),
);
$content['how-it-works'] = (object)array(
  'exported_path' => 'how-it-works',
  'link' => array(
    'menu_name' => 'main-menu',
    'link_path' => 'node-name/how-it-works',
    'router_path' => 'node/%',
    'link_title' => 'How it works',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'identifier' => 'main-menu:node-name/how-it-works',
  ),
  'title' => 'How It Works',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1318260188',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'how-it-works',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<h2>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</h2><p>Curabitur eu lacus vitae odio interdum ultricies. Ut nisi lectus, condimentum eget congue vel, gravida fermentum nisl. Maecenas non justo massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Nulla ornare, augue quis faucibus consectetur, sapien orci pharetra nisl, in aliquam nisi lacus ac est. Etiam in diam et tellus feugiat dignissim. Proin et mi vel nisl blandit ullamcorper at sed tellus. In eu tellus nec risus laoreet ultrices. In eu est vitae lorem consectetur eleifend. Nunc eu risus id velit rutrum auctor ut quis est. Sed tempus pellentesque lectus sit amet vehicula. Praesent consequat blandit sodales. Aenean sit amet sem non dui commodo volutpat. Vivamus sed mi quis leo facilisis scelerisque eget quis lectus. Quisque eu sollicitudin libero.</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<h2>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</h2>
<p>Curabitur eu lacus vitae odio interdum ultricies. Ut nisi lectus, condimentum eget congue vel, gravida fermentum nisl. Maecenas non justo massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Nulla ornare, augue quis faucibus consectetur, sapien orci pharetra nisl, in aliquam nisi lacus ac est. Etiam in diam et tellus feugiat dignissim. Proin et mi vel nisl blandit ullamcorper at sed tellus. In eu tellus nec risus laoreet ultrices. In eu est vitae lorem consectetur eleifend. Nunc eu risus id velit rutrum auctor ut quis est. Sed tempus pellentesque lectus sit amet vehicula. Praesent consequat blandit sodales. Aenean sit amet sem non dui commodo volutpat. Vivamus sed mi quis leo facilisis scelerisque eget quis lectus. Quisque eu sollicitudin libero.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$content['thank-you'] = (object)array(
  'exported_path' => 'thank-you',
  'title' => 'Thank you',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1318675447',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'thank-you',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Thank you for contacting us. We will respond as soon as possible.</p><p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>Thank you for contacting us. We will respond as soon as possible.</p>
<p> </p>
<p> </p>
<p> </p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
return $content;
}
