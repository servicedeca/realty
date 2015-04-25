<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_menu_complex_gallery_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Menu complex gallery'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_menu_complex_gallery_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_menu_complex_gallery_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_menu_complex_gallery');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_menu_complex_gallery_content_type_theme(&$theme, $plugin) {
  $theme['realty_menu_complex_gallery'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-menu-complex-gallery',
  );
}

/**
 * Process variables for realty-menu-complex.tpl.php.
 */
function template_preprocess_realty_menu_complex_gallery(&$vars) {
  $nid = arg(1);
  $node = node_load($nid);

  $menu_items = array(
    0 => array(
      'path' => l(t('visualization'), 'complexes/' . $node->nid . '/gallery/visualization'),
      'title' => 'visualization',
    ),

    1 => array(
      'path' => l(t('diaries construction'), 'complexes/' . $node->nid . '/gallery/photo'),
      'title' => 'photo',
    ),

    2 => array(
      'path' => l(t('3D tour'), 'complexes/' . $node->nid . '/gallery/tour'),
      'title' => 'tour',
    ),
  );

  $url = arg(3);
  foreach ($menu_items as $key => $item) {
    if ($url == $item['title']) {
      $vars['menu'][$key] = '<div class="col-xs-4 tab-menu-active">' . $item['path'] . '</div>';
      $vars['page'] = $item['path'];
    }
    else {
      $vars['menu'][$key] = '<div class="col-xs-4 tab-menu-passive">' . $item['path'] . '</div>';
    }
  }

}
