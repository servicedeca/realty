<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_bread_crumbs_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Bread crumbs'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_bread_crumbs_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_bread_crumbs_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_bread_crumbs');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_bread_crumbs_content_type_theme(&$theme, $plugin) {

  $theme['realty_bread_crumbs'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-bread-crumbs',
  );
}

/**
 * Process variables for realty-block-complexes.tpl.php.
 */
function template_preprocess_realty_bread_crumbs(&$vars) {

  $entity = arg(0);
  $tit = drupal_get_title();
  if ($entity == 'node') {
    $node =  menu_get_object('node', 1);
    $complex = node_load($node->field_apartament_home[LANGUAGE_NONE][0]['taxonomy_term']->field_home_complex['und'][0]['target_id']);
    $developer = taxonomy_term_load($complex->field_complex_developer[LANGUAGE_NONE][0]['tid']);
    $city = taxonomy_term_load($developer->field_city[LANGUAGE_NONE][0]['tid']);
    $vars['bread_crumbs'] = array(
      'city' => l($city->name, 'taxonomy/term/' . $city->tid),
      'complex' => l($complex->title, 'node/' . $complex->nid),
      'apartment' => l(t('apartment') . ' №' . $node->field_number_apartament[LANGUAGE_NONE][0]['value'] ,
        'node/' . $node->nid)
    );
  }
  elseif ($entity == 'taxonomy' || $entity == 'developer') {
    $tid = arg(1);
    $entity == 'taxonomy' ? $term = menu_get_object('taxonomy_term', 2) : $term = taxonomy_term_load(arg(1));
    if ($term->vid == 3) {
      $city = taxonomy_term_load($term->field_city[LANGUAGE_NONE][0]['tid']);
      $vars['city'] = l($city->name, 'taxonomy/term/' . $city->tid);
      $vars['bread_crumbs'] = array(
        'city' => l($city->name, 'taxonomy/term/' . $city->tid),
        'developers' => l(t('developers'), 'developers/city/' . $city->tid),
        'developer' => l($term->name, 'taxonomy/term/' . $term->tid),
      );
      if ($entity == 'developer') {
      }
    }
    if ($term->vid == 10) {
      $vars['bread_crumbs']['partners'] = l($term->name, '#href', array('external' => TRUE));
    }
  }
  elseif ($entity == 'city') {
    $city = taxonomy_term_load(arg(1));
    $vars['bread_crumbs']['city'] = l($city->name, 'taxonomy/term/' . $city->tid);
    if (arg(2) == 'stock') {
      $vars['bread_crumbs']['stock'] = l(t('Акции'), '#href', array('external' => TRUE));
    }
    elseif (arg(2) == 'news') {
      $vars['bread_crumbs']['news'] = l(t('Новости'), '#href', array('external' => TRUE));
    }
    elseif (arg(2) == 'partners') {
      $vars['bread_crumbs']['partners'] = l(t('partners'), '#href', array('external' => TRUE));
    }

  }
}