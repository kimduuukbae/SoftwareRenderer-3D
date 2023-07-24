#pragma once

/* Logic
	1. Command로 데이터를 셋하고, 드로우 요청을 한 후  execute 를 실행
	2. CommandQueue가 Execute를 받으면, CommandProcessor 에게 데이터를 넘겨주고 처리시킴
	3. CommandProcessor가 셋하고, 드로우 하고 설정하고 PSO의 파이프라인 흐름이 흘러가게 함
	4. PSO의 Output Merger가 버퍼를 만들어서 뱉어내면, Window 에서 bitblt 함.
*/

class GraphicsPipelineStateObject {
public:
	void SetGraphicsPipeline(class GraphicsPipeline* pipeline);
	
private:
	class GraphicsPipeline* __pipeline;

	friend GraphicsCommandQueue;
};

