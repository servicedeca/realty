<?php

/**
 * @file.
 */

/**
 * Preprocess for taxonomy-form-term-homes.tpl.php
 */
function mark_picture_preprocess_taxonomy_form_term_homes(&$vars) {
  $a = 1;
  drupal_add_js(drupal_get_path('module', 'mark_picture') . '/js/mark_picture.js');
  drupal_add_css(drupal_get_path('module', 'mark_picture') . '/css/mark_picture.css');
  $vars['palan_complex'] = '';

  $vars['tool_add_complex'] = theme('image', array(
    'path' => drupal_get_path('module', 'mark_picture') . '/images/centre.png',
    'title' => t('add picture'),
    'width' => '25px',
    'attributes' => array (
      'class' => array('tool-add', 'tool-add-complex'),
    ),
  ));

  $vars['tool_add_section'] = theme('image', array(
    'path' => drupal_get_path('module', 'mark_picture') . '/images/centre.png',
    'title' => t('add picture'),
    'width' => '25px',
    'attributes' => array (
      'class' => array('tool-add', 'tool-add-section'),
    ),
  ));
  if (!empty($vars['form']['field_home_plan']['und'][0]['#entity']->field_home_plan)){
    $vars['image_home_plan'] = theme('image', array(
      'path' => $vars['form']['field_home_plan']['und'][0]['#entity']->field_home_plan['und'][0]['uri'],
      'attributes' => array (
      ),
    ));
  }

  foreach($vars['form']['field_home_section']['und'] as $key => $val) {
    if(!empty($val['#entity']->field_number_section)) {
      $position = json_decode($val['#entity']->field_lage_plan_home['und'][0]['value']);
      $vars['sections'][$key] = '<div id="section-'.$val['#entity']->field_number_section['und'][0]['value'].'-'.$key.'" class="mark section section-'.$val['#entity']->field_number_section['und'][0]['value'].'"
                 style="position: absolute; left:'.$position->left.'%; top:'.$position->top.'% ; z-index: 100;">
                 '.$val['#entity']->field_number_section['und'][0]['value'].'
               </div>';
    }
  }

}