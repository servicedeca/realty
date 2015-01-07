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

  $vars['search_map_form'] = drupal_get_form('realty_search_map_form');

  $view = views_get_view('map');
  $view->set_display('main_map');
  //$view->display_handler->options['filters']['field_area_city_tid']['value'] = $city_tid;
  $view->pre_execute(array());
  $view->display_handler->preview();
  $view->post_execute();
//  $view = views_embed_view('map', 'main_map');
  $vars['map'] = $view->display_handler->output;

}