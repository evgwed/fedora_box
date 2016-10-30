#!/bin/bash
sudo dnf install -y httpd php php-devel php-xml php-gd php-pgsql php-mbstring php-zip

sudo cp /vagrant/conf/httpd/conf.modules.d/00-base.conf /etc/httpd/conf.modules.d/00-base.conf
sudo cp /vagrant/conf/httpd/conf/httpd.conf /etc/httpd/conf/httpd.conf
sudo cp /vagrant/conf/php.ini /etc/php.ini
sudo cp /vagrant/conf/selinux/config /etc/selinux/config

sudo setenforce 0

chown -R vagrant:vagrant /var/www/html/
