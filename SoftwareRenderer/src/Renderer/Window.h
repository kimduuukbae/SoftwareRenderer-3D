#pragma once

#include <Windows.h>
#include "CommonHeader.h"
#include "Resource.h"

class Window : public Resource {
public:
	//Factory

	static Window* CreateWindowFactory(HINSTANCE hInstance, const std::wstring_view& windowName, uint32_t width, uint32_t height);
	
	//Member Function

	void AddProcCallback(std::function<LRESULT(HWND,UINT,WPARAM,LPARAM)>&& callback);

private:
	HWND __handle;

	//Internal

	Window() = default;
	~Window() = default;
	Window(const Window& rhs) = delete;
	Window(Window&&) = delete;
};