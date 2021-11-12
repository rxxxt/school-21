YAML = srcs/docker-compose.yml

all:
	sudo docker-compose -f $(YAML) build

up:
	sudo docker-compose -f $(YAML) up -d

down:
	sudo docker-compose -f $(YAML) down

ps:
	sudo docker-compose -f $(YAML) ps -a

images:
	sudo docker images -a

rm:
	@sudo docker rm $$(sudo docker ps -aq) --force || :

rmi:
	sudo docker rmi $$(sudo docker images -aq) --force || :

clean: down
	sudo rm -rf /home/tredfort/data/wp/*
	sudo rm -rf /home/tredfort/data/db/*
	@sudo docker volume rm $$(sudo docker volume ls -q) || :
	@sudo docker network rm $$(sudo docker network ls -q) || :

fclean: clean rm rmi

re: fclean all