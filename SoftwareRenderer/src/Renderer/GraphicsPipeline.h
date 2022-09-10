#pragma once

// Forward Declaration //

class GraphicsRenderOption;
class GraphicsInputAssembler;
class GraphicsVertexShader;
class GraphicsRasterizer;
class GraphicsPixelShader;

class GraphicsPipeline {
public:
	void SetGraphicsRenderOption(GraphicsRenderOption* option);
	void SetGraphicsInputAssembler(GraphicsInputAssembler* inputAssembler);
	void SetGraphicsVertexShader(GraphicsVertexShader* vertexShader);
	void SetGraphicsRasterizer(GraphicsRasterizer* rasterizer);
	void SetGraphicsPixelShader(GraphicsPixelShader* pixelShader);

private:
	GraphicsPipeline();
	~GraphicsPipeline();

	// InputAssembler -> VertexShader -> Rasterizer -> PixelShader

	GraphicsRenderOption* __option;
	GraphicsInputAssembler* __inputAssembler;
	GraphicsVertexShader* __vertexShader;
	GraphicsRasterizer* __rasterizer;
	GraphicsPixelShader* __pixelShader;
};