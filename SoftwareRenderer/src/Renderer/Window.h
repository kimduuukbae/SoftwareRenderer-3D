#pragma once

#include <Windows.h>
#include "CommonHeader.h"


class Window {
public:
	//Factory

	static Window* CreateWindowFactory(HINSTANCE hInstance, const std::wstring_view& windowName, uint32_t width, uint32_t height);
	
	//Member Function

	void AddProcCallback(std::function<void(int, int)>&& callback);

private:
	HWND __handle;

	//Internal

	Window() = default;
	~Window() = default;
	Window(const Window& rhs) = delete;
	Window(Window&&) = delete;
};