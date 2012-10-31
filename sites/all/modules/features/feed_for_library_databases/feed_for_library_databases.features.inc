<?php
/**
 * @file
 * feed_for_library_databases.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feed_for_library_databases_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
