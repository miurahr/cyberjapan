/**
 * @file
 * Layer handler for CyberJapan layers
 */

if (Drupal.openlayers === undefined) {
  Drupal.openlayers = {};
}
Drupal.openlayers.layer = Drupal.openlayers.layer || {};

/**
 * Openlayer layer handler for CyberJapan layer
 */
Drupal.openlayers.layer.CyberJapan = function(title, map, options) {
  var styleMap = Drupal.openlayers.getStyleMap(map, options.name);
    if (options.maxExtent !== undefined) {
      options.maxExtent = new OpenLayers.Bounds.fromArray(options.maxExtent);
    }
    if (options.type === undefined){
      options.type = "png";
    }
    options.projection = new OpenLayers.Projection('EPSG:'+options.projection);
    var layer = new OpenLayers.Layer.CyberJapan(title, options);
    layer.styleMap = styleMap;
    return layer;
};
