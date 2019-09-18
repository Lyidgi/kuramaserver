//
// Created by dev on 17/09/2019.
//

#include "Common/Errors/SimpleException.hpp"

namespace nine
{

SimpleException::SimpleException( const std::string &_where,
		const std::string &_message ) :
			m_msg( _message ),
			m_where( _where )
{}

std::string SimpleException::to_string() const
{
	return std::string( m_msg );
}

const char* SimpleException::what() const noexcept
{
	auto str = " Error ( " + m_where + " ): [ " + m_msg + "]";
	return str.c_str() ;
}

} // namespace nine