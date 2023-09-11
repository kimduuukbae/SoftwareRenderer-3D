#pragma once

#include "Resource.h"
#include "Enum.h"

class BufferBase : public Resource {
public:
	uint64_t GetBufferSize() const;
	void* GetBuffer() const;

	virtual ~BufferBase() = default;

protected:
	uint64_t __bufferSize;
	void* __buffer;

	BufferType __bufferType;
};
