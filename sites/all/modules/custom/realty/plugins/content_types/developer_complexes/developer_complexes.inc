<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_developer_complexes_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('developer complexes'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_developer_complexes_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_developer_complexes_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_developer_complexes');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_developer_complexes_content_type_theme(&$theme, $plugin) {
  $theme['realty_developer_complexes'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-developer-complexes',
  );
}

/**
 * Process variables for realty-menu-complex.tpl.php.
 */
function template_preprocess_realty_developer_complexes(&$vars) {
  $tid = arg(1);

  $vars['view'] = views_embed_view('complex', 'complex_developer', $tid);
}
