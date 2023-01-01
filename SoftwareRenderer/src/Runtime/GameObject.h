#pragma once

// ��ġ�� �� �ִ� ��� ������Ʈ�� 

#include <cstdint>
#include <string>

class GameObject {
public:

	GameObject();
	virtual ~GameObject();

	std::string GetObjectName() const;

	template <typename T>
	inline T* AddComponent();

	template <typename T>
	inline T* GetComponent();

protected:
	uint64_t __objectID;
	std::string __objectName;
};

// TODO : Impl

template <typename T>
inline T* GameObject::AddComponent() {
	return nullptr;
}

template <typename T>
inline T* GameObject::GetComponent() {
	return nullptr;
}