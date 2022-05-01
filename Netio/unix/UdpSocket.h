#pragma once

//
//  Netio
//
//  Created by Sadullah Nader on 8/15/14.
//  Copyright (c). All rights reserved.
//

#include "Endpoint.h"

namespace netio
{
class Endpoint;
class PacketBuffer;

class UdpSocket
{
public:
    
    enum Direction
    {
        Incoming,
        Outgoing
    };
    
    UdpSocket();
    UdpSocket(const Endpoint & address);
    ~UdpSocket();
    
    void setEndpoint(const Endpoint &endpoint);
    const Endpoint & getEndpoint() const { return m_endpoint; }
    
    bool open();
    bool close();
    
    bool toggleBlocking(bool blocking);
    bool isBlocking();
   
    bool setBufferSize(Direction bufferDirection, size_t bufferSize);
    size_t getBufferSize(Direction bufferDirection);
    
    bool send(const Endpoint &remoteEndpoint, const PacketBuffer & sendBuffer);
    
	bool recv(Endpoint &remoteEndpoint, PacketBuffer & sendBuffer);
    
private:    
    int m_socket;
    Endpoint m_endpoint;
};

}
