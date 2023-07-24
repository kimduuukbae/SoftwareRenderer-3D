#pragma once

#include <vector>

class GraphicsCommandQueue {
public:
	GraphicsCommandQueue();
	~GraphicsCommandQueue();

private:
	void SetGraphicsPipelineObject(class GraphicsPipelineStateObject* pso);
	void SetRenderTarget(class BufferBase* base);
	void DrawVertices();
	void DrawIndices();
	void Execute();

	class GraphicsPipelineStateObject* __pso;
	class GraphicsBufferBase* __renderTarget;

	struct __SavedBuffer {
		class BufferBase* setBuffer;
		int bufferSize;
		int stride;
	};

	// Draw IndexBuffer
	__SavedBuffer* __storedVertexBuffer;
	__SavedBuffer* __storedIndexBuffer;
	bool __isSetVertexBuffer;

	// std::vector< optional*

	friend class GraphicsCommand;
};