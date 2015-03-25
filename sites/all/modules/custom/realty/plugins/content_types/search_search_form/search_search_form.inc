<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_search_search_form_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Search search form'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_search_search_form_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_search_search_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_search_search_form');

  drupal_add_js(array('get' => $_GET), 'setting');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_search_search_form_content_type_theme(&$theme, $plugin) {
  $theme['realty_search_search_form'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-search-search-form',
  );
}

/**
 * Process variables for realty-search-form.tpl.php.
 */
function template_preprocess_realty_search_search_form(&$vars) {

  drupal_add_js(REALTY_FRONT_THEME_PATH.'/js/realty_search_form.js');
  $vars['search_form'] = drupal_get_form('realty_search_form');
  $result = views_get_view_result('news', 'information_form_search');

  if ($result[0]) {
    $vars['image_path'] = '/' . realty_file_directory_path().'/'.$result[0]->field_field_image_news[0]['raw']['filename'];
    $logo_path = $result[0]->field_field_news_logo[0]['raw']['uri'];
    $vars['title'] = $result[0]->node_title;
    if (!empty($logo_path)) {
      $vars['news_logo'] =  theme('image', array(
          'path' => $logo_path,
          'attributes' => array(
            'class' => array('logo-z'),
          ),
        )
      );;
    }
      $vars['description'] = $result[0]->field_body[0]['raw']['value'];
      $vars['details'] = l(t('Details'), 'node/'.$result[0]->nid, array('attributes' => array('class' => 'button-info') ));
  }

  $vars['modal'] = theme('realty_modal_search_form');
}
