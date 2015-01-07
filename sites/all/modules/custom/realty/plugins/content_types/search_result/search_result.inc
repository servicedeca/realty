<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_search_result_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Search result'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_search_result_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $view = views_get_view('apartments');
  $view->set_display('result_search');
  if(isset($_GET['selectAllarea'][0]) || !isset($_GET['area'])) {
    unset($view->display_handler->options['filters']['field_area_tid']);
  }
  else {
    foreach($_GET['area'] as $area) {
      $view->display_handler->options['filters']['field_area_tid']['value'][$area] = $area;
    }
  }

  if(isset($_GET['selectAllmasonry'][0]) || !isset($_GET['masonry'])) {
    unset($view->display_handler->options['filters']['field_masonry_value']);
  }
  else {
    unset($view->display_handler->options['filters']['field_masonry_value']['value']);
    foreach($_GET['masonry'] as $masonry){
      $view->display_handler->options['filters']['field_masonry_value']['value'][$masonry] = $masonry;
    }
  }

  if(isset($_GET['selectAllcategory'][0]) || !isset($_GET['category'])) {
    unset($view->display_handler->options['filters']['field_category_value']);
  }
  else {
    unset($view->display_handler->options['filters']['field_category_value']['value']);
    foreach($_GET['category'] as $category){
      $view->display_handler->options['filters']['field_category_value']['value'][$category] = $category;
    }
  }

  if(empty($_GET['floor']) || $_GET['floor'] == 0) {
    unset($view->display_handler->options['filters']['field_apartment_floor_value']);
  }
  else {
    $view->display_handler->options['filters']['field_apartment_floor_value']['value']['value'] = $_GET['floor'];
  }
  if(isset($_GET['selectAllroom'][0]) || !isset($_GET['room'])) {
    unset($view->display_handler->options['filters']['field_number_rooms_value']);
  }
  else {
    foreach($_GET['room'] as $room) {
      $view->display_handler->options['filters']['field_number_rooms_value']['value'][$room] = $room;
    }
  }
  if(empty($_GET['sq_from']) && empty($_GET['sq_to'])) {
    unset($view->display_handler->options['filters']['field_gross_area_value']);
  }
  else {
    $view->display_handler->options['filters']['field_gross_area_value']['value']['min'] = $_GET['sq_from'];
    $view->display_handler->options['filters']['field_gross_area_value']['value']['max'] = $_GET['sq_to'];
  }

  if(empty($_GET['price_from']) && empty($_GET['price_to'])) {
   unset($view->display_handler->options['filters']['field_price_value']);
  }
  else {
    $view->display_handler->options['filters']['field_price_value']['value']['min'] = $_GET['price_from'];
    $view->display_handler->options['filters']['field_price_value']['value']['max'] = $_GET['price_to'];
  }
  if(!isset($_GET['parking'])) {
    unset($view->display_handler->options['filters']['field_parking_value']);
  }
  if(empty($_GET['coast_from']) && empty($_GET['coast_to'])) {
    unset($view->display_handler->options['filters']['field_full_cost_value']);
  }
  else {
    $view->display_handler->options['filters']['field_full_cost_value']['value']['min'] = $_GET['coast_from'];
    $view->display_handler->options['filters']['field_full_cost_value']['value']['max'] = $_GET['coast_to'];
  }
  if(isset($_GET['selectAlldeveloper']) || !isset($_GET['developer'])) {
    unset($view->display_handler->options['filters']['field_complex_developer_tid']);
  }
  else {
    unset($view->display_handler->options['filters']['field_complex_developer_tid']['value']);
    foreach($_GET['developer'] as $value) {
      $view->display_handler->options['filters']['field_complex_developer_tid']['value'][$value] = $value;
    }
  }
  if(isset($_GET['year'])) {
    unset($view->display_handler->options['filters']['field_complex_developer_tid']['value']);
    $view->display_handler->options['filters']['field_complex_developer_tid']['value'] = $_GET['year'];
  }
  else {
    $view->display_handler->options['filters']['field_complex_developer_tid'];
  }
  if(isset($_GET['selectAllquarter']) || !isset($_GET['quarter'])) {
    unset($view->display_handler->options['filters']['field_quarter_value']['value']);
  }
  else {
    unset($view->display_handler->options['filters']['field_quarter_value']['value']);
    foreach($_GET['quarter'] as $value) {
      $view->display_handler->options['filters']['field_quarter_value']['value'][$value] = $value;
    }
  }
  if(empty($_GET['year']) && empty($_GET['year'])) {
    unset($view->display_handler->options['filters']['field_year_value']);
  }
  else {
    $view->display_handler->options['filters']['field_year_value']['value']['value'] = $_GET['year'];
  }
  $view->pre_execute(array());
  $block->content = $view->display_handler->preview();
  $view->post_execute();

  return $block;
}
