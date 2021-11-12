FROM	alpine:3.14.2

RUN   apk update \
      && apk add bash vim busybox-extras openssl nginx

ARG   DOMAIN_NAME
ARG   CERTS_

RUN   mkdir -p /etc/nginx/ssl
COPY  conf/my.conf /etc/nginx/http.d/my.conf
COPY  tools/setup.sh /tmp/setup.sh
RUN   chmod +x /tmp/setup.sh
RUN   /tmp/setup.sh

CMD   [ "nginx", "-g", "daemon off;" ]