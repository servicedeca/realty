<?php
/**
 * @file
 * Ctools content type
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_apartment_complex_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Apartment complex'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_apartment_complex_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_apartment_complex_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_apartment_complex');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_apartment_complex_content_type_theme(&$theme, $plugin) {
  $theme['realty_apartment_complex'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-apartment-complex',
  );
}

/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_apartment_complex(&$vars) {
  $nid = arg(1);
  $node = node_load($nid);
  if ($node->type == 'apartament') {
    $complex_id = $node->field_apartament_home['und'][0]['taxonomy_term']->field_home_complex['und'][0]['target_id'];
    $vars['view'] = '<div class="container fin zero-padding"><div class="col-xs-12 zero-padding">' .
      views_embed_view('apartments', 'apartment_complex', $complex_id) .
      '</div></div>';
  }
  else {
    $vars['view'] = views_embed_view('apartments', 'apartment_complex');
  }
}
