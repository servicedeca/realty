<?php
/**
 * @file
 * realty_feature_field_base.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function realty_feature_field_base_taxonomy_default_vocabularies() {
  return array(
    'area' => array(
      'name' => 'Районы',
      'machine_name' => 'area',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'cities' => array(
      'name' => 'Города',
      'machine_name' => 'cities',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 5,
    ),
    'developers' => array(
      'name' => 'Застройщики',
      'machine_name' => 'developers',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'homes' => array(
      'name' => 'Дома',
      'machine_name' => 'homes',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'metro' => array(
      'name' => 'Метро',
      'machine_name' => 'metro',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
