#include "Server/KuramaServer.hpp"

#include "Common/Log.hpp"

#include <memory>
#include <thread>

int main() {
	auto kurama_server = std::make_shared<nine::KuramaServer>();
	kurama_server->start();

	Logger::error( "Start Sleep" );

	std::this_thread::sleep_for( std::chrono::microseconds(2) );

	Logger::error( "Stop sleep" );

	kurama_server->stop();

	return 0;
}

