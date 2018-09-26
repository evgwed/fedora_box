<?php
$ConfigOptions = array(
    'DatabaseName' => '//192.168.224.70/med2dev:shared',

    'OutCodePage' => 'UTF-8',
    'DatabaseCharset' => 'UTF8',
    'TempTalonsDir' => 'c:/SharedTalonsDir/',
    'debug' => 1,
    'TempDir' => 'temp/',
    'help_conf' => 'Etc/help.inc',
    'openssl' => 'C:\OpenSSL-Win64\bin\openssl.exe',
    'FilesDir' => 'Files/',
    'XlsCharset' => 'windows-1251',
    'Forms' => '/Forms/',
    'UserForms' => '/UserForms/',
	
    'RecipsBarCodesFontPath' => 'Modules/Recips/PDF417Font.ttf',

    'wkhtmltopdf' => array(
        'binpath'   => 'C:/Program Files/wkhtmltopdf/bin/', // путь до директории с исполняющими файлам программы
        'binfile'   => 'wkhtmltopdf.exe', // имя исполняющего файла
        'binprefix' => 'env LANG=ru_RU.UTF-8' //
    ),
    'Exec7z' => 'C:\Program Files\7-Zip\7z.exe',
    'zint' => 'zint',
    'Theme' => (isset($_GET["theme"])) ? $_GET["theme"] : 'bars',
    'design_mode' => 0,
    'enabled_modules' => array(),
    'cache_maxage' => 3600, //client
    'cache_enabled' => 0,
    'cache_type' => 'server', // client, server, both
    'cache_dir' => 'temp/cache/',
    'cache_ttl' => 60 * 60 * 3, // server
    'client_config' => '{jsPrintSetup: {marginTop: 5, marginRight: 5, marginBottom: 5, marginLeft: 5}}',
    'ldap_auth' => array( //Информация для авторизации по LDAP

        //Статус, вкл.(true)/выкл.(false)
        'enabled' => false,
        //Имя хоста или IP сервера авторизации
        'hostname' => '127.0.0.1',
        //Порт
        'port' => null,
        //Домен
        'domain' => '',
        //Кодировка используемая в LDAP
        'charset' => 'windows-1251',
        //Пользователи,для которых не использовать LDAP авторизацию, а авторизовать стандартным механизмом
        'sysusers' => array(),
        //Атрибут содержащий полное имя пользователя
        'attr_name' => 'cn',
        //Атрибут содержащий логин пользователя
        'attr_login' => 'samaccountname',
        //Атрибут содержащий группы, в которых состоит пользователь
        'attr_groups' => 'memberof',
        //Путь до каталога, для поиска пользователей
        'dn' => 'CN=Users,DC=domain,DC=ru',
        //Список групп в которых должен состоять пользователь, чтобы пройти авторизацию. Если список пустой то проверка не производится.
        'groups' => array(),
        //Пользователь, который имеет права на добавление пользователей и удаление/добавление ролей
        'sysuser' => '',
        //Пароль
        'sysuserpass' => '',
        //ЛПУ
        'sysuserlpu' => '',
        //Создавать пользователя в системе, true - да, false - нет
        'create_user' => true,
        //Каталог, в котором будут созданы новые пользователи
        'catalog' => '',
        //Синхронизировать роли со списком групп, в которых состоит пользователь, true - да, false - нет
        'sync_roles' => true,
        //Список ролей, которые будут назначены по умолчанию
        'roles_default' => array(
            'Минимальная'
        ),
        //Синхронизировать роли всегда, true - да, false - использовать кеширование, если набор групп не изменился
        'sync_force' => true,
        //Использовать только LDAP-авторизацию, true - да, false - использовать дополнительно стандартный механизм
        'only' => true
    ),
    'esia_auth' => array( // Настройки авторизации через ЕСИАиА
        // Статус, вкл.(true)/выкл.(false)
        'enabled' => true,
        // Пользователь под которым подключаться к системе, array('логин','пароль')
        'sysuser' => array('esia', '')
    ),
    'cas_auth' => array( // Настройки авторизации CAS
        // Статус, вкл.(true)/выкл.(false)
        'enabled' => true,
        'version' => '2.0',
        'hostname' => 'demo.i-novus.ru',
        'port' => 443,
        'uri' => 'cas',
        'certificate' => '',
        // Пользователь под которым подключаться к системе, array('логин','пароль')
        'sysuser' => array('mva', '')
    ),
    'cas_risar_auth' => array( // Настройки авторизации CAS РИСАР
        // Статус, вкл.(true)/выкл.(false)
        'enabled' => true,
        'uri' => 'cas_risar',
        // Пользователь под которым подключаться к системе, array('логин','пароль')
        'sysuser' => array('dev', '')
	),
    'd3' => './d3/',
    '' => 0);