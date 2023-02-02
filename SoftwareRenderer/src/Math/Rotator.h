#pragma once

#include "Vector3.h"	// euler
#include "Quaternion.h"	// quaternion

// ȸ�� ����, ȸ����  z -> x -> y ������ �Ѵ�. 
class Rotator {
public:
	inline Rotator() = default;
	inline Rotator(const Vector3& euler);
	inline Rotator(float x, float y, float z);
	inline Rotator(const Quaternion& quaternion);

	inline Vector3 ToVector() const;
private:
	float roll{};
	float pitch{};
	float yaw{};
};

// pitch, yaw, roll
Vector3 Rotator::ToVector() const {
	return { pitch, yaw, roll };
}
