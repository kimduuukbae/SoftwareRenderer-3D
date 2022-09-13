#pragma once

class Shader {
public:
	Shader() = default;
	virtual ~Shader() = default;


	// 여기에 셰이더 코드를 작성합니다.
	virtual void Implementation(class StructedBuffer* sb) = 0;

	// 파이프라인의 다음 구간에 버퍼를 넘기는 행동
	void PassBuffer();
private:

};