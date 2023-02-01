#pragma once

#include "Vector3.h"
#include "Matrix4x4.h"
#include "Rotator.h"

class Quaternion {
public:
	inline Quaternion() = default;
	inline Quaternion(float realNumberW, float imaginaryI, float imaginaryJ, float imaginaryK);

	inline Rotator ToEuler() const;
	inline Matrix4x4 ToMatrix() const;

	inline float GetRealPart() const;
	inline Vector3 GetImaginaryPart() const;

	inline Quaternion GetConjugate();

	inline Quaternion operator*(const Quaternion& other);
	inline Quaternion operator+(const Quaternion& other);
private:

	float w{ 1.0f };
	float x{ 0.0f };
	float y{ 0.0f };
	float z{ 0.0f };
};

Quaternion::Quaternion(float realNumberW, float imaginaryI, float imaginaryJ, float imaginaryK)
	: w{ realNumberW }, x{ imaginaryI }, y{ imaginaryJ }, z{ imaginaryK }
{}

float Quaternion::GetRealPart() const {
	return w;
}

Vector3 Quaternion::GetImaginaryPart() const {
	return Vector3{ x, y, z };
}

Quaternion Quaternion::operator*(const Quaternion& other) {
	// (w, i, j, k)(other.w, other.i, other.j, other.k)

	float real = {
		w * other.w -
		(GetImaginaryPart() | other.GetImaginaryPart())	// dot
	};

	Vector3 arg1 = { other.GetImaginaryPart() * w };
	Vector3 arg2 = { GetImaginaryPart() * other.w };
	Vector3 arg3 = { GetImaginaryPart() ^ other.GetImaginaryPart() };	// cross

	Vector3 imaginary = { arg1 + arg2 + arg3 };

	return Quaternion{ real, imaginary.x, imaginary.y, imaginary.z };
}

Quaternion Quaternion::operator+(const Quaternion& other) {
	return Quaternion{
		w + other.w,
		x + other.x,
		y + other.y,
		z + other.z
	};
}