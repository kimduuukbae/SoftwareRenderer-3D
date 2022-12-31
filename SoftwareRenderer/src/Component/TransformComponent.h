#pragma once

#include "ComponentBase.h"
#include "Vector3.h"
#include "Matrix.h"

class TransformComponent : public ComponentBase {
public:
	TransformComponent();
	virtual ~TransformComponent();

	void SetPosition(const Vector3& pos);
	void SetRotation(const Vector3& euler);
	void SetScale(const Vector3& scale);

private:
	// resource == x, y, z
	void UpdateMatrix();

	Matrix __worldMatrix4x4 {};

	// euler 

	Vector3 __position { 0.0f, 0.0f, 0.0f };
	Vector3 __rotation { 0.0f, 0.0f, 0.0f };
	Vector3 __scale	   { 1.0f, 1.0f, 1.0f };
};