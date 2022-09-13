#pragma once

#include "BufferBase.h"

class UploadBuffer : public BufferBase {
public:

	void UpdateBuffer(void* data, uint64_t dataSize);
};