<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_user_profile_form_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('User profile form'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_user_profile_form_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_user_profile_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $account = reset($context)->data;

  $block = new stdClass();
  $block->content = theme('realty_profile_form');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_user_profile_form_content_type_theme(&$theme, $plugin) {
  $theme['realty_profile_form'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-profile-form',
    'variables' => array(
      'account' => NULL,
    ),
  );
}

/**
 * Process variables for realty-search-form.tpl.php.
 */
function template_preprocess_realty_profile_form(&$vars) {
  $user = $vars['user'];
  module_load_include('pages.inc', 'user');
  $vars['profile_form'] = drupal_get_form('user_profile_form', $user);
}