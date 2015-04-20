<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_complex_map_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Complex map'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_complex_map_content_type_render($subtype, $conf, $panel_args, $context) {
  //$complex_nid = node_load(arg(1));

  $block = new stdClass();
  $block->content = '<div class="container fin">
    <div class="col-xs-12 zero-padding complex-map">'.views_embed_view('map', 'map_complex', arg(1)).'</div></div>';

  return $block;
}
