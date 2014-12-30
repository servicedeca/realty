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
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_user_profile_form_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $account = user_load($user->uid);
  $block = new stdClass();

  module_load_include('pages.inc', 'user');
  $block->content = drupal_get_form('user_profile_form', $account);

  return $block;
}
