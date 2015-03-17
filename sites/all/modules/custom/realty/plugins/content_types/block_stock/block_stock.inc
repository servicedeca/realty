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
        'image' => theme('image', array(
            'path' => $val->field_field_image[0]['raw']['uri'],
            'attributes' => array(
              'class' => array('title-image'),
            ),
          )
        ),
        'details' => l(t('details'), 'node/' . $val->nid, array('attributes' => array('class' => array('button-info',
        'stock-button', 'cb-b-stock')))),
      );
    }
  }

  $priority_stock = views_get_view_result('stock', 'priority_stock');

     if (!empty($priority_stock)) {
      $vars['priority_stock'] = array(
        'title' => $priority_stock[0]->node_title,
        'description' => $priority_stock[0]->field_body[0]['raw']['value'],
        'image' => theme('image', array(
          'path' => $priority_stock[0]->field_field_image[0]['raw']['uri'],
          'attributes' => array(
            'class' => array('big-stock-image'),
            ),
          )
        ),
        'details' => l(t('details'), 'node/' . $priority_stock[0]->nid, array('attributes' => array('class' => array('button-info',
          'stock-button', 'stock-button')))),
      );
    }

  $vars['micro_logo'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/micrologo.png',
    'attributes' => array(
      'class' => array('micrologo'),
    ),
  ));

  $vars['all_stock'] = 'stock/city/'.$city->tid;
}