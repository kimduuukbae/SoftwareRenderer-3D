#pragma once

#include <type_traits>

#include "GraphicsDeviceBase.h"

// Graphics Device 들의 Smart Pointer 입니다.

template <typename T>
requires std::is_same_v<T, GraphicsDeviceBase>
class DevicePtr {
public:
	static DevicePtr* CreatePtr(T*&& ptr);
	~CreatePtr();
	
private:
	CreatePtr();

};