//
// Created by dev on 17/09/2019.
//

#ifndef KUBI_KURAMASERVER_HPP_INCLUDED
#define KUBI_KURAMASERVER_HPP_INCLUDED

#include <boost/asio.hpp>

namespace nine{

class KuramaServer {

public:
	KuramaServer() = default;
	~KuramaServer() = default;

	void start();
	void stop();

private:
	using socket_ptr = std::shared_ptr<boost::asio::ip::tcp::socket>;
	static void start_session( socket_ptr sock,
							   const boost::system::error_code &_error);

	std::atomic_bool m_stopped = false;
};

}

#endif //KUBI_KURAMASERVER_HPP_INCLUDED
