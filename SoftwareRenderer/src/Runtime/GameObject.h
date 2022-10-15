#pragma once

// ��ġ�� �� �ִ� ��� ������Ʈ�� 

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