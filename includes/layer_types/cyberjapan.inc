<?php

/**
 * @file CyberJapan layer type definition for OpenLayers
 */

class openlayers_layer_type_cyberjapan extends openlayers_layer_type {

  function options_init() {
    return array(
      'serverResolutions' => openlayers_get_resolutions('900913'),
      'maxExtent' => openlayers_get_extent('900913'),
      'projection' => array('900913'),
      'osm' => FALSE,
      'baselayer' => TRUE,
      'layer_handler' => 'CyberJapan',
      'layer_type' => 'cyberjapan',
      'type' => 'png',
    );
  }

  /**
   * Options form: only names and resolutions can change.
   */
  function options_form() {
    if (!isset($this->data)) {
      $this->data = $this->options_init();
    }
    /* define several censitive extents by lon/lat 
       w/ transform from WGS 1984
       to Spherical Mercator Projection
     */
    var fromProjection = new OpenLayers.Projection("EPSG:4326"); 
    var toProjection = new OpenLayers.Projection("EPSG:900913"); 
    var borderExtents =  array(
      new OpenLayers.Bounds(130.387,36.875,132.277,37.801).transform(fromProjection,toProjection),// takeshima
      new OpenLayers.Bounds(123.0, 25.0, 124.0, 26.0).transform(fromProjection,toProjection),// senkaku
    );
    var allJapanExtent = new OpenLayers.Bounds(122.0,20.0,154.0,46.5).transform(fromProjection,toProjection);
    return array(
      'layername' => array(
        '#type' => 'textfield',
        '#title' => t('Layer Name'),
        '#description' => t('The layer name'),
        '#default_value' => $this->data['layername']
      ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_cyberjapan'
      ),
      'baselayer' => array(
        '#type' => 'checkbox',
        '#default_value' => $this->data['baselayer'],
        '#title' => t('BaseLayer'),
        '#description' => t('Uncheck to make this map an overlay.'),
      ),
      'type' => array(
        '#type' => 'hidden',
        '#value' => 'png'
      ),
      'resolutions' => array(
        '#type' => 'select',
        '#multiple' => TRUE,
        '#options' => array_combine(array_map('strval', openlayers_get_resolutions('900913')), range(0, 18)),
        '#title' => t('Zoom Level Range'),
        '#default_value' => isset($this->data['resolutions']) ? $this->data['resolutions'] : object()
      ),
      'maxExtent' => array(
        '#type' => 'select',
        '#multiple' => FALSE,
        '#title' => 'Extent type',
        '#options' => array(
          borderExtents  => 'border',
          allJapanExtent => 'allJapan',
        ),
      ),
      'projection' => array(
        '0' => array(
          '#type' => 'hidden',
          '#value' => '900913',
        ),
      ),
    );
  }

  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'cyberjapan') . '/js/cyberjapan.js');
    drupal_add_js(drupal_get_path('module', 'cyberjapan') . '/includes/layer_types/cyberjapan_layer.js');
    drupal_add_css(drupal_get_path('module', 'cyberjapan') .'/css/webtis.css');
    return $this->options;
  }
}
