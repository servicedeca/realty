<?php

/**
 * Implements hook_css_alter().
 */
function realty_theme_css_alter(&$css) {
  unset($css['modules/system/system.menus.css']);
  unset($css['modules/system/system.theme.css']);
}

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
  global $user;

  $account = user_load($user->uid);

  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $val) {
      $vars['apartments'][$key] = array(
        'number' => l('<div class="flat-number flat-number-booked">'
          .$val->field_field_number_apartament[0]['rendered']['#markup'].'</div>', 'node/' . $val->nid, array(
            'attributes' => array(
              'title' => t('View apartment'),
            ),
            'html' => TRUE,
        )),
        'address' => $val->field_field_address_house[0]['rendered']['#markup'],
        'section' => $val->field_field_section[0]['rendered']['#markup'],
        'floor' => $val->field_field_apartment_floor[0]['raw']['value'],
        'room' => $val->field_field_number_rooms[0]['raw']['value'],
        'sq' => $val->field_field_gross_area[0]['rendered']['#markup'],
        'price' => $val->field_field_price[0]['raw']['value'] / 1000,
        'coast' => $val->field_field_full_cost[0]['raw']['value'] / 1000,
        'status' => $val->field_field_status[0]['raw']['value'],
      );

      $add = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/add.svg',
        'attributes' => array(
          'class' => array('add','z-but'),
        ),
      ));

      $add_h = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/addh.svg',
        'attributes' => array(
          'class' => array('add','z-but-h'),
        ),
      ));

      $vars['apartments'][$key]['comparison'] = '<div class="apartment-comparison" data-node-id='.$val->nid.'>' .
          l($add . $add_h , '#complex', array(
            'html' => TRUE,
            'external' => TRUE,
            'attributes' => array(
              'title' => t('Add an apartment to Compare'),
              'data-placement' => 'right',
              'rel' => 'tooltip',
            ),
          )) .
        '</div>';

      if (!empty($account->field_apartment_comparison)) {
        foreach ($account->field_apartment_comparison[LANGUAGE_NONE] as $id) {

          if($id['target_id'] == $val->nid ) {

            $add_r = theme('image', array (
              'path' => REALTY_FRONT_THEME_PATH . '/images/ready.svg',
              'attributes' => array(
                'class' => array('add'),
              ),
            ));

            $vars['apartments'][$key]['comparison'] = l($add_r , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Apartment in comparison'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
              ),
            ));

          }
        }
      }

      if($val->field_field_status[0]['raw']['value'] == 0) {

        $dindon = theme('image', array(
          'path' => REALTY_FRONT_THEME_PATH . '/images/dingdong.svg',
          'attributes' => array(
            'class' => array('dingdong','z-but'),
          ),
        ));

        $dindon_h = theme('image', array(
          'path' => REALTY_FRONT_THEME_PATH . '/images/dingdongh.svg',
          'attributes' => array(
            'class' => array('dingdong','z-but-h'),
          ),
        ));

        $vars['apartments'][$key]['dindong'] = '<div class="apartment-signal" data-node-id='.$val->nid.'>'.
          l($dindon . $dindon_h , '#href', array(
            'html' => TRUE,
            'external' => TRUE,
            'attributes' => array(
              'title' => t('Send a notice of withdrawal of the reservation'),
              'data-placement' => 'right',
              'rel' => 'tooltip',
            ),
        ));

        if (!empty($val->_field_data['nid']['entity']->field_user_signal)) {
          foreach ($val->_field_data['nid']['entity']->field_user_signal[LANGUAGE_NONE] as $value) {
            if ($value['target_id'] == $user->uid) {

              $dindon_r = theme('image', array(
                'path' => REALTY_FRONT_THEME_PATH . '/images/dingdongr.svg',
                'attributes' => array(
                  'class' => array('dingdong'),
                ),
              ));

              $vars['apartments'][$key]['dindong'] = l($dindon_r , '#href', array(
                'html' => TRUE,
                'external' => TRUE,
                'attributes' => array(
                  'rel' => 'tooltip',
                  'data-placement' => 'right',
                  'title' => 'Notification will be sent to the withdrawal of reservations',
                ),
              ));
            }
          }

        }
      }

    }
  }
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

  $add_img = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/add.svg',
    'attributes' => array(
      'class' => array('add', 'z-but'),
    ),
  ));
  $addh_img = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/addh.svg',
    'attributes' => array(
      'class' => array('add', 'z-but-h'),
    ),
  ));

  $dingdong = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/dingdong.svg',
    'attributes' => array(
      'class' => array('dingdong', 'z-but'),
    ),
  ));
  $dingdongh = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/dingdongh.svg',
    'attributes' => array(
      'class' => array('dingdong', 'z-but-h'),
    ),
  ));

  if (!empty($vars['view']->result)) {

    foreach ($vars['view']->result as $key => $val) {
      $vars['apartments'][$key] = array(
        'apartment_path' => 'node/' . $val->nid,
        'number' => l('<div class="flat-number flat-number-booked">' . $val->field_field_number_apartament[0]['raw']['value'] . '</div>',
          'node/' . $val->nid, array('html'=> TRUE)),

        'area' => $val->field_field_area[0]['raw']['taxonomy_term']->name,
        'developer_path' => 'taxonomy/term/'.$val->field_field_complex_developer[0]['raw']['tid'],
        'developer' => $val->field_field_complex_developer[0]['raw']['taxonomy_term']->name,

        'complex' => $val->field_field_home_complex[0]['raw']['entity']->title,
        'complex_path' => 'node/' . $val->field_field_home_complex[0]['raw']['target_id'],

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
        'apartment_comparison' => l($add_img . $addh_img, '#apartment-comparison', array(
          'external' => TRUE,
          'html' => TRUE,
          'attributes'=> array(
            'rel' => "tooltip",
            'data-placement' => 'right',
            'title' => 'добавить квартиру в сравнение',
            'id' => 'apartment-comparison',
            'data-node-id' => $val->nid,
            ),
          )
        ),
        'apartment_signal' => l($dingdong . $dingdongh, '#apartment-signal', array(
            'external' => TRUE,
            'html' => TRUE,
            'attributes'=> array(
              'rel' => "tooltip",
              'data-placement' => 'right',
              'title' => "отправить уведомлении о снятии брони",
              'id' => 'apartment-signal',
              'data-node-id' => $val->nid,
            ),
          )
        ),
      );
    }
  }

}

/**
 * Process variables for search-form.tpl.php
 */
function realty_theme_preprocess_search_form(&$vars) {

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

}

/**
 * Process variables realty-modal-search-form.tpl.php
 */
function realty_preprocess_realty_modal_search_form(&$vars) {

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));

  $vars['areas'] = realty_get_options_current_city('area');
  $vars['metros'] = realty_get_options_current_city('metro');
  $vars['developers'] = realty_get_developer_current_city();
  $vars['complexes'] = realty_get_complex_current_city();
  $vars['rooms'] = realty_options_search('room');
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

/**
 * Process variables for views-view-unformatted--news--news-city.tpl.php
 */
function realty_preprocess_views_view_unformatted__news__news_city(&$vars) {
  foreach ($vars['view']->result as $key => $value) {
    $vars['news'][$key] = array(
      'title' => l($value->node_title, 'node/' .$value->nid),
      'description' => $value->field_field_news_description[0]['raw']['value'],
      'details' => l('details', 'node/' .$value->nid),
      'date' => format_date($value->node_created, 'm/d/Y'),
    );
  }
}

/**
 * Process variables for comment.tpl.php
 */
function realty_theme_preprocess_comment(&$vars) {
  $account = user_load($vars['comment']->uid);
  $vars['comments'] = $vars['comment']->field_body[LANGUAGE_NONE][0]['safe_value'];
  $vars['name'] = $account->name;
  $vars['date'] = gmdate("m-d-Y", $vars['comment']->created);

  $vars['image_finger'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/finger.svg',
    'attributes' => array('class' => array('recall-img')),
  ));
}

/**
 * Process variables for comment_wrapper.tpl.php
 */
function realty_theme_preprocess_comment_wrapper(&$vars) {
  $vars['realty_comment_form'] = drupal_get_form('realty_comment_form');
  unset($vars['content']['comments']['pager']);

}

/**
 * Process variables for comment-form.tpl.php
 */
function realty_theme_preprocess_realty_comment_form(&$vars) {
  $vars['node'] = menu_get_object('node', 1);

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));

  $vars['image'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/c-pen.svg',
  ));
}

/**
 * Process variables for views-view-unformatted--comments-complex--comments-complex.tpl.php
 */

function realty_preprocess_views_view_unformatted__comments_complex__comments_complex(&$vars) {
  $vars['image_finger'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/finger.svg',
    'attributes' => array('class' => array('recall-img')),
  ));

  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $comment) {
      $vars['comments'][] = array(
       'comment' => $comment->field_field_body[0]['rendered']['#markup'],
       'name' => $comment->comment_name,
       'date' => gmdate("m-d-Y", $comment->comment_created),
      );
    }
  }
  $a = 1;
}