FROM	alpine:3.12

RUN		apk update && apk add influxdb libc6-compat

RUN		mkdir -p /usr/share/webapps \
		&& wget https://dl.grafana.com/oss/release/grafana-7.5.5.linux-amd64.tar.gz \
		&& tar -zxvf grafana-7.5.5.linux-amd64.tar.gz -C /usr/share/webapps \
		&& mv usr/share/webapps/grafana-7.5.5 usr/share/webapps/grafana \
		&& rm -rf grafana-7.5.5.linux-amd64.tar.gz

COPY	grafana.db /usr/share/webapps/grafana/data/grafana.db

WORKDIR	usr/share/webapps/grafana/bin

EXPOSE	3000

CMD		["./grafana-server"]