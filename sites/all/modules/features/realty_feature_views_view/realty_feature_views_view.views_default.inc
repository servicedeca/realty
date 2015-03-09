<?php
/**
 * @file
 * realty_feature_views_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function realty_feature_views_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'apartments';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Квартиры';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Содержимое: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  /* Связь: Содержимое: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Главное изображение */
  $handler->display->display_options['fields']['field_main_photo']['id'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['table'] = 'field_data_field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['field'] = 'field_main_photo';
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'apartament' => 'apartament',
  );
  /* Критерий фильтра: Содержимое: Дом (field_apartament_home) */
  $handler->display->display_options['filters']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['filters']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['operator_id'] = 'field_apartament_home_tid_op';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['label'] = 'Дом (field_apartament_home)';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['operator'] = 'field_apartament_home_tid_op';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['identifier'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_apartament_home_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_apartament_home_tid']['vocabulary'] = 'homes';
  /* Критерий фильтра: Содержимое: Количество комнат (field_number_rooms) */
  $handler->display->display_options['filters']['field_number_rooms_value']['id'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['filters']['field_number_rooms_value']['field'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator_id'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['label'] = 'Количество комнат (field_number_rooms)';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['identifier'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Квартиры застройщика */
  $handler = $view->new_display('panel_pane', 'Квартиры застройщика', 'apartment_developer');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Главное изображение */
  $handler->display->display_options['fields']['field_main_photo']['id'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['table'] = 'field_data_field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['field'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_photo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Поле: Содержимое: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  /* Поле: Содержимое: Дом */
  $handler->display->display_options['fields']['field_apartament_home']['id'] = 'field_apartament_home';
  $handler->display->display_options['fields']['field_apartament_home']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['fields']['field_apartament_home']['field'] = 'field_apartament_home';
  /* Поле: Содержимое: Жилая площадь */
  $handler->display->display_options['fields']['field_living_space']['id'] = 'field_living_space';
  $handler->display->display_options['fields']['field_living_space']['table'] = 'field_data_field_living_space';
  $handler->display->display_options['fields']['field_living_space']['field'] = 'field_living_space';
  $handler->display->display_options['fields']['field_living_space']['type'] = 'text_default';
  /* Поле: Содержимое: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area']['id'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['field'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['type'] = 'text_default';
  /* Поле: Содержимое: Срок сдачи */
  $handler->display->display_options['fields']['field_deadline']['id'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['table'] = 'field_data_field_deadline';
  $handler->display->display_options['fields']['field_deadline']['field'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['settings'] = array(
    'edit' => 'Правка',
    'delete' => 'Удалить',
    'add' => 'Добавить',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Статус (field_status) */
  $handler->display->display_options['filters']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['filters']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Квартиры жилого комплекса */
  $handler = $view->new_display('panel_pane', 'Квартиры жилого комплекса', 'apartment_complex');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  /* Поле: Термин таксономии: Адрес */
  $handler->display->display_options['fields']['field_address_house']['id'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['table'] = 'field_data_field_address_house';
  $handler->display->display_options['fields']['field_address_house']['field'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['relationship'] = 'field_apartament_home_tid';
  /* Поле: Содержимое: Секция */
  $handler->display->display_options['fields']['field_section']['id'] = 'field_section';
  $handler->display->display_options['fields']['field_section']['table'] = 'field_data_field_section';
  $handler->display->display_options['fields']['field_section']['field'] = 'field_section';
  /* Поле: Содержимое: Количество комнат */
  $handler->display->display_options['fields']['field_number_rooms']['id'] = 'field_number_rooms';
  $handler->display->display_options['fields']['field_number_rooms']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['fields']['field_number_rooms']['field'] = 'field_number_rooms';
  /* Поле: Содержимое: Этаж */
  $handler->display->display_options['fields']['field_apartment_floor']['id'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['field'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['label'] = '';
  $handler->display->display_options['fields']['field_apartment_floor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_apartment_floor']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Поле: Содержимое: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area']['id'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['field'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['type'] = 'text_default';
  /* Поле: Содержимое: Цена за кв.м */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['type'] = 'text_default';
  /* Поле: Содержимое: Стоимость */
  $handler->display->display_options['fields']['field_full_cost']['id'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['field'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Статус */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Этаж (field_apartment_floor) */
  $handler->display->display_options['sorts']['field_apartment_floor_value']['id'] = 'field_apartment_floor_value';
  $handler->display->display_options['sorts']['field_apartment_floor_value']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['sorts']['field_apartment_floor_value']['field'] = 'field_apartment_floor_value';
  $handler->display->display_options['sorts']['field_apartment_floor_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_apartment_floor_value']['expose']['label'] = 'Этаж (field_apartment_floor)';
  /* Критерий сортировки: Содержимое: Общая площадь (field_gross_area) */
  $handler->display->display_options['sorts']['field_gross_area_value']['id'] = 'field_gross_area_value';
  $handler->display->display_options['sorts']['field_gross_area_value']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['sorts']['field_gross_area_value']['field'] = 'field_gross_area_value';
  $handler->display->display_options['sorts']['field_gross_area_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_gross_area_value']['expose']['label'] = 'Общая площадь (field_gross_area)';
  /* Критерий сортировки: Содержимое: Цена за кв.м (field_price) */
  $handler->display->display_options['sorts']['field_price_value']['id'] = 'field_price_value';
  $handler->display->display_options['sorts']['field_price_value']['table'] = 'field_data_field_price';
  $handler->display->display_options['sorts']['field_price_value']['field'] = 'field_price_value';
  $handler->display->display_options['sorts']['field_price_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_price_value']['expose']['label'] = 'Цена за кв.м (field_price)';
  /* Критерий сортировки: Содержимое: Стоимость (field_full_cost) */
  $handler->display->display_options['sorts']['field_full_cost_value']['id'] = 'field_full_cost_value';
  $handler->display->display_options['sorts']['field_full_cost_value']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['sorts']['field_full_cost_value']['field'] = 'field_full_cost_value';
  $handler->display->display_options['sorts']['field_full_cost_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_full_cost_value']['expose']['label'] = 'Стоимость (field_full_cost)';
  /* Критерий сортировки: Глобальный: Случайно */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['sorts']['random']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['random']['expose']['label'] = 'Случайно';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Редакции материала: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'apartament' => 'apartament',
  );
  /* Критерий фильтра: Содержимое: Дом (field_apartament_home) */
  $handler->display->display_options['filters']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['filters']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['operator_id'] = 'field_apartament_home_tid_op';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['label'] = 'Дом (field_apartament_home)';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['operator'] = 'field_apartament_home_tid_op';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['identifier'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_apartament_home_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_apartament_home_tid']['vocabulary'] = 'homes';
  /* Критерий фильтра: Содержимое: Количество комнат (field_number_rooms) */
  $handler->display->display_options['filters']['field_number_rooms_value']['id'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['filters']['field_number_rooms_value']['field'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator_id'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['label'] = 'Количество комнат (field_number_rooms)';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['identifier'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Критерий фильтра: Содержимое: Этаж (field_apartment_floor) */
  $handler->display->display_options['filters']['field_apartment_floor_value']['id'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['filters']['field_apartment_floor_value']['field'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['operator_id'] = 'field_apartment_floor_value_op';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['label'] = 'Этаж (field_apartment_floor)';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['operator'] = 'field_apartment_floor_value_op';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['identifier'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_apartment_floor_value']['group_info']['label'] = 'Этаж (field_apartment_floor)';
  $handler->display->display_options['filters']['field_apartment_floor_value']['group_info']['identifier'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_apartment_floor_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Критерий фильтра: Содержимое: Общая площадь (field_gross_area) */
  $handler->display->display_options['filters']['field_gross_area_value']['id'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['filters']['field_gross_area_value']['field'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_gross_area_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['operator_id'] = 'field_gross_area_value_op';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['label'] = 'Общая площадь (field_gross_area)';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['operator'] = 'field_gross_area_value_op';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['identifier'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Критерий фильтра: Содержимое: Секция (field_section) */
  $handler->display->display_options['filters']['field_section_value']['id'] = 'field_section_value';
  $handler->display->display_options['filters']['field_section_value']['table'] = 'field_data_field_section';
  $handler->display->display_options['filters']['field_section_value']['field'] = 'field_section_value';
  $handler->display->display_options['filters']['field_section_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_section_value']['expose']['operator_id'] = 'field_section_value_op';
  $handler->display->display_options['filters']['field_section_value']['expose']['label'] = 'Секция (field_section)';
  $handler->display->display_options['filters']['field_section_value']['expose']['operator'] = 'field_section_value_op';
  $handler->display->display_options['filters']['field_section_value']['expose']['identifier'] = 'field_section_value';
  $handler->display->display_options['filters']['field_section_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_section_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Квартира */
  $handler = $view->new_display('panel_pane', 'Квартира', 'apartment');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Дом */
  $handler->display->display_options['fields']['field_apartament_home']['id'] = 'field_apartament_home';
  $handler->display->display_options['fields']['field_apartament_home']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['fields']['field_apartament_home']['field'] = 'field_apartament_home';
  $handler->display->display_options['fields']['field_apartament_home']['type'] = 'taxonomy_term_reference_plain';
  /* Поле: Содержимое: Район */
  $handler->display->display_options['fields']['field_area']['id'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['table'] = 'field_data_field_area';
  $handler->display->display_options['fields']['field_area']['field'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['fields']['field_area']['type'] = 'taxonomy_term_reference_plain';
  /* Поле: Содержимое: Срок сдачи */
  $handler->display->display_options['fields']['field_deadline']['id'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['table'] = 'field_data_field_deadline';
  $handler->display->display_options['fields']['field_deadline']['field'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['fields']['field_deadline']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_deadline']['settings'] = array(
    'view_mode' => 'full',
  );
  /* Поле: Содержимое: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area_1']['id'] = 'field_gross_area_1';
  $handler->display->display_options['fields']['field_gross_area_1']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area_1']['field'] = 'field_gross_area';
  /* Поле: Содержимое: Балкон */
  $handler->display->display_options['fields']['field_balcony']['id'] = 'field_balcony';
  $handler->display->display_options['fields']['field_balcony']['table'] = 'field_data_field_balcony';
  $handler->display->display_options['fields']['field_balcony']['field'] = 'field_balcony';
  /* Поле: Содержимое: Главное изображение */
  $handler->display->display_options['fields']['field_main_photo']['id'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['table'] = 'field_data_field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['field'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['fields']['field_main_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_photo']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Поле: Содержимое: Лоджия */
  $handler->display->display_options['fields']['field_loggia']['id'] = 'field_loggia';
  $handler->display->display_options['fields']['field_loggia']['table'] = 'field_data_field_loggia';
  $handler->display->display_options['fields']['field_loggia']['field'] = 'field_loggia';
  /* Поле: Термин таксономии: Жилой комплекс */
  $handler->display->display_options['fields']['field_home_complex']['id'] = 'field_home_complex';
  $handler->display->display_options['fields']['field_home_complex']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['fields']['field_home_complex']['field'] = 'field_home_complex';
  $handler->display->display_options['fields']['field_home_complex']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['fields']['field_home_complex']['settings'] = array(
    'link' => 1,
  );
  /* Поле: Содержимое: Застройщик */
  $handler->display->display_options['fields']['field_complex_developer']['id'] = 'field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['field'] = 'field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['relationship'] = 'field_home_complex_target_id';
  /* Поле: Содержимое: Планировка квартиры */
  $handler->display->display_options['fields']['field_plan_apartment']['id'] = 'field_plan_apartment';
  $handler->display->display_options['fields']['field_plan_apartment']['table'] = 'field_data_field_plan_apartment';
  $handler->display->display_options['fields']['field_plan_apartment']['field'] = 'field_plan_apartment';
  $handler->display->display_options['fields']['field_plan_apartment']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_plan_apartment']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Поле: Содержимое: Документы */
  $handler->display->display_options['fields']['field_documents']['id'] = 'field_documents';
  $handler->display->display_options['fields']['field_documents']['table'] = 'field_data_field_documents';
  $handler->display->display_options['fields']['field_documents']['field'] = 'field_documents';
  $handler->display->display_options['fields']['field_documents']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['fields']['field_documents']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_documents']['delta_offset'] = '0';
  /* Поле: Содержимое: Этаж */
  $handler->display->display_options['fields']['field_apartment_floor']['id'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['field'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area']['id'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['field'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Жилая площадь */
  $handler->display->display_options['fields']['field_living_space']['id'] = 'field_living_space';
  $handler->display->display_options['fields']['field_living_space']['table'] = 'field_data_field_living_space';
  $handler->display->display_options['fields']['field_living_space']['field'] = 'field_living_space';
  $handler->display->display_options['fields']['field_living_space']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Стоимость */
  $handler->display->display_options['fields']['field_full_cost']['id'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['field'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Цена за кв.м */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Квартиры на этаже */
  $handler = $view->new_display('panel_pane', 'Квартиры на этаже', 'apartment_floor');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Предложения на этаже';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area']['id'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['field'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Стоимость */
  $handler->display->display_options['fields']['field_full_cost']['id'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['field'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = '00';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'apartament' => 'apartament',
  );
  /* Критерий фильтра: Содержимое: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['operator'] = '!=';
  $handler->display->display_options['filters']['nid']['value']['value'] = '0';
  /* Критерий фильтра: Содержимое: Этаж (field_apartment_floor) */
  $handler->display->display_options['filters']['field_apartment_floor_value']['id'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['filters']['field_apartment_floor_value']['field'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['value']['value'] = '0';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Квартиры в доме */
  $handler = $view->new_display('panel_pane', 'Квартиры в доме', 'apartment_home');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Предложения в этом доме';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area']['id'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['field'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Стоимость */
  $handler->display->display_options['fields']['field_full_cost']['id'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['field'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = '00';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'apartament' => 'apartament',
  );
  /* Критерий фильтра: Содержимое: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['operator'] = '!=';
  $handler->display->display_options['filters']['nid']['value']['value'] = '0';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Результаты поиска */
  $handler = $view->new_display('panel_pane', 'Результаты поиска', 'result_search');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  /* Связь: Содержимое: Срок сдачи (field_deadline) */
  $handler->display->display_options['relationships']['field_deadline_value']['id'] = 'field_deadline_value';
  $handler->display->display_options['relationships']['field_deadline_value']['table'] = 'field_data_field_deadline';
  $handler->display->display_options['relationships']['field_deadline_value']['field'] = 'field_deadline_value';
  $handler->display->display_options['relationships']['field_deadline_value']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_deadline_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  /* Поле: Содержимое: Район */
  $handler->display->display_options['fields']['field_area']['id'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['table'] = 'field_data_field_area';
  $handler->display->display_options['fields']['field_area']['field'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['relationship'] = 'field_home_complex_target_id';
  /* Поле: Содержимое: Застройщик */
  $handler->display->display_options['fields']['field_complex_developer']['id'] = 'field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['field'] = 'field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['relationship'] = 'field_home_complex_target_id';
  /* Поле: Термин таксономии: Жилой комплекс */
  $handler->display->display_options['fields']['field_home_complex']['id'] = 'field_home_complex';
  $handler->display->display_options['fields']['field_home_complex']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['fields']['field_home_complex']['field'] = 'field_home_complex';
  $handler->display->display_options['fields']['field_home_complex']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['fields']['field_home_complex']['settings'] = array(
    'link' => 0,
  );
  /* Поле: Термин таксономии: Адрес */
  $handler->display->display_options['fields']['field_address_house']['id'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['table'] = 'field_data_field_address_house';
  $handler->display->display_options['fields']['field_address_house']['field'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['relationship'] = 'field_apartament_home_tid';
  /* Поле: Элемент коллекции полей: Квартал */
  $handler->display->display_options['fields']['field_quarter']['id'] = 'field_quarter';
  $handler->display->display_options['fields']['field_quarter']['table'] = 'field_data_field_quarter';
  $handler->display->display_options['fields']['field_quarter']['field'] = 'field_quarter';
  $handler->display->display_options['fields']['field_quarter']['relationship'] = 'field_deadline_value';
  /* Поле: Элемент коллекции полей: Год */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['relationship'] = 'field_deadline_value';
  $handler->display->display_options['fields']['field_year']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Количество комнат */
  $handler->display->display_options['fields']['field_number_rooms']['id'] = 'field_number_rooms';
  $handler->display->display_options['fields']['field_number_rooms']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['fields']['field_number_rooms']['field'] = 'field_number_rooms';
  /* Поле: Содержимое: Этаж */
  $handler->display->display_options['fields']['field_apartment_floor']['id'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['field'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area']['id'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['field'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Цена за кв.м */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Стоимость */
  $handler->display->display_options['fields']['field_full_cost']['id'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['field'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Статус */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['label'] = '';
  $handler->display->display_options['fields']['field_status']['element_label_colon'] = FALSE;
  /* Поле: Термин таксономии: Количество этажей */
  $handler->display->display_options['fields']['field_number_floor']['id'] = 'field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['table'] = 'field_data_field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['field'] = 'field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['fields']['field_number_floor']['label'] = '';
  $handler->display->display_options['fields']['field_number_floor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_number_floor']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'apartament' => 'apartament',
  );
  /* Критерий фильтра: Содержимое: Район (field_area) */
  $handler->display->display_options['filters']['field_area_tid']['id'] = 'field_area_tid';
  $handler->display->display_options['filters']['field_area_tid']['table'] = 'field_data_field_area';
  $handler->display->display_options['filters']['field_area_tid']['field'] = 'field_area_tid';
  $handler->display->display_options['filters']['field_area_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_area_tid']['value'] = array(
    24 => '24',
  );
  $handler->display->display_options['filters']['field_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_area_tid']['vocabulary'] = 'area';
  /* Критерий фильтра: Термин таксономии: Материал стен (field_masonry) */
  $handler->display->display_options['filters']['field_masonry_value']['id'] = 'field_masonry_value';
  $handler->display->display_options['filters']['field_masonry_value']['table'] = 'field_data_field_masonry';
  $handler->display->display_options['filters']['field_masonry_value']['field'] = 'field_masonry_value';
  $handler->display->display_options['filters']['field_masonry_value']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_masonry_value']['value'] = array(
    1 => '1',
  );
  /* Критерий фильтра: Содержимое: Этаж (field_apartment_floor) */
  $handler->display->display_options['filters']['field_apartment_floor_value']['id'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['filters']['field_apartment_floor_value']['field'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['value']['value'] = '0';
  /* Критерий фильтра: Содержимое: Количество комнат (field_number_rooms) */
  $handler->display->display_options['filters']['field_number_rooms_value']['id'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['filters']['field_number_rooms_value']['field'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['value'] = array(
    1 => '1',
  );
  /* Критерий фильтра: Содержимое: Общая площадь (field_gross_area) */
  $handler->display->display_options['filters']['field_gross_area_value']['id'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['filters']['field_gross_area_value']['field'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_gross_area_value']['value']['min'] = '0';
  $handler->display->display_options['filters']['field_gross_area_value']['value']['max'] = '0';
  /* Критерий фильтра: Содержимое: Цена за кв.м (field_price) */
  $handler->display->display_options['filters']['field_price_value']['id'] = 'field_price_value';
  $handler->display->display_options['filters']['field_price_value']['table'] = 'field_data_field_price';
  $handler->display->display_options['filters']['field_price_value']['field'] = 'field_price_value';
  $handler->display->display_options['filters']['field_price_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_price_value']['value']['min'] = '0';
  $handler->display->display_options['filters']['field_price_value']['value']['max'] = '0';
  /* Критерий фильтра: Содержимое: Парковка (field_parking) */
  $handler->display->display_options['filters']['field_parking_value']['id'] = 'field_parking_value';
  $handler->display->display_options['filters']['field_parking_value']['table'] = 'field_data_field_parking';
  $handler->display->display_options['filters']['field_parking_value']['field'] = 'field_parking_value';
  $handler->display->display_options['filters']['field_parking_value']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_parking_value']['value'] = array(
    1 => '1',
  );
  /* Критерий фильтра: Содержимое: Стоимость (field_full_cost) */
  $handler->display->display_options['filters']['field_full_cost_value']['id'] = 'field_full_cost_value';
  $handler->display->display_options['filters']['field_full_cost_value']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['filters']['field_full_cost_value']['field'] = 'field_full_cost_value';
  $handler->display->display_options['filters']['field_full_cost_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_full_cost_value']['value']['min'] = '0';
  $handler->display->display_options['filters']['field_full_cost_value']['value']['max'] = '0';
  /* Критерий фильтра: Содержимое: Застройщик (field_complex_developer) */
  $handler->display->display_options['filters']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['filters']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_complex_developer_tid']['value'] = array(
    21 => '21',
  );
  $handler->display->display_options['filters']['field_complex_developer_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_complex_developer_tid']['vocabulary'] = 'developers';
  /* Критерий фильтра: Элемент коллекции полей: Квартал (field_quarter) */
  $handler->display->display_options['filters']['field_quarter_value']['id'] = 'field_quarter_value';
  $handler->display->display_options['filters']['field_quarter_value']['table'] = 'field_data_field_quarter';
  $handler->display->display_options['filters']['field_quarter_value']['field'] = 'field_quarter_value';
  $handler->display->display_options['filters']['field_quarter_value']['relationship'] = 'field_deadline_value';
  $handler->display->display_options['filters']['field_quarter_value']['value'] = array(
    1 => '1',
  );
  /* Критерий фильтра: Элемент коллекции полей: Год (field_year) */
  $handler->display->display_options['filters']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['filters']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['relationship'] = 'field_deadline_value';
  $handler->display->display_options['filters']['field_year_value']['value']['value'] = '1';
  /* Критерий фильтра: Термин таксономии: Категория (field_category) */
  $handler->display->display_options['filters']['field_category_value']['id'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['table'] = 'field_data_field_category';
  $handler->display->display_options['filters']['field_category_value']['field'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_category_value']['value'] = array(
    1 => '1',
  );
  /* Критерий фильтра: Термин таксономии: Жилой комплекс (field_home_complex) */
  $handler->display->display_options['filters']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['filters']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_home_complex_target_id']['value'] = array(
    4 => '4',
    5 => '5',
  );
  /* Критерий фильтра: Содержимое: Метро (field_complex_metro) */
  $handler->display->display_options['filters']['field_complex_metro_tid']['id'] = 'field_complex_metro_tid';
  $handler->display->display_options['filters']['field_complex_metro_tid']['table'] = 'field_data_field_complex_metro';
  $handler->display->display_options['filters']['field_complex_metro_tid']['field'] = 'field_complex_metro_tid';
  $handler->display->display_options['filters']['field_complex_metro_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_complex_metro_tid']['value'] = array(
    31 => '31',
  );
  $handler->display->display_options['filters']['field_complex_metro_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_complex_metro_tid']['vocabulary'] = 'metro';
  /* Критерий фильтра: Содержимое: Лоджия (field_loggia) */
  $handler->display->display_options['filters']['field_loggia_value']['id'] = 'field_loggia_value';
  $handler->display->display_options['filters']['field_loggia_value']['table'] = 'field_data_field_loggia';
  $handler->display->display_options['filters']['field_loggia_value']['field'] = 'field_loggia_value';
  $handler->display->display_options['filters']['field_loggia_value']['value'] = array(
    1 => '1',
  );
  /* Критерий фильтра: Содержимое: Балкон (field_balcony) */
  $handler->display->display_options['filters']['field_balcony_value']['id'] = 'field_balcony_value';
  $handler->display->display_options['filters']['field_balcony_value']['table'] = 'field_data_field_balcony';
  $handler->display->display_options['filters']['field_balcony_value']['field'] = 'field_balcony_value';
  $handler->display->display_options['filters']['field_balcony_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Полученные пользователем */
  $handler = $view->new_display('panel_pane', 'Полученные пользователем', 'user_apartment');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Связывающая сущность */
  $handler->display->display_options['relationships']['reverse_field_received_id_user']['id'] = 'reverse_field_received_id_user';
  $handler->display->display_options['relationships']['reverse_field_received_id_user']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_received_id_user']['field'] = 'reverse_field_received_id_user';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Пользователь: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'reverse_field_received_id_user';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Сравнение */
  $handler = $view->new_display('panel_pane', 'Сравнение', 'comprassion');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Связывающая сущность */
  $handler->display->display_options['relationships']['reverse_field_apartment_comparison_user']['id'] = 'reverse_field_apartment_comparison_user';
  $handler->display->display_options['relationships']['reverse_field_apartment_comparison_user']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_apartment_comparison_user']['field'] = 'reverse_field_apartment_comparison_user';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Пользователь: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'reverse_field_apartment_comparison_user';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['apartments'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('термин из field_apartament_home'),
    t('Сущность Содержимое связана через поле field_home_complex'),
    t('термин из field_complex_developer'),
    t('Главное изображение'),
    t('Все'),
    t('Дом (field_apartament_home)'),
    t('Количество комнат (field_number_rooms)'),
    t('Квартиры застройщика'),
    t('номер квартиры'),
    t('Дом'),
    t('Жилая площадь'),
    t('Общая площадь'),
    t('Срок сдачи'),
    t('Представления-Фрагменты'),
    t('Квартиры жилого комплекса'),
    t('Адрес'),
    t('Секция'),
    t('Количество комнат'),
    t('Цена за кв.м'),
    t('Стоимость'),
    t('Статус'),
    t('Этаж (field_apartment_floor)'),
    t('Общая площадь (field_gross_area)'),
    t('Цена за кв.м (field_price)'),
    t('Стоимость (field_full_cost)'),
    t('Случайно'),
    t('Секция (field_section)'),
    t('Квартира'),
    t('Район'),
    t('Балкон'),
    t('Лоджия'),
    t('Жилой комплекс'),
    t('Застройщик'),
    t('Планировка квартиры'),
    t('Документы'),
    t('Этаж'),
    t('Квартиры на этаже'),
    t('Предложения на этаже'),
    t('Квартиры в доме'),
    t('Предложения в этом доме'),
    t('Результаты поиска'),
    t('field collection item from field_deadline'),
    t('Квартал'),
    t('Год'),
    t('Полученные пользователем'),
    t('Пользователь ссылается на Содержимое через field_received_id'),
    t('Сравнение'),
    t('Пользователь ссылается на Содержимое через field_apartment_comparison'),
  );
  $export['apartments'] = $view;

  $view = new view();
  $view->name = 'comments_complex';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'Коментариии';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access comments';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Комментарий: Содержимое */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Поле: Комментарий: Заголовок */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = '';
  $handler->display->display_options['fields']['subject']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['subject']['alter']['ellipsis'] = FALSE;
  /* Поле: Комментарий: body */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  /* Поле: Комментарий: Автор */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'comment';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Поле: Комментарий: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'comment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Критерий сортировки: Комментарий: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'comment';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Комментарий: Одобрено */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status_node']['id'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['table'] = 'node';
  $handler->display->display_options['filters']['status_node']['field'] = 'status';
  $handler->display->display_options['filters']['status_node']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_node']['value'] = 1;
  $handler->display->display_options['filters']['status_node']['group'] = 1;
  $handler->display->display_options['filters']['status_node']['expose']['operator'] = FALSE;

  /* Display: Коментарии ЖК */
  $handler = $view->new_display('panel_pane', 'Коментарии ЖК', 'comments_complex');
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['comments_complex'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Содержимое'),
    t('body'),
    t('Автор'),
    t('Дата публикации'),
    t('Все'),
    t('Коментарии ЖК'),
    t('Представления-Фрагменты'),
  );
  $export['comments_complex'] = $view;

  $view = new view();
  $view->name = 'complex';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Жилой комплекс';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Entity Reference: Связывающая сущность */
  $handler->display->display_options['relationships']['reverse_field_home_complex_taxonomy_term']['id'] = 'reverse_field_home_complex_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_home_complex_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_home_complex_taxonomy_term']['field'] = 'reverse_field_home_complex_taxonomy_term';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Район */
  $handler->display->display_options['fields']['field_area']['id'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['table'] = 'field_data_field_area';
  $handler->display->display_options['fields']['field_area']['field'] = 'field_area';
  /* Поле: Содержимое: Застройщик */
  $handler->display->display_options['fields']['field_complex_developer']['id'] = 'field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['field'] = 'field_complex_developer';
  /* Поле: Содержимое: Срок сдачи */
  $handler->display->display_options['fields']['field_deadline']['id'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['table'] = 'field_data_field_deadline';
  $handler->display->display_options['fields']['field_deadline']['field'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_deadline']['settings'] = array(
    'view_mode' => 'full',
  );
  /* Поле: Содержимое: Главное изображение */
  $handler->display->display_options['fields']['field_main_photo']['id'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['table'] = 'field_data_field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['field'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['label'] = '';
  $handler->display->display_options['fields']['field_main_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_photo']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Поле: Содержимое: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '20',
  );
  /* Поле: Содержимое: Панорама */
  $handler->display->display_options['fields']['field_pano']['id'] = 'field_pano';
  $handler->display->display_options['fields']['field_pano']['table'] = 'field_data_field_pano';
  $handler->display->display_options['fields']['field_pano']['field'] = 'field_pano';
  $handler->display->display_options['fields']['field_pano']['settings'] = array(
    'edit' => 'Правка',
    'delete' => 'Удалить',
    'add' => 'Добавить',
    'description' => 1,
    'view_mode' => 'full',
  );
  /* Поле: Содержимое: Логотип */
  $handler->display->display_options['fields']['field_complex_logo']['id'] = 'field_complex_logo';
  $handler->display->display_options['fields']['field_complex_logo']['table'] = 'field_data_field_complex_logo';
  $handler->display->display_options['fields']['field_complex_logo']['field'] = 'field_complex_logo';
  $handler->display->display_options['fields']['field_complex_logo']['label'] = '';
  $handler->display->display_options['fields']['field_complex_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_complex_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_complex_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Критерий сортировки: Глобальный: Случайно */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'complex' => 'complex',
  );

  /* Display: Жилые комплексы */
  $handler = $view->new_display('panel_pane', 'Жилые комплексы', 'complexs');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['required'] = TRUE;
  /* Связь: Термин таксономии: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_city_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'complex' => 'complex',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Жилой комплекс */
  $handler = $view->new_display('panel_pane', 'Жилой комплекс', 'complex');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Район */
  $handler->display->display_options['fields']['field_area']['id'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['table'] = 'field_data_field_area';
  $handler->display->display_options['fields']['field_area']['field'] = 'field_area';
  /* Поле: Содержимое: Застройщик */
  $handler->display->display_options['fields']['field_complex_developer']['id'] = 'field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['field'] = 'field_complex_developer';
  /* Поле: Содержимое: Срок сдачи */
  $handler->display->display_options['fields']['field_deadline']['id'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['table'] = 'field_data_field_deadline';
  $handler->display->display_options['fields']['field_deadline']['field'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_deadline']['settings'] = array(
    'view_mode' => 'full',
  );
  /* Поле: Содержимое: Главное изображение */
  $handler->display->display_options['fields']['field_main_photo']['id'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['table'] = 'field_data_field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['field'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['label'] = '';
  $handler->display->display_options['fields']['field_main_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_photo']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Поле: Содержимое: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Описание';
  /* Поле: Содержимое: План жилого комплекса */
  $handler->display->display_options['fields']['field_plan_complex']['id'] = 'field_plan_complex';
  $handler->display->display_options['fields']['field_plan_complex']['table'] = 'field_data_field_plan_complex';
  $handler->display->display_options['fields']['field_plan_complex']['field'] = 'field_plan_complex';
  $handler->display->display_options['fields']['field_plan_complex']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_plan_complex']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Поле: Содержимое: Документы */
  $handler->display->display_options['fields']['field_documents']['id'] = 'field_documents';
  $handler->display->display_options['fields']['field_documents']['table'] = 'field_data_field_documents';
  $handler->display->display_options['fields']['field_documents']['field'] = 'field_documents';
  $handler->display->display_options['fields']['field_documents']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_documents']['delta_offset'] = '0';
  /* Поле: Содержимое: Панорама */
  $handler->display->display_options['fields']['field_pano']['id'] = 'field_pano';
  $handler->display->display_options['fields']['field_pano']['table'] = 'field_data_field_pano';
  $handler->display->display_options['fields']['field_pano']['field'] = 'field_pano';
  $handler->display->display_options['fields']['field_pano']['settings'] = array(
    'edit' => 'Правка',
    'delete' => 'Удалить',
    'add' => 'Добавить',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Жилые комплексы застройщика */
  $handler = $view->new_display('panel_pane', 'Жилые комплексы застройщика', 'complex_developer');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['required'] = TRUE;
  /* Связь: Термин таксономии: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'complex' => 'complex',
  );
  /* Критерий фильтра: Содержимое: Застройщик (field_complex_developer) */
  $handler->display->display_options['filters']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['filters']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['value'] = array(
    21 => '21',
  );
  $handler->display->display_options['filters']['field_complex_developer_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_complex_developer_tid']['vocabulary'] = 'developers';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Жилые комплексы */
  $handler = $view->new_display('panel_pane', 'Жилые комплексы', 'complexs_search');
  $handler->display->display_options['display_description'] = 'Жилые комплексы для формы поиска';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['required'] = TRUE;
  /* Связь: Термин таксономии: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_city_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = '11';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'complex' => 'complex',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Случайный комплекс */
  $handler = $view->new_display('panel_pane', 'Случайный комплекс', 'random_complex');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Логотип */
  $handler->display->display_options['fields']['field_complex_logo']['id'] = 'field_complex_logo';
  $handler->display->display_options['fields']['field_complex_logo']['table'] = 'field_data_field_complex_logo';
  $handler->display->display_options['fields']['field_complex_logo']['field'] = 'field_complex_logo';
  $handler->display->display_options['fields']['field_complex_logo']['label'] = '';
  $handler->display->display_options['fields']['field_complex_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_complex_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_complex_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Поле: Содержимое: Главное изображение */
  $handler->display->display_options['fields']['field_main_photo']['id'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['table'] = 'field_data_field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['field'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['label'] = '';
  $handler->display->display_options['fields']['field_main_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Глобальный: Случайно */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: Город (field_city) */
  $handler->display->display_options['arguments']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['arguments']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['arguments']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['arguments']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['arguments']['field_city_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_city_tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_city_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_city_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_city_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_city_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'complex' => 'complex',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['complex'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('Термин таксономии ссылается на Содержимое через field_home_complex'),
    t('Район'),
    t('Застройщик'),
    t('Срок сдачи'),
    t('Панорама'),
    t('Все'),
    t('Жилые комплексы'),
    t('термин из field_complex_developer'),
    t('термин из field_city'),
    t('Представления-Фрагменты'),
    t('Жилой комплекс'),
    t('Описание'),
    t('План жилого комплекса'),
    t('Документы'),
    t('Жилые комплексы застройщика'),
    t('Жилые комплексы для формы поиска'),
    t('Случайный комплекс'),
  );
  $export['complex'] = $view;

  $view = new view();
  $view->name = 'map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Карты';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default_map';
  $handler->display->display_options['style_options']['yandex_map_field'] = 'field_map';
  $handler->display->display_options['style_options']['yamaps_center_options'] = array(
    'map_center_type' => 'geolocation',
    'map_center_geolocation' => '',
    'zoom' => '11',
    'map_container' => array(
      'coords' => '',
    ),
  );
  $handler->display->display_options['style_options']['placemark_title'] = '';
  $handler->display->display_options['style_options']['baloon_title'] = 'field_map';
  $handler->display->display_options['style_options']['baloon_body'] = array(
    '' => '',
  );
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  /* Поле: Термин таксономии: Карта */
  $handler->display->display_options['fields']['field_map']['id'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['table'] = 'field_data_field_map';
  $handler->display->display_options['fields']['field_map']['field'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['click_sort_column'] = 'coords';
  $handler->display->display_options['fields']['field_map']['settings'] = array(
    'yamaps_display_options' => array(
      'display_type' => 'map',
      'open_button_text' => 'Open map',
      'close_button_text' => 'Close map',
    ),
    'controls' => 0,
    'traffic' => 0,
    'behaviors' => array(
      'clickZoom' => 'clickZoom',
      'dblClickZoom' => 'dblClickZoom',
      'drag' => 'drag',
      'multiTouch' => 'multiTouch',
      'rightMouseButtonMagnifier' => 'rightMouseButtonMagnifier',
      'scrollZoom' => 0,
      'ruler' => 0,
    ),
    'width' => '100%',
    'height' => '400px',
  );
  /* Контекстный фильтр: Термин таксономии: Жилой комплекс (field_home_complex) */
  $handler->display->display_options['arguments']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Термин таксономии: Словарь */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    6 => '6',
  );

  /* Display: Карта жилого комплекса */
  $handler = $view->new_display('panel_pane', 'Карта жилого комплекса', 'map_complex');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: Карта */
  $handler->display->display_options['fields']['field_map']['id'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['table'] = 'field_data_field_map';
  $handler->display->display_options['fields']['field_map']['field'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['click_sort_column'] = 'coords';
  $handler->display->display_options['fields']['field_map']['settings'] = array(
    'yamaps_display_options' => array(
      'display_type' => 'map',
      'open_button_text' => 'Open map',
      'close_button_text' => 'Close map',
    ),
    'controls' => 1,
    'traffic' => 0,
    'behaviors' => array(
      'clickZoom' => 'clickZoom',
      'scrollZoom' => 'scrollZoom',
      'dblClickZoom' => 'dblClickZoom',
      'drag' => 'drag',
      'ruler' => 'ruler',
      'rightMouseButtonMagnifier' => 'rightMouseButtonMagnifier',
      'multiTouch' => 0,
    ),
    'width' => '100%',
    'height' => '100%',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Карта застройщика */
  $handler = $view->new_display('panel_pane', 'Карта застройщика', 'developer_map');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['required'] = TRUE;
  /* Связь: Содержимое: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Карта для квартиры */
  $handler = $view->new_display('panel_pane', 'Карта для квартиры', 'apartment_map');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Термин таксономии: Содержимое, используя Дом */
  $handler->display->display_options['relationships']['reverse_field_apartament_home_node']['id'] = 'reverse_field_apartament_home_node';
  $handler->display->display_options['relationships']['reverse_field_apartament_home_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_apartament_home_node']['field'] = 'reverse_field_apartament_home_node';
  $handler->display->display_options['relationships']['reverse_field_apartament_home_node']['required'] = TRUE;
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_apartament_home_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Карта города */
  $handler = $view->new_display('panel_pane', 'Карта города', 'map_city');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: Карта */
  $handler->display->display_options['fields']['field_map']['id'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['table'] = 'field_data_field_map';
  $handler->display->display_options['fields']['field_map']['field'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['click_sort_column'] = 'coords';
  $handler->display->display_options['fields']['field_map']['settings'] = array(
    'yamaps_display_options' => array(
      'display_type' => 'map',
      'open_button_text' => 'Open map',
      'close_button_text' => 'Close map',
    ),
    'controls' => 1,
    'traffic' => 0,
    'behaviors' => array(
      'clickZoom' => 'clickZoom',
      'dblClickZoom' => 'dblClickZoom',
      'drag' => 'drag',
      'multiTouch' => 'multiTouch',
      'rightMouseButtonMagnifier' => 'rightMouseButtonMagnifier',
      'scrollZoom' => 0,
      'ruler' => 0,
    ),
    'width' => '100%',
    'height' => '100%',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Термин таксономии: Словарь */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    6 => '6',
  );
  $handler->display->display_options['filters']['vid']['expose']['operator_id'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['label'] = 'Словарь';
  $handler->display->display_options['filters']['vid']['expose']['operator'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['identifier'] = 'vid';
  $handler->display->display_options['filters']['vid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Критерий фильтра: Содержимое: Район (field_area) */
  $handler->display->display_options['filters']['field_area_tid']['id'] = 'field_area_tid';
  $handler->display->display_options['filters']['field_area_tid']['table'] = 'field_data_field_area';
  $handler->display->display_options['filters']['field_area_tid']['field'] = 'field_area_tid';
  $handler->display->display_options['filters']['field_area_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_area_tid']['expose']['operator_id'] = 'field_area_tid_op';
  $handler->display->display_options['filters']['field_area_tid']['expose']['label'] = 'Район (field_area)';
  $handler->display->display_options['filters']['field_area_tid']['expose']['operator'] = 'field_area_tid_op';
  $handler->display->display_options['filters']['field_area_tid']['expose']['identifier'] = 'field_area_tid';
  $handler->display->display_options['filters']['field_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_area_tid']['vocabulary'] = 'area';
  /* Критерий фильтра: Термин таксономии: Категория (field_category) */
  $handler->display->display_options['filters']['field_category_value']['id'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['table'] = 'field_data_field_category';
  $handler->display->display_options['filters']['field_category_value']['field'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_category_value']['expose']['operator_id'] = 'field_category_value_op';
  $handler->display->display_options['filters']['field_category_value']['expose']['label'] = 'Категория (field_category)';
  $handler->display->display_options['filters']['field_category_value']['expose']['operator'] = 'field_category_value_op';
  $handler->display->display_options['filters']['field_category_value']['expose']['identifier'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_category_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Критерий фильтра: Содержимое: Акция (field_stock) */
  $handler->display->display_options['filters']['field_stock_value']['id'] = 'field_stock_value';
  $handler->display->display_options['filters']['field_stock_value']['table'] = 'field_data_field_stock';
  $handler->display->display_options['filters']['field_stock_value']['field'] = 'field_stock_value';
  $handler->display->display_options['filters']['field_stock_value']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_stock_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_stock_value']['expose']['operator_id'] = 'field_stock_value_op';
  $handler->display->display_options['filters']['field_stock_value']['expose']['label'] = 'Акция (field_stock)';
  $handler->display->display_options['filters']['field_stock_value']['expose']['operator'] = 'field_stock_value_op';
  $handler->display->display_options['filters']['field_stock_value']['expose']['identifier'] = 'field_stock_value';
  $handler->display->display_options['filters']['field_stock_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Критерий фильтра: Термин таксономии: Жилой комплекс (field_home_complex) */
  $handler->display->display_options['filters']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['filters']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_home_complex_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['operator_id'] = 'field_home_complex_target_id_op';
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['label'] = 'Жилой комплекс (field_home_complex)';
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['operator'] = 'field_home_complex_target_id_op';
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['identifier'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Критерий фильтра: Содержимое: Застройщик (field_complex_developer) */
  $handler->display->display_options['filters']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['filters']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_complex_developer_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['operator_id'] = 'field_complex_developer_tid_op';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['label'] = 'Застройщик (field_complex_developer)';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['operator'] = 'field_complex_developer_tid_op';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['identifier'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_complex_developer_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_complex_developer_tid']['vocabulary'] = 'developers';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['map'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Сущность Содержимое связана через поле field_home_complex'),
    t('Карта'),
    t('Все'),
    t('Карта жилого комплекса'),
    t('Представления-Фрагменты'),
    t('Карта застройщика'),
    t('термин из field_complex_developer'),
    t('Карта для квартиры'),
    t('field_apartament_home'),
    t('Карта города'),
    t('Словарь'),
    t('Район (field_area)'),
    t('Категория (field_category)'),
    t('Акция (field_stock)'),
    t('Жилой комплекс (field_home_complex)'),
    t('Застройщик (field_complex_developer)'),
  );
  $export['map'] = $view;

  $view = new view();
  $view->name = 'maps';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Карты';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Термин таксономии: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  $translatables['maps'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
  );
  $export['maps'] = $view;

  $view = new view();
  $view->name = 'news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Содержимое';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Поле: Содержимое: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Содержимое';
  /* Поле: Содержимое: Изображение */
  $handler->display->display_options['fields']['field_image_news']['id'] = 'field_image_news';
  $handler->display->display_options['fields']['field_image_news']['table'] = 'field_data_field_image_news';
  $handler->display->display_options['fields']['field_image_news']['field'] = 'field_image_news';
  $handler->display->display_options['fields']['field_image_news']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_news']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Поле: Содержимое: Логотип */
  $handler->display->display_options['fields']['field_news_logo']['id'] = 'field_news_logo';
  $handler->display->display_options['fields']['field_news_logo']['table'] = 'field_data_field_news_logo';
  $handler->display->display_options['fields']['field_news_logo']['field'] = 'field_news_logo';
  $handler->display->display_options['fields']['field_news_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Критерий сортировки: Глобальный: Случайно */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );

  /* Display: Информация на форме поиска */
  $handler = $view->new_display('panel_pane', 'Информация на форме поиска', 'information_form_search');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'information' => 'information',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Новости на странице города */
  $handler = $view->new_display('panel_pane', 'Новости на странице города', 'news_city');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Город (field_news_city) */
  $handler->display->display_options['relationships']['field_news_city_tid']['id'] = 'field_news_city_tid';
  $handler->display->display_options['relationships']['field_news_city_tid']['table'] = 'field_data_field_news_city';
  $handler->display->display_options['relationships']['field_news_city_tid']['field'] = 'field_news_city_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Поле: Содержимое: Краткое описание */
  $handler->display->display_options['fields']['field_news_description']['id'] = 'field_news_description';
  $handler->display->display_options['fields']['field_news_description']['table'] = 'field_data_field_news_description';
  $handler->display->display_options['fields']['field_news_description']['field'] = 'field_news_description';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_news_city_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Все новости города */
  $handler = $view->new_display('panel_pane', 'Все новости города', 'all_new_city');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Город (field_news_city) */
  $handler->display->display_options['relationships']['field_news_city_tid']['id'] = 'field_news_city_tid';
  $handler->display->display_options['relationships']['field_news_city_tid']['table'] = 'field_data_field_news_city';
  $handler->display->display_options['relationships']['field_news_city_tid']['field'] = 'field_news_city_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Поле: Содержимое: Краткое описание */
  $handler->display->display_options['fields']['field_news_description']['id'] = 'field_news_description';
  $handler->display->display_options['fields']['field_news_description']['table'] = 'field_data_field_news_description';
  $handler->display->display_options['fields']['field_news_description']['field'] = 'field_news_description';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_news_city_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['news'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Заголовок'),
    t('Содержимое'),
    t('Изображение'),
    t('Логотип'),
    t('Информация на форме поиска'),
    t('Представления-Фрагменты'),
    t('Новости на странице города'),
    t('термин из field_news_city'),
    t('Краткое описание'),
    t('Дата публикации'),
    t('Все'),
    t('Все новости города'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
  );
  $export['news'] = $view;

  $view = new view();
  $view->name = 'search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Поиск';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Термин таксономии: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Критерий фильтра: Термин таксономии: Словарь */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    5 => '5',
  );

  /* Display: Районы */
  $handler = $view->new_display('panel_pane', 'Районы', 'search_area');
  $handler->display->display_options['display_description'] = 'Районы текущего города';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Термин таксономии: Словарь */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    5 => '5',
  );
  /* Критерий фильтра: Термин таксономии: Город (field_area_city) */
  $handler->display->display_options['filters']['field_area_city_tid']['id'] = 'field_area_city_tid';
  $handler->display->display_options['filters']['field_area_city_tid']['table'] = 'field_data_field_area_city';
  $handler->display->display_options['filters']['field_area_city_tid']['field'] = 'field_area_city_tid';
  $handler->display->display_options['filters']['field_area_city_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_area_city_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_area_city_tid']['vocabulary'] = 'cities';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Метро */
  $handler = $view->new_display('panel_pane', 'Метро', 'search_metro');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Термин таксономии: Словарь */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    8 => '8',
  );
  /* Критерий фильтра: Термин таксономии: Город (field_city_metro) */
  $handler->display->display_options['filters']['field_city_metro_tid']['id'] = 'field_city_metro_tid';
  $handler->display->display_options['filters']['field_city_metro_tid']['table'] = 'field_data_field_city_metro';
  $handler->display->display_options['filters']['field_city_metro_tid']['field'] = 'field_city_metro_tid';
  $handler->display->display_options['filters']['field_city_metro_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_city_metro_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_city_metro_tid']['vocabulary'] = 'cities';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['search'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Районы'),
    t('Районы текущего города'),
    t('Представления-Фрагменты'),
    t('Метро'),
  );
  $export['search'] = $view;

  $view = new view();
  $view->name = 'stock';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Акции';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Содержимое: Застройщик (field_developer) */
  $handler->display->display_options['relationships']['field_developer_tid']['id'] = 'field_developer_tid';
  $handler->display->display_options['relationships']['field_developer_tid']['table'] = 'field_data_field_developer';
  $handler->display->display_options['relationships']['field_developer_tid']['field'] = 'field_developer_tid';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Изображение */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Критерий сортировки: Глобальный: Случайно */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Контекстный фильтр: Термин таксономии: Город (field_city) */
  $handler->display->display_options['arguments']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['arguments']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['arguments']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['arguments']['field_city_tid']['relationship'] = 'field_developer_tid';
  $handler->display->display_options['arguments']['field_city_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_city_tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_city_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_city_tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_city_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_city_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_city_tid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stock' => 'stock',
  );
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Критерий фильтра: Содержимое: Приоритет (field_priority) */
  $handler->display->display_options['filters']['field_priority_value']['id'] = 'field_priority_value';
  $handler->display->display_options['filters']['field_priority_value']['table'] = 'field_data_field_priority';
  $handler->display->display_options['filters']['field_priority_value']['field'] = 'field_priority_value';
  $handler->display->display_options['filters']['field_priority_value']['value'] = array(
    1 => '1',
  );

  /* Display: Приоритетные акции */
  $handler = $view->new_display('panel_pane', 'Приоритетные акции', 'priority_stock');
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Простые акции */
  $handler = $view->new_display('panel_pane', 'Простые акции', 'stock');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stock' => 'stock',
  );
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Критерий фильтра: Содержимое: Приоритет (field_priority) */
  $handler->display->display_options['filters']['field_priority_value']['id'] = 'field_priority_value';
  $handler->display->display_options['filters']['field_priority_value']['table'] = 'field_data_field_priority';
  $handler->display->display_options['filters']['field_priority_value']['field'] = 'field_priority_value';
  $handler->display->display_options['filters']['field_priority_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_priority_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Все акции в городе */
  $handler = $view->new_display('panel_pane', 'Все акции в городе', 'all_stock_city');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stock' => 'stock',
  );
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['stock'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('термин из field_developer'),
    t('Все'),
    t('Приоритетные акции'),
    t('Представления-Фрагменты'),
    t('Простые акции'),
    t('Все акции в городе'),
  );
  $export['stock'] = $view;

  $view = new view();
  $view->name = 'term_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Термины';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Жилые комплексы';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Термин таксономии: Логотип */
  $handler->display->display_options['fields']['field_developer_logo']['id'] = 'field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['table'] = 'field_data_field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['field'] = 'field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['label'] = '';
  $handler->display->display_options['fields']['field_developer_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_developer_logo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_developer_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_developer_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Термин таксономии: Словарь */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    3 => '3',
  );

  /* Display: Застройщик */
  $handler = $view->new_display('panel_pane', 'Застройщик', 'developer');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Поле: Термин таксономии: Адрес Застройщика */
  $handler->display->display_options['fields']['field_address_developer']['id'] = 'field_address_developer';
  $handler->display->display_options['fields']['field_address_developer']['table'] = 'field_data_field_address_developer';
  $handler->display->display_options['fields']['field_address_developer']['field'] = 'field_address_developer';
  /* Поле: Термин таксономии: Логотип */
  $handler->display->display_options['fields']['field_developer_logo']['id'] = 'field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['table'] = 'field_data_field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['field'] = 'field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['label'] = '';
  $handler->display->display_options['fields']['field_developer_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_developer_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_developer_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Поле: Термин таксономии: Описание термина */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Описание ';
  /* Поле: Термин таксономии: веб сайт */
  $handler->display->display_options['fields']['field_web_site']['id'] = 'field_web_site';
  $handler->display->display_options['fields']['field_web_site']['table'] = 'field_data_field_web_site';
  $handler->display->display_options['fields']['field_web_site']['field'] = 'field_web_site';
  $handler->display->display_options['fields']['field_web_site']['alter']['make_link'] = TRUE;
  /* Поле: Термин таксономии: Номер телефона */
  $handler->display->display_options['fields']['field_number_phone']['id'] = 'field_number_phone';
  $handler->display->display_options['fields']['field_number_phone']['table'] = 'field_data_field_number_phone';
  $handler->display->display_options['fields']['field_number_phone']['field'] = 'field_number_phone';
  /* Поле: Термин таксономии: Эл.почта */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Термин таксономии: Словарь */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Застройщики */
  $handler = $view->new_display('panel_pane', 'Застройщики', 'developers');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Застройщики';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Термин таксономии: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_city_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Термин таксономии: Словарь */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Застройщики поиск */
  $handler = $view->new_display('panel_pane', 'Застройщики поиск', 'developers_search');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Застройщики';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Термин таксономии: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_city_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Термин таксономии: Словарь */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Дома ЖК */
  $handler = $view->new_display('panel_pane', 'Дома ЖК', 'homes_complex');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Дома жк';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['required'] = TRUE;
  /* Связь: Термин таксономии: Секции (field_home_section) */
  $handler->display->display_options['relationships']['field_home_section_value']['id'] = 'field_home_section_value';
  $handler->display->display_options['relationships']['field_home_section_value']['table'] = 'field_data_field_home_section';
  $handler->display->display_options['relationships']['field_home_section_value']['field'] = 'field_home_section_value';
  $handler->display->display_options['relationships']['field_home_section_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_home_section_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: ID термина */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Поле: Термин таксономии: Адрес */
  $handler->display->display_options['fields']['field_address_house']['id'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['table'] = 'field_data_field_address_house';
  $handler->display->display_options['fields']['field_address_house']['field'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['label'] = '';
  $handler->display->display_options['fields']['field_address_house']['element_label_colon'] = FALSE;
  /* Поле: Элемент коллекции полей: Номер секции */
  $handler->display->display_options['fields']['field_number_section']['id'] = 'field_number_section';
  $handler->display->display_options['fields']['field_number_section']['table'] = 'field_data_field_number_section';
  $handler->display->display_options['fields']['field_number_section']['field'] = 'field_number_section';
  $handler->display->display_options['fields']['field_number_section']['relationship'] = 'field_home_section_value';
  $handler->display->display_options['fields']['field_number_section']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Термин таксономии: Расположение на плане жк */
  $handler->display->display_options['fields']['field_lage_plan_complex']['id'] = 'field_lage_plan_complex';
  $handler->display->display_options['fields']['field_lage_plan_complex']['table'] = 'field_data_field_lage_plan_complex';
  $handler->display->display_options['fields']['field_lage_plan_complex']['field'] = 'field_lage_plan_complex';
  /* Поле: Термин таксономии: Описание термина */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  /* Поле: Термин таксономии: План дома */
  $handler->display->display_options['fields']['field_home_plan']['id'] = 'field_home_plan';
  $handler->display->display_options['fields']['field_home_plan']['table'] = 'field_data_field_home_plan';
  $handler->display->display_options['fields']['field_home_plan']['field'] = 'field_home_plan';
  $handler->display->display_options['fields']['field_home_plan']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_plan']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Поле: Элемент коллекции полей: Номер секции */
  $handler->display->display_options['fields']['field_number_section_1']['id'] = 'field_number_section_1';
  $handler->display->display_options['fields']['field_number_section_1']['table'] = 'field_data_field_number_section';
  $handler->display->display_options['fields']['field_number_section_1']['field'] = 'field_number_section';
  $handler->display->display_options['fields']['field_number_section_1']['relationship'] = 'field_home_section_value';
  $handler->display->display_options['fields']['field_number_section_1']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Элемент коллекции полей: Расположение на плане дома */
  $handler->display->display_options['fields']['field_lage_plan_home']['id'] = 'field_lage_plan_home';
  $handler->display->display_options['fields']['field_lage_plan_home']['table'] = 'field_data_field_lage_plan_home';
  $handler->display->display_options['fields']['field_lage_plan_home']['field'] = 'field_lage_plan_home';
  $handler->display->display_options['fields']['field_lage_plan_home']['relationship'] = 'field_home_section_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Контекстный фильтр: Термин таксономии: Секции (field_home_section) */
  $handler->display->display_options['arguments']['field_home_section_value']['id'] = 'field_home_section_value';
  $handler->display->display_options['arguments']['field_home_section_value']['table'] = 'field_data_field_home_section';
  $handler->display->display_options['arguments']['field_home_section_value']['field'] = 'field_home_section_value';
  $handler->display->display_options['arguments']['field_home_section_value']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_home_section_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_home_section_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Термин таксономии: Словарь */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    6 => '6',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['term_view'] = array(
    t('Master'),
    t('Жилые комплексы'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Все'),
    t('Застройщик'),
    t('Имя'),
    t('Адрес Застройщика'),
    t('Описание '),
    t('веб сайт'),
    t('Номер телефона'),
    t('Эл.почта'),
    t('Представления-Фрагменты'),
    t('Застройщики'),
    t('термин из field_city'),
    t('Застройщики поиск'),
    t('Дома ЖК'),
    t('Дома жк'),
    t('Сущность Содержимое связана через поле field_home_complex'),
    t('field collection item from field_home_section'),
    t('.'),
    t(','),
    t('Номер секции'),
    t('Расположение на плане жк'),
    t('Описание термина'),
    t('План дома'),
    t('Расположение на плане дома'),
  );
  $export['term_view'] = $view;

  return $export;
}
