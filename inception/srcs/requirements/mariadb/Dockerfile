FROM    debian:buster

RUN     apt-get update \
        && apt-get install -y mariadb-server procps vim

ARG     DB_NAME
ARG     MYSQL_USER
ARG     MYSQL_PASSWORD
ARG     MYSQL_ROOT_PASSWORD

COPY    /conf/wordpress.sql /wordpress.sql
COPY    /tools/setup.sh ./tmp
RUN     chmod +x /tmp/setup.sh

RUN     tmp/setup.sh
COPY    /conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

CMD     [ "mysqld", "-u", "root" ]