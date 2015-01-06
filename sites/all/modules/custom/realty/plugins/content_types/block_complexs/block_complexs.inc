<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_block_complexs_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Block complexs'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_block_complexs_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_block_complexs_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_block_complexs');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_block_complexs_content_type_theme(&$theme, $plugin) {
  $a = 1;
  $theme['realty_block_complexs'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-block-complexs',
  );
}

/**
 * Process variables for realty-block-complexes.tpl.php.
 */
function template_preprocess_realty_block_complexs(&$vars) {

  $city = menu_get_object('taxonomy_term', 2);

  $result = views_get_view_result('complex', 'complexs');

  foreach ($result as $key => $val) {

    $vars['complexes'][$key] = array(
      'title' => l($val->node_title, 'node/'.$val->nid),
      'image' => theme('image_style', array(
          'style_name' => 'medium',
          'path' => $val->field_field_main_photo[0]['raw']['uri'],
          'alt' => $val->node_title,
          'title' => $val->node_title,
          'attributes' => array(
          ),
        )
      ),
      'description' => $val->field_body[0]['rendered']['#markup'],
      'details' => l('Details', 'node/'.$val->nid),
    );
  }

  $vars['all_complexes'] = l('Residential complexes', 'complexes/city/'.$city->tid);
}