#pragma once

class Shader {
public:
	Shader() = default;
	virtual ~Shader() = default;


	// ���⿡ ���̴� �ڵ带 �ۼ��մϴ�.
	virtual void Implementation(class StructedBuffer* sb) = 0;
	void PassBuffer();
private:

};