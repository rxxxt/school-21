FROM	alpine:3.12

RUN		apk update && apk add nginx openssl

RUN		mkdir -p /etc/nginx/ssl \
		&& mkdir -p /run/nginx \
		&& openssl req \
			-newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
			-out /etc/nginx/ssl/ssl.crt \
			-keyout /etc/nginx/ssl/ssl.key \
			-subj "/C=RU/ST=RT/L=Kazan/O=21/OU=school_21/CN=localhost"

COPY	nginx.conf /etc/nginx/conf.d/default.conf
COPY	src/* /var/lib/nginx/html/

EXPOSE	80 443

CMD		["nginx", "-g", "daemon off;"]