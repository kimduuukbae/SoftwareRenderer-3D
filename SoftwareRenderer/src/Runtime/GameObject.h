#pragma once

// 배치될 수 있는 모든 오브젝트들 

#include <cstdint>
#include <string>

class GameObject {
public:

	GameObject();
	virtual ~GameObject();

	std::string GetObjectName() const;

protected:
	uint64_t __objectID;
	std::string __objectName;
};