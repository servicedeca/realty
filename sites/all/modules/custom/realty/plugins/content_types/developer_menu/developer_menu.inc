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
      'path' => l(t('current objects'), 'developer/' . $term->tid .'/complexes'),
      'title' => 'current',
    ),
    1 => array(
      'path' => l(t('archive'), 'developer/' . $term->tid . '/archive'),
      'title' => 'archive',
    ),
    2 => array(
      'path' => l(t('Gallery'), 'developer/' . $term->tid . '/gallery'),
      'title' => 'gallery',
    ),

    3 => array(
      'path' => l(t('Stock'), 'developer/' . $term->tid . '/stock'),
      'title' => 'stock',
    ),
  );

  foreach($menu_items as $key => $item) {
    if($url == $item['title']) {
      $vars['menu'][$key] = '<li class="active-menu">'.$item['path'].'</li>';
      $vars['page'] = $item['path'];
    }
    else {
      $vars['menu'][$key] = '<li>'.$item['path'].'</li>';
    }
  }

  $vars['name'] = $term->name;
  if (!empty($term->field_developer_mini_logo)) {
    $path = $term->field_developer_mini_logo[LANGUAGE_NONE][0]['uri'];
  }
  else {
      $path = $term->field_developer_logo[LANGUAGE_NONE][0]['uri'];
  }

  $vars['logo'] = theme('image', array(
    'path' => $path,
    'attributes' => array(
      'class' => array('complex-logo'),
    ),
  ));

}
