<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_front_map_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Front_map'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_front_map_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_front_map_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_front_map');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_front_map_content_type_theme(&$theme, $plugin) {
  $theme['realty_front_map'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-front-map',
  );
}

/**
 * Process variables for realty-front-map.tpl.php.
 */
function template_preprocess_realty_front_map(&$vars) {

  $city = menu_get_object('taxonomy_term', 2);

  $vars['image_map'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/minihome.png',
    'attributes' => array(
      'class' => array('minihome'),
    ),
  ));

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));

  $complex = views_get_view_result('complex', 'random_complex');
  if (!empty($complex)) {
    $vars['title'] =  $complex[0]->node_title;

    if (!empty($complex[0]->field_field_main_photo)) {
      $vars['image'] =  theme('image', array(
        'path' => $complex[0]->field_field_main_photo[0]['raw']['uri'],
        'title' => $complex[0]->node_title,
        'alt' => $complex[0]->node_title,
        'attributes' => array(
          'class' => array('title-image'),
        ),
      ));
    }

    if (!empty($complex[0]->field_field_complex_logo)) {
      $vars['logo'] =  theme('image', array(
        'path' => $complex[0]->field_field_complex_logo[0]['raw']['uri'],
        'title' => $complex[0]->node_title,
        'alt' => $complex[0]->node_title,
        'attributes' => array(
          'class' => array('logo-z', 'vertical-logo'),
        ),
      ));
    }

    $vars['areas'] = realty_get_options_current_city('area');

    $vars['search_map_form'] = drupal_get_form('realty_search_map_form');

    unset($vars['search_map_form']['category']['#title']);

    if (!empty($complex[0]->field_field_description)) {
      $vars['description'] = $complex[0]->field_field_description[0]['raw']['value'];
    }

    $vars['details'] = l('details', 'node/' . $complex[0]->nid, array('attributes' => array('class' => array(
      'button-info','button-info-top')
    )));
  }

  $view = views_embed_view('map', 'map_city');

  $vars['map'] = $view;

}