#!/bin/sh

sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf
sed -i "s|.*skip-networking.*|skip-networking=false|g" /etc/my.cnf.d/mariadb-server.cnf
sed -i "s|.*\[mysqld\].*|\[mysqld\]\nskip-networking=false\nbind-address=0.0.0.0|g" /etc/my.cnf

openrc default
rc-service mariadb setup
rc-service mariadb start

echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "CREATE DATABASE phpmyadmin;"| mysql -u root --skip-password
echo "CREATE USER admin;"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'admin'@'%' IDENTIFIED BY 'admin';"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON phpmyadmin.* TO 'admin'@'%' IDENTIFIED BY 'admin';"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'admin'@'%' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON phpmyadmin.* TO 'admin'@'%' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password

mysql < tmp/phpmyadmin.sql
mysql < tmp/wordpress.sql
rc-service mariadb stop
mysqld_safe