/*****************************************************************//**
 * \file   TcpConnector.cpp
 * \brief  
 * 
 * \author clucle
 * \date   December 2020
 *********************************************************************/


#include "TcpConnector.h"


TcpConnector::TcpConnector( tcp::socket socket ) :
	m_socket( std::move( socket ) ),
    m_data()
{
}

void TcpConnector::OnAccept()
{
    std::cout << "Test Accept" << '\n';
}

void TcpConnector::_Read()
{
    auto self( shared_from_this() );
    boost::asio::async_read( m_socket,
        boost::asio::buffer( m_data, MAX_LENGTH ),
        [this, self]( boost::system::error_code ec, std::size_t /*length*/ )
        {
            if ( !ec )
            {
                _OnRead();
            }
            else
            {
                // close user
            }
        } );
}

void TcpConnector::_OnRead()
{
    OnRead();

    std::cout << m_data << '\n';

    _Read();
}

void TcpConnector::OnRead()
{
    std::cout << "need implement" << '\n';
}