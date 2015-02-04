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

  $vars['logo'] = l($logo, '', array(
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

  $vars['footer_logo'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/black-logo.svg',
    'attributes' => array(
      'class' => array('footer-logo'),
    ),
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
 * Process variables for views-view-unformatted--apartments--result-search.tpl.php.
 */
function realty_preprocess_views_view_unformatted__apartments__result_search(&$vars) {

  if (!empty($vars['view']->result)) {

    foreach ($vars['view']->result as $key => $val) {
      $vars['apartments'][$key] = array(
        'number' => l($val->field_field_number_apartament[0]['raw']['value'], 'node/' . $val->nid),
        'area' => $val->field_field_area[0]['raw']['taxonomy_term']->name,
        'developer' =>l($val->field_field_complex_developer[0]['raw']['taxonomy_term']->name,
          'taxonomy/term/'.$val->field_field_complex_developer[0]['raw']['tid']),

        'complex' => l($val->field_field_home_complex[0]['raw']['entity']->title,
          'node/' . $val->field_field_home_complex[0]['raw']['target_id'] ),

        'address' => $val->field_field_address_house[0]['raw']['value'],
        'quarter' => $val->field_field_quarter[0]['raw']['value'],
        'year' => $val->field_field_year[0]['raw']['value'],
        'rooms' => $val->field_field_number_rooms[0]['raw']['value'],
        'floor' => $val->field_field_apartment_floor[0]['raw']['value'],
        'home_floor' =>  $val->field_field_number_floor[0]['raw']['value'],
        'sq' => $val->field_field_gross_area[0]['raw']['value'],
        'price' => $val->field_field_price[0]['raw']['value'] / 1000,
        'coast' => $val->field_field_full_cost[0]['raw']['value'] / 1000,
        'status' => $val->field_field_status[0]['raw']['value'],
        'apartment_comparison' => l('<svg version="1.0" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                     width="30px" height="30px" viewBox="0 0 30.343 28.871" enable-background="new 0 0 30.343 28.871" xml:space="preserve" class="scales" class="scales-target">
                    <g>
                      <path d="M30.218,13.606L27.061,0.59C26.977,0.243,26.668,0,26.294,0l-0.018,0c-0.232,0-0.448,0.103-0.594,0.279
                            L15.631,4.721c-0.234-0.133-0.505-0.211-0.794-0.211c-0.767,0-1.408,0.537-1.57,1.255L4.128,9.805
                            C4.114,9.804,4.103,9.798,4.081,9.804l-0.017,0C3.391,9.88,3.32,10.372,3.32,10.372c-0.002,0.007-0.004,0.015-0.006,0.022
                            L0.157,23.411H0v0.264c0,1.759,1.824,3.19,4.065,3.19s4.065-1.431,4.065-3.19v-0.264H8.005l-2.964-12.05l8.872-3.92v20.684
                            h-2.618v0.747h7.282v-0.747h-2.604V7.264c0.294-0.292,0.475-0.621,0.475-1.068l8.688-3.897L22.37,13.606h-0.157v0.264
                            c0,1.759,1.824,3.19,4.065,3.19s4.065-1.431,4.065-3.19v-0.264H30.218z M6.414,23.411H1.748l2.333-9.621L6.414,23.411z
                             M23.961,13.606l2.333-9.621l2.333,9.621H23.961z"/>
                    </g>
</svg>',
          '#apartment-comparison', array(
            'external' => TRUE,
            'html' => TRUE,
            'attributes'=> array(
              'id' => 'apartment-comparison',
              'data-node-id' => $val->nid,
            ),
          )),
      );
    }
  }
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

  unset($vars['form']['masonry']['#title']);
  unset($vars['form']['category']['#title']);
  unset($vars['form']['quarter']['#title']);
  unset($vars['form']['year']['#title']);
  unset($vars['form']['sq']['#title']);
  unset($vars['form']['price']['#title']);
  unset($vars['form']['coast']['#title']);
  unset($vars['form']['parking']['#title']);
  unset($vars['form']['balcony']['#title']);
  unset($vars['form']['floor']['#title']);

  $vars['area'] = realty_get_options_current_city('area');

}


/**
*  implement hook_theme_registry_alter().
 */
function realty_theme_registry_alter(&$theme_registry) {
  $theme_path = path_to_theme();

  // Checkboxes.
 /* if (isset($theme_registry['checkbox'])) {
    $theme_registry['checkbox']['type'] = 'theme';
    $theme_registry['checkbox']['theme path'] = $theme_path;
    $theme_registry['checkbox']['template'] = $theme_path. '/templates/field--type-checkbox';
    unset($theme_registry['checkbox']['function']);
  }
*/
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

/**
 * Process variables for realty-map-complex.tpl.php.
 */
function realty_theme_preprocess_realty_map_complex(&$vars) {
  $a = 1;
  if ($vars['nid']) {
    $vars['node'] = node_load($vars['nid']);
    $vars['image'] = theme('image', array(
      'path' => $vars['node']->field_main_photo['und'][0]['uri'],
      'attributes' => array(
        'class' => array('title-image'),
      ),
    ));

    $vars['logo'] = theme('image', array(
      'path' => $vars['node']->field_complex_logo['und'][0]['uri'],
      'attributes' => array(
        'class' => array('logo-z', 'vertical-logo'),
      ),
    ));

    $vars['details'] = l('details', 'node/' . $vars['node']->nid, array('attributes' => array('class' => array('button-info','button-info-top') )));
  }
}