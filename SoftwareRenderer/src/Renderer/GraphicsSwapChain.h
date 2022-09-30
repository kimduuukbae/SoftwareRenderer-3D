#pragma once

class GraphicsSwapChain {
public:
	void CreateSwapChain(int swapChainCount);
	void SetWindow(class Window* window);
	void Present();

	bool IsCompletePresent();

	class Window* GetWindoW() const;
	class DefaultBuffer* GetBackBuffer() const;


private:
	class DefaultBuffer* __backBuffer;
	class Window* __frontBuffer;
};