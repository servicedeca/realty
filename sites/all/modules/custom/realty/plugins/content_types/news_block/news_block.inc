<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_news_block_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('News'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_news_block_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_news_block_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_news_block');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_news_block_content_type_theme(&$theme, $plugin) {
  $theme['realty_news_block'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-news-block',
  );
}

/**
 * Process variables for realty-search-form.tpl.php.
 */
function template_preprocess_realty_news_block(&$vars) {
  $city = menu_get_object('taxonomy_term', 2);

  $vars['micro_logo'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/micrologo.png',
    'attributes' => array(
      'class' => array('micrologo'),
    ),
  ));

  $vars['all_news'] = 'news/city/' . $city->tid;

  $vars['view'] = views_embed_view('news', 'news_city');

}
