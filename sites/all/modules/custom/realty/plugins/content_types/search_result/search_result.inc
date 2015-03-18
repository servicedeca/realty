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

  if (isset($_GET['price'])) {
    $pricemin = explode(";", $_GET['price']);
    $pricemax = explode(";", $_GET['price']);
    $data['priceMin'] = $pricemin[0] * 1000;
    if ($pricemax[1] == 100){
      $data['priceMax'] = $pricemax[1] * 100000;
    }
    else {
      $data['priceMax'] = $pricemax[1] * 1000;
    }
  }
  if (isset($_GET['sq'])) {
    $sqmin = explode(";", $_GET['sq']);
    $sqmax = explode(";", $_GET['sq']);
    $data['sqMin'] = $sqmin[0];
    if ($sqmax[1] == 200){
      $data['sqMax'] = $sqmax[1] * 10;
    }
    else {
      $data['sqMax'] = $sqmax[1];
    }
  }
  if (isset($_GET['coast'])) {
    $coastmin = explode(";", $_GET['coast']);
    $coastmax = explode(";", $_GET['coast']);
    $data['coastMin'] = $coastmin[0] * 1000000;
    $data['coastMax'] = $coastmax[1] * 1000000;
    if ($coastmax[1] == 5){
      $data['coastMax'] = $coastmax[1] * 100000000;
    }
    else {
      $data['coastMax'] = $coastmax[1] * 1000000;
    }
  }

  $view = views_get_view('apartments');
  $view->set_display('result_search');
  if (!isset($_GET['area'])) {
    unset($view->display_handler->options['filters']['field_area_tid']);
  }
  else {
    foreach($_GET['area'] as $area) {
      $view->display_handler->options['filters']['field_area_tid']['value'][$area] = $area;
    }
  }

  if(!isset($_GET['metro'])) {
    unset($view->display_handler->options['filters']['field_complex_metro_tid']);
  }
  else {
    foreach($_GET['metro'] as $metro) {
      $view->display_handler->options['filters']['field_complex_metro_tid']['value'][$metro] = $metro;
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
  if(empty($_GET['sq'])) {
    unset($view->display_handler->options['filters']['field_gross_area_value']);
  }
  else {
    $view->display_handler->options['filters']['field_gross_area_value']['value']['min'] = $data['sqMin'];
    $view->display_handler->options['filters']['field_gross_area_value']['value']['max'] = $data['sqMax'];
  }

  if(empty($_GET['price'])) {
   unset($view->display_handler->options['filters']['field_price_value']);
  }
  else {
    $view->display_handler->options['filters']['field_price_value']['value']['min'] = $data['priceMin'];
    $view->display_handler->options['filters']['field_price_value']['value']['max'] = $data['priceMax'];
  }
  if(!isset($_GET['parking'])) {
    unset($view->display_handler->options['filters']['field_parking_value']);
  }
  if(empty($_GET['coast'])) {
    unset($view->display_handler->options['filters']['field_full_cost_value']);
  }
  else {
    $view->display_handler->options['filters']['field_full_cost_value']['value']['min'] = $data['coastMin'];
    $view->display_handler->options['filters']['field_full_cost_value']['value']['max'] = $data['coastMax'];
  }
  if (isset($_GET['selectAlldeveloper']) || !isset($_GET['developer'])) {
    unset($view->display_handler->options['filters']['field_complex_developer_tid']);
  }
  else {
    unset ($view->display_handler->options['filters']['field_complex_developer_tid']['value']);
    foreach ($_GET['developer'] as $value) {
      $view->display_handler->options['filters']['field_complex_developer_tid']['value'][$value] = $value;
    }
  }
  if (isset($_GET['selectAllcomplex']) || !isset($_GET['complex'])) {
    unset($view->display_handler->options['filters']['field_home_complex_target_id']);
  }
  else {
    unset ($view->display_handler->options['filters']['field_home_complex_target_id']['value']);
    foreach ($_GET['complex'] as $value) {
      $view->display_handler->options['filters']['field_home_complex_target_id']['value'][$value] = $value;
    }
  }
  if(isset($_GET['year']) && $_GET['year'] != '') {
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

  if($_GET['selectAllbalcony'] || !$_GET['balcony']) {
    unset($view->display_handler->options['filters']['field_balcony_value']);
    unset($view->display_handler->options['filters']['field_loggia_value']);
  }
  else {
    if($_GET['balcony'][0] && $_GET['balcony'][0] == 1){
      unset($view->display_handler->options['filters']['field_loggia_value']['value']);
      $view->display_handler->options['filters']['field_loggia_value']['value'][1] = 1;
    }
    if($_GET['balcony'][0] && $_GET['balcony'][0] == 2){
      unset($view->display_handler->options['filters']['field_balcony_value']['value']);
      $view->display_handler->options['filters']['field_balcony_value']['value'][1] = 1;
    }
  }

  $view->pre_execute(array());
  $block->content = $view->display_handler->preview();
  $view->post_execute();

    $a =1;
  return $block;
}
