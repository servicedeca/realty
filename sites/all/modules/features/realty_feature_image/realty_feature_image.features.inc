<?php
/**
 * @file
 * realty_feature_image.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function realty_feature_image_image_default_styles() {
  $styles = array();

  // Exported image style: realty-1.
  $styles['realty-1'] = array(
    'name' => 'realty-1',
    'label' => 'realty-1',
    'effects' => array(),
  );

  return $styles;
}
