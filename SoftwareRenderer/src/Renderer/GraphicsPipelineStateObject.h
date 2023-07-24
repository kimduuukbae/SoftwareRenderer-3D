#pragma once

/* Logic
	1. Command�� �����͸� ���ϰ�, ��ο� ��û�� �� ��  execute �� ����
	2. CommandQueue�� Execute�� ������, CommandProcessor ���� �����͸� �Ѱ��ְ� ó����Ŵ
	3. CommandProcessor�� ���ϰ�, ��ο� �ϰ� �����ϰ� PSO�� ���������� �帧�� �귯���� ��
	4. PSO�� Output Merger�� ���۸� ���� ����, Window ���� bitblt ��.
*/

class GraphicsPipelineStateObject {
public:
	void SetGraphicsPipeline(class GraphicsPipeline* pipeline);
	
private:
	class GraphicsPipeline* __pipeline;

	friend GraphicsCommandQueue;
};

