FROM	alpine:3.12

RUN		apk update && apk add supervisor nginx php7-fpm lighttpd php7-fpm php7-common \
		php7-session php7-iconv php7-json php7-gd php7-curl php7-xml \
		php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap \
		php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom

RUN		mkdir -p /run/nginx \
		&& mkdir -p /usr/share/webapps \
		&& wget https://wordpress.org/latest.tar.gz \
		&& tar -xvf latest.tar.gz -C usr/share/webapps \
		&& rm -f latest.tar.gz

COPY	wp-config.php /usr/share/webapps/wordpress
COPY	nginx.conf /etc/nginx/conf.d/default.conf
COPY	supervisord.conf /etc/supervisord.conf

EXPOSE	5050

CMD 	["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]