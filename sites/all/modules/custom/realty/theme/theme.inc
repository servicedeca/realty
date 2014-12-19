<?php

/**
 * @file.
 */

/**
 * Preprocess for excur-profile-form.tpl.php.
 */
function realty_preprocess_realty_profile_form(&$vars) {
  $a = 1;
  unset($vars['profile_form']['timezone']);
  unset($vars['profile_form']['locale']);
  unset($vars['profile_form']['metatags']);
}
