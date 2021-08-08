#include "Server.hpp"

Server::Server() : m_socket_(-1), m_port_(8080) {}

Server::Server(int port) : m_socket_(-1), m_port_(port) {}

Server::Server(const Server &other) {}

Server &Server::operator=(const Server &other) {
	if (this != &other)
		*this = other;
	return *this;
}

Server::~Server() {}

bool Server::_socket_init() {
	m_socket_ = socket(PF_INET, SOCK_STREAM, 0);
	if (m_socket_ == -1) {
		std::cerr << "Can't listening port" << std::endl;
		return false;
	}
	sockaddr_in sa_serv;// = {0};
	std::memset(&sa_serv, 0, sizeof(sa_serv));
	sa_serv.sin_family = AF_INET;
	sa_serv.sin_addr.s_addr = INADDR_ANY;
	sa_serv.sin_port = htons(m_port_);
	if (bind(m_socket_, (sockaddr*)&sa_serv, sizeof(sa_serv)) != 0) {
		std::cerr << "Can't bind port " << m_port_ << std::endl;
		return false;
	}
	if (listen(m_socket_, 16) != 0) {
		std::cerr << "Can't configure listening port" << std::endl;
		return false;
	}
	return true;
}
