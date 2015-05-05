<?php

define('FTP_HOST', '62.109.22.209');
define('FTP_USER', 'ftpadmin');
define('FTP_PASSWORD', 'password1');

/**
 * Implements hook_drush_command().
 */
function realty_data_update_drush_command(){
  $items['apartment-update'] = array(
    'description' => 'Apartment update',
    'aliases' => array('aup'),
    'callback' => 'realty_data_update_drush_apartment_update',
  );

  return $items;
}

/**
 *
 */
function realty_data_update_complex_name_list() {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->propertyCondition('status', 1);
  $query->propertyCondition('type', 'complex');
  $result = $query->execute();
  return node_load_multiple(array_keys($result['node']));
}

/**
 * The connection to the ftp server.
 */
function realty_data_update_connect_ftp() {
  $connect = ftp_connect(FTP_HOST);

  if(!$connect) {
    die('Error connect');
  }

  $result = ftp_login($connect, FTP_USER, FTP_PASSWORD);
  $directory = ftp_nlist($connect, "/");
  foreach ($directory as $dir) {
    $files = ftp_nlist($connect, $dir . "/files");
    foreach ($files as $file) {
      $name_file = explode('/', $file);
      $fp = fopen(realty_file_directory_path(). '/ftpfiles/' . $name_file[3], "w");
      fclose($fp);
      ftp_get($connect, realty_file_directory_path(). '/ftpfiles/' . $name_file[3], $file, FTP_BINARY);
      $local_files[] =  $name_file[3];
    }
  }
  return $local_files;
}

/**
 * Callback for 'apartment-update'drush command.
 */
function realty_data_update_drush_apartment_update() {
  $complexes = realty_data_update_complex_name_list();
  $files = realty_data_update_connect_ftp();
  foreach ($files as $file) {
    //$name_file = explode('/', $file);
    $xmlNode = simplexml_load_file(realty_file_directory_path(). '/ftpfiles/' . $file);
    $object = realty_data_update_xmlToArray($xmlNode);
    $complex_name = $object['LISTINGS']['PARTNER']['COMPLEX_NAME'];
    foreach ($complexes as $complex) {
      if ($complex->title == $complex_name) {
        $complex_id = $complex->nid;
        break;
      }
    }
    $apartment_complex = views_get_view_result('apartments', 'apartments_complex_for_plan', $complex_id);
    foreach ($object['LISTINGS']['ADS']['OBJECT'] as $val) {
      foreach ($apartment_complex as $apartment) {
        if ($apartment->field_field_number_apartament[0]['raw']['value'] == $val['AD']['@APPTNUM']) {
          $a = 1;
          if ($val['TYPE_STATUS'] == 'В продаже') {
            $node = node_load($apartment->nid);
            $node->field_status[LANGUAGE_NONE][0]['value'] = 1;
            node_save($node);
            continue;
          }
          if ($val['TYPE_STATUS'] == 'Бронь') {
            $node = node_load($apartment->nid);
            $node->field_status[LANGUAGE_NONE][0]['value'] = 0;
            node_save($node);
            continue;
          }
          if ($val['TYPE_STATUS'] == 'Продано') {
            $node = node_load($apartment->nid);
            $node->status = 0;
            node_save($node);
            continue;
          }
        }
      }
    }
    $a = 1;
  }

}




/**
 * Converter xml.
 */
function realty_data_update_xmlToArray($xml, $options = array()) {
  $defaults = array(
    'namespaceSeparator' => ':',//you may want this to be something other than a colon
    'attributePrefix' => '@',   //to distinguish between attributes and nodes with the same name
    'alwaysArray' => array(),   //array of xml tag names which should always become arrays
    'autoArray' => true,        //only create arrays for tags which appear more than once
    'textContent' => '$',       //key used for the text content of elements
    'autoText' => true,         //skip textContent key if node has no attributes or child nodes
    'keySearch' => false,       //optional search and replace on tag and attribute names
    'keyReplace' => false       //replace values for above search values (as passed to str_replace())
  );
  $options = array_merge($defaults, $options);
  $namespaces = $xml->getDocNamespaces();
  $namespaces[''] = null; //add base (empty) namespace

  //get attributes from all namespaces
  $attributesArray = array();
  foreach ($namespaces as $prefix => $namespace) {
    foreach ($xml->attributes($namespace) as $attributeName => $attribute) {
      //replace characters in attribute name
      if ($options['keySearch']) $attributeName =
        str_replace($options['keySearch'], $options['keyReplace'], $attributeName);
      $attributeKey = $options['attributePrefix']
        . ($prefix ? $prefix . $options['namespaceSeparator'] : '')
        . $attributeName;
      $attributesArray[$attributeKey] = (string)$attribute;
    }
  }

  //get child nodes from all namespaces
  $tagsArray = array();
  foreach ($namespaces as $prefix => $namespace) {
    foreach ($xml->children($namespace) as $childXml) {
      //recurse into child nodes
      $childArray = realty_data_update_xmlToArray($childXml, $options);
      list($childTagName, $childProperties) = each($childArray);

      //replace characters in tag name
      if ($options['keySearch']) $childTagName =
        str_replace($options['keySearch'], $options['keyReplace'], $childTagName);
      //add namespace prefix, if any
      if ($prefix) $childTagName = $prefix . $options['namespaceSeparator'] . $childTagName;

      if (!isset($tagsArray[$childTagName])) {
        //only entry with this key
        //test if tags of this type should always be arrays, no matter the element count
        $tagsArray[$childTagName] =
          in_array($childTagName, $options['alwaysArray']) || !$options['autoArray']
            ? array($childProperties) : $childProperties;
      } elseif (
        is_array($tagsArray[$childTagName]) && array_keys($tagsArray[$childTagName])
        === range(0, count($tagsArray[$childTagName]) - 1)
      ) {
        //key already exists and is integer indexed array
        $tagsArray[$childTagName][] = $childProperties;
      } else {
        //key exists so convert to integer indexed array with previous value in position 0
        $tagsArray[$childTagName] = array($tagsArray[$childTagName], $childProperties);
      }
    }
  }

  //get text content of node
  $textContentArray = array();
  $plainText = trim((string)$xml);
  if ($plainText !== '') $textContentArray[$options['textContent']] = $plainText;

  //stick it all together
  $propertiesArray = !$options['autoText'] || $attributesArray || $tagsArray || ($plainText === '')
    ? array_merge($attributesArray, $tagsArray, $textContentArray) : $plainText;

  //return node as array
  return array(
    $xml->getName() => $propertiesArray
  );
}