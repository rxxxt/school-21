FROM	alpine:3.12

RUN		apk update && apk add libc6-compat supervisor influxdb

RUN		wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_i386.tar.gz \
		&& tar -zxvf telegraf-1.18.2_linux_i386.tar.gz -C /usr \
		&& mv usr/telegraf-1.18.2 usr/telegraf \
		&& rm -rf telegraf-1.18.2_linux_i386.tar.gz

COPY	supervisord.conf etc/supervisord.conf

RUN		mkdir -p /etc/telegraf \
		&& usr/telegraf/usr/bin/telegraf -sample-config --input-filter docker \
		--output-filter influxdb > /etc/telegraf/telegraf.conf

EXPOSE	8086

CMD		["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]