<?php
/**
*@file
*Views integration for site_status
*/

/**
 * Implements hook_views_data()
 */
function site_status_views_data() {
  $table = array (
      'user_status' => array ( // User status Custom table
          'table' => array (
              'group' => 'Site_Status', // Groupname
              'base' => array (
                  'field' => 'sid', // Primary key
                  'title' => 'Site Status Log',
                  'help' => 'The log of site status toggles.' 
              ) 
          ),
          // Description of sid
          'sid' => array (
              'title' => t ( 'Site_Status Custom Id' ),
              'help' => t ( 'Site_Status Custom table Id field' ),
              // is Site_Status custom_id field sortable TRUE
              'field' => array (
                  'click sortable' => TRUE 
              ),
              // Filter handler for filtering records by sid
              'filter' => array (
                  'handler' => 'views_handler_filter_numeric' 
              ),
              'sort' => array (
                  'handler' => 'views_handler_sort' 
              ) 
          ),
          // Description of site_status date field
          'date' => array (
              'title' => t ( 'Site_Status Date' ),
              'help' => t ( 'Site_Status Date field' ),
              'field' => array (
                  'click sortable' => TRUE 
              ),
              'filter' => array (
                  'handler' => 'views_handler_filter_date' 
              ),
              'sort' => array (
                  'handler' => 'views_handler_sort' 
              ) 
          ),
          // Description of Site_Status UID field
          'uid' => array (
              'title' => t ( 'UID' ),
              'help' => t ( 'UID field' ),
              'field' => array (
                  'click sortable' => TRUE 
              ),
              'filter' => array (
                  'handler' => 'views_handler_filter_numeric' 
              ),
              'sort' => array (
                  'handler' => 'views_handler_sort' 
              ) 
          ),
          // Description of Site_Status Status field
          'status' => array (
              'title' => t ( 'Status' ),
              'help' => t ( 'Status field' ),
              'field' => array (
                  'click sortable' => TRUE
              ),
              'filter' => array (
                  'handler' => 'views_handler_filter_numeric'
              ),
              'sort' => array (
                  'handler' => 'views_handler_sort'
              )
          ),
      ) 
  );
  
  //Join the users table to allow filter by current logged in user.
  $table['users']['table']['join']['user_status'] = array(
      'left_field' => 'uid',
      'field' => 'uid',
  );
  
  return $table;
}

