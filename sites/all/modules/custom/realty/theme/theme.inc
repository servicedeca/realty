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
  $a = 1;
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

  drupal_add_js(REALTY_FRONT_THEME_PATH.'/js/realty_main_search_form.js');
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

  foreach(realty_get_list_city() as $city) {
    $vars['cities'][] = l($city->name, 'taxonomy/term/'.$city->tid);
  }

  $city = realty_get_current_city();
  $vars['city'] = $city;

}