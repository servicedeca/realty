<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_search_bread_crumbs_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Search bread crumbs'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_search_bread_crumbs_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_search_bread_crumbs_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_search_bread_crumbs');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_search_bread_crumbs_content_type_theme(&$theme, $plugin) {

  $theme['realty_search_bread_crumbs'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-search-bread-crumbs',
  );
}

/**
 * Process variables for realty-block-complexes.tpl.php.
 */
function template_preprocess_realty_search_bread_crumbs(&$vars) {
  $city = taxonomy_term_load(arg(1));
  $vars['city'] = l($city->name, 'taxonomy/term/' . $city->tid);
  $vars['search'] = l(t('search results'), '#href', array(
    'external' => TRUE,
  ));
}