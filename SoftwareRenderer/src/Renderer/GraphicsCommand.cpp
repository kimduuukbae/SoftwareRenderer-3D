#include <stdexcept>
#include "GraphicsCommand.h"
#include "GraphicsCommandQueue.h"
#include "GraphicsPipelineStateObject.h"
#include <ranges>


void GraphicsCommand::SetGraphicsCommandQueue(GraphicsCommandQueue* queue){
	__commandQueue = queue;
}

void GraphicsCommand::SetPSO(GraphicsPipelineStateObject* pso){
	__commandQueue->SetGraphicsPipelineObject(pso);
}

void GraphicsCommand::SetRenderTarget(BufferBase* buffer){
	__commandQueue->SetRenderTarget(buffer);
}

void GraphicsCommand::DrawVertex(){
	__commandQueue->DrawVertices();
}

void GraphicsCommand::SetVertexBuffer(BufferBase* buffer, int bufferSize, int stride) {
	__commandQueue->__storedVertexBuffer->setBuffer = buffer;
	__commandQueue->__storedVertexBuffer->bufferSize = bufferSize;
	__commandQueue->__storedVertexBuffer->stride = stride;

	__commandQueue->__isSetVertexBuffer = true;
}

void GraphicsCommand::DrawIndexed(BufferBase* buffer, int bufferSize){
	if (__commandQueue->__isSetVertexBuffer == false)
		throw std::runtime_error{ "error, __isSetVertexBuffer == false" };
	
	__commandQueue->__storedIndexBuffer->setBuffer = buffer;
	__commandQueue->__storedIndexBuffer->bufferSize = bufferSize;

	__commandQueue->DrawIndices();
}