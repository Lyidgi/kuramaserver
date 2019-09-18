//
// Created by dev on 17/09/2019.
//

#ifndef KUBI_CONNECTION_HPP_INCLUDED
#define KUBI_CONNECTION_HPP_INCLUDED

#include <netinet/in.h>

class Connection {

public:
	Connection();
	~Connection() = default;

private:
	in_port_t m_port = 8080;
	in_addr_t ip_v4 = INADDR_ANY;
	sockaddr_in address{};
};


#endif //KUBI_CONNECTION_HPP_INCLUDED
