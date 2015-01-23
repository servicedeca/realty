<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_search_form_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Search form'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_search_form_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_search_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_search_form');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_search_form_content_type_theme(&$theme, $plugin) {
  $theme['realty_search_form'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-search-form',
  );
}

/**
 * Process variables for realty-search-form.tpl.php.
 */
function template_preprocess_realty_search_form(&$vars) {

  $vars['search_form'] = drupal_get_form('realty_search_form');

  $result = views_get_view_result('news', 'main_news');

  if ($result[0]) {
    $image_path = $result[0]->field_field_image_news[0]['raw']['uri'];
    $logo_path = $result[0]->field_field_news_logo[0]['raw']['uri'];
    $vars['title'] = $result[0]->node_title;
    if (!empty($image_path)) {
      $vars['image'] =  theme('image', array(
          'path' => $image_path,
          'attributes' => array(
            'class' => array('photo'),
          ),
        )
      );
    }
    if (!empty($logo_path)) {
      $vars['news_logo'] =  theme('image', array(
          'path' => $logo_path,
          'attributes' => array(
            'class' => array('logo-z'),
          ),
        )
      );;
    }
      $vars['description'] = $result[0]->field_body[0]['raw']['value'];
      $vars['details'] = l('Details', 'node/'.$result[0]->nid, array('attributes' => array('class' => 'button-info') ));
  }

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));

  $vars['areas'] = realty_get_options_current_city('area');
}
