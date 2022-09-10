#pragma once

class GraphicsPixelShader {
public:
	GraphicsPixelShader(class Shader* shader);
	~GraphicsPixelShader();

private:
	class Shader* __pixelShader;
};