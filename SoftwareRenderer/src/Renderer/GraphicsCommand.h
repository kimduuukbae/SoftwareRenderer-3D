#pragma once


// �۾� �ֱ�
class GraphicsCommand {
public:
	void SetGraphicsCommandQueue(class GraphicsCommandQueue* queue);

private:
	class GraphicsCommandQueue* commandQueue;
};