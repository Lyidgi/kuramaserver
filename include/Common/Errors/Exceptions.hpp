//
// Created by dev on 17/09/2019.
//

#ifndef KUBI_EXCEPTIONS_HPP_INCLUDED
#define KUBI_EXCEPTIONS_HPP_INCLUDED

#include "Common/Errors/SimpleException.hpp"

namespace nine
{


class ConnectionException : public SimpleException {
public:

	ConnectionException( const std::string  &_message ) : SimpleException( "Connection", _message ) {} ;
	~ConnectionException() override  = default;
};

} // namespace
#endif //KUBI_EXCEPTIONS_HPP_INCLUDED
