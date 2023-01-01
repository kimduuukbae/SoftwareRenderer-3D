#include <cmath>
#include "TransformComponent.h"

TransformComponent::TransformComponent() {

}

TransformComponent::~TransformComponent() {
}

void TransformComponent::SetPosition(const Vector3& pos) {
	__position = pos;

	UpdateMatrix();
}

void TransformComponent::SetRotation(const Vector3& euler) {
	__rotation = euler;

	UpdateMatrix();
}

void TransformComponent::SetScale(const Vector3& scale) {
	__scale = scale;

	UpdateMatrix();
}

void TransformComponent::UpdateMatrix() {
	// Scale * Rotation * Translation	

	// 회전 순서는 z -> x -> y 순으로 한다.
	// Rzxy
	float cosX{ std::cosf(__rotation.x) };	float sinX{ std::sinf(__rotation.x) };
	float cosY{ std::cosf(__rotation.y) };	float sinY{ std::sinf(__rotation.y) };
	float cosZ{ std::cosf(__rotation.z) };	float sinZ{ std::sinf(__rotation.z) };
	
	Matrix worldMat{
		cosZ * cosY + sinZ * sinX * sinY,			sinZ * cosX,		cosZ * -sinY + sinZ * sinY * cosY,		 0,
		-sinZ * cosY + sinY * cosZ * sinX,			cosZ * cosX,		sinZ * sinY + sinX * cosZ * cosY,		 0,
		sinY * cosX,								-sinX,				cosX * cosY,							 0,
		__position.x,								__position.y,		__position.z,							 1
	};

	__worldMatrix4x4 = worldMat;
}
