# Vagrant машина Fedora 24

### Инструкция по настройке


* склонировать репозиторий командой `git clone https://github.com/evgwed/fedora_box.git bars --config core.autocrlf=false` и `cd bars`
* сгенерировать ключ для аботы с stash по ssh командой `ssh-keygen -t rsa -b 4096 -C "ваша почта@simbirsoft.com"` https://help.github.com/articles/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent/
Должны быть созданы файлы id_rsa и id_rsa.pub в папке `~/.ssh/`
* Добавить содержимое(открыть в блокноте и скопировать) `id_ras.pub` в stash по ссылке (https://stash.bars-open.ru/plugins/servlet/ssh/account/keys/add)
* Перейти в папку `vagrant` и выполнить команду `cp Vagrantfile.example Vagrantfile`
*  Выполнить команду запуска машины и дождаться завершения установки `vagrant up`
*  Перезапустить машину, выполнив команду `vagrant reload`
*  Зайти в машину `vagrant ssh` и внутри выполнить команду `cd /vagrant` и  `sudo sh install.sh` (везде отвечать yes/enter в ходе установки)
*  выйти из машины `exit`
* Выполнить следующие команды:
```
cd ../project
git clone ssh://git@stash.bars-open.ru:7999/med/mis-out.git mis
git clone ssh://git@stash.bars-open.ru:7999/med/mis_d3.git mis/d3
mkdir mis/d3/Extensions
git clone ssh://git@stash.bars-open.ru:7999/med/mis_d3ext.git mis/d3/Extensions/mis
mkdir mis/temp
mkdir mis/d3/temp
cp ../vagrant/conf/mis/Etc/conf.inc mis/Etc/conf.inc
cp ../vagrant/conf/mis/d3/Etc/conf.inc mis/d3/Etc/conf.inc
```
*  Перезапустить машину, выполнив команду `vagrant reload`
*  Добавить в файл `hosts` строку `192.168.100.103 bars.test`
* Открыть в браузере http://bars.test/mis и убедиться, что открылась страница авторизации в системе

 
 ### Возможные ошибки

 ##### Если на этапе `vagrant up` на моменте с ssh и падает с сообщением об увеличении timeout.
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
Необходимо открыть настройки машины и в Сеть указать для Адаптера 1 галку "Кабель подключен". (http://prntscr.com/d13mgq).

 ##### Если падает с ошибкой на сеть:
```
The following SSH command responded with a non-zero exit status.
Vagrant assumes that this means the command failed!

/sbin/ifdown 'enp0s8'
/sbin/ifdown 'enp0s9'
mv -f '/tmp/vagrant-network-entry-enp0s8-1537957192-0' '/etc/sysconfig/network-scripts/ifcfg-enp0s8'
mv -f '/tmp/vagrant-network-entry-enp0s9-1537957193-1' '/etc/sysconfig/network-scripts/ifcfg-enp0s9'
(test -f /etc/init.d/NetworkManager && /etc/init.d/NetworkManager restart) || ((systemctl | grep NetworkManager.service) && systemctl restart NetworkManager)
/sbin/ifup 'enp0s8'
/sbin/ifup 'enp0s9'
...
```

Нужно в файле `Vagrantfile` вместо `config.vm.network "public_network"` прописать `config.vm.network "public_network", bridge: "имя подключения, оно выпадает в списке", auto_config: false`.