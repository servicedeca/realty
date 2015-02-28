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
    'title' => t('Comment complex '),
    'all contexts' => TRUE,
    'category' => t('Realty'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_comment_complex_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = menu_get_object('node', 1);
  $block = new stdClass();
  $node_view = node_view($node);

  $comment_form = drupal_get_form('comment_form',(object) array('nid' => $node->nid));
  $block->content = render($node_view['comments']);

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
