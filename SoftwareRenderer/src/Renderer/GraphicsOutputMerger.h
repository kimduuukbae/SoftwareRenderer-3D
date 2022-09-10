#pragma once

class GraphicsOutputMerger {
public:
	void SetStructuredBuffer(class StructedBuffer* buffer);

private:
	void DrawBackBuffer();
};