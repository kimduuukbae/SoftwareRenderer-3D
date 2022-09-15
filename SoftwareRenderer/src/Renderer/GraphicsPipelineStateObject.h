#pragma once

class GraphicsPipelineStateObject {
public:
	void SetGraphicsPipeline(class GraphicsPipeline* pipeline);
	void SetGraphicsCommandQueue(class GraphicsCommandQueue* queue);
	
private:
	class GraphicsPipeline* __pipeline;
};
