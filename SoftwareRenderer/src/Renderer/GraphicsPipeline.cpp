#include "GraphicsPipeline.h"
#include "GraphicsRenderOption.h"
#include "GraphicsInputAssembler.h"
#include "GraphicsRasterizer.h"
#include "GraphicsVertexShader.h"
#include "GraphicsPixelShader.h"

void GraphicsPipeline::SetGraphicsRenderOption(GraphicsRenderOption* option) {
	__option = option;
}

void GraphicsPipeline::SetGraphicsInputAssembler(GraphicsInputAssembler* inputAssembler) {
	__inputAssembler = inputAssembler;
}

void GraphicsPipeline::SetGraphicsVertexShader(GraphicsVertexShader* vertexShader) {
	__vertexShader = vertexShader;
}

void GraphicsPipeline::SetGraphicsRasterizer(GraphicsRasterizer* rasterizer) {
	__rasterizer = rasterizer;
}

void GraphicsPipeline::SetGraphicsPixelShader(GraphicsPixelShader* pixelShader) {
	__pixelShader = pixelShader;
}