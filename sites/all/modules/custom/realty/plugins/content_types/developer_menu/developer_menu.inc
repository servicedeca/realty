<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_developer_menu_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Menu developer'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_developer_menu_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_developer_menu_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_developer_menu');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_developer_menu_content_type_theme(&$theme, $plugin) {
  $theme['realty_developer_menu'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-developer-menu',
  );
}

/**
 * Process variables for realty-menu-complex.tpl.php.
 */
function template_preprocess_realty_developer_menu(&$vars) {
  $entity = arg(1);
  if ($entity == 'term') {
    $term = menu_get_object('taxonomy_term', 2);
  }
  else {
    $term = taxonomy_term_load($entity);
    $url = arg(2);
  }
  $menu_items = array(
    0 => array(
      'path' => l($term->name, 'taxonomy/term/' . $term->tid),
      'title' => 'developer',
    ),
    1 => array(
      'path' => l(t('current objects'), 'developer/' . $term->tid . '/complexes'),
      'title' => 'complexes',
    ),
    2 => array(
      'path' => l(t('archive'), 'developer/' . $term->tid . '/archive'),
      'title' => 'archive',
    ),
    3 => array(
      'path' => l(t('Gallery'), 'developer/' . $term->tid . '/gallery'),
      'title' => 'gallery',
    ),

    4 => array(
      'path' => l(t('Stock'), 'developer/' . $term->tid . '/stock'),
      'title' => 'stock',
    ),
  );
  $tid = arg(2);
  foreach ($menu_items as $key => $item) {
    if ($url == $item['title']) {
      $vars['menu'][$key] = '<li class="active-menu">' . $item['path'] . '</li>';
      $vars['page'] = $item['path'];
    }
    else {
      $vars['menu'][$key] = '<li>' . $item['path'] . '</li>';
    }
  }

  $vars['name'] = l($term->name, 'taxonomy/term/' . $term->tid, array(
    'attributes' => array(
      'class' => array('active-complex'),
    ),
  ));

  $vars['logo'] = theme('image', array(
    'path' => $term->field_developer_logo[LANGUAGE_NONE][0]['uri'],
    'attributes' => array(
      'class' => array('complex-logo', 'developer-logo'),
    ),
  ));

}
