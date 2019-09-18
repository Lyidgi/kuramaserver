//
// Created by dev on 17/09/2019.
//

#ifndef KUBI_SIMPLEEXCEPTION_HPP_INCLUDED
#define KUBI_SIMPLEEXCEPTION_HPP_INCLUDED

#include <exception>
#include <string>

namespace nine{

class SimpleException : public std::exception {
public:

	SimpleException( const std::string &_where, const std::string &_message );
	~SimpleException() override = default;

	std::string to_string() const;
	const char* what() const noexcept override ;

private:
	std::string m_msg;
	std::string m_where;
};

} // namespace nine

#endif //KUBI_SIMPLEEXCEPTION_HPP_INCLUDED
