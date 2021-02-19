# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tredfort <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/01 18:48:25 by tredfort          #+#    #+#              #
#    Updated: 2021/02/18 21:46:27 by tredfort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update && \
	apt-get install -y wget nginx mariadb-server php-fpm php-mysql php-mbstring vim

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz && \
	tar -xvf phpMyAdmin-5.0.4-all-languages.tar.gz -C var/www && \
	mv var/www/phpMyAdmin-5.0.4-all-languages var/www/html/phpMyAdmin && \
	rm -f phpMyAdmin-5.0.4-all-languages.tar.gz
RUN wget https://wordpress.org/latest.tar.gz && \
	tar -xvf latest.tar.gz -C var/www/html && \
	rm -f latest.tar.gz

COPY ./srcs/nginx.conf /etc/nginx/sites-available/nginx.conf
COPY ./srcs/index.html var/www/html
COPY ./srcs/2048_files var/www/html/2048_files
COPY ./srcs/toggle.sh ./tmp
COPY ./srcs/start.sh ./tmp
COPY ./srcs/config.inc.php var/www/html/phpMyAdmin/config.inc.php
COPY ./srcs/wp-config.php var/www/html/wordpress

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/localhost.crt -keyout /etc/nginx/ssl/localhost.key -subj "/C=RU/ST=RT/L=Kazan/O=21/OU=school_21/CN=localhost"
RUN ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/nginx.conf
RUN rm -rf /etc/nginx/sites-enabled/default

CMD bash tmp/start.sh
