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
    'title' => t('Plan complex'),
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
  $c = 0;
  if (!empty($node->field_plan_complex)) {
    $vars['complex_plan'] = theme('image', array(
      'path' => $node->field_plan_complex[LANGUAGE_NONE][0]['uri'],
      'title' => $node->title,
    ));
  }
  $apartment_complex = views_get_view_result('apartments', 'apartments_complex_for_plan', $node->nid);
  $homes = views_get_view_result('term_view', 'homes_complex', $node->nid);

  $vars['deadline_description'] = $node->field_deadline_description[LANGUAGE_NONE][0]['value'];
  foreach ($homes as $key => $home) {

    if (!empty($home->field_field_lage_plan_complex) && !empty($home->field_field_home_plan)) {
      $position = json_decode($home->field_field_lage_plan_complex[0]['raw']['value']);
      $vars['homes'][$home->tid] = array(
        'tid' => $home->tid,
        'number' => l($home->field_field_number_home[0]['raw']['value'], '#href', array(
          'external' => TRUE,
          'attributes' => array(
            'class' => array('a-dom', 'plan-complex-home'),
            'id' => 'home-' . $home->tid,
            'style' => 'position: absolute; top: ' . $position->top . '%; left:' . $position->left . '% ',
          ),
        )),
        'description' => $home->taxonomy_term_data_description,
        'plan' => theme('image', array(
          'path' => $home->field_field_home_plan[0]['raw']['uri'],
          'title' => $home->field_field_address_house[0]['rendered']['#markup'],
        )),
      );

      if ($home->field_field_number_section[0]['raw']['value'] == $home->field_field_plan_number_section[0]['raw']['value']) {
        $position_section = json_decode($home->field_field_lage_plan_home[0]['raw']['value']);
        $vars['sections'][$home->field_field_number_section[0]['raw']['value'] . '-' . $home->tid] = array(
          'home_tid' => $home->tid,
          'number' => $home->field_field_number_section[0]['raw']['value'],
          'section' => l($home->field_field_number_section[0]['raw']['value'], '#href', array(
            'external' => TRUE,
            'attributes' => array(
              'class' => array('a-section', 'plan-complex-home-section'),
              'id' => 'section-' . $home->tid . '-' . $home->field_field_number_section[0]['raw']['value'] . '-1',
              'style' => 'position: absolute; top: ' . $position_section->top . '%; left:' . $position_section->left . '% ',
            ),
          )),
        );

        if (substr_count($home->field_field_plan_number_floor[0]['raw']['value'], ',') > 0) {
          $floors = explode(',', $home->field_field_plan_number_floor[0]['raw']['value']);
          foreach ($floors as $floor) {
            $vars['floors'][] = array(
              'home_tid' => $home->tid,
              'number_section' => $home->field_field_plan_number_section[0]['raw']['value'],
              'number_floor' => $floor,
              'number_floor_link' => l($floor . '-' . t('floor'), '#href', array(
                'external' => TRUE,
                'attributes' => array(
                  'class' => array('plan-complex-home-section'),
                  'id' => 'floor-' . $home->tid . '-' . $home->field_field_number_section[0]['raw']['value'] . '-' . $floor,
                ),
              )),
              'plan_floor' => theme('image', array(
                //'style_name' => 'realty_plan_floor',
                'path' => $home->field_field_image_plan_floor[0]['raw']['uri'],
                'attributes' => array(
                  'class' => array('vertical-flat-image'),
                ),
              )),
            );
            $a=1;
          }
        }

        if (substr_count($home->field_field_plan_number_floor[0]['raw']['value'], '-') > 0) {
          $floors = explode('-', $home->field_field_plan_number_floor[0]['raw']['value']);
          for ($i = $floors[0]; $i <= $floors[1]; $i++) {
            $vars['floors'][] = array(
              'home_tid' => $home->tid,
              'number_section' => $home->field_field_plan_number_section[0]['raw']['value'],
              'number_floor' => $i,
              'number_floor_link' => l($i . '-' . t('floor'), '#href', array(
                'external' => TRUE,
                'attributes' => array(
                  'class' => array('plan-complex-home-section'),
                  'id' => 'floor-' . $home->tid . '-' . $home->field_field_number_section[0]['raw']['value'] . '-' . $i,
                ),
              )),
              'plan_floor' => theme('image', array(
                //'style_name' => 'realty_plan_floor',
                'path' => $home->field_field_image_plan_floor[0]['raw']['uri'],
                'attributes' => array(
                  'class' => array('vertical-flat-image'),
                ),
              )),
            );
          }
        }

        if (substr_count($home->field_field_plan_number_floor[0]['raw']['value'], ',') == 0) {
          if (substr_count($home->field_field_plan_number_floor[0]['raw']['value'], '-') == 0) {

            $vars['floors'][] = array(
              'home_tid' => $home->tid,
              'number_section' => $home->field_field_plan_number_section[0]['raw']['value'],
              'number_floor' => $home->field_field_plan_number_floor[0]['raw']['value'],
              'number_floor_link' => l($home->field_field_plan_number_floor[0]['raw']['value'] . '-' . t('floor'), '#href', array(
                'external' => TRUE,
                'attributes' => array(
                  'class' => array('plan-complex-home-section'),
                  'id' => 'floor-' . $home->tid . '-' . $home->field_field_number_section[0]['raw']['value'] . '-' . $home->field_field_plan_number_floor[0]['raw']['value'],
                ),
              )),
              'plan_floor' => theme('image', array(
                //'style_name' => 'realty_plan_floor',
                'path' => $home->field_field_image_plan_floor[0]['raw']['uri'],
                'attributes' => array(
                    'class' => array('vertical-flat-image'),
                  ),
                )),
            );

          }
        }
      }
      if (!empty($home->field_field_apartments)) {
        $apartments =  $home->field_field_apartments[0]['raw']['value'];
        $apartments = json_decode($apartments);
        foreach ($apartment_complex as $apartment) {
          foreach ($apartments as $apart) {
            foreach ($apart as $ap) {
              if ($ap->apartment == $apartment->field_field_number_apartament[0]['raw']['value']) {
                if ($ap->floor == $apartment->field_field_apartment_floor[0]['raw']['value']) {
                 $c++;
                 $vars['apartmens'][$c] = array(
                   'home' => $home->tid,
                   'section' => $apartment->field_field_section[0]['raw']['value'],
                   'floor' => $ap->floor,
                   'number' => $ap->apartment,
                   'link' => l($ap->apartment, 'node/' . $apartment->nid, array('attributes' => array(
                     'class' => array('a-section'),
                     'style' => 'position: absolute; top: ' . $ap->top . '%; left:' . $ap->left . '% ',
                   ))),
                 );
                }
              }
            }
          }
        }

      }
    }
  }
  $a = 1;
}
