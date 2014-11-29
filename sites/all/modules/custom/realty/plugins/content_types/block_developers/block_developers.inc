<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_block_developers_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Block developers'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_block_developers_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = views_embed_view('term_view', 'developers');

  return $block;
}
