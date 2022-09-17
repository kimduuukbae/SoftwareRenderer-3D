#pragma once

#include <type_traits>

#include "GraphicsDeviceBase.h"

// Graphics Device ���� Smart Pointer �Դϴ�.

template <typename T>
requires std::is_same_v<T, GraphicsDeviceBase>
class DevicePtr {
public:
	static DevicePtr* CreatePtr(T*&& ptr);
	~CreatePtr();
	
private:
	CreatePtr();

};