//
// Created by dev on 18/09/2019.
//

#ifndef KUBI_LOG_HPP
#define KUBI_LOG_HPP

#include <string>

class Logger {
public:
	Logger() = default;
	~Logger() = default;

	static void error( const std::string &_msg );
	static void info( const std::string &_msg );
	static void debug( const std::string &_msg );

private:
	static void write( const std::string &_msg );
};


#endif //KUBI_0_1_LOG_HPP
