//
// Created by dev on 17/09/2019.
//

#include <Server/KuramaServer.hpp>

#include <cstring>
#include <thread>

#include <boost/asio/ip/tcp.hpp>

#include <Common/Errors/Exceptions.hpp>
#include <Common/Log.hpp>


namespace nine {

void KuramaServer::start()
{

	boost::asio::io_service io_service;
	// listen on port
	boost::asio::ip::tcp::endpoint endpoint( boost::asio::ip::tcp::v4(), 8080 );
	boost::asio::ip::tcp::acceptor acceptor( io_service, endpoint );
	boost::asio::deadline_timer timeout( io_service );

	while ( !m_stopped ) {
		Logger::debug( "Start accepting" );
		socket_ptr sock = std::make_shared<boost::asio::ip::tcp::socket >( io_service );
		acceptor.async_accept( *sock,
				std::bind( &KuramaServer::start_session, sock, std::placeholders::_1 ) );

		timeout.expires_from_now(boost::posix_time::seconds( 5 ) );
		timeout.async_wait(  [&acceptor]( const boost::system::error_code &_error ) { Logger::info("Close"); acceptor.close(); } );

		std::this_thread::sleep_for( std::chrono::microseconds(10 ) );
	}
	Logger::debug( "Finish accepting" );
}

void KuramaServer::start_session( socket_ptr sock, const boost::system::error_code &_error )
{
	if ( _error )
		return;

	char data[512];

	boost::system::error_code error_code;
	while ( error_code != boost::asio::error::eof  ) {
		size_t len = sock->read_some( boost::asio::buffer( data ), error_code );

		if ( len > 0 )
			write( *sock, boost::asio::buffer( "ok", 2 ) );

		std::string string_data = data;
		if ( string_data == "exit" )
			return;
	}
}

void KuramaServer::stop() {
	Logger::debug( "Stop Server" );
	m_stopped = true;
}

} // namespace nine