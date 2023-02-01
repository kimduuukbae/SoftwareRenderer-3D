#pragma once

#include "Vector3.h"
#include "Matrix4x4.h"
#include "Rotator.h"

class Quaternion {
public:
	inline Quaternion() = default;
	inline Quaternion(float realNumberW, float imaginaryI, float imaginaryJ, float imaginaryK);

	inline Rotator ToEuler() const;
	inline Vector3 ToVector() const;
	inline Matrix4x4 ToMatrix() const;

	inline Quaternion GetConjugate();

	inline Quaternion operator*(const Quaternion& other);
	inline Quaternion operator+(const Quaternion& other);
private:

	float w, i, j, k;
};

Quaternion::Quaternion(float realNumberW, float imaginaryI, float imaginaryJ, float imaginaryK)
	: w{ realNumberW }, i{ imaginaryI }, j{ imaginaryJ }, k{ imaginaryK }
{}



Vector3 Quaternion::ToVector() const {
	return Vector3{ i, j, k };
}

Quaternion Quaternion::operator*(const Quaternion& other) {
	// (w, i, j, k)(other.w, other.i, other.j, other.k)

	float real = {
		w * other.w -
		(ToVector() | other.ToVector())	// dot
	};

	Vector3 arg1 = { other.ToVector() * w };
	Vector3 arg2 = { ToVector() * other.w };
	Vector3 arg3 = { ToVector() ^ other.ToVector() };	// cross

	Vector3 imaginary = { arg1 + arg2 + arg3 };

	return Quaternion{ real, imaginary.x, imaginary.y, imaginary.z };
}

Quaternion Quaternion::operator+(const Quaternion& other) {
	return Quaternion{
		w + other.w,
		i + other.i,
		j + other.j,
		k + other.k
	};
}