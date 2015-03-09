<?php
/**
 * @file
 * realty_feature_page_manager_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_page_manager_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'about_project';
  $page->task = 'page';
  $page->admin_title = 'О проекте';
  $page->admin_description = '';
  $page->path = 'about_project';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'О проекте',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_about_project_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'about_project';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $display->uuid = '836523fb-b4a5-4901-af7d-e00d31940538';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['about_project'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'all_stock_city';
  $page->task = 'page';
  $page->admin_title = 'Все акции в городе';
  $page->admin_description = '';
  $page->path = 'stock/city/%name';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          1 => '1',
          6 => 0,
          3 => 0,
          5 => 0,
          7 => 0,
        ),
        'breadcrumb' => 1,
        'transform' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_all_stock_city_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'all_stock_city';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $display->uuid = '5359a301-0fbc-488a-8494-b324200dc0fe';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4465f59b-c5b3-4ab6-b1ed-ff9fe54d2136';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'stock-all_stock_city';
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
    $pane->uuid = '4465f59b-c5b3-4ab6-b1ed-ff9fe54d2136';
    $display->content['new-4465f59b-c5b3-4ab6-b1ed-ff9fe54d2136'] = $pane;
    $display->panels['middle'][0] = 'new-4465f59b-c5b3-4ab6-b1ed-ff9fe54d2136';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['all_stock_city'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'comparison';
  $page->task = 'page';
  $page->admin_title = 'Сравнение';
  $page->admin_description = '';
  $page->path = 'comparison';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_comparison_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'comparison';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1e3b55de-7854-4aa8-a14d-a077500b82ea';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-48720e50-1928-4e97-98d9-9f63e28cf67e';
    $pane->panel = 'content_center';
    $pane->type = 'views_panes';
    $pane->subtype = 'apartments-comprassion';
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
    $pane->uuid = '48720e50-1928-4e97-98d9-9f63e28cf67e';
    $display->content['new-48720e50-1928-4e97-98d9-9f63e28cf67e'] = $pane;
    $display->panels['content_center'][0] = 'new-48720e50-1928-4e97-98d9-9f63e28cf67e';
    $pane = new stdClass();
    $pane->pid = 'new-48a94bfd-7f67-4003-99cf-91acf0183397';
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
    $pane->uuid = '48a94bfd-7f67-4003-99cf-91acf0183397';
    $display->content['new-48a94bfd-7f67-4003-99cf-91acf0183397'] = $pane;
    $display->panels['content_left'][0] = 'new-48a94bfd-7f67-4003-99cf-91acf0183397';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-48a94bfd-7f67-4003-99cf-91acf0183397';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['comparison'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'complexes';
  $page->task = 'page';
  $page->admin_title = 'Жилые комплексы';
  $page->admin_description = '';
  $page->path = 'complexes/city/%name';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          1 => '1',
          6 => 0,
          3 => 0,
          5 => 0,
          7 => 0,
        ),
        'breadcrumb' => 1,
        'transform' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_complexes_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'complexes';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $display->uuid = '857df2a4-5caa-439e-9d2d-8eec6344f191';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f3909395-77b5-49bd-a1b8-a5a17f9cfb3e';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'complex-complexs';
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
    $pane->uuid = 'f3909395-77b5-49bd-a1b8-a5a17f9cfb3e';
    $display->content['new-f3909395-77b5-49bd-a1b8-a5a17f9cfb3e'] = $pane;
    $display->panels['middle'][0] = 'new-f3909395-77b5-49bd-a1b8-a5a17f9cfb3e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['complexes'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'developers';
  $page->task = 'page';
  $page->admin_title = 'Застройщик';
  $page->admin_description = '';
  $page->path = 'developers/city/%name';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          1 => '1',
          6 => 0,
          3 => 0,
          5 => 0,
          7 => 0,
        ),
        'breadcrumb' => 1,
        'transform' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_developers_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'developers';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $display->uuid = '45d32603-8032-4eb5-9739-d29ce2311b93';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-85248e1c-b8b0-4220-a8c0-0e51b5e3a991';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'term_view-developers';
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
    $pane->uuid = '85248e1c-b8b0-4220-a8c0-0e51b5e3a991';
    $display->content['new-85248e1c-b8b0-4220-a8c0-0e51b5e3a991'] = $pane;
    $display->panels['middle'][0] = 'new-85248e1c-b8b0-4220-a8c0-0e51b5e3a991';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['developers'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'documents';
  $page->task = 'page';
  $page->admin_title = 'Докуметы';
  $page->admin_description = '';
  $page->path = 'complexes/%name/documents';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Материал: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_documents__panel_context_5230c72c-2e70-4708-b813-3e17ab207274';
  $handler->task = 'page';
  $handler->subtask = 'documents';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b56b89e6-6813-4486-908d-7951cf395baa';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-30879b00-b9c7-4608-b145-adfb3bf3090f';
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
    $pane->uuid = '30879b00-b9c7-4608-b145-adfb3bf3090f';
    $display->content['new-30879b00-b9c7-4608-b145-adfb3bf3090f'] = $pane;
    $display->panels['top'][0] = 'new-30879b00-b9c7-4608-b145-adfb3bf3090f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-30879b00-b9c7-4608-b145-adfb3bf3090f';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['documents'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'gallery';
  $page->task = 'page';
  $page->admin_title = 'Галерея';
  $page->admin_description = '';
  $page->path = 'complexes/%name/gallery';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Материал: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_gallery__panel_context_b0d676ab-1337-4d7d-bef0-afc8301e6402';
  $handler->task = 'page';
  $handler->subtask = 'gallery';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '626475fc-2917-4448-b87a-322b5233bcf1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-21d32c5b-efff-4a9b-9664-f434d3b07725';
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
    $pane->uuid = '21d32c5b-efff-4a9b-9664-f434d3b07725';
    $display->content['new-21d32c5b-efff-4a9b-9664-f434d3b07725'] = $pane;
    $display->panels['top'][0] = 'new-21d32c5b-efff-4a9b-9664-f434d3b07725';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-21d32c5b-efff-4a9b-9664-f434d3b07725';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['gallery'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'get_id_apartment';
  $page->task = 'page';
  $page->admin_title = 'Полученные квартиры пользователя';
  $page->admin_description = '';
  $page->path = 'apartment_id';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_get_id_apartment_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'get_id_apartment';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $display->uuid = '4364ca36-54d8-4b5a-b30e-de6dd856c9ad';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-01cded16-0ae7-4746-8e21-e094a0b9bfee';
    $pane->panel = 'content_center';
    $pane->type = 'apartment_id';
    $pane->subtype = 'apartment_id';
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
    $pane->uuid = '01cded16-0ae7-4746-8e21-e094a0b9bfee';
    $display->content['new-01cded16-0ae7-4746-8e21-e094a0b9bfee'] = $pane;
    $display->panels['content_center'][0] = 'new-01cded16-0ae7-4746-8e21-e094a0b9bfee';
    $pane = new stdClass();
    $pane->pid = 'new-e698b4cb-923c-4e09-83f6-7fbdf32312b2';
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
    $pane->uuid = 'e698b4cb-923c-4e09-83f6-7fbdf32312b2';
    $display->content['new-e698b4cb-923c-4e09-83f6-7fbdf32312b2'] = $pane;
    $display->panels['content_left'][0] = 'new-e698b4cb-923c-4e09-83f6-7fbdf32312b2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['get_id_apartment'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'main_page';
  $page->task = 'page';
  $page->admin_title = 'Главная страница';
  $page->admin_description = '';
  $page->path = '<front>';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_main_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'main_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $display->uuid = '0336c3a8-eebd-4d58-b85c-ee8be1f1bc22';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f141fe50-2caa-463a-bb52-89ffcf551b79';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f141fe50-2caa-463a-bb52-89ffcf551b79';
    $display->content['new-f141fe50-2caa-463a-bb52-89ffcf551b79'] = $pane;
    $display->panels['middle'][0] = 'new-f141fe50-2caa-463a-bb52-89ffcf551b79';
    $pane = new stdClass();
    $pane->pid = 'new-61de23b3-e7b9-439e-9757-969415f065f8';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '61de23b3-e7b9-439e-9757-969415f065f8';
    $display->content['new-61de23b3-e7b9-439e-9757-969415f065f8'] = $pane;
    $display->panels['middle'][1] = 'new-61de23b3-e7b9-439e-9757-969415f065f8';
    $pane = new stdClass();
    $pane->pid = 'new-d4bf6eef-a1fb-482e-b70f-71fa9a3e1bd1';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd4bf6eef-a1fb-482e-b70f-71fa9a3e1bd1';
    $display->content['new-d4bf6eef-a1fb-482e-b70f-71fa9a3e1bd1'] = $pane;
    $display->panels['middle'][2] = 'new-d4bf6eef-a1fb-482e-b70f-71fa9a3e1bd1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['main_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news';
  $page->task = 'page';
  $page->admin_title = 'Новости';
  $page->admin_description = '';
  $page->path = 'news/city/%name';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Материал: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_news_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'news';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $display->title = 'Новости';
  $display->uuid = '8d46ab79-1b4d-4a05-84e8-9697fd0b2315';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e1b968f1-e12d-4ff8-8649-4e2d8be4263d';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'news-all_new_city';
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
    $pane->uuid = 'e1b968f1-e12d-4ff8-8649-4e2d8be4263d';
    $display->content['new-e1b968f1-e12d-4ff8-8649-4e2d8be4263d'] = $pane;
    $display->panels['middle'][0] = 'new-e1b968f1-e12d-4ff8-8649-4e2d8be4263d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'plan_complex';
  $page->task = 'page';
  $page->admin_title = 'План ЖК';
  $page->admin_description = '';
  $page->path = 'complexes/%name/plan';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Материал: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_plan_complex__panel_context_bcd0f298-5d3f-4a92-9b13-8a9987b01f34';
  $handler->task = 'page';
  $handler->subtask = 'plan_complex';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '531b5829-cd5b-431e-9888-a4ca8d21cc91';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e6ac4da1-9a27-460d-94fb-d6be696b45ff';
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
    $pane->uuid = 'e6ac4da1-9a27-460d-94fb-d6be696b45ff';
    $display->content['new-e6ac4da1-9a27-460d-94fb-d6be696b45ff'] = $pane;
    $display->panels['content_left'][0] = 'new-e6ac4da1-9a27-460d-94fb-d6be696b45ff';
    $pane = new stdClass();
    $pane->pid = 'new-cbbbae7f-259d-47a3-9c61-9a071b112ae2';
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
    $pane->uuid = 'cbbbae7f-259d-47a3-9c61-9a071b112ae2';
    $display->content['new-cbbbae7f-259d-47a3-9c61-9a071b112ae2'] = $pane;
    $display->panels['content_right'][0] = 'new-cbbbae7f-259d-47a3-9c61-9a071b112ae2';
    $pane = new stdClass();
    $pane->pid = 'new-ac719a8f-f6d8-4e56-ae50-caa204d52779';
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
    $pane->uuid = 'ac719a8f-f6d8-4e56-ae50-caa204d52779';
    $display->content['new-ac719a8f-f6d8-4e56-ae50-caa204d52779'] = $pane;
    $display->panels['top'][0] = 'new-ac719a8f-f6d8-4e56-ae50-caa204d52779';
    $pane = new stdClass();
    $pane->pid = 'new-4b13ff07-38b2-49e2-b9be-f38c2fce62e8';
    $pane->panel = 'top';
    $pane->type = 'plan_complex';
    $pane->subtype = 'plan_complex';
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
    $pane->uuid = '4b13ff07-38b2-49e2-b9be-f38c2fce62e8';
    $display->content['new-4b13ff07-38b2-49e2-b9be-f38c2fce62e8'] = $pane;
    $display->panels['top'][1] = 'new-4b13ff07-38b2-49e2-b9be-f38c2fce62e8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['plan_complex'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search';
  $page->task = 'page';
  $page->admin_title = 'Поиск';
  $page->admin_description = '';
  $page->path = 'search';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $display->title = 'Результаты поиска';
  $display->uuid = 'e7789cb1-4a13-47d4-9dc4-6ada6b706e01';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ec47d031-4889-43a4-823c-c47868c425a7';
    $pane->panel = 'middle';
    $pane->type = 'search_search_form';
    $pane->subtype = 'search_search_form';
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
    $pane->uuid = 'ec47d031-4889-43a4-823c-c47868c425a7';
    $display->content['new-ec47d031-4889-43a4-823c-c47868c425a7'] = $pane;
    $display->panels['middle'][0] = 'new-ec47d031-4889-43a4-823c-c47868c425a7';
    $pane = new stdClass();
    $pane->pid = 'new-facae358-2783-4345-9500-adc012dee924';
    $pane->panel = 'middle';
    $pane->type = 'search_result';
    $pane->subtype = 'search_result';
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
    $pane->uuid = 'facae358-2783-4345-9500-adc012dee924';
    $display->content['new-facae358-2783-4345-9500-adc012dee924'] = $pane;
    $display->panels['middle'][1] = 'new-facae358-2783-4345-9500-adc012dee924';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'stock';
  $page->task = 'page';
  $page->admin_title = 'Акции';
  $page->admin_description = '';
  $page->path = 'complexes/%name/stock';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Материал: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_stock__panel_context_eba581c5-80f1-4502-82b3-160ec6782580';
  $handler->task = 'page';
  $handler->subtask = 'stock';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '23c0f35a-3a37-4a98-9750-d6f0071ca094';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ca4986a2-9c3d-460b-a45e-c78dc5ae7036';
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
    $pane->uuid = 'ca4986a2-9c3d-460b-a45e-c78dc5ae7036';
    $display->content['new-ca4986a2-9c3d-460b-a45e-c78dc5ae7036'] = $pane;
    $display->panels['top'][0] = 'new-ca4986a2-9c3d-460b-a45e-c78dc5ae7036';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ca4986a2-9c3d-460b-a45e-c78dc5ae7036';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['stock'] = $page;

  return $pages;

}
