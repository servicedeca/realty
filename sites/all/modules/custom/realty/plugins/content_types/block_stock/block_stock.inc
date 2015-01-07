<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_block_stock_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Block stock'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_block_stock_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_block_stock_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_block_stock');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_block_stock_content_type_theme(&$theme, $plugin) {
  $theme['realty_block_stock'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-block-stock',
  );
}

/**
 * Process variables for realty-block-stock.tpl.php.
 */
function template_preprocess_realty_block_stock(&$vars) {

  $city = menu_get_object('taxonomy_term', 2);

  $stock = views_get_view_result('stock', 'stock');

  if ($stock) {
    foreach ($stock as $key => $val) {
      $vars['stock'][$key] = array(
        'title' => $val->node_title,
        'description' => $val->field_body[0]['raw']['value'],
        'image' => $val->field_field_image[0]['rendered'],
      );
    }
  }

  $priority_stock = views_get_view_result('stock', 'priority_stock');

  if ($priority_stock) {
    foreach ($priority_stock as $key => $val) {
      $vars['priority_stock'][$key] = array(
        'title' => $val->node_title,
        'description' => $val->field_body[0]['raw']['value'],
        'image' => $val->field_field_image[0]['rendered'],
      );
    }
  }

  $vars['all_stock'] = l('All stock', 'stock/city/'.$city->tid);
}