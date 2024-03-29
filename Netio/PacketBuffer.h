#pragma once

//
//  Netio
//
//  Created by Sadullah Nader on 12/26/11.
//  Copyright (c). All rights reserved.
//

#include "Transport.h"
#include <numeric>
namespace netio 
{

class PacketBuffer
{
public:
	
	PacketBuffer();
	PacketBuffer(size_t bufferCapacity);
	~PacketBuffer();
	size_t getCapacity() { return m_capacity; }
	size_t getSize() const { return m_position; }
    
    const void* getDataBuffer() const { return m_buffer; }

protected:
	size_t getPosition() { return m_position; }
	void setPosition(size_t position) { m_position = position; }
	size_t m_capacity;
	size_t m_position;
	uint8_t m_bitOffset;
	char *m_buffer;

};

}
