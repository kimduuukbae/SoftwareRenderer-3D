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

	Matrix __worldMatrix4x4{};

	// euler 
	Vector3 position{};
	Vector3 rotation{};
	Vector3 scale{};
};