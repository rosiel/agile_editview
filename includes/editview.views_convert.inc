<?php

/**
 * @file
 * Style conversion for editable node views.
 */

/**
 * Implements hook_views_convert().
 */
function editview_views_convert($display, $type, &$view, $field) {
  static $displays = array();
  if ($type == 'style') {
    switch ($field) {
      case 'editview_table':
      case 'editview_compressed':
        $displays[] = $display;
        $handler = &$view->display[$display]->handler;
        $handler->set_option('style_plugin', 'editview');
        break;
    }
  }
  elseif ($type == 'filter' && $field['field'] == 'type') {
    foreach ($displays as $display) {
      $handler = &$view->display[$display]->handler;
      $handler->set_option('style_options', array(
        'editview_node_type' => array_shift($field['value']),
        'editview_node_position' => EDITVIEW_NEW_ABOVE,
      ));
    }
  }
}
