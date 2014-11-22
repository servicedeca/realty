<?php

/**
 * Process variables for page.tpl.php.
 */
function realty_theme_preprocess_page(&$vars) {
  global $user;

  // Get site logo.
  $logo = theme('image', array(
    'path' => theme_get_setting('logo_path'),
    'alt' => t(variable_get('site_name')),
    'title' => t(variable_get('site_name')),
  ));
  $vars['logo'] = l($logo, '', array('query' => $_GET,
    'html' => TRUE,
    'attributes' => array('class' => 'logo',)));

  // Get footer menu.
 /* $footer_menu = menu_navigation_links('menu-footer-menu');
  foreach ($footer_menu as $item) {
    $vars['footer_menu'][] = l($item['title'], $item['href']);
  }*/

  // Get user links.
  if (user_is_logged_in()) {
    $vars['login_profile'] = l(t('User profile'), "user/$user->uid");
    $vars['logout_register'] = l(t('Logout'), 'user/logout');
  }
  else {
    $vars['login_profile'] =  l(t('Login'), 'user/login');
    $vars['logout_register'] = l(t('Register'), 'user/register');
  }
}