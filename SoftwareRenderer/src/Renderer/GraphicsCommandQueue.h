#pragma once

class GraphicsCommandQueue {
public:
	GraphicsCommandQueue();
	~GraphicsCommandQueue();

private:
	void SetGraphicsPipelineObject(class GraphicsPipelineStateObject* pso);
	void SetRenderTarget(class BufferBase* base);

	friend class GraphicsCommand;

	class GraphicsPipelineStateObject* __pso;
	class GraphicsBufferBase* __renderTarget;
};