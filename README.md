# Vagrant машина Fedora 24

### Инструкция по настройке

* Перейти в папку `vagrant` и выполнить команду `cp Vagrantfile.example Vagrantfile`
*  Выполнить команду запуска машины и дождаться завершения установки `vagrant up`
*  Перезапустить машину, выполнив команду `vagrant reload`
*  Добавить в файл `hosts` строку `192.168.100.103 bars.dev`
* Открыть в браузере http://bars.dev/ и убедиться, что открылась страница **Fedora Test Page**
 
 ### Возможные ошибки

* Если на этапе `vagrant up` на моменте с ssh и падает с сообщением об увеличении timeout.
```
Bringing machine 'default' up with 'virtualbox' provider...
==> default: Importing base box 'bento/fedora-24'...
==> default: Matching MAC address for NAT networking...
==> default: Setting the name of the VM: bars_medicine
==> default: Clearing any previously set network interfaces...
==> default: Preparing network interfaces based on configuration...
    default: Adapter 1: nat
    default: Adapter 2: hostonly
    default: Adapter 3: bridged
==> default: Forwarding ports...
    default: 80 (guest) => 8080 (host) (adapter 1)
    default: 22 (guest) => 2222 (host) (adapter 1)
==> default: Running 'pre-boot' VM customizations...
==> default: Booting VM...
==> default: Waiting for machine to boot. This may take a few minutes...
    default: SSH address: 127.0.0.1:2222
    default: SSH username: vagrant
    default: SSH auth method: private key
    default: Error: Connection timeout. Retrying...
    default: Error: Connection timeout. Retrying...
    default: Error: Connection timeout. Retrying...
    default: Error: Connection timeout. Retrying...
    default: Error: Connection timeout. Retrying...
    default: Error: Connection timeout. Retrying...
    default: Error: Connection timeout. Retrying...
    default: Error: Connection timeout. Retrying...
    default: Error: Connection timeout. Retrying...
```
Необходимо открыть настройки машины и в Сеть указать для Адаптера 1 галку "Кабель подключен". (http://prntscr.com/d13mgq)