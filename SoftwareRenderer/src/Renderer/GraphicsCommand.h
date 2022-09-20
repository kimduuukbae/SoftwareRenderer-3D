#pragma once


// 작업 넣기
class GraphicsCommand {
public:
	void SetGraphicsCommandQueue(class GraphicsCommandQueue* queue);
	void SetPSO(class GraphicsPipelineStateObject* pso);
	void SetRenderTarget(class BufferBase* buffer);

	void DrawVertex();
	void DrawIndexed();

private:
	class GraphicsCommandQueue* commandQueue;
};