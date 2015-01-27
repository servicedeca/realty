<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_block_developers_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Block developers'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_block_developers_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_block_developers_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_block_developers');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_block_developers_content_type_theme(&$theme, $plugin) {
  $theme['realty_block_developers'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-block-developers',
  );
}

/**
 * Process variables for realty-block-complexes.tpl.php.
 */
function template_preprocess_realty_block_developers(&$vars) {

  $city = menu_get_object('taxonomy_term', 2);

  $result = views_get_view_result('term_view', 'developers');

  foreach($result as $key => $val) {
    $vars['developers'][$key] = array(
      'logo' => theme('image', array(
        'path' => $val->field_field_developer_logo[0]['raw']['uri'],
        'title' => $val->_field_data['tid']['entity']->name,
        'alt' => $val->_field_data['tid']['entity']->name,
      )),
      'path' => 'taxonomy/term/' . $val->tid,
    );
  }

  $vars['all_developers'] = 'developers/city/' . $city->tid;

  $vars['micro_logo'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/micrologo.png',
    'attributes' => array(
      'class' => array('micrologo'),
    ),
  ));
}