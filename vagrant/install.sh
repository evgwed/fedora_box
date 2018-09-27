#!/bin/bash
sudo dnf install -y httpd php php-devel php-xml php-gd php-pgsql php-mbstring php-zip php-pear
sudo dnf install -y gcc sshpass git wkhtmltopdf liberation-* libpng12 
sudo dnf install -y xorg-x11-server-Xvfb
export PHP_DTRACE=yes
sudo pecl install -y oci8-2.0.12

sudo cp /vagrant/conf/httpd/conf.modules.d/00-base.conf /etc/httpd/conf.modules.d/00-base.conf
sudo cp /vagrant/conf/httpd/conf/httpd.conf /etc/httpd/conf/httpd.conf
sudo cp /vagrant/conf/php.ini /etc/php.ini
sudo cp /vagrant/conf/selinux/config /etc/selinux/config

sudo setenforce 0

sudo dnf install -y libaio
sudo rpm -ivh /vagrant/additions/oracle-instantclient11.2-basic-11.2.0.4.0-1.x86_64.rpm
sudo rpm -ivh /vagrant/additions/oracle-instantclient11.2-devel-11.2.0.4.0-1.x86_64.rpm

sudo echo "extension=oci8.so" >> /etc/php.ini
sudo echo "extension=oci8.so" >> /etc/php.d/oci.ini

chown vagrant:vagrant /var/www/html/mis/temp/
chown vagrant:vagrant /var/www/html/mis/d3/temp

sudo cp /vagrant/additions/wkhtmltopdf /usr/bin/wkhtmltopdf

sudo chown -R vagrant:vagrant /var/www/html/

sudo systemctl restart httpd
# xvfb-run -a /usr/bin/wkhtmltopdf /vagrant/additions/file.html /var/www/html/file.pdf

