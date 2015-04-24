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
    $vars['login_profile'] =  l(t('Login/Register'), '#href', array('external' => TRUE,
      'attributes' => array(
        'class' => array(
          'btn', 'head-reg'
          ),
        'data-toggle' => 'modal',
        'data-target' => '.registration',
        ),
      )
    );
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
  $vars['modal_login_form'] = theme('realty_modal_user_login', array());
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
$a= 1;
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
        'home_floor' =>  $val->field_field_number_floor[0]['raw']['value'],
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
      if ($user->uid != 0) {
        $vars['apartments'][$key]['comparison'] = '<div class="apartment-comparison" data-node-id='.$val->nid.'>' .
          l($add . $add_h , '#href', array(
            'html' => TRUE,
            'external' => TRUE,
            'attributes' => array(
              'title' => t('Add an apartment to Compare'),
              'data-placement' => 'right',
              'rel' => 'tooltip',
            ),
          )) .
          '</div>';

        if($val->field_field_status[0]['raw']['value'] == 0) {
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

      else {
        $vars['apartments'][$key]['comparison'] = '<div class="comparison">' .
          l($add . $add_h , '#href', array(
            'html' => TRUE,
            'external' => TRUE,
            'attributes' => array(
              'title' => t('Add an apartment to Compare'),
              'data-placement' => 'right',
              'rel' => 'tooltip',
              'data-toggle' => 'modal',
              'data-target' => '.registration',
              ),
            )
          ) .
          '</div>';

        if($val->field_field_status[0]['raw']['value'] == 0) {
          $vars['apartments'][$key]['dindong'] = '<div>'.
            l($dindon . $dindon_h , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Send a notice of withdrawal of the reservation'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
                'data-toggle' => 'modal',
                'data-target' => '.registration',
              ),
            )).'</div>';
        }
      }

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
    }
  }
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
        'apartment_path' => '/node/' . $val->nid,
        'number' => l('<div class="flat-number flat-number-booked">' . $val->field_field_number_apartament[0]['raw']['value'] . '</div>',
          'node/' . $val->nid, array('html'=> TRUE)),
        'area' => $val->field_field_area[0]['raw']['taxonomy_term']->name,
        'developer_path' => '/taxonomy/term/'.$val->field_field_complex_developer[0]['raw']['tid'],
        'developer' => $val->field_field_complex_developer[0]['raw']['taxonomy_term']->name,
        'complex' => $val->field_field_home_complex[0]['raw']['entity']->title,
        'complex_path' => '/node/' . $val->field_field_home_complex[0]['raw']['target_id'],
        'address' => $val->field_field_address_house[0]['raw']['value'],
        'quarter' => $val->field_field_home_deadline_quarter[0]['raw']['value'],
        'year' => $val->field_field_home_deadline_year[0]['raw']['value'],
        'rooms' => $val->field_field_number_rooms[0]['raw']['value'],
        'floor' => $val->field_field_apartment_floor[0]['raw']['value'],
        'home_floor' =>  $val->field_field_number_floor[0]['raw']['value'],
        'sq' => $val->field_field_gross_area[0]['raw']['value'],
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

      if ($user->uid != 0) {

        $vars['apartments'][$key]['apartment_comparison'] = '<div class="apartment-comparison" data-node-id='.$val->nid.'>' .
          l($add . $add_h , '#href', array(
            'html' => TRUE,
            'external' => TRUE,
            'attributes' => array(
              'title' => t('Add an apartment to Compare'),
              'data-placement' => 'right',
              'rel' => 'tooltip',
            ),
          )) .
          '</div>';

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
              )
            );

          }
        }

        $vars['apartments'][$key]['apartment_signal'] = '<div class="apartment-signal" data-node-id='.$val->nid.'>'.
        l($dingdong . $dingdongh , '#href', array(
            'html' => TRUE,
            'external' => TRUE,
            'attributes' => array(
              'title' => t('Send a notice of withdrawal of the reservation'),
              'data-placement' => 'right',
              'rel' => 'tooltip',
            ),
          )
        ).'</div>';

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

      else {
        $vars['apartments'][$key]['apartment_comparison'] = '<div class="comparison">' .
          l($add . $add_h , '#href', array(
            'html' => TRUE,
            'external' => TRUE,
            'attributes' => array(
              'title' => t('Add an apartment to Compare'),
              'data-placement' => 'right',
              'rel' => 'tooltip',
              'data-toggle' => 'modal',
              'data-target' => '.registration',
              ),
            )
          ) .
          '</div>';

        $vars['apartments'][$key]['apartment_signal'] = '<div class="">'.
          l($dingdong . $dingdongh , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Send a notice of withdrawal of the reservation'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
                'data-toggle' => 'modal',
                'data-target' => '.registration',
              ),
            )
          ).'</div>';

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

  $menu_items = array(
    0 => array(
      'path' => l(t('Profile'), "user/$uid"),
      'title' => 'user',
    ),
    1 => array(
      'path' => l(t('Comparison'), "/comparison"),
      'title' => 'comparison',
    ),
    2 => array(
      'path' => l(t('Get id'), "/apartment_id"),
      'title' => 'apartment_id',
    ),

    3 => array(
      'path' => l(t('Reward'), "/reward"),
      'title' => 'reward',
    ),
  );

  $url = arg(0);
  foreach($menu_items as $key => $item) {
    if($url == $item['title']) {
      $vars['menu'][$key] = '<li class="active-menu">'.$item['path'].'</li>';
      $vars['page'] = $item['path'];
    }
    else {
      $vars['menu'][$key] = '<li>'.$item['path'].'</li>';
    }
  }
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
      'details' => l(t('details'), 'node/' .$value->nid),
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

function realty_preprocess_views_view_unformatted__comments_complex(&$vars) {
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

  if ($user->uid != 0) {
    $account = user_load($user->uid);
    $vars['name'] = $account->field_user_name[LANGUAGE_NONE][0]['safe_value'];
    if (!empty($account->field_phone_number)) {
      $vars['number'] = $account->field_phone_number[LANGUAGE_NONE][0]['safe_value'];
    }

    $vars['get_id'] = l($img_id . $img_id_h . '<div class="tip-button" id="bank">'.t('Get id apartment').'</div>',
      '#href', array(
        'external' => TRUE,
        'html' => TRUE,
        'attributes' => array(
          'id' => 'download-id-apartment',
          'data-nid-apartment' => $vars['nid'],
          'class' => array(),
        )
      )
    );

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
      $vars['add_comparison'] = '<div class="apartment-comparison comparison" data-apartment="1" data-node-id = "'.$vars['nid'].'"'
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
  }

  else {
    $vars['add_comparison'] = '<div class="comparison"' .
      l($add . $addh . '<div class="tip-button" id="comparison">'.
      t('Add to Compare') . '</div>',
      '#href', array(
        'external' => TRUE,
        'html' => TRUE,
        'attributes' => array(
          'data-toggle' => 'modal',
          'data-target' => '.registration',
          'class' => array('apartment-comparison'),
        )
      )
    ).'</div>';

    $vars['get_id'] = l($img_id . $img_id_h . '<div class="tip-button" id="bank">'.t('Get id apartment').'</div>',
      '#href', array(
        'external' => TRUE,
        'html' => TRUE,
        'attributes' => array(
          'data-toggle' => 'modal',
          'data-target' => '.registration',
        )
      )
    );
  }

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
          'id' => 'modal-free-booking-apartment'
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
    if ($user->uid == 0) {
      $vars['link_modal_book'] = '<div class=""АF>'.
        l($call . $callh . '<span class="new-tip-button" id="call">
        '. t('Send notification if your will act') .'
        </span>', '#href', array(
            'external' => TRUE,
            'html' => TRUE,
            'attributes' => array(
              'data-toggle' => 'modal',
              'data-target' => '.registration',
            )
          )
        ).'</div>';
    }
    else {
      $vars['link_modal_book'] = '<div class="apartment-signal" data-apartment="1" data-node-id='.$vars['nid'].'>'.
        l($call . $callh . '<span class="new-tip-button" id="call">
        '. t('Send notification if your will act') .'
        </span>', '#href', array(
            'external' => TRUE,
            'html' => TRUE,
            'attributes' => array(
              'data-toggle' => 'modal',
              'data-target' => '.modal_booking',
            )
          )
        ).'</div>';
    }

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
            )
        )
      );
    }

  }

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
    '#href', array(
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array(
        'data-toggle' => 'modal',
        'data-target' => '.modal_docs',
        'class' => array('apartment-comparison'),
      )
    )
  );


 /* empty($vars['field_plan_apartment']) ? $path_apartment_plan = $vars['field_location_floor']['und'][0]['uri'] :
    $path_apartment_plan = $vars['field_plan_apartment'][0]['uri'];
*/
  $vars['apartment_plan'] = theme('image', array(
    //'style_name' => '667x450',
    'path' => $vars['field_location_floor']['und'][0]['uri'],
    'title' => 'plan apartment',
    'attributes' => array(
      'class' => array('apartment-image-vertical'),
    ),
  ));

  if (!empty($vars['field_location_home'])) {
    $vars['home_plan'] = theme('image', array(
      //'style_name' => '667x450',
      'path' => $vars['field_location_home'][0]['uri'],
      'title' => 'plan apartment',
      'attributes' => array(
        'class' => array('apartment-image-vertical'),
      ),
    ));
  }

  if (!empty($vars['field_location_floor'])) {
    $vars['floor_plan'] = theme('image_style', array(
      'style_name' => '667x450',
      'path' => $vars['field_location_floor']['und'][0]['uri'],
      'title' => 'plan apartment',
      'attributes' => array(
        'class' => array('apartment-image-vertical'),
      ),
    ));
  }

  if (!empty($vars['field_apartment_vizual'])) {
    $vars['vizual'] = theme('image_style', array(
      'style_name' => '667x450',
      'path' => $vars['field_apartment_vizual']['und'][0]['uri'],
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
  $vars['image_close'] = realty_get_image_close();

  $vars['image_doc'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/doc.svg'
  ));

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

  $vars['image_man'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/c-man.svg'
    )
  );

  $vars['image_phone'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/c-phone.svg'
    )
  );
  if ($user->uid != 0) {
    $vars['booking_form'] = drupal_get_form('realty_booking_apartment_form');
  }

}

/**
 * Preprocess variables for views-view-unformatted--complex--gallery-photo.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__gallery_photo(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $album) {
      if (isset($album->field_field_image_gallery[0])) {
        $vars['albums'][$key]['title'] = l($album->field_field_name_gallery[0]['rendered']['#markup'],
          file_create_url($album->field_field_image_gallery[0]['raw']['uri']), array('attributes' => array(
            'class' => array('date-album'),
          )));
        $image_album = theme('image', array(
          'path' => $album->field_field_image_gallery[0]['raw']['uri'],
          'width' => '100%',
          'height' => '100%',
        ));

        $vars['albums'][$key]['image_album'] = l($image_album,
          file_create_url($album->field_field_image_gallery[0]['raw']['uri']), array(
            'html' => TRUE,
            'title' => $album->field_field_image_gallery[0]['raw']['title'],
            'attributes' => array(
            )
          )
        );
        foreach ($album->field_field_image_gallery as $photo) {
          continue;
          $vars['albums'][$key]['photos'][] = l('',file_create_url($photo['raw']['uri']), array(
            'title' => $photo['raw']['title'],
          ));
        }
      }
    }
  }
}

/*
 * Preprocess variables views-view-unformatted--complex--gallery-visualization.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__gallery_visualization(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result[0]->field_field_visualization as $val) {
      $photo = theme('image', array(
        'path' => $val['raw']['uri'],
        'width' => '100%',
        'height' => '100%',
        )
      );
      $vars['photos'][] = l($photo, file_create_url($val['raw']['uri']), array(
        'html' => TRUE,
        'attributes' => array(
        ),
      ));
    }
  }
}

/**
 * Preprocess variables views-view-unformatted--complex--gallery-tours.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__gallery_tours(&$vars) {
  if (!empty($vars['view']->result)) {
    $vars['image_pano'] = theme('image', array(
      'path' => $vars['view']->result[0]->field_field_image_pano[0]['raw']['uri'],
    ));
    $vars['pano'] = $vars['view']->result[0]->field_field_pano_complex[0]['raw']['value'];
  }
  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));
}

/**
 * Preprocess variables views-view-unformatted--complex--complex-documents.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__complex_documents(&$vars) {
  if (!empty($vars['view']->result[0]->field_field_title)) {
    foreach ($vars['view']->result as $document) {
      $vars['documents'][] = array(
        'title' => $document->field_field_title[0]['rendered']['#markup'],
        'link_download' => l(t('download'), file_create_url($document->field_field_document[0]['raw']['uri'])),
        'link_view' => l(t('View sample'), file_create_url($document->field_field_document[0]['raw']['uri'])),
      );
    }
  }

  $vars['image'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/doc.svg'
  ));
}

/**
 * Preprocess variables views-view-unformatted--stock--stock-complex.tpl.php.
 */
function realty_preprocess_views_view_unformatted__stock__stock_complex(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $stock) {
      $vars['stocks'][$key] = array(
        'title' => $stock->node_title,
        'description' => $stock->field_body[0]['rendered']['#markup'],
      );
      if (!empty($stock->field_field_image)) {
        $vars['stocks'][$key]['image'] = theme('image', array(
          'path' => $stock->field_field_image[0]['raw']['uri'],
        ));
      }
    }
  }
}

/**
 * Preprocess variables views-view-unformatted--term-view--developer.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__developer(&$vars) {
  $a = 1;
  $vars['img_close'] = realty_get_image_close();
  $vars['findome_logo'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/findome-gray.svg',
    'attributes' => array(
      'class' => array('margin-left-15')
    )));
}

/**
 * Preprocess variables views-view-unformatted--apartments--apartment-developer.tpl.php.
 */
function realty_preprocess_views_view_unformatted__apartments__apartment_developer(&$vars) {
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
        l($add . $add_h , '#href', array(
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
 * Process variables for views-view-unformatted--complex--complex-developer.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__complex_developer(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $val) {
      $logo = theme('image', array(
        'path' => $val->field_field_complex_logo[0]['raw']['uri'],
        'title' => $val->node_title,
        'alt' => $val->node_title,
      ));
      $vars['complexes'][] = l($logo, '/node/' . $val->nid, array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('col-xs-4', 'develop-complex-item'),
        ),
      ));
    }
  }
}

/**
 * Process variables for views-view-unformatted--complexes-archiv--archiv-complexes-developer.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complexes_archiv__archiv_complexes_developer(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $val) {
      $logo = theme('image', array(
        'path' => $val->field_field_archiv_complex_logo[0]['raw']['uri'],
        'title' => $val->node_title,
        'alt' => $val->node_title,
      ));
      $vars['complexes'][] = l($logo, '/node/' . $val->nid, array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('col-xs-4', 'develop-complex-item'),
        ),
      ));
    }
  }
}

/**
 * Process variables for views-view-unformatted--term-view--developer-gallery.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__developer_gallery(&$vars) {
    if (!empty($vars['view']->result)) {
      foreach ($vars['view']->result as $key => $album) {
        if (isset($album->field_field_developer_gallery_image[0])) {
          $vars['albums'][$key]['title'] = l($album->field_field_developer_gallery_title[0]['raw']['value'],
            file_create_url($album->field_field_developer_gallery_image[0]['raw']['uri']), array('attributes' => array(
              'class' => array('date-album'),
              )
            )
          );

          $image_album = theme('image', array(
            'path' => $album->field_field_developer_gallery_image[0]['raw']['uri'],
            'width' => '100%',
            'height' => '100%',
            )
          );

          $vars['albums'][$key]['image_album'] = l($image_album,
            file_create_url($album->field_field_developer_gallery_image[0]['raw']['uri']), array(
              'html' => TRUE,
              'title' => $album->field_field_developer_gallery_image[0]['raw']['title'],
              'attributes' => array(
              )
            )
          );

          foreach ($album->field_field_developer_gallery_image as $photo) {
            $vars['albums'][$key]['photos'][] = l('',file_create_url($photo['raw']['uri']), array(
              'title' => $photo['raw']['title'],
              )
            );
          }
        }
      }
    }
}

/**
 * Process variables views-view-unformatted--stock--stock-developer.tpl.php.
 */
function realty_preprocess_views_view_unformatted__stock__stock_developer(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $stock) {
      $vars['stocks'][$key] = array(
        'title' => $stock->node_title,
        'description' => $stock->field_body[0]['rendered']['#markup'],
      );
      if (!empty($stock->field_field_image)) {
        $vars['stocks'][$key]['image'] = theme('image', array(
          'path' => $stock->field_field_image[0]['raw']['uri'],
        ));
      }
    }
  }
}

/**
 * Process variables views-view-unformatted--stock--all-stock-city.tpl.php
 */
function realty_preprocess_views_view_unformatted__stock__all_stock_city(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $stock) {
      $vars['stocks'][] = array(
        'link' => '/node/'. $stock->nid,
        'title' => $stock->node_title,
        'body' =>  $stock->field_body[0]['rendered']['#markup'],
        'image' => theme('image_style', array(
          'style_name' => 'realty_stock',
          'path' => $stock->field_field_image[0]['raw']['uri'],
          'title' => $stock->node_title,
          'alt' => $stock->node_title,
        ))
      );
    }
  }
}

/**
 * Process variables views-view-unformatted--news--all-new-city.tpl.php.
 */
function realty_preprocess_views_view_unformatted__news__all_new_city(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $new) {
      $vars['news'][] = array(
        'link' => '/node/'. $new->nid,
        'title' => $new->node_title,
        'body' => $new->field_field_news_description[0]['rendered']['#markup'],
      );

      if (!empty($new->field_field_news_image)) {
        $vars['news'][]['image'] = theme('image_style', array(
          'style_name' => 'realty_stock',
        ));
      }
    }
  }
}

/**
 * Process variables views-view-unformatted--term-view--partners.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__partners(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $partner) {
      $logo = theme('image', array(
        'path' => $partner->field_field_partners_logo[0]['raw']['uri'],
        'title' => $partner->taxonomy_term_data_name,
        'alt' => $partner->taxonomy_term_data_name,
      ));

      $vars['partners'][] = l('<div class="col-xs-4 p-item">'. $logo .'</div>', '/taxonomy/term/' . $partner->tid,
        array('html' => TRUE));
    }
  }
}

/**
 * Process variables views-view-unformatted--term-view--all-partners.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__all_partners(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $partner) {
      $logo = theme('image', array(
        'path' => $partner->field_field_partners_logo[0]['raw']['uri'],
        'title' => $partner->taxonomy_term_data_name,
        'alt' => $partner->taxonomy_term_data_name,
      ));

      $vars['partners'][] = l($logo, '/taxonomy/term/' . $partner->tid,
        array('html' => TRUE,
          'attributes' => array('class' => array('col-xs-4','develop-complex-item'))
        ));
    }
  }
}

/**
 * Process variables views-view-unformatted--term-view--partner.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__partner(&$vars) {
  $vars['name'] = $vars['view']->result[0]->taxonomy_term_data_name;
  $vars['body'] = $vars['view']->result[0]->taxonomy_term_data_description;
  $vars['logo'] = theme('image', array(
    'path' => $vars['view']->result[0]->field_field_partners_logo[0]['raw']['uri'],
    'title' => $vars['view']->result[0]->taxonomy_term_data_name,
    'alt' => $vars['view']->result[0]->taxonomy_term_data_name,
  ));
}

/**
 * Process variables for realty-modal-user-login.tpl.php
 */
function realty_preprocess_realty_modal_user_login(&$vars) {
  global $user;

  if ($user->uid == 0) {
    $vars['register_form'] = drupal_get_form('user_register_form');
    $vars['login_form'] = drupal_get_form('user_login');
  }

  $vars['image_close'] = realty_get_image_close();
  $vars['logo'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/findome-gray.svg',
    'attributes' => array(
      'class' => array('margin-left-15'),
      ),
    )
  );
}

/**
 * Process variables for views-view-unformatted--apartments--comprassion.tpl.php
 */
function realty_preprocess_views_view_unformatted__apartments__comprassion(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $val) {
      $vars['number_apartment'][] = $val->field_field_number_apartament[0]['rendered']['#markup'];
      $vars['address'][] = $val->field_field_address_house[0]['rendered']['#markup'];
      $vars['sections'][] = $val->field_field_section[0]['rendered']['#markup'];
      $vars['rooms'][] = $val->field_field_number_rooms[0]['rendered']['#markup'];
      $vars['floor'][] = $val->field_field_apartment_floor[0]['raw']['value']  . '/' .
        $val->field_field_number_floor[0]['rendered']['#markup'];
      $vars['sq'][] = $val->field_field_gross_area[0]['raw']['value'];
      $vars['price'][] = $val->field_field_price[0]['raw']['value'] / 1000;
      $vars['coast'][] = $val->field_field_full_cost[0]['raw']['value'] / 1000000;
      $vars['balcony'][] = $val->field_field_balcony[0]['rendered']['#markup'];
      $vars['parking'][] = $val->field_field_parking[0]['rendered']['#markup'];
    }
  }
}

/**
 * Process variables for realty-booking-apartment-form.tpl.php
 */
function realty_theme_preprocess_realty_booking_apartment_form(&$vars) {
  $vars['image_man'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/c-man.svg'
    )
  );

  $vars['image_phone'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/c-phone.svg'
    )
  );

  $vars['image_mail'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/mail.svg',
    )
  );

  $vars['img_close'] = realty_get_image_close();
}