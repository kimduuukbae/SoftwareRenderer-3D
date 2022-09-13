#pragma once

#include "Resource.h"
#include "Enum.h"

class BufferBase : public Resource {


protected:
	uint64_t __bufferSize;
	void* __buffer;

	BufferType __bufferType;
};