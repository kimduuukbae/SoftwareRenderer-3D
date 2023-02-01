#pragma once

#include "Vector3.h"	// euler
#include "Quaternion.h"	// quaternion

// 어떠한 회전을 처리해줌 
class Rotator {
public:
	Rotator(const Vector3& euler);
	Rotator(float x, float y, float z);
	Rotator(const Quaternion& quaternion);

private:
};