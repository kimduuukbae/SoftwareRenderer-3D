#pragma once


// 작업 넣기
class GraphicsCommand {
public:
	/* Setter */
	void	SetGraphicsCommandQueue(class GraphicsCommandQueue* queue);
	void	SetPSO(class GraphicsPipelineStateObject* pso);
	void	SetRenderTarget(class BufferBase* buffer);
	void	SetVertexBuffer(class BufferBase* buffer, int bufferSize, int stride);


	/* Draw */
	void	DrawVertex();
	void	DrawIndexed(class BufferBase* buffer, int bufferSize);

private:
	class GraphicsCommandQueue* __commandQueue;
};