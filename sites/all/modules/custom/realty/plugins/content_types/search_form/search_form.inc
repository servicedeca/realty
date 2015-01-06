<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_search_form_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Search form'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_search_form_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_search_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_search_form');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_search_form_content_type_theme(&$theme, $plugin) {
  $theme['realty_search_form'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-search-form',
  );
}

/**
 * Process variables for realty-search-form.tpl.php.
 */
function template_preprocess_realty_search_form(&$vars) {

  $vars['search_form'] = drupal_get_form('realty_search_form');

  $result = views_get_view_result('news', 'main_news');

  if ($result[0]) {
    $vars['news'] = array(
      'title' => $result[0]->node_title,
      'image' => $result[0]->field_field_image_news[0]['rendered'],
      'description' => $result[0]->field_body[0]['raw']['value'],
      'details' => l('Details', 'node/'.$result[0]->nid),
    );
  }
}
