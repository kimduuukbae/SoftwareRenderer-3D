#pragma once

#include "GraphicsCommonHeader.h"

class GraphicsInputAssembler {
public:
	void SetDescribe(IAAssembleDescribe desc);
	void SetVertices(class BufferBase* buffer);

private:
	void Process();

	IAAssembleDescribe __describe;
	class BufferBase* __vertexBuffer;
};