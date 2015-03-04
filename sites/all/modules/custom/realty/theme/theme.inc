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
  $a = 1;
  $vars['form'] = $vars[''];
  $vars['form']['field_apartament_home_tid']['#attributes']['class'][] = 'cf';
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