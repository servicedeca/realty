<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_menu_complex_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Menu complex '),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_menu_complex_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_menu_complex_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_menu_complex');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_menu_complex_content_type_theme(&$theme, $plugin) {
  $theme['realty_menu_complex'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-menu-complex',
  );
}

/**
 * Process variables for realty-menu-complex.tpl.php.
 */
function template_preprocess_realty_menu_complex(&$vars) {
  $nid = arg(1);
  $node = node_load($nid);

  $dev_tid = $node->field_complex_developer['und'][0]['tid'];
  $developer = taxonomy_term_load($dev_tid);
  $city_tid = $developer->field_city[LANGUAGE_NONE][0]['tid'];
  $city = taxonomy_term_load($city_tid);
  $vars['city'] = l($city->name, 'taxonomy/term/' . $city->tid);
  $vars['complex'] = l($node->title, 'node/' . $node->nid);
  $vars['title_complex'] = l($node->title, 'node/' . $node->nid, array('attributes' => array('class' => array('active-complex'))));
  if (!empty($node->field_complex_mini_logo)) {
    $vars['complex_mini_logo'] = theme('image', array(
      'path' => $node->field_complex_mini_logo[LANGUAGE_NONE][0]['uri'],
      'alt' => $node->title,
      'title' => $node->title,
      'attributes' => array(
        'class' => array('complex-logo'),
      ),
    ));
  }

  $menu_items = array(
    0 => array(
      'path' => l(t('Plan RC'), 'complexes/' .$node->nid. '/plan'),
      'title' => 'plan',
    ),
    1 => array(
      'path' => l(t('Gallery'), 'complexes/' .$node->nid. '/gallery'),
      'title' => 'gallery',
    ),
    2 => array(
        'path' => l(t('Documents'), 'complexes/' .$node->nid. '/documents'),
      'title' => 'documents',
    ),

    3 => array(
      'path' => l(t('Stock'), 'complexes/' .$node->nid. '/stock'),
      'title' => 'stock',
    ),
  );
  $url = arg(2);
  foreach($menu_items as $key=>$item) {
    if($url == $item['title']) {
      $vars['menu'][$key] = '<li class="active-menu">'.$item['path'].'</li>';
      $vars['page'] = $item['path'];
    }
    else {
      $vars['menu'][$key] = '<li>'.$item['path'].'</li>';
    }
  }
}
