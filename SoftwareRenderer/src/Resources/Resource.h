#pragma once

#include <cstdint>

class Resource{
public:
	Resource() = default;
	virtual ~Resource() = default;

	uint64_t __resourceID;
protected:
	void* __resource;
};

