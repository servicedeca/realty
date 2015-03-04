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
  $vars['form']['field_apartament_home_tid']['#attributes']['class'][] = 'cf';
  $vars['form']['field_number_rooms_value']['#attributes']['class'][] = 'cf';
  $vars['form']['field_section_value']['#attributes']['class'][] = 'cf';
  $vars['form']['field_apartment_floor_value']['#title'] = t('floor');
  $vars['form']['field_apartment_floor_value']['#attributes']['class'][] = 'complex-filter-square-input';


  $vars['form']['field_gross_area_value']['min']['#title'] = t('from');
  $vars['form']['field_gross_area_value']['max']['#title'] = t('to');
  $vars['form']['field_gross_area_value']['min']['#attributes']['class'][] = 'complex-filter-square-input';
  $vars['form']['field_gross_area_value']['max']['#attributes']['class'][] = 'complex-filter-square-input';
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