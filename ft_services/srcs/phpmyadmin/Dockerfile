FROM	alpine:3.12

RUN		apk update && apk add supervisor nginx mysql mariadb mysql-client openrc lighttpd \
		php7-fpm php7-common php7-session php7-iconv php7-json php7-gd php7-curl \
		php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap \
		php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom php7-mbstring

RUN		mkdir -p /usr/share/webapps \
		&& mkdir -p /run/nginx \
		&& wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-all-languages.tar.gz && \
		tar -xvf phpMyAdmin-5.1.0-all-languages.tar.gz -C /usr/share/webapps && \
		mv usr/share/webapps/phpMyAdmin-5.1.0-all-languages usr/share/webapps/phpmyadmin && \
		rm -f phpMyAdmin-5.1.0-all-languages.tar.gz

COPY	config.inc.php usr/share/webapps/phpmyadmin
COPY 	nginx.conf /etc/nginx/conf.d/default.conf
COPY	supervisord.conf /etc/supervisord.conf

EXPOSE	5000

CMD 	["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]