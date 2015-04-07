<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_user_profile_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('User profile'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_user_profile_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_user_profile_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content = theme('realty_user_profile');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_user_profile_content_type_theme(&$theme, $plugin) {
  $theme['realty_user_profile'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-user-profile',
  );
}

/**
 * Process variables for realty-block-stock.tpl.php.
 */
function template_preprocess_realty_user_profile(&$vars) {
  global $user;

  drupal_add_js('/' . REALTY_FRONT_THEME_PATH . '/js/realty_edit_user_profile.js');

  $account = user_load($user->uid);
  $vars['image'] = theme('image', array(
    'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/profile.png'
    )
  );
  $vars['image_close'] = realty_get_image_close();

  $vars['image_mail'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/mail.svg',
    )
  );
  $vars['image_phone'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/c-phone.svg',
    )
  );
  $vars['image_man'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/c-man.svg',
    )
  );

  $vars['name'] = $account->field_user_name['und'][0]['safe_value'];
  $vars['mail'] = $account->mail;

  if (empty($account->field_phone_number)) {
    $vars['number'] = t('00000000');
  }
  else {
    $vars['number'] = $account->field_phone_number['und'][0]['safe_value'];
  }

}