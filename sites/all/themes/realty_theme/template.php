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
    'attributes' => array('class' => 'logo',)
  ));

  // Get user links.
  if (user_is_logged_in()) {
    $vars['login_profile'] = l(t('User profile'), "user/$user->uid");
    $vars['logout_register'] = l(t('Logout'), 'user/logout');
  }
  else {
    $vars['login_profile'] =  l(t('Login'), 'user/login');
    $vars['logout_register'] = l(t('Register'), 'user/register');
  }
  $term = menu_get_object('taxonomy_term',2);
  $vars['city'] = $term->name;
  foreach(realty_get_list_city() as $city) {
    $vars['cities'][] = l($city->name, 'taxonomy/term/'.$city->tid);
  }
}

/**
 * Preprocess variables for node.
 */
function realty_preprocess_node(&$vars, $hook) {
  $node = $vars['node'];
  $view_mode = $vars['view_mode'];

  $vars['theme_hook_suggestions'][] = 'node__' . $view_mode;
  $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '_' . str_replace('-', '_', $view_mode);

  $preprocesses[] = 'realty_preprocess_node__' . $view_mode;
  $preprocesses[] = 'realty_preprocess_node__' . $node->type;
  $preprocesses[] = 'realty_preprocess_node__' . $node->type . '_' . str_replace('-', '_', $view_mode);

  foreach ($preprocesses as $preprocess) {
    if (function_exists($preprocess)) {
      $preprocess($vars, $hook);
    }
  }
}

/**
 * Process variables for views-exposed-form.tpl.php.
 */
function realty_preprocess_views_exposed_form(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view.tpl.php.
 */
function realty_preprocess_views_view(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-unformatted.tpl.php.
 */
function realty_preprocess_views_view_unformatted(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-fields.tpl.php.
 */
function realty_preprocess_views_view_fields(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-grid.tpl.php.
 */
function realty_preprocess_views_view_grid(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-table.tpl.php.
 */
function realty_preprocess_views_view_table(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/*
 * Process variables for views-view-unformatted--complex--complexs.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__complexs(&$vars) {
  $a = 1;
 /* foreach($vars['view']->result as $value){
    $image = theme('image', array(
        'path' => $value->field_field_main_photo[0]['raw']['uri'],
        'width' => '100px',
        'height' => '100px',
      )
    );
    $vars['complex'][] = array(
      'name' =>  l($value->taxonomy_term_data_name, 'taxonomy/term/'.$value->tid, array('html' => TRUE,)),
      'developer' => $value->field_field_developer[0]['rendered'],
      'photo' => l($image, 'taxonomy/term/'.$value->tid, array('html' => TRUE,)),
      'area' => $value->field_field_complex_area[0]['rendered'],
      'deadline' => $value->field_field_deadline[0]['raw']['value'],
    );
  }*/
}

/*
 * Process variables for views-view-unformatted--term-view--complexes.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__developers(&$vars) {
  foreach($vars['view']->result as $value){
    $logo = theme('image', array(
        'path' => $value->field_field_developer_logo[0]['raw']['uri'],
        'width' => '100px',
        'height' => '100px',
      )
    );
    $vars['developers'][] = array(
      'logo' => l($logo, 'taxonomy/term/'.$value->tid, array('html' => TRUE,)),
    );
  }
}

/*
 * Process variables for views-view-table--apartments--developer-apartment.tpl.php.
 */
function realty_preprocess_views_view_table__apartments__developer_apartment(&$vars){
  $a = 1;
}

/**
 * Process variables for views-view-unformatted--term-view--complex.tpl.php
 */
function realty_preprocess_views_view_unformatted__term_view__complex(&$vars){
  $a = 1;
}

/**
 * Process variables for views-view-table--apartments--apartment-complex.tpl.php.
 */
function realty_preprocess_views_view_table__apartments__apartment_complex(&$vars){
  $a = 1;
}

/**
 * Process variables for views-view-unformatted--apartments--apartment.tpl.php.
 */
function realty_preprocess_views_view_unformatted__apartments__apartment(&$vars){
  $a = 1;
}

/**
 * Process variables for views-view--apartments--result-search.tpl.php.
 */
function realty_preprocess_views_view_table__apartments__result_search(&$vars){
  $a = 1;
}

/**
 * Process variables for search-form.tpl.php
 */
function realty_preprocess_search_form(&$vars){
  $vars['area'] = $vars['form']['area'];
  $vars['submit'] = $vars['form']['submit'];
}

/**
 * Process variables for realty-user-menu.tpl.php.
 */
function realty_theme_preprocess_realty_user_menu(&$vars) {
  $account = $vars['account'];
  $uid = $account->uid;

  $vars['menu'] = array(
    'profile' => l(t('Profile'), "user/$uid"),
    'payment_info' => l(t('Payment information'), "user/$uid/payment"),
    'comparison' => l(t('Comparison'), ""),
    'apartment' => l(t('Apartment'), ""),
  );
}