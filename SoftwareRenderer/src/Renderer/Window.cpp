#include "Window.h"
#include <format>

LRESULT __MainWndPoc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam) {
	return DefWindowProc(handle, msg, wParam, lParam);
}

Window* Window::CreateWindowFactory(HINSTANCE hInstance, const std::wstring_view& windowName, uint32_t width, uint32_t height) {
	Window* window{ new Window{} };

	SetLastError(99);

	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = __MainWndPoc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = 0;
	wc.hCursor = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = L"MainWnd";

	if (!RegisterClass(&wc))
	{
		MessageBox(0, L"RegisterClass Failed.", 0, 0);
		return nullptr;
	}

	RECT R { 0, 0, static_cast<LONG>( width ), static_cast<LONG>( height ) };
	AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);

	window->__handle = CreateWindow(L"MainWnd", L"Test",
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, 0, 0, hInstance, 0);
	if (!window->__handle)
	{
		MessageBox(0, std::format(L"Create Window Failed ErrorCode : {0}", GetLastError()).c_str(), 0, 0);
		return nullptr;
	}

	ShowWindow(window->__handle, SW_SHOW);
	UpdateWindow(window->__handle);

	return window;
}

void Window::AddProcCallback(std::function<void(int, int)>&& callback){

}