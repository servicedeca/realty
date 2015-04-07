<?php
/**
 * @file
 * Ctools content type
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_get_id_apartment_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Get id apartment'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_get_id_apartment_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_get_id_apartment_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_get_id_apartment');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_get_id_apartment_content_type_theme(&$theme, $plugin) {
  $theme['realty_get_id_apartment'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-get-id-apartment',
  );
}

/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_get_id_apartment(&$vars) {
  global $user;

  $apartments = views_get_view_result('apartments', 'apartments_user_apartmens', $user->uid);
}
