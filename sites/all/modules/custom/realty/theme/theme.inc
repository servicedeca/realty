<?php

/**
 * @file.
 */

/**
 * Preprocess for realty-user-profile-form.tpl.php.
 */
function realty_preprocess_realty_user_profile_form(&$vars) {
  $a = 1;
  unset($vars['form']['timezone']);
  unset($vars['form']['metatags']);
  unset($vars['form']['locale']);

}

/**
 * Preprocess for realty-views-exposed-form.tpl.php.
 */
function realty_preprocess_realty_views_exposed_form(&$vars) {

  $vars['form'] = $vars[''];

  $vars['form']['field_number_rooms_value']['#attributes']['class'][] = 'cf';
  $vars['form']['field_apartment_floor_value']['#title'] = t('floor');
  $vars['form']['field_apartment_floor_value']['#attributes']['class'][] = 'complex-filter-square-input';


  $vars['form']['field_gross_area_value']['min']['#title'] = t('from');
  $vars['form']['field_gross_area_value']['max']['#title'] = t('to');
  $vars['form']['field_gross_area_value']['min']['#attributes']['class'][] = 'complex-filter-square-input';
  $vars['form']['field_gross_area_value']['max']['#attributes']['class'][] = 'complex-filter-square-input';

  $vars['form_filter'] = drupal_get_form('realty_filter_complex_apartment_form');

  $vars['button'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/clear.svg',
  ));

}

/**
 * Preprocess for realty-id-apartment-pdf.tpl.php.
 */
function realty_preprocess_realty_id_apartment_pdf(&$vars) {
  $vars['logo'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/minilogo.svg'
    )
  );
  $vars['id'] = $vars['node']->field_id_appartament[LANGUAGE_NONE][0]['safe_value'];
  $vars['number'] = $vars['node']->field_number_apartament[LANGUAGE_NONE][0]['safe_value'];
  $home = taxonomy_term_load($vars['node']->field_apartament_home[LANGUAGE_NONE][0]['tid']);
  $vars['home_address'] = $home->field_address_house[LANGUAGE_NONE][0]['safe_value'];
  $complex = node_load($home->field_home_complex[LANGUAGE_NONE][0]['target_id']);
  $vars['home_plan'] = theme('image', array(
      'path' => $vars['node']->field_location_home[LANGUAGE_NONE][0]['uri'],
    )
  );
  $vars['plan'] = theme('image', array(
      'path' => $vars['node']->field_plan_apartment[LANGUAGE_NONE][0]['uri'],
    )
  );
  $vars['complex'] = $complex->title;
  $vars['coast'] = $vars['node']->field_full_cost[LANGUAGE_NONE][0]['value'] / 1000 . ' т.р';
  $vars['rooms'] = $vars['node']->field_number_rooms[LANGUAGE_NONE][0]['value'];
  $vars['floor'] = $vars['node']->field_apartment_floor[LANGUAGE_NONE][0]['value'];
  $vars['section'] = $vars['node']->field_section[LANGUAGE_NONE][0]['value'];
  $vars['sq'] = $vars['node']->field_gross_area['und'][0]['value'] . ' м<sup>2</sup>';
}

/**
 * Preprocess for realty-sending-messages.tpl.php
 */
function realty_preprocess_realty_sending_messages(&$vars) {

}

/**
 * Preprocess for realty-main-search-form.tpl.php.
 */
function realty_preprocess_realty_main_search_form(&$vars) {
  $vars['form'] = $vars[''];

  drupal_add_js(REALTY_FRONT_THEME_PATH . '/js/realty_main_search_form.js');
  $city = menu_get_object('taxonomy_term', 2);
  $vars['form']['field_city_tid']['#value'] = $city->tid;
  $vars['form']['field_apartment_floor_value']['#maxlength'] = 2;
  $vars['form']['field_apartment_floor_value']['#attributes'] = array(
    'class' => array('search-input', 'mini-width', 'floor'),
  );
  $vars['form']['field_masonry_value']['#attributes']['class'] = array('ss');
  $vars['form']['field_category_value']['#attributes']['class'] = array('ss', 'mini-ss');
  $vars['form']['field_quarter_value']['#attributes']['class'] = array('ss', 'mini-ss');
  $vars['form']['field_year_value']['#attributes'] = array(
    'class' => array('search-input ear'),
    'placeholder' => t('Year'),
    'maxlength' => '4',
  );
  $vars['form']['submit']['#value'] = t('Choose option');
  $vars['form']['submit']['#attributes']['class'] = array('search-button');

  $vars['micro_logo'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/micrologo.png',
    'attributes' => array(
      'class' => array('search-head-logo'),
    ),
  ));

  foreach (realty_get_list_city() as $city) {
    $vars['cities'][] = l($city->name, 'taxonomy/term/' . $city->tid);
  }

  $city = realty_get_current_city();
  $vars['city'] = $city;

}

/**
 * Process variables for realty-user-login-form.tpl.php
 */
function realty_preprocess_realty_user_login_form(&$vars) {
  $vars['form'] = $vars[''];
  $vars['form']['name']['#attributes']['class'] = array('form-control', 'reg-input');
  $vars['form']['pass']['#attributes']['class'] = array('form-control', 'reg-input');
  unset($vars['form']['name']['#title']);
  unset($vars['form']['name']['#description']);
  unset($vars['form']['pass']['#title']);
  unset($vars['form']['pass']['#description']);
  $vars['form']['name']['#attributes']['placeholder'] = t('e-mail');
  $vars['form']['pass']['#attributes']['placeholder'] = t('password');
  $vars['form']['actions']['submit']['#attributes']['class'] = array('col-xs-4', 'col-xs-offset-4', 'registration-button');

  $vars['image_mail'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/mail.svg',
    )
  );

  $vars['image_key'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/key.svg',
    )
  );
}

/**
 * Process variables for realty-user-register-form.tpl.php
 */
function realty_preprocess_realty_user_register_form(&$vars) {
  $a = 1;
  $vars['form'] = $vars[''];
  $vars['form']['account']['mail']['#attributes']['class'] = array('form-control', 'reg-input');
  unset($vars['form']['account']['mail']['#description']);
  unset($vars['form']['account']['mail']['#title']);
  $vars['form']['account']['mail']['#attributes']['placeholder'] = t('e-mail');
  unset( $vars['form']['account']['pass']['pass1']['#title']);
  unset( $vars['form']['account']['pass']['pass2']['#title']);
  $vars['form']['account']['pass']['pass1']['#attributes']['class'][] = 'form-control';
  $vars['form']['account']['pass']['pass1']['#attributes']['class'][] = 'reg-input';
  $vars['form']['account']['pass']['pass1']['#attributes']['placeholder'] = t('password');
  $vars['form']['account']['pass']['pass2']['#attributes']['class'][] = 'form-control';
  $vars['form']['account']['pass']['pass2']['#attributes']['class'][] = 'reg-input';
  $vars['form']['account']['pass']['pass2']['#attributes']['placeholder'] = t('confirm password');
  $vars['form']['actions']['submit']['#attributes']['class'][] = 'col-xs-4';
  $vars['form']['actions']['submit']['#attributes']['class'][] = 'col-xs-offset-4';
  $vars['form']['actions']['submit']['#attributes']['class'][] = 'registration-button';
  unset($vars['form']['field_user_name']['und'][0]['value']['#title']);
  $vars['form']['field_user_name']['und'][0]['value']['#attributes']['class'] = array('form-control', 'reg-input');
  $vars['form']['field_user_name']['und'][0]['value']['#attributes']['placeholder'] = t('Ф.И.О');


  $vars['image_mail'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/mail.svg',
    )
  );
  $vars['image_key'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/key.svg',
    )
  );
  $vars['image_man'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/c-man.svg',
    )
  );

}