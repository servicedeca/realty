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

    $vars['complexes'][$key] = array (
      'title' => l($val->node_title, 'node/'.$val->nid),
      'description' => $val->field_field_description[0]['raw']['value'],
      'image' => theme('image', array(
          'path' => $val->field_field_main_photo[0]['rendered']['#item']['uri'],
          'alt' => $val->node_title,
          'title' => $val->node_title,
          'attributes' => array(
            'class' => array('photo'),
          ),
        )
      ),
      'details' => l('Details', 'node/'.$val->nid, array(
        'attributes' => array('class' => array('button-info button-info-top'),))),
    );

    if ($val->field_field_complex_logo[0]['raw']['uri']) {
      $vars['complexes'][$key]['logo'] = theme('image', array(
          'path' => $val->field_field_complex_logo[0]['raw']['uri'],
          'alt' => $val->node_title,
          'title' => $val->node_title,
          'attributes' => array(
            'class' => array('logo-z'),
          ),
        )
      );
    }
  }

  $vars['all_complexes'] = 'complexes/city/' . $city->tid;

  $vars['micro_logo'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/micrologo.png',
    'attributes' => array(
      'class' => array('micrologo'),
    ),
  ));

  $vars['image_complexes'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/c-image.jpg',
    'alt' => t('Residential complexes'),
    'title' => t('Residential complexes'),
    'attributes' => array(
      'class' => array('title-image'),
    ),
  ));

}