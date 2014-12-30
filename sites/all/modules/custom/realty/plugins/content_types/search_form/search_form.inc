<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_search_form_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Search form'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_search_form_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_search_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_search_form');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_search_form_content_type_theme(&$theme, $plugin) {
  $theme['realty_search_form'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-search-form',
  );
}

/**
 * Process variables for realty-search-form.tpl.php.
 */
function template_preprocess_realty_search_form(&$vars) {
  $vars['search_form'] = drupal_get_form('realty_search_form');
}
