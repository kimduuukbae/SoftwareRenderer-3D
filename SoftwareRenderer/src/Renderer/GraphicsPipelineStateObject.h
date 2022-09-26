#pragma once

class GraphicsPipelineStateObject {
public:
	void SetGraphicsPipeline(class GraphicsPipeline* pipeline);
	
private:
	class GraphicsPipeline* __pipeline;
};
