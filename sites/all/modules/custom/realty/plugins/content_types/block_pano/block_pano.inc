<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_block_pano_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Block Pano'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_block_pano_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_block_pano_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_block_pano');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_block_pano_content_type_theme(&$theme, $plugin) {
  $a = 1;
  $theme['realty_block_pano'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-block-pano',
  );
}

/**
 * Process variables for realty-block-pano.tpl.php.
 */
function template_preprocess_realty_block_pano(&$vars) {

  $city = menu_get_object('taxonomy_term', 2);

  $result = views_get_view_result('complex', 'complexs');

  foreach ($result as $key => $val) {
    $image_pano_path = $val->field_field_pano[0]['rendered']['entity']['field_collection_item'][4]['field_image_pano']['#items'][0]['uri'];
    $image = theme('image_style', array(
        'style_name' => 'medium',
        'path' => $image_pano_path,
        'alt' => $val->node_title,
        'title' => $val->node_title,
        'attributes' => array(
        ),
      )
    );
    $vars['complexes'][$key] = array(
      'title' => $val->node_title,
      'image' => l($image, 'node/'.$val->nid, array('html' => TRUE,)),
    );
  }

}