#!/bin/bash

openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
            -out /etc/nginx/ssl/$CERTS_.crt \
            -keyout /etc/nginx/ssl/$CERTS_.key \
            -subj "/C=RU/ST=RT/L=Kazan/O=21/OU=school_21/CN=localhost";

sed -i "s/DOMAIN_NAME_/$DOMAIN_NAME/g" /etc/nginx/http.d/my.conf
sed -i "s/CERTS_/$CERTS_/g" /etc/nginx/http.d/my.conf
