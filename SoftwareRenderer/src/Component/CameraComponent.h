#pragma once

#include "TransformComponent.h"
#include "Vector4.h"
#include "Matrix.h"

class CameraComponent : public ComponentBase {
public:
	Matrix GetViewMatrix() const;
	Matrix GetClipMatrix() const;

	// ���������� ����Ʈ���� �����Ͷ������� ó���Ѵ�.

	
private:
	Matrix __viewMatrix4x4;
	Matrix __clipMatrix4x4;


	TransformComponent* __transform;	// TransformComponent �� ���ؼ� ī�޶��� world pos�� ��Ÿ��
};