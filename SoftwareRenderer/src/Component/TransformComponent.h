#pragma once

#include "ComponentBase.h"
#include "Vector3.h"
#include "Matrix.h"

class TransformComponent : public ComponentBase {
public:
	TransformComponent();
	virtual ~TransformComponent();

	void SetPosition();

private:
	// resource == x, y, z
	void UpdateMatrix();


	Vector3 position{};
	Matrix __worldMatrix4x4{};
};