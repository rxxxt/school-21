#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <fstream>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <cstring>


class Server {

public:
	Server();
	Server(int);
	~Server();

	bool start();



private:
	bool _socket_init();
	void _client_processing(int, std::string);

private:
	int m_socket_;
	int m_port_;

private:
	Server(const Server &other);
	Server &operator=(const Server &other);

};


#endif
