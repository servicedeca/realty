<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_block_partners_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Block partners'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_block_partners_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_block_partners_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_block_partners');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_block_partners_content_type_theme(&$theme, $plugin) {
  $theme['realty_block_partners'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-block-partners',
  );
}

/**
 * Process variables for realty-block-partners.tpl.php.
 */
function template_preprocess_realty_block_partners(&$vars) {
  $city = menu_get_object('taxonomy_term', 2);
  $vars['view'] = views_embed_view('term_view', 'partners');
  $vars['micro_logo'] = realty_get_image_micro_logo();
  $vars['all_partners'] = 'city/' . $city->tid . '/partners';
}