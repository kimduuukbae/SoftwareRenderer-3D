#pragma once

#include "Vector3.h"	// euler
#include "Quaternion.h"	// quaternion

// ��� ȸ���� ó������ 
class Rotator {
public:
	Rotator(const Vector3& euler);
	Rotator(float x, float y, float z);
	Rotator(const Quaternion& quaternion);

private:
};