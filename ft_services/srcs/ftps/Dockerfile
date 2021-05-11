FROM	alpine:3.12

RUN		apk update && apk add openssl vsftpd
RUN		openssl req \
			-newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
			-out /etc/ssl/ssl.crt \
			-keyout /etc/ssl/ssl.key \
			-subj "/C=RU/ST=RT/L=Kazan/O=21/OU=school_21/CN=localhost"

COPY 	vsftpd.conf /etc/vsftpd/
COPY	setup.sh tmp/setup.sh
RUN 	chmod +x tmp/setup.sh

EXPOSE	21

CMD		["tmp/setup.sh"]