<?php

/**
 * @file
 */

function _cyberjapan_openlayers_layers() {
  $layers = array();

  // cyberjapan basemap
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

  // Kiban WMS
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'kiban25000wms';
  $layer->title = 'FGD25000WMS';
  $layer->description = 'Fundamental Geospatial Data 25000 Web Map Service - GYOU-SHI No.449 2008';
  $layer->data = array(
    'osm' => FALSE,
    'baselayer' => FALSE,
    'type' => 'png',
    'attribution' => t('Copyright 2012, Geospatial Information Authority of Japan'),
    'projection' => array('900913'),
    'layer_type' => 'openlayers_layer_type_wms',
    'base_url' => 'http://www.finds.jp/ws/tmcwms.php?',
    'layers' => array('KBN25000ANF-900913'),
    'TRANSPARENT' => true,
    'srs' => null,
    'resolutions' => array_combine(range(0, 18), openlayers_get_resolutions('900913')),
    'params' => array(
      'maxextent' => array(13580978,2273031,17143202,5860840),
      'isBaseLayer' => FALSE,
    ),
  );
  $layers[$layer->name] = $layer;

  return $layers;
}
