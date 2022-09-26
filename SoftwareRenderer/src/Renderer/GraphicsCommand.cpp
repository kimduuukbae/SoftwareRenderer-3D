#include "GraphicsCommand.h"
#include "GraphicsCommandQueue.h"
#include "GraphicsPipelineStateObject.h"


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

}

void GraphicsCommand::DrawIndexed()
{
}
