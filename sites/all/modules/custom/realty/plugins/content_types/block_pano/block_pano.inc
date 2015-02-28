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

  $vars['micro_logo'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/micrologo.png',
    'attributes' => array(
      'class' => array('micrologo'),
    ),
  ));
  if (!empty($result)) {
    foreach ($result as $key => $val) {
      $vars['complexes'][$key] = array (
        'title' => l($val->node_title, 'node/'.$val->nid),
        'image' => theme('image', array(
            'path' => $val->field_field_main_photo[0]['rendered']['#item']['uri'],
            'alt' => $val->node_title,
            'title' => $val->node_title,
            'attributes' => array(
              'class' => array('photo'),
            ),
          )
        ),
        'details' => l('Details', 'node/'.$val->nid . '/#3d-tour', array(
          'external' => TRUE,
          'attributes' => array('class' => array('button-info button-info-top'),))),
      );

      if(!empty($val->field_field_description)) {
        $vars['complexes'][$key]['description'] = $val->field_field_description[0]['rendered']['#markup'];
      }

      if (isset($val->field_field_complex_logo[0])) {
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
  }

}