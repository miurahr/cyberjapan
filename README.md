CyberJapan module for drupal/openlayers
=======================================

CyberJapan provides Digital Japan tile map  layer provided by GSI,
Japan onto the openlayers. The OpenLayers Module and its submodules
bring the OpenLayers JS library into Drupal. 
You can show Digital Japan map on your site using the OpenLayers module
and the CyberJapan module.

FEATURES
--------

CyberJapan now only support a tile map image for base map.

REQUIREMENTS
------------

* OpenLayers module
* Chaos Tools (ctools) module

INSTALLATION
------------

1. You can get module from github.com

git clone --recursive https://github.com/miurahr/cyberjapan.git

now with --recursive option, you also get cyberjapan-js project into js/ subdirectory
as submodule.

If you use older git, you may need to do as following:

$ git clone --recursive https://github.com/miurahr/cyberjapan.git
$ cd cyberjapan
$ git submodule update --init


2. Install as usual.

You can place files at <drupal-root>/site/all/modules/cyberjapan/
and enable module from administer/module interface.


CONFIGURATION
-------------

You can use CyberJapan Map as same as OSM mapnik map for Base Layers.

RoadMap & Current State
-----------------------

* == 1.x == current:  first public version. Only support for basemap. It support only map image.
* == 2.x == overlay support, ability to select map data collection for layers, photo image layer.


CONTACT
---------

Developer

* Hiroshi Miura (miurahr) - http://drupal.org/user/101223



LEGAL and CONDITIONS
--------------------

You can see a license and rules of Digital Japan map data 
at http://portal.cyberjapan.jp/portalsite/kiyaku/index.html

The development roadmap of  Digital Japan Web System is placed on
http://portal.cyberjapan.jp/portalsite/version/djapan_yotei.html

Some portion are come from 'DenshiKokudo Web API for OpenLayers'.

You may require to get a written permission from Geospatial Information 
Authority of Japan, according to the rule of Digital Japan map data usage.
There are some exception. Details are placed at
http://portal.cyberjapan.jp/portalsite/kiyaku/kyodaku.html

You also need to display Digital Japan logo where web site shows Digital Japan map.
http://cyberjapan.jp/image/logo.gif
http://portal.cyberjapan.jp/portalsite/q_and_a/ans7.html


LICENSE
--------

File: cyberjapan.js
Copyright: 2012 Hiroshi Miura and Geospatial Information Authority of Japan
License: FreeBSD and GPLv2+ dual license

Files: *
Copyright: 2012 Hiroshi Miura and MapBox Inc.
License: GPLv2+





[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/miurahr/cyberjapan/trend.png)](https://bitdeli.com/free "Bitdeli Badge")

