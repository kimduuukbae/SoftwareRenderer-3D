#pragma once


// 작업 넣기
class GraphicsCommand {
public:
	void SetGraphicsCommandQueue(class GraphicsCommandQueue* queue);

private:
	class GraphicsCommandQueue* commandQueue;
};