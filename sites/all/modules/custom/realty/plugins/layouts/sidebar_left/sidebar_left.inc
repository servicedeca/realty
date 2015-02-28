<?php
/**
 * @file
 * landing_user.inc
 * Definition of custom panels layout.
 *
 */

// Plugin definition
$plugin = array(
  'category' => t('Realty'),
  'title' => t('Top, right, left sidebar'),
  'icon' => 'sidebar_left.png',
  'theme' => 'sidebar-left',
  'regions' => array(
    'top' => t('Top'),    
    'content_left' => t('Content: left'),
    'content_right' => t('Content: right'),
  ),
);
