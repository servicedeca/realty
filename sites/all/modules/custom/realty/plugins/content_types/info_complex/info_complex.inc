<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_info_complex_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Info complex '),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_info_complex_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_info_complex_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_info_complex');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_info_complex_content_type_theme(&$theme, $plugin) {
  $theme['realty_info_complex'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-info-complex',
  );
}

/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_info_complex(&$vars) {

  $node = menu_get_object('node', 1);
  $photos = field_get_items('node', $node, 'field_photos_complex');
  if (!empty($photos)) {
    foreach ($photos as $key => $photo) {
      $vars['photos'][$key] = theme('image', array(
        'path' => $photo['uri'],
        'alt' => $photo['alt'],
        'title' => $photo['title'],
      ));
    }
  }
  $developer =  field_get_items('node', $node, 'field_complex_developer');
  $vars['developer'] = $developer[0]['taxonomy_term']->name;
  $deadline =  field_view_field('node', $node, 'field_deadline');
  $dead_entity = $deadline['#object']->field_deadline['und'][0]['value'];
  $vars['complex_name'] = $node->title;
  $vars['quarter'] = $deadline[0]['entity']['field_collection_item'][$dead_entity]['field_quarter']['#items'][0]['value'];
  $vars['year'] = $deadline[0]['entity']['field_collection_item'][$dead_entity]['field_year']['#items'][0]['value'];
  $description =  field_view_field('node', $node, 'field_description');
  $desc_entity = $description['#object']->field_description['und'][0]['value'];
  if (isset($description[0]['entity']['field_collection_item'][$desc_entity]['field_location'])) {
    $vars['mini_description'] = $description[0]['entity']['field_collection_item'][$desc_entity]['field_location'][0]['#markup'];
    $vars['location_description'] = $description[0]['entity']['field_collection_item'][$desc_entity]['field_location']['#items'][0]['value'];
  }
  if (isset($description[0]['entity']['field_collection_item'][$desc_entity]['field_architecture'])) {
    $vars['architecture_description'] = $description[0]['entity']['field_collection_item'][$desc_entity]['field_architecture'][0]['#markup'];
  }
  if (isset($description[0]['entity']['field_collection_item'][$desc_entity]['field_accomplishment'])) {
    $vars['accomplishment_description'] = $description[0]['entity']['field_collection_item'][$desc_entity]['field_accomplishment'][0]['#markup'];
  }
  if (isset($description[0]['entity']['field_collection_item'][$desc_entity]['field_infrastructure'])) {
    $vars['infrastructure_description'] = $description[0]['entity']['field_collection_item'][$desc_entity]['field_infrastructure'][0]['#markup'];
  }
  if (isset($description[0]['entity']['field_collection_item'][$desc_entity]['field_service'])) {
    $vars['service_description'] = $description[0]['entity']['field_collection_item'][$desc_entity]['field_service'][0]['#markup'];
  }
  $address =  field_get_items('node', $node, 'field_address');
  $vars['address'] = $address[0]['value'];

  $vars['findome_logo'] = theme('image',array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/findome-gray.svg',
    'attributes' => array(
      'class' => array('margin-left-15')
    ),));

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));

  $vars['map'] = views_embed_view('map', 'map_complex');

}
