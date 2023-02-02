#pragma once

#include "Vector3.h"
#include "Matrix4x4.h"
#include "Rotator.h"

struct Rotator;

class Quaternion {
public:
	inline Quaternion() = default;
	inline Quaternion(float realNumberW, float imaginaryI, float imaginaryJ, float imaginaryK);

	inline void FromRotator(const Rotator& inRotator);
	inline Rotator ToRotator() const;

	inline void FromMatrix(const Matrix4x4& inMatrix);
	inline Matrix4x4 ToMatrix() const;

	inline float GetRealPart() const;
	inline Vector3 GetImaginaryPart() const;

	inline Quaternion GetConjugate() const;

	inline Quaternion Multiply(const Quaternion& other);

	inline Quaternion operator*(const Quaternion& other);
	inline Vector3 operator*(const Vector3& inVector);
	inline Quaternion operator+(const Quaternion& other);

	inline Vector3 RotateVector(const Vector3& inVector);

private:

	float w{ 1.0f };
	float x{ 0.0f };
	float y{ 0.0f };
	float z{ 0.0f };
};

Quaternion::Quaternion(float realNumberW, float imaginaryI, float imaginaryJ, float imaginaryK)
	: w{ realNumberW }, x{ imaginaryI }, y{ imaginaryJ }, z{ imaginaryK }
{}

void Quaternion::FromRotator(const Rotator& inRotator){
	Vector3 v = { inRotator.ToVector() };
	
	float cosPit = { std::cosf(v.x * 0.5f) }; float sinPit = { std::sinf(v.x * 0.5f) };
	float cosYaw = { std::cosf(v.y * 0.5f) }; float sinYaw = { std::sinf(v.y * 0.5f) };
	float cosRoll = { std::cosf(v.z * 0.5f) }; float sinRoll = { std::sinf(v.z * 0.5f) };

	w = sinYaw * sinPit * sinRoll + cosYaw * cosPit * cosRoll;
	x = sinYaw * sinRoll * cosPit + sinPit * cosYaw * cosRoll;
	y = sinYaw * cosPit * cosRoll + sinPit * sinRoll * cosYaw;
	z = -sinYaw * sinPit * cosRoll + sinRoll * cosYaw * cosPit;
}

Rotator Quaternion::ToRotator() const {

}

float Quaternion::GetRealPart() const {
	return w;
}

Vector3 Quaternion::GetImaginaryPart() const {
	return Vector3{ x, y, z };
}

Quaternion Quaternion::GetConjugate() const {
	return Quaternion{
		w,
		-x,
		-y,
		-z
	};
}

Quaternion Quaternion::Multiply(const Quaternion& other) {
	// (w, i, j, k)(other.w, other.i, other.j, other.k), 성분곱

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

Quaternion Quaternion::operator*(const Quaternion& other) {
	// 두 개의 다른 각을 연속 회전 시키는 경우의 연산자
	
	Vector3 v1{ x, y, z };
	Vector3 v2{ other.x, other.y, other.z };
	Vector3 v = { v2 * w + v1 * other.w + (v1 ^ v2) };

	return Quaternion{
		w * other.w - (v1 | v2),
		v.x,
		v.y,
		v.z
	};
}

Vector3 Quaternion::operator*(const Vector3& inVector) {
	return RotateVector(inVector);
}

Quaternion Quaternion::operator+(const Quaternion& other) {
	return Quaternion{
		w + other.w,
		x + other.x,
		y + other.y,
		z + other.z
	};
}

Vector3 Quaternion::RotateVector(const Vector3& inVector) {
	Vector3 q{ x, y, z };
	Vector3 t{ (q ^ inVector) * 2.0f };
	Vector3 result{ inVector + (t + w) + (q ^ t) };
	
	return result;
}