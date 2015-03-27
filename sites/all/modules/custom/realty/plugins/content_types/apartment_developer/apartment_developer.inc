<?php
/**
 * @file
 * Ctools content type
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_apartment_developer_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Apartment developer'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_apartment_developer_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_apartment_developer_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_apartment_developer');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_apartment_developer_content_type_theme(&$theme, $plugin) {
  $theme['realty_apartment_developer'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-apartment-developer',
  );
}

/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_apartment_developer(&$vars) {
  $entity = arg(2);
  if ($entity == 'term') {
    $term = menu_get_object('taxonomy_term', 2);
  }
  else {
    $term = taxonomy_term_load($entity);
  }

  $vars['view'] = views_embed_view('apartments', 'apartment_developer', $term->tid);
}
