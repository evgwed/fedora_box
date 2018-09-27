<?php
$ConfigOptions = array(

    //	в конфе д3 изменить/добавить следующее:
    'Extensions' => array('path' => 'Extensions/',
        'only' => array('mis')),
    'Forms' => array(
        '/FormsMis/',
        '/Forms/'
    ),
    'UserForms' => '/UserFormsMis/',
    //т.е. указать расширение мис, и указать путь до мисовских форм
    'Theme' => 'bars',

    'client_config' => array('formCache' => false, 'showDependence' => false, 'path' => 'd3'),

    'DBType' => 'MIS',
    'DatabaseName' => '',
    //тип базы - МИС, без указания самой БД

    'OutCodePage' => 'UTF-8',
    'DatabaseCharset' => 'UTF8',
    'debug' => 2,
    'TempDir' => 'temp/',
    'FilesDir' => 'Files/',
    'XlsCharset' => 'windows-1251',
    'Exec7z' => '"/usr/bin/zip"',
    'zint' => 'zint',
    'design_mode' => 0,
    'enabled_modules' => array(),
    'cache_maxage' => 3600, //client
    'cache_enabled' => 0,
    'cache_type' => 'server', // client, server, both
    'cache_dir' => 'temp/cache/',
    'cache_ttl' => 60 * 60 * 3, // server
    'session_cache' => 1,
    'proxy_auth' => array('hostname' => null, //'bsrv',
        'port' => null, //8080,
        'user' => null, //'',
        'pass' => ''),
    '' => 0
);