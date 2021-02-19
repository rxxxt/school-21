#!bin/bash
if grep "autoindex on" /etc/nginx/sites-available/nginx.conf -q
then
    sed -i.tmp '/autoindex on/s/on/off/' /etc/nginx/sites-available/nginx.conf
else
    sed -i.tmp '/autoindex off/s/off/on/' /etc/nginx/sites-available/nginx.conf
fi 
service nginx restart