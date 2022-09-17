#pragma once

class GraphicsCommandQueue {
public:
	GraphicsCommandQueue();
	~GraphicsCommandQueue();

private:
	friend class GraphicsCommand;
};