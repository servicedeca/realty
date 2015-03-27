<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_comment_developer_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Comment developer'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_comment_developer_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_comment_developer_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content = theme('realty_comment_developer');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_comment_developer_content_type_theme(&$theme, $plugin) {
  $theme['realty_comment_developer'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-comment-developer',
  );
}

/**
 * Process variables for realty-comment-developer.tpl.php.
 */
function template_preprocess_realty_comment_developer(&$vars) {
  $arg = arg('1');
  $arg == 'term' ? $tid = arg('2') :  $tid = $arg;

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));

  $vars['image'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/c-pen.svg',
  ));

  $vars['comments'] = views_embed_view('comments_complex', 'comment_developer', $tid);
}
