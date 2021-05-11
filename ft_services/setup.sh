#!/bin/sh

#minikube delete
#minikube stop
#minikube addons enable dashboard
#docker pull metallb/speaker:v0.8.2
#docker pull metallb/controller:v0.8.2
#minikube addons list
#kubectl get deploy
#kubectl get svc
#kubectl get pod


minikube start --vm-driver=virtualbox --cpus 4 --memory 4g
minikube addons enable metallb
minikube addons enable metrics-server
eval $(minikube docker-env)

docker build -t img_nginx srcs/nginx/
docker build -t img_phpmyadmin srcs/phpmyadmin/
docker build -t img_wordpress srcs/wordpress/
docker build -t img_mysql srcs/mysql/
docker build -t img_ftps ./srcs/ftps/
docker build -t img_grafana ./srcs/grafana/
docker build -t img_influxdb ./srcs/influxdb/

kubectl apply -f srcs/metallb.yaml
kubectl apply -f srcs/nginx/nginx.yaml
kubectl apply -f srcs/phpmyadmin/phpmyadmin.yaml
kubectl apply -f srcs/wordpress/wordpress.yaml
kubectl apply -f srcs/mysql/mysql.yaml
kubectl apply -f srcs/ftps/ftps.yaml
kubectl apply -f srcs/grafana/grafana.yaml
kubectl apply -f srcs/influxdb/influxdb.yaml

minikube dashboard