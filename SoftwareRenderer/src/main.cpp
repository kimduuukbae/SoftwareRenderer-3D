#include <iostream>
#include <thread>
#include "Resources/Window.h"

using namespace std;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow) {

    Window* window{ Window::CreateWindowFactory(hInstance, L"Test", 1024, 768) };

    std::this_thread::sleep_for(100s);
}