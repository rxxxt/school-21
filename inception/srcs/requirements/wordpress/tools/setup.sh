#!/bin/bash

sed -i "s/DB_USER_/$MYSQL_USER/g" /var/www/html/wordpress/wp-config.php
sed -i "s/DB_PASSWORD_/$MYSQL_PASSWORD/g" /var/www/html/wordpress/wp-config.php
sed -i "s/DB_NAME_/$DB_NAME/g" /var/www/html/wordpress/wp-config.php
sed -i "s/DB_HOST_/$DB_HOST/g" /var/www/html/wordpress/wp-config.php