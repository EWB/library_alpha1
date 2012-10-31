<?php
/**
 * @file
 * feed_for_library_databases.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function feed_for_library_databases_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'library_database_importer';
  $feeds_importer->config = array(
    'name' => 'Library Database Importer',
    'description' => 'Import library databases from D5 site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
        'allowed_extensions' => 'txt csv tsv xml opml',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'base_library_database',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'vid',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'field_library_database_link_title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_library_database_link_url',
            'target' => 'field_database_link:url',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_description_brief_value',
            'target' => 'field_database_brief_description',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_library_database_link_title',
            'target' => 'field_database_link:title',
            'unique' => FALSE,
          ),
        ),
        'input_format' => 'plain_text',
        'author' => '1',
        'authorize' => 1,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['library_database_importer'] = $feeds_importer;

  return $export;
}
