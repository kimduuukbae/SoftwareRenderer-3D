#pragma once

class GraphicsVertexShader {
public:
	GraphicsVertexShader(class Shader* shader);
	~GraphicsVertexShader();
	
private:
	class Shader* __vertexShader;
};