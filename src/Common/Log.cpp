//
// Created by dev on 18/09/2019.
//

#include "Common/Log.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>

void Logger::error( const std::string &_msg )
{
	write( "|ERR| " + _msg);
}

void Logger::info( const std::string &_msg )
{
	write( "|INF| " + _msg);
}

void Logger::debug( const std::string &_msg )
{
	write( "|DEB| " + _msg);
}

void Logger::write( const std::string &_msg )
{
	auto now = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now());
	std::cout << std::put_time( std::localtime(&now), "%F %T " )  << _msg << std::endl;
}
