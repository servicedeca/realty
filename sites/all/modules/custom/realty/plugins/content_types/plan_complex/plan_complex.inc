<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_plan_complex_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Plan complex '),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_plan_complex_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_plan_complex_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_plan_complex');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_plan_complex_content_type_theme(&$theme, $plugin) {
  $theme['realty_plan_complex'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-plan-complex',
  );
}

/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_plan_complex(&$vars) {
  $nid = arg(1);
  $node = node_load($nid);
  if (!empty($node->field_plan_complex)) {
    $vars['complex_plan'] = theme('image', array(
      'path' => $node->field_plan_complex[LANGUAGE_NONE][0]['uri'],
      'title' => $node->title,
    ));
  }

  $homes = views_get_view_result('term_view', 'homes_complex', $node->nid);

  $vars['deadline_description'] = $node->field_deadline_description[LANGUAGE_NONE][0]['value'];
  foreach ($homes as $key => $home) {

    if(!empty($home->field_field_lage_plan_complex) && !empty($home->field_field_home_plan)) {
      $position = json_decode($home->field_field_lage_plan_complex[0]['raw']['value']);
      $vars['homes'][$home->tid] = array(
        'tid' => $home->tid,
        'number' => l($key+1, '#href', array(
          'external' => TRUE,
          'attributes' => array(
            'class' => array('a-dom', 'plan-complex-home'),
            'id' => 'home-'.$home->tid,
            'style' => 'position: absolute; top: '.$position->top.'%; left:'. $position->left.'% ',
          ),
        )),
        'description' => $home->taxonomy_term_data_description,
        'plan' => theme('image', array(
          'path' => $home->field_field_home_plan[0]['raw']['uri'],
          'title' => $home->field_field_address_house[0]['rendered']['#markup'],
        )),
      );
    }
  }

  foreach ($homes as $key => $section) {
    if(!empty($section->field_field_lage_plan_complex)) {
      $position_section = json_decode($section->field_field_lage_plan_home[0]['raw']['value']);
      $vars['sections'][] = array(
        'home_tid' => $section->tid,
        'number' => $section->field_field_number_section[0]['raw']['value'],
        'section' => l($section->field_field_number_section[0]['raw']['value'], '#href', array(
          'external' => TRUE,
          'attributes' => array(
            'class' => array('a-section', 'plan-complex-home-section'),
            'id' => 'section-'.$home->tid.'-'.$home->field_field_number_section[0]['raw']['value'],
            'style' => 'position: absolute; top: '.$position_section->top.'%; left:'. $position_section->left.'% ',
          ),
        )),
      );
    }
  }
  $a = 1;
}
