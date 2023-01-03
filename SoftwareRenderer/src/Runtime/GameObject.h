#pragma once

// 배치될 수 있는 모든 오브젝트들 

#include <cstdint>
#include <string>
#include "ExternContainerHeader.h"

class GameObject {
public:

	GameObject();
	virtual ~GameObject();

	template <typename T>
	inline T* AddComponent();

	template <typename T>
	inline T* GetComponent() const;

	inline void SetName(std::string&& name);
	inline void SetName(const std::string& name);
	inline std::string_view GetName() const;

protected:
	uint64_t __objectID;
	std::string __objectName;

protected:
	std::vector<class ComponentBase*> __components;
};

template <typename T>
inline T* GameObject::AddComponent() {
	__components.push_back(new T{});

	return __components.back();
}

template <typename T>
inline T* GameObject::GetComponent() const {

	return nullptr;
}

inline void GameObject::SetName(std::string&& name) {
	__objectName = std::move(name);
}

inline void GameObject::SetName(const std::string& name) {
	__objectName = name;
}

inline std::string_view GameObject::GetName() const {
	return std::string_view{ __objectName };
}