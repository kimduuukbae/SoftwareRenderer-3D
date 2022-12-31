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

	// ȸ�� ������ z -> x -> y ������ �Ѵ�.
	// Rzxy

	// TODO : Euler Angles 
	



	/*
	Matrix matrix{

		__position.x, __position.y, __position.z
	};*/


}
