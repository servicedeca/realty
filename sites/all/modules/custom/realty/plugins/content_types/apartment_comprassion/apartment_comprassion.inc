<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_apartment_comprassion_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Apartment comprassion'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_apartment_comprassion_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;

  $block = new stdClass();
  $block->content = views_embed_view('apartments', 'comprassion', $user->uid);

  return $block;
}
