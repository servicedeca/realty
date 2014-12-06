<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_apartment_home_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Apartment home'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_apartment_home_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = menu_get_object('node', 1);
  $tid = $node->field_apartament_home['und'][0]['tid'];
  $block = new stdClass();

  $view = views_get_view('apartments');
  $view->set_display('apartment_home');
  $view->preview = TRUE;
  $view->display_handler->options['arguments']['tid']['default_argument_options']['argument'] = $tid;
  $view->pre_execute(array());
  $block->content = $view->display_handler->preview();
  $view->post_execute();

  return $block;
}
