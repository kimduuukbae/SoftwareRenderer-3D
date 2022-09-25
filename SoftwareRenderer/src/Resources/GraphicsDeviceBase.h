#pragma once

// 모든 Graphics Device들의 기반이 되는 클래스입니다.
class GraphicsDeviceBase {
public:
	GraphicsDeviceBase();
	
	virtual ~GraphicsDeviceBase();
	virtual void Release();

private:

	int __deviceID;
};