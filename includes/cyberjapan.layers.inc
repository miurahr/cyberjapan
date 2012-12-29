<?php

/**
 * @file
 */

function _cyberjapan_openlayers_layers() {
  $layers = array();

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'cyberjapan';
  $layer->title = 'Cyber Japan Map';
  $layer->description = 'Cyber Japan Map';
  $layer->data = array(
    'osm' => FALSE,
    'baselayer' => TRUE,
    'type' => 'png',
    'attribution' => t('Copyright 2012, Geospatial Information Authority of Japan'),
    'projection' => array('900913'),
    'layer_type' => 'openlayers_layer_type_cyberjapan',
    'resolutions' => array_combine(range(0, 18), openlayers_get_resolutions('900913')),
  );
  $layers[$layer->name] = $layer;

  return $layers;
}
