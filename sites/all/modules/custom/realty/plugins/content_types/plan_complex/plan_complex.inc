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
  foreach ($homes as $key => $home) {
    if(!empty($home->field_field_lage_plan_complex)) {
      $position = json_decode($home->field_field_lage_plan_complex[0]['raw']['value']);
      $vars['homes'][$home->tid] = array(
        'number' => l($key+1, '#href', array(
          'external' => TRUE,
          'attributes' => array(
            'class' => array('a-dom', 'plan-complex-home'),
            'id' => 'home-'.$home->tid,
            'style' => 'position: absolute; top: '.$position->top.'%; left:'. $position->left.'% ',
          ),
        )),
      );

    }

  }

}
