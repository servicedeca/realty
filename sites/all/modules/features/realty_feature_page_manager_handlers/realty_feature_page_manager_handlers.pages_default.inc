<?php
/**
 * @file
 * realty_feature_page_manager_handlers.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function realty_feature_page_manager_handlers_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Жилой комплекс',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'complex' => 'complex',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '152d0f9f-404c-4fb6-8e25-d13920194add';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e04592f0-1a18-4be0-bef9-ef6802cfc8e2';
    $pane->panel = 'content_left';
    $pane->type = 'apartment_complex';
    $pane->subtype = 'apartment_complex';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e04592f0-1a18-4be0-bef9-ef6802cfc8e2';
    $display->content['new-e04592f0-1a18-4be0-bef9-ef6802cfc8e2'] = $pane;
    $display->panels['content_left'][0] = 'new-e04592f0-1a18-4be0-bef9-ef6802cfc8e2';
    $pane = new stdClass();
    $pane->pid = 'new-c34dacbe-f5c3-4807-9b8e-fcd929c93301';
    $pane->panel = 'content_right';
    $pane->type = 'comment_complex';
    $pane->subtype = 'comment_complex';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c34dacbe-f5c3-4807-9b8e-fcd929c93301';
    $display->content['new-c34dacbe-f5c3-4807-9b8e-fcd929c93301'] = $pane;
    $display->panels['content_right'][0] = 'new-c34dacbe-f5c3-4807-9b8e-fcd929c93301';
    $pane = new stdClass();
    $pane->pid = 'new-338ed087-d967-4cc0-85f7-1cdc119d41fb';
    $pane->panel = 'top';
    $pane->type = 'menu_complex';
    $pane->subtype = 'menu_complex';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '338ed087-d967-4cc0-85f7-1cdc119d41fb';
    $display->content['new-338ed087-d967-4cc0-85f7-1cdc119d41fb'] = $pane;
    $display->panels['top'][0] = 'new-338ed087-d967-4cc0-85f7-1cdc119d41fb';
    $pane = new stdClass();
    $pane->pid = 'new-79f791b1-26ef-414f-9771-0928de310268';
    $pane->panel = 'top';
    $pane->type = 'info_complex';
    $pane->subtype = 'info_complex';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '79f791b1-26ef-414f-9771-0928de310268';
    $display->content['new-79f791b1-26ef-414f-9771-0928de310268'] = $pane;
    $display->panels['top'][1] = 'new-79f791b1-26ef-414f-9771-0928de310268';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Квартира',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'apartament' => 'apartament',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cddd9adc-744d-45c9-af12-e4b867ef9bbd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8f37c2e2-fc1d-4c07-908c-4bf388ecf04b';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8f37c2e2-fc1d-4c07-908c-4bf388ecf04b';
    $display->content['new-8f37c2e2-fc1d-4c07-908c-4bf388ecf04b'] = $pane;
    $display->panels['middle'][0] = 'new-8f37c2e2-fc1d-4c07-908c-4bf388ecf04b';
    $pane = new stdClass();
    $pane->pid = 'new-2aa49f0e-88b9-4dfe-ab2c-5ccbfff1e58a';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'apartments-apartment';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2aa49f0e-88b9-4dfe-ab2c-5ccbfff1e58a';
    $display->content['new-2aa49f0e-88b9-4dfe-ab2c-5ccbfff1e58a'] = $pane;
    $display->panels['middle'][1] = 'new-2aa49f0e-88b9-4dfe-ab2c-5ccbfff1e58a';
    $pane = new stdClass();
    $pane->pid = 'new-d3e66d6a-5a0f-46ca-9005-baf709148d80';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'map-apartment_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd3e66d6a-5a0f-46ca-9005-baf709148d80';
    $display->content['new-d3e66d6a-5a0f-46ca-9005-baf709148d80'] = $pane;
    $display->panels['middle'][2] = 'new-d3e66d6a-5a0f-46ca-9005-baf709148d80';
    $pane = new stdClass();
    $pane->pid = 'new-e58d4b59-c104-41b6-bb0d-087e027e1133';
    $pane->panel = 'middle';
    $pane->type = 'apartment_floor';
    $pane->subtype = 'apartment_floor';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e58d4b59-c104-41b6-bb0d-087e027e1133';
    $display->content['new-e58d4b59-c104-41b6-bb0d-087e027e1133'] = $pane;
    $display->panels['middle'][3] = 'new-e58d4b59-c104-41b6-bb0d-087e027e1133';
    $pane = new stdClass();
    $pane->pid = 'new-037de920-6a4d-4c62-873e-b182a61cf4ac';
    $pane->panel = 'middle';
    $pane->type = 'apartment_home';
    $pane->subtype = 'apartment_home';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '037de920-6a4d-4c62-873e-b182a61cf4ac';
    $display->content['new-037de920-6a4d-4c62-873e-b182a61cf4ac'] = $pane;
    $display->panels['middle'][4] = 'new-037de920-6a4d-4c62-873e-b182a61cf4ac';
    $pane = new stdClass();
    $pane->pid = 'new-84aba13b-3319-4101-b455-fe960be24b60';
    $pane->panel = 'middle';
    $pane->type = 'panel_buttons';
    $pane->subtype = 'panel_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '84aba13b-3319-4101-b455-fe960be24b60';
    $display->content['new-84aba13b-3319-4101-b455-fe960be24b60'] = $pane;
    $display->panels['middle'][5] = 'new-84aba13b-3319-4101-b455-fe960be24b60';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2aa49f0e-88b9-4dfe-ab2c-5ccbfff1e58a';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Застройщики',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'developers' => 'developers',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b06a4c31-e6a4-47d8-bca9-9d96414b9fa3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6d03727d-37e8-48db-9985-feec793ee1ff';
    $pane->panel = 'middle';
    $pane->type = 'developer';
    $pane->subtype = 'developer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6d03727d-37e8-48db-9985-feec793ee1ff';
    $display->content['new-6d03727d-37e8-48db-9985-feec793ee1ff'] = $pane;
    $display->panels['middle'][0] = 'new-6d03727d-37e8-48db-9985-feec793ee1ff';
    $pane = new stdClass();
    $pane->pid = 'new-1bbb91f8-5b7b-4276-9a3b-72e9d82d8dab';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'apartments-apartment_developer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1bbb91f8-5b7b-4276-9a3b-72e9d82d8dab';
    $display->content['new-1bbb91f8-5b7b-4276-9a3b-72e9d82d8dab'] = $pane;
    $display->panels['middle'][1] = 'new-1bbb91f8-5b7b-4276-9a3b-72e9d82d8dab';
    $pane = new stdClass();
    $pane->pid = 'new-e71b0c43-b6d6-42bd-a276-52aa8adc6611';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'map-developer_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e71b0c43-b6d6-42bd-a276-52aa8adc6611';
    $display->content['new-e71b0c43-b6d6-42bd-a276-52aa8adc6611'] = $pane;
    $display->panels['middle'][2] = 'new-e71b0c43-b6d6-42bd-a276-52aa8adc6611';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context_2';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Город',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'cities' => 'cities',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '564e541c-7e81-4530-b759-5d6998007176';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-36830686-d59c-4999-8fd3-76b26bc0a388';
    $pane->panel = 'middle';
    $pane->type = 'header_front';
    $pane->subtype = 'header_front';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '36830686-d59c-4999-8fd3-76b26bc0a388';
    $display->content['new-36830686-d59c-4999-8fd3-76b26bc0a388'] = $pane;
    $display->panels['middle'][0] = 'new-36830686-d59c-4999-8fd3-76b26bc0a388';
    $pane = new stdClass();
    $pane->pid = 'new-4249fbeb-1564-4cf9-b37e-1f993a65baea';
    $pane->panel = 'middle';
    $pane->type = 'search_form';
    $pane->subtype = 'search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4249fbeb-1564-4cf9-b37e-1f993a65baea';
    $display->content['new-4249fbeb-1564-4cf9-b37e-1f993a65baea'] = $pane;
    $display->panels['middle'][1] = 'new-4249fbeb-1564-4cf9-b37e-1f993a65baea';
    $pane = new stdClass();
    $pane->pid = 'new-992656e8-f99d-4db9-8356-dcf43f6db755';
    $pane->panel = 'middle';
    $pane->type = 'block_complexs';
    $pane->subtype = 'block_complexs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '992656e8-f99d-4db9-8356-dcf43f6db755';
    $display->content['new-992656e8-f99d-4db9-8356-dcf43f6db755'] = $pane;
    $display->panels['middle'][2] = 'new-992656e8-f99d-4db9-8356-dcf43f6db755';
    $pane = new stdClass();
    $pane->pid = 'new-2621b2b6-fe7d-4423-8726-1a084205a51e';
    $pane->panel = 'middle';
    $pane->type = 'front_map';
    $pane->subtype = 'front_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '2621b2b6-fe7d-4423-8726-1a084205a51e';
    $display->content['new-2621b2b6-fe7d-4423-8726-1a084205a51e'] = $pane;
    $display->panels['middle'][3] = 'new-2621b2b6-fe7d-4423-8726-1a084205a51e';
    $pane = new stdClass();
    $pane->pid = 'new-96b0dc94-3ef7-4aad-a327-7a490bb7e3e3';
    $pane->panel = 'middle';
    $pane->type = 'news_block';
    $pane->subtype = 'news_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '96b0dc94-3ef7-4aad-a327-7a490bb7e3e3';
    $display->content['new-96b0dc94-3ef7-4aad-a327-7a490bb7e3e3'] = $pane;
    $display->panels['middle'][4] = 'new-96b0dc94-3ef7-4aad-a327-7a490bb7e3e3';
    $pane = new stdClass();
    $pane->pid = 'new-448ca697-b5fa-434e-8eb1-b9e87e3b18b0';
    $pane->panel = 'middle';
    $pane->type = 'block_stock';
    $pane->subtype = 'block_stock';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '448ca697-b5fa-434e-8eb1-b9e87e3b18b0';
    $display->content['new-448ca697-b5fa-434e-8eb1-b9e87e3b18b0'] = $pane;
    $display->panels['middle'][5] = 'new-448ca697-b5fa-434e-8eb1-b9e87e3b18b0';
    $pane = new stdClass();
    $pane->pid = 'new-a057c449-dcff-4254-a908-6f22668be919';
    $pane->panel = 'middle';
    $pane->type = 'block_developers';
    $pane->subtype = 'block_developers';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'a057c449-dcff-4254-a908-6f22668be919';
    $display->content['new-a057c449-dcff-4254-a908-6f22668be919'] = $pane;
    $display->panels['middle'][6] = 'new-a057c449-dcff-4254-a908-6f22668be919';
    $pane = new stdClass();
    $pane->pid = 'new-0d49d976-4522-43d8-a86b-c59d8dd3681b';
    $pane->panel = 'middle';
    $pane->type = 'block_pano';
    $pane->subtype = 'block_pano';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '0d49d976-4522-43d8-a86b-c59d8dd3681b';
    $display->content['new-0d49d976-4522-43d8-a86b-c59d8dd3681b'] = $pane;
    $display->panels['middle'][7] = 'new-0d49d976-4522-43d8-a86b-c59d8dd3681b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Профиль',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '83ad53d3-f808-403e-8c29-af07c01a8d39';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-af11de67-d5ed-4da7-81b2-56b1441b19ad';
    $pane->panel = 'content_center';
    $pane->type = 'user_profile_form';
    $pane->subtype = 'user_profile_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'af11de67-d5ed-4da7-81b2-56b1441b19ad';
    $display->content['new-af11de67-d5ed-4da7-81b2-56b1441b19ad'] = $pane;
    $display->panels['content_center'][0] = 'new-af11de67-d5ed-4da7-81b2-56b1441b19ad';
    $pane = new stdClass();
    $pane->pid = 'new-1e1bd664-8144-40f2-940a-232fecfaa83d';
    $pane->panel = 'content_left';
    $pane->type = 'user_menu';
    $pane->subtype = 'user_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1e1bd664-8144-40f2-940a-232fecfaa83d';
    $display->content['new-1e1bd664-8144-40f2-940a-232fecfaa83d'] = $pane;
    $display->panels['content_left'][0] = 'new-1e1bd664-8144-40f2-940a-232fecfaa83d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  return $export;
}
