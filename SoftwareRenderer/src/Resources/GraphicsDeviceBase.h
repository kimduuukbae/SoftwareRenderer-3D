#pragma once

// ��� Graphics Device���� ����� �Ǵ� Ŭ�����Դϴ�.
class GraphicsDeviceBase {
public:
	GraphicsDeviceBase();
	
	virtual ~GraphicsDeviceBase();
	virtual void Release();

private:

	int __deviceID;
};