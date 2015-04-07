<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_comment_complex_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Comment complex'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_comment_complex_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_comment_complex_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content = theme('realty_comment_complex');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_comment_complex_content_type_theme(&$theme, $plugin) {
  $theme['realty_comment_complex'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-comment-complex',
  );
}

/**
 * Process variables for realty-block-stock.tpl.php.
 */
function template_preprocess_realty_comment_complex(&$vars) {
  $node = menu_get_object('node', 1);
  if ($node == NULL) {
    $nid = arg(1);
    $node = node_load($nid);
  }

  $vars['node'] = $node;

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));

  $vars['image'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/c-pen.svg',
  ));

  $vars['comments'] = views_embed_view('comments_complex', 'comments_complex', $node->nid);
}
