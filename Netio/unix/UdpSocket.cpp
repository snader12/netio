//
//  Netio
//
//  Created by Sadullah Nader on 8/15/14.
//  Copyright (c). All rights reserved.
//

#include "UdpSocket.h"
#include "PacketBuffer.h"

#include <unistd.h>
#include <sys/socket.h>
#include <fcntl.h>

namespace netio
{

const int SOCKET_ERROR = -1;
const int INVALID_SOCKET = -1;
UdpSocket::UdpSocket()
    : m_endpoint(), m_socket(INVALID_SOCKET)
{
    
}

UdpSocket::UdpSocket(const Endpoint &endpoint)
    : m_endpoint(endpoint), m_socket(INVALID_SOCKET)
{
    
}

void UdpSocket::setEndpoint(const Endpoint &endpoint)
{
    m_endpoint = endpoint;
}

bool UdpSocket::open()
{
    m_socket = socket(convertEndpointTypeToFamily(m_endpoint.getEndpointType()), SOCK_DGRAM, IPPROTO_UDP);
    if (m_socket == INVALID_SOCKET)
    {
        // TODO: Add log here for failed socket creation
        return false;
    }
        
    if (!m_endpoint.isValid() && m_endpoint.getSockAddr() == nullptr)
    {
        // TODO: Add log here for failed socket creation
        return false;
    }

    int result = SOCKET_ERROR;
    
    result = bind(m_socket, m_endpoint.getSockAddr(), m_endpoint.getSockAddr()->sa_len);
    if (result == SOCKET_ERROR)
    {
        // TODO: Add log here to show error
        return false;
    }
    
    return true;
}

bool UdpSocket::close()
{
    int result = ::close(m_socket);
    if (result == SOCKET_ERROR)
    {
        // TODO: Add log here to show error
        return false;
    }
    return true;
}

bool UdpSocket::toggleBlocking(bool blocking)
{
    if (m_socket == INVALID_SOCKET)
    {
        // TODO: Add log here for bad socket
        return false;
    }
    
    int flags = fcntl(m_socket, F_GETFL);

    if (blocking)
        flags &= ~O_NONBLOCK;
    else
        flags |= O_NONBLOCK;
    
    if (fcntl(m_socket, F_SETFL, flags) == SOCKET_ERROR)
    {
        // TODO: Add log here to show error
        return false; 
    }
    return true;
}

bool UdpSocket::isBlocking()
{
    if (m_socket == INVALID_SOCKET)
    {
        // TODO: Add log here to show a bad socket
        return false;
    }
    
    int flags = fcntl(m_socket, F_GETFL);
    if (flags & O_NONBLOCK)
        return true;
    return false;
}
bool UdpSocket::setBufferSize(Direction bufferDirection, size_t bufferSize)
{
    if (m_socket == INVALID_SOCKET)
    {
        // TODO: Add log here to show a bad socket
        return false;
    }
    
    
    int result = setsockopt(m_socket, SOL_SOCKET, bufferDirection == Incoming ? SO_RCVBUF : SO_SNDBUF, &bufferSize, sizeof(bufferSize));
    if (result == SOCKET_ERROR)
    {
        // TODO: Add log here to show error
        return false;
    }

    return true;
}

size_t UdpSocket::getBufferSize(Direction bufferDirection)
{
    if (m_socket == INVALID_SOCKET)
    {
        // TODO: Add log here to show a bad socket
        return 0;
    }
    size_t bufferSize;
    socklen_t lengthHolder;
    int result = getsockopt(m_socket, SOL_SOCKET, bufferDirection == Incoming ? SO_RCVBUF : SO_SNDBUF, &bufferSize, &lengthHolder);
    if (result == SOCKET_ERROR)
    {
        // TODO: Add log here to show error
        
    }
    return bufferSize;
}

bool UdpSocket::send(const netio::Endpoint &remoteEndpoint, const netio::PacketBuffer &sendBuffer)
{
    if (sendBuffer.getSize() == 0)
    {
        return false;
    }
    
    
    size_t socketBufferSize = getBufferSize(Outgoing);
    
    if (socketBufferSize > sendBuffer.getSize())
    {
        ssize_t result = ::send(m_socket, sendBuffer.getDataBuffer(), sendBuffer.getSize(), 0);
        if (result == SOCKET_ERROR)
        {
            return false;
        }
    }
    
    
    
    return true;
}

}


















