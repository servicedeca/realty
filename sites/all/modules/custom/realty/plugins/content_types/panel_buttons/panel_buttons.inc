<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_panel_buttons_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Panel buttons '),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_panel_buttons_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_panel_buttons_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_panel_buttons');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_panel_buttons_content_type_theme(&$theme, $plugin) {
  $theme['realty_panel_buttons'] = array(
    'path' => $plugin['path'],
    'template' => 'realty_panel_buttons',
  );
}

/**
 * Process variables for realty-panel-buttons.tpl.php.
 */
function template_preprocess_realty_panel_buttons(&$vars) {
  $node = menu_get_object('node', 1);
  $vars['buttons'] = array(
    'get_id_apartment' => l(t('Get id apartments'),'#get-id-apartment', array(
      'external' => TRUE,
      'attributes'=> array(
        'id' => 'get-id-apartment',
        'data-node-id' => $node->nid,
    ),)),

  );
}
