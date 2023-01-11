#pragma once

#include "TransformComponent.h"
#include "Vector4.h"
#include "Matrix4x4.h"

class CameraComponent : public ComponentBase {
public:
	Matrix4x4 GetViewMatrix() const;
	Matrix4x4 GetClipMatrix() const;

	// ���������� ����Ʈ���� �����Ͷ������� ó���Ѵ�.

	
private:
	Matrix4x4 __viewMatrix4x4;
	Matrix4x4 __clipMatrix4x4;


	TransformComponent* __transform;	// TransformComponent �� ���ؼ� ī�޶��� world pos�� ��Ÿ��
};