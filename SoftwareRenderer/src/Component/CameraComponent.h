#pragma once

#include "TransformComponent.h"
#include "Vector4.h"
#include "Matrix.h"

class CameraComponent : public ComponentBase {
public:
	Matrix GetViewMatrix() const;
	Matrix GetClipMatrix() const;

	// 원근투영은 소프트웨어 래스터라이저가 처리한다.

	
private:
	Matrix __viewMatrix4x4;
	Matrix __clipMatrix4x4;


	TransformComponent* __transform;	// TransformComponent 를 통해서 카메라의 world pos를 나타냄
};