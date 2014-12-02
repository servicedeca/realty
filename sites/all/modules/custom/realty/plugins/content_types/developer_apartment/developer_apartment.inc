<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_developer_apartment_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Developer apartment'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_developer_apartment_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = views_embed_view('apartments', 'developer_apartment');

  return $block;
}
