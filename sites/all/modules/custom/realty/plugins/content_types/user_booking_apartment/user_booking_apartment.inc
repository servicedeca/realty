<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_user_booking_apartment_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('User booking apartment'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_user_booking_apartment_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_user_booking_apartment_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;

  $block = new stdClass();
  $block->content = theme('realty_user_booking_apartment');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_user_booking_apartment_content_type_theme(&$theme, $plugin) {
  $theme['realty_user_booking_apartment'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-user-booking-apartment',
  );
}

/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_user_booking_apartment(&$vars) {
  global $user;

  $get_id = views_get_view_result('apartments', 'user_apartment', $user->uid);
  $booking = views_get_view_result('apartments', 'booking_apartment', $user->uid);
  if (!empty($get_id)) {
    foreach ($get_id as $key => $val) {
      $vars['apartments'][] = array(
        'nid' => $val->nid,
        'id' => $val->field_field_id_appartament[0]['raw']['value'],
        'book' => t('not booked')
      );
      if (!empty($booking)) {
        foreach ($booking as $i => $book) {
          if ($val->nid == $book->nid) {
            continue;
          }
          else {
            $flag = FALSE;
            foreach ($vars['apartments'] as $apartment) {
              if ($apartment['nid'] == $book->nid) {
                $flag = TRUE;
              }
            }
            if ($flag == FALSE) {
              $vars['apartments'][] = array(
                'nid' => $book->nid,
                'id' => $book->field_field_id_appartament[0]['raw']['value'],
                'book' => $book->field_field_booking_numbers[0]['raw']['value'],
              );
            }
          }
        }
      }
    }
  }
}