<?php

/**
 * Implements hook_css_alter().
 */
function realty_theme_css_alter(&$css) {
  unset($css['modules/system/system.menus.css']);
  unset($css['modules/system/system.theme.css']);
}

function realty_theme_html_head_alter(&$head_elements) {
  $head_elements['device_width'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array('name' => 'viewport', 'content' => 'width=device-width'),
  );
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
  $city_id = arg(2);
  $city = taxonomy_term_load($city_id);
  $vars['city'] = l($city->name, 'taxonomy/term/'.$city->tid);
  $vars['complexes_link'] = l(t('complexes'), 'complexes/city/'.$city->tid);

  foreach($vars['view']->result as $k => $value) {
      $vars['complexes'][$k] = array(
          'logo' => theme('image', array(
              'path' => $value->field_field_complex_logo[0]['raw']['uri'],
              'title' => $value->node_title,
              )
            ),
          'complex_link' => '/node/'.$value->nid,
      );
  }
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
 * Process variables for views-view-unformatted--term-view--developers.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__developers(&$vars) {

  $city_id = arg(2);
  $city = taxonomy_term_load($city_id);
  $vars['city'] = l($city->name, 'taxonomy/term/'.$city->tid);
  $vars['developers_link'] = l(t('developers'), 'developers/city/'.$city->tid);

  foreach($vars['view']->result as $k=>$value){
    $vars['developers'][$k] = array(
        'logo' => theme('image', array(
            'path' => $value->field_field_developer_logo[0]['raw']['uri'],
            'width' => '100px',
            'height' => '100px',
            )
        ),
        'name' => $value->taxonomy_term_data_name,
        'developer_link' => 'taxonomy/term/'.$value->tid,
    );

    $complexes = views_get_view_result('complex', 'complex_developer', $value->tid);
    foreach ($complexes as $key => $val) {
       $vars['developers'][$k]['complexes'][]['complex']= $val->node_title;
    }
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
        'apartment_path' => '/node/' . $val->nid,
        'address' => $val->field_field_address_house[0]['rendered']['#markup'],
        'section' => $val->field_field_section[0]['rendered']['#markup'],
        'floor' => $val->field_field_apartment_floor[0]['raw']['value'],
        'room' => $val->field_field_number_rooms[0]['raw']['value'],
        'sq' => $val->field_field_gross_area[0]['rendered']['#markup'],
        'price' => $val->field_field_price[0]['raw']['value'],
        'coast' => $val->field_field_full_cost[0]['raw']['value'] / 1000,
        'status' => $val->field_field_status[0]['raw']['value'] / 1000,
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
        )).'</div>';

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
                  'title' => t('Notification will be sent to the withdrawal of reservations'),
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
  global $user;
    if ($user->uid != 0) {
        $account = user_load($user->uid);
    }
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
        'apartment_signal' => '<div class="apartment-signal" data-node-id='.$val->nid.'>'.
          l($dingdong . $dingdongh , '#href', array(
            'html' => TRUE,
            'external' => TRUE,
            'attributes' => array(
              'title' => t('Send a notice of withdrawal of the reservation'),
              'data-placement' => 'right',
              'rel' => 'tooltip',
            ),)).'</div>'
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

      $vars['apartments'][$key]['apartment_comparison'] = '<div class="apartment-comparison" data-node-id='.$val->nid.'>' .
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

      if ($user->uid != 0) {
        foreach ($account->field_apartment_comparison[LANGUAGE_NONE] as $id) {

          if($id['target_id'] == $val->nid ) {

            $add_r = theme('image', array (
              'path' => REALTY_FRONT_THEME_PATH . '/images/ready.svg',
              'attributes' => array(
                'class' => array('add'),
              ),
            ));

            $vars['apartments'][$key]['apartment_comparison']= l($add_r , '#href', array(
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

      if (realty_check_status_apartment_user($user->uid, $val->nid) == TRUE) {

        $dindon_r = theme('image', array(
          'path' => REALTY_FRONT_THEME_PATH . '/images/dingdongr.svg',
          'attributes' => array(
            'class' => array('dingdong'),
          ),
        ));

        $vars['apartments'][$key]['apartment_signal'] = l($dindon_r , '#href', array(
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
/*function realty_theme_registry_alter(&$theme_registry) {
  $theme_path = path_to_theme();
  // Checkboxes.
 if (isset($theme_registry['checkbox'])) {
    $theme_registry['checkbox']['type'] = 'theme';
    $theme_registry['checkbox']['theme path'] = $theme_path;
    $theme_registry['checkbox']['template'] = $theme_path. '/templates/field--type-checkbox';
    unset($theme_registry['checkbox']['function']);
  }
}*/

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
}

/**
 * Preprocess variables for node--apartament-full.tpl.php
 */
function realty_preprocess_node__apartament_full(&$vars) {
  global $user;

  $vars['title_number'] = l(t('apartment №') . $vars['field_number_apartament'][0]['safe_value'],
    'node/' . $vars['nid'], array('attributes'=> array('class'=> array('active-complex'))));

  if ($vars['field_status'][0]['value'] == 1) {
    $path_image = REALTY_FRONT_THEME_PATH . '/images/free.svg';
    $vars['status_text'] = t('The apartment is available');

    $lock = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/lock.svg',
      'attributes' => array(
        'class' => array('but1', 'bad-button-fix'),
      ),
    ));

    $lockh = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/lockh.svg',
      'attributes' => array(
        'class' => array('but1h', 'bad-button-fix'),
        'id' => 'callh'
      ),
    ));

    $vars['link_modal_book'] = l($lock . $lockh . '<span class="new-tip-button" id="call">
      '. t('book') .'
      </span>', '#href', array(
        'external' => TRUE,
        'html' => TRUE,
        'attributes' => array(
          'data-toggle' => 'modal',
          'data-target' => '.modal_free',
        )));
  }

  else {
    $path_image = REALTY_FRONT_THEME_PATH . '/images/booked.svg';
    $vars['status_text'] = t('The apartment is booked');

    $call = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/call.svg',
      'attributes' => array(
        'class' => array('but1', 'bad-button-fix'),
      ),
    ));

    $callh = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/callh.svg',
      'attributes' => array(
        'class' => array('but1h', 'bad-button-fix'),
        'id' => 'callh'
      ),
    ));

    $vars['link_modal_book'] = '<div class="apartment-signal" data-apartment="1" data-node-id='.$vars['nid'].'>'.
      l($call . $callh . '<span class="new-tip-button" id="call">
        '. t('Send notification if your will act') .'
        </span>', '#href', array(
          'external' => TRUE,
          'html' => TRUE,
          'attributes' => array(
            'data-toggle' => 'modal',
            'data-target' => '.modal_booking',
        ))).'</div>';

    if (realty_check_status_apartment_user($user->uid, $vars['nid']) == TRUE) {
      $call = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/dingdong_big.svg',
        'attributes' => array(
          'class' => array('bad-button-fix'),
        ),
      ));

      $vars['link_modal_book'] = l($call. '<span class="new-tip-button">
        '. t('Send notification if your removed') .'
        </span>', '#href', array(
            'external' => TRUE,
            'html' => TRUE,
            'attributes' => array(
            )));
    }

  }

  if (realty_checking_apartments_comparison($vars['nid']) == TRUE) {
    $redy = theme('image', array (
      'path' => REALTY_FRONT_THEME_PATH . '/images/ready_comprasion.svg',
      'attributes' => array(
        'class' => array(''),
      ),
    ));

    $vars['add_comparison'] = l($redy.'<div class="tip-button" id="comparison">
        '.t('added to comparison').'
        </div>' , '#href', array(
        'html' => TRUE,
        'external' => TRUE,
        'attributes' => array(
          'class' => array('added-comparison'),
        ),
      ));
  }

  else {
    $add = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/but1.svg',
      'attributes' => array(
        'class' => array('but1'),
      ),
    ));

    $addh = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/but1h.svg',
      'attributes' => array(
        'class' => array('but1h'),
        'id' => 'comparisonh',
      ),
    ));

    $vars['add_comparison'] = '<div class="apartment-comparison" data-apartment="1" data-node-id = "'.$vars['nid'].'"'
      .l($add . $addh . '<div class="tip-button" id="comparison">
        '.t('Add to Compare').'
        </div>', '#href', array(
          'external' => TRUE,
          'html' => TRUE,
          'attributes' => array(
            'data-node-id' => $vars['nid'],
            'data-apartment' => 1,
            'class' => array('apartment-comparison'),
        ))).'</div>';
    }

  $img_id = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/but2.svg',
    'attributes' => array(
      'class' => array('but1'),
    ),
  ));

  $img_id_h = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/but2h.svg',
    'attributes' => array(
      'class' => array('but1h'),
      'id' => 'bankh',
    ),
  ));

  $vars['get_id'] = l($img_id . $img_id_h . '<div class="tip-button" id="bank">'.t('Get id apartment').'</div>',
    'http://style.findome.ru/id.html', array(
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array(
        //'data-toggle' => 'modal',
        //'data-target' => '.modal_id',
        //'class' => array('apartment-comparison'),
      )
    )
  );

  $img_doc = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/but3.svg',
    'attributes' => array(
      'class' => array('but1'),
    ),
  ));

  $img_doc_h = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/but3h.svg',
    'attributes' => array(
      'class' => array('but1h'),
      'id' => 'documentsh',
    ),
  ));

  $vars['get_doc'] = l($img_doc . $img_doc_h . '<div class="tip-button" id="documents">'.t('Get documents').'</div>',
    'http://style.findome.ru/docs.html', array(
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array(
        ///'data-toggle' => 'modal',
       // 'data-target' => '.modal_docs',
       // 'class' => array('apartment-comparison'),
      )
    )
  );

  if (!empty($vars['field_plan_apartment'])) {
    $vars['apartment_plan'] = theme('image', array(
      'path' => $vars['field_plan_apartment'][0]['uri'],
      'title' => 'plan apartment',
      'attributes' => array(
        'class' => array('apartment-image-vertical'),
      ),
    ));
  }

  if (!empty($vars['field_location_home'])) {
    $vars['home_plan'] = theme('image', array(
      'path' => $vars['field_location_home'][0]['uri'],
      'title' => 'plan apartment',
      'attributes' => array(
        'class' => array('apartment-image-vertical'),
      ),
    ));
  }

  if (!empty($vars['field_location_floor'])) {
    $vars['floor_plan'] = theme('image', array(
      'path' => $vars['field_location_floor']['und'][0]['uri'],
      'title' => 'plan apartment',
      'attributes' => array(
        'class' => array('apartment-image-vertical'),
      ),
    ));
  }

  $vars['image_status'] = theme('image', array(
    'path' => $path_image,
    )
  );
  $vars['address'] = $vars['field_apartament_home'][0]['taxonomy_term']->field_address_house['und'][0]['value'];
  $complex = node_load($vars['field_apartament_home'][0]['taxonomy_term']->field_home_complex['und'][0]['target_id']);
  $vars['complex'] = $complex->title;
  $deadline = field_collection_item_load($complex->field_deadline['und'][0]['revision_id']);
  $vars['deadline'] = $deadline->field_quarter['und'][0]['value'] . t('quarter').' '.
    $deadline->field_year['und'][0]['value'] . t('year');
  $area = taxonomy_term_load($complex->field_area['und'][0]['tid']);
  $vars['area'] = $area->name;
  $developer = taxonomy_term_load($complex->field_complex_developer['und'][0]['tid']);
  $vars['developer'] = $developer->name;
}
