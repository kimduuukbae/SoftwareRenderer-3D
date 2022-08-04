#pragma once

class GraphicsPipeline {
public:


	void Execute();

private:
	GraphicsPipeline();
	~GraphicsPipeline();

	class GraphicsRenderOption* option;
};