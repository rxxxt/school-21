FROM	alpine:3.14.2

RUN		apk update \
		&& apk add bash vim busybox-extras php7 php7-fpm php7-mysqli php7-json wget

WORKDIR	/var/www/html
RUN		wget https://wordpress.org/latest.tar.gz \
		&& tar -xvf latest.tar.gz \
		&& rm -f latest.tar.gz

ARG     DB_NAME
ARG     DB_HOST
ARG		MYSQL_USER
ARG		MYSQL_PASSWORD

COPY    tools/setup.sh /tmp/setup.sh
COPY    conf/wp-config.php /var/www/html/wordpress/wp-config.php
COPY    conf/www.conf /etc/php7/php-fpm.d/www.conf
RUN     chmod +x /tmp/setup.sh
RUN     /tmp/setup.sh

CMD     [ "/usr/sbin/php-fpm7", "-F" ]