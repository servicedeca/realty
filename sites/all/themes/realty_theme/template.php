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

  $main_menu = menu_navigation_links('main-menu');
  unset($vars['main_menu']);
  foreach ($main_menu as $item) {
    $vars['main_menu'][] = l($item['title'], $item['href']);
  }

  // Get user links.
  if (user_is_logged_in()) {
    $vars['login_profile'] = l(t('User profile'), "user/$user->uid");
    $vars['logout_register'] = l(t('Logout'), 'user/logout');
  }
  else {
    $vars['login_profile'] =  l(t('Login'), 'user/login');
    $vars['logout_register'] = l(t('Register'), 'user/register');
  }

  $city = realty_get_current_city();
  $vars['city'] = $city;

  foreach(realty_get_list_city() as $city) {
    $vars['cities'][] = l($city->name, 'taxonomy/term/'.$city->tid);
  }

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));
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
}

/*
 * Process variables for views-view-unformatted--complex--complex.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__complex(&$vars) {
  $a = 1;
  $image_path = $vars['view']->result[0]->field_field_pano[0]['rendered']['entity']['field_collection_item'][4]['field_image_pano']['#items'][0]['uri'];
  $image_pano =  theme('image_style', array(
      'style_name' => 'medium',
      'path' => $image_path,
      'attributes' => array(
      ),
    )
  );
  $vars['complex'] = array(
    'title' => $vars['view']->result[0]->node_title,
    'area' => $vars['view']->result[0]->field_field_area[0]['rendered']['#title'],
    'developer' => $vars['view']->result[0]->field_field_complex_developer[0]['rendered'],
    'deadline' => $vars['view']->result[0]->field_field_deadline[0]['rendered'],
    'main_photo' => $vars['view']->result[0]->field_field_main_photo[0]['rendered'],
    'body'=> $vars['view']->result[0]->field_body[0]['rendered'],
    'pano' => $vars['view']->result[0]->field_field_pano[0]['rendered']['entity']['field_collection_item'][4]['field_pano_complex']['#items'][0]['value'],
    'image_pano' => l($image_pano,'#modal-pano', array('external' => TRUE,
      'html' =>TRUE,
      'attributes'=> array(
        'data-toggle' => 'modal',
      ),
    )
  ),
  );
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
 * Process variables for views-view-unformatted--apartments--apartment-complex.tpl.php.
 */
function realty_preprocess_views_view_unformatted__apartments__apartment_complex(&$vars) {
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
function realty_preprocess_search_form(&$vars) {

  $vars['micro_logo'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/micrologo.png',
    'attributes' => array(
      'class' => array('search-head-logo'),
    ),
  ));

  foreach(realty_get_list_city() as $city) {
    $vars['cities'][] = l($city->name, 'taxonomy/term/'.$city->tid);
  }

  $city = realty_get_current_city();
  $vars['city'] = $city;

  $vars['area'] = $vars['form']['area'];
  $vars['masonry'] = $vars['form']['masonry'];
  unset($vars['masonry']['#title']);
  $vars['category'] = $vars['form']['category'];
  unset($vars['category']['#title']);
  $vars['quarter'] = $vars['form']['quarter'];
  unset($vars['quarter']['#title']);
  $vars['year'] = $vars['form']['year'];
  unset($vars['year']['#title']);
  $vars['sq'] = $vars['form']['sq'];
  unset($vars['sq']['#title']);
  $vars['price'] = $vars['form']['price'];
  unset($vars['price']['#title']);
  $vars['coast'] = $vars['form']['coast'];
  unset($vars['coast']['#title']);
  $vars['parking'] = $vars['form']['parking'];
  unset($vars['parking']['#title']);
  $vars['balcony'] = $vars['form']['balcony'];
  unset($vars['balcony']['#title']);
  $vars['submit'] = $vars['form']['submit'];

  $vars['area'] = realty_get_options_current_city('area');

}


/**
*  implement hook_theme_registry_alter().
 */
function realty_theme_registry_alter(&$theme_registry) {
  $theme_path = path_to_theme();

  // Checkboxes.
  if (isset($theme_registry['checkbox'])) {
    $theme_registry['checkbox']['type'] = 'theme';
    $theme_registry['checkbox']['theme path'] = $theme_path;
    $theme_registry['checkbox']['template'] = $theme_path. '/templates/field--type-checkbox';
    unset($theme_registry['checkbox']['function']);
  }

}

/**
 * Process variables for realty-user-menu.tpl.php.
 */
function realty_theme_preprocess_realty_user_menu(&$vars) {
  global $user;
  $uid = $user->uid;

  $vars['menu'] = array(
    'profile' => l(t('Profile'), "user/$uid"),
    'comparison' => l(t('Comparison'), "comparison"),
    'apartment' => l(t('Apartment'), "apartment_id"),
  );
}

/**
 * Process variables for field--type-checkbox.tpl.php.
 */
function realty_theme_preprocess_field__type_checkbox(&$vars) {
  $a = 1;
}