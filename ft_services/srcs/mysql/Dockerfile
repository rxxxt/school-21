FROM	alpine:3.12

RUN		apk update && apk add mysql mariadb mysql-client openrc

COPY	phpmyadmin.sql tmp/phpmyadmin.sql
COPY	wordpress.sql tmp/wordpress.sql
COPY	setup.sh tmp/setup.sh
RUN		chmod +x tmp/setup.sh

EXPOSE	3306

CMD		["./tmp/setup.sh"]