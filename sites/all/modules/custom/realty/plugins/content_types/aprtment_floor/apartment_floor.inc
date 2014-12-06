<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_apartment_floor_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Apartment floor'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_apartment_floor_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = menu_get_object('node', 1);
  $floor = $node->field_apartment_floor['und'][0]['value'];
  $tid = $node->field_apartament_home['und'][0]['tid'];
  $block = new stdClass();

  $view = views_get_view('apartments');
  $view->set_display('apartment_floor');
  $view->preview = TRUE;
  $view->display_handler->options['arguments']['tid']['default_argument_options']['argument'] = $tid;
  $view->display_handler->options['filters']['field_apartment_floor_value']['value']['value'] = $floor;
  $view->pre_execute(array());
  $block->content = $view->display_handler->preview();
  $view->post_execute();

  return $block;
}
