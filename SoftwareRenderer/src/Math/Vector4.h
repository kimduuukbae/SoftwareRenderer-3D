#pragma once

#include "Vector3.h"
#include "Matrix4x4.h"


struct Matrix4x4;

/*
	Homogeneous Vector or Color
*/
__declspec(align(16)) struct Vector4 {
	/* components */

	union {
		float x;
		float r;
	};

	union {
		float y;
		float g;
	};

	union {
		float z;
		float b;
	};

	union {
		float w;
		float a;
	};


	inline Vector4();
	inline Vector4(float x, float y, float z, float w);
	inline Vector4(const Vector3& newVector, float newW);
	inline Vector4(const Vector4& newVector);

	/* element operations */
	inline void Add(const Vector4& other);
	inline void Multiply(const Vector4& other);
	inline void Subtract(const Vector4& other);

	/* add by components */
	inline Vector4 operator+(const Vector4& other);
	inline Vector4 operator-(const Vector4& other);
	inline Vector4 operator*(const Vector4& other);
	inline Vector4 operator*(const Matrix4x4& other);
	inline Vector4 operator/(const Vector4& other);
	inline Vector4 operator/(float scalar);

	/* cross product */
	inline Vector4 operator^(const Vector4& other) const;

	/* Access components*/
	inline float operator[](int32_t componentIndex) const;
	inline float& operator[](int32_t componentIndex);

	/* Set all of the vectors coordinates */
	inline void Set(float newX, float newY, float newZ);

	inline static float Dot3Product(const Vector4& lhs, const Vector4& rhs);
	inline static float Dot4Product(const Vector4& lhs, const Vector4& rhs);
	inline static Vector3 CrossProduct(const Vector4& lhs, const Vector4& rhs);

	inline void Normalize();
	inline void Normalize3();

	inline bool IsNormalized();
	inline bool IsNormalized3();

	inline float Size() const;
	inline float Size3() const;

	inline float SizeSquared() const;
	inline float SizeSquared3() const;
};

using Color = Vector4;


inline Vector4::Vector4() : 
	Vector4{ 0.0f, 0.0f, 0.0f, 1.0f } {}

inline Vector4::Vector4(float x, float y, float z, float w) :
	x{ x },
	y{ y },
	z{ z },
	w{ w } {}

inline Vector4::Vector4(const Vector3& newVector, float newW = 1.0f) :
	x{ newVector.x },
	y{ newVector.y },
	z{ newVector.z },
	w{ newW } {}

inline Vector4::Vector4(const Vector4& newVector) : 
	x{ newVector.x },
	y{ newVector.y },
	z{ newVector.z },
	w{ newVector.w } {}

float& Vector4::operator[](int32_t componentIndex) {
	return (&x)[componentIndex];
}

float Vector4::operator[](int32_t componentIndex) const {
	return (&x)[componentIndex];
}

void Vector4::Add(const Vector4& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
}

void Vector4::Multiply(const Vector4& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
	w *= other.w;
}

void Vector4::Subtract(const Vector4& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.z;
}

Vector4 Vector4::operator+(const Vector4& other) {
	return { x + other.x, y + other.y, z + other.z, w + other.w };
}

Vector4 Vector4::operator-(const Vector4& other) {
	return { x - other.x, y - other.y, z - other.z, w - other.w };
}

Vector4 Vector4::operator*(const Vector4& other) {
	return { x * other.x, y * other.y, z * other.z, w * other.w };
}

Vector4 Vector4::operator*(const Matrix4x4& other)
{
	Vector4 __dest{ };

	__dest.x = x * other.m[0][0] + y * other.m[1][0] + z * other.m[2][0] + w * other.m[3][0];
	__dest.y = x * other.m[0][1] + y * other.m[1][1] + z * other.m[2][1] + w * other.m[3][1];
	__dest.z = x * other.m[0][2] + y * other.m[1][2] + z * other.m[2][2] + w * other.m[3][2];
	__dest.w = x * other.m[0][3] + y * other.m[1][3] + z * other.m[2][3] + w * other.m[3][3];

	return __dest;
}

Vector4 Vector4::operator/(const Vector4& other) {
	return { x / other.x, y / other.y, z / other.z, w / other.w };
}

Vector4 Vector4::operator/(float scalar) {
	return { x / scalar, y / scalar, z / scalar, w / scalar };
}

Vector4 Vector4::operator^(const Vector4& other) const {
	return{
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x,
		0.0f
	};
}

void Vector4::Set(float newX, float newY, float newZ) {
	x = newX;
	y = newY;
	z = newZ;
}

float Vector4::Dot3Product(const Vector4& lhs, const Vector4& rhs) {
	return { lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z };
}

float Vector4::Dot4Product(const Vector4& lhs, const Vector4& rhs) {
	return { Dot3Product(lhs, rhs) + lhs.w * rhs.w };
}

Vector3 Vector4::CrossProduct(const Vector4& lhs, const Vector4& rhs) {
	 Vector4 v{ lhs ^ rhs };
	 return { v.x, v.y, v.z };
}

void Vector4::Normalize(){
	 float pow{ Size() };

	 x /= pow;
	 y /= pow;
	 z /= pow;
	 w /= pow;
 }

void Vector4::Normalize3() {
	float pow{ Size3() };
	x /= pow;
	y /= pow;
	z /= pow;
}

bool Vector4::IsNormalized(){
	return std::abs(1.0f - SizeSquared()) < 0.01f;
}

bool Vector4::IsNormalized3(){
	return std::abs(1.0f - SizeSquared3()) < 0.01f;
}

float Vector4::Size() const {
	return std::sqrtf(x * x + y * y + z * z + w * w);
}

float Vector4::Size3() const{
	return std::sqrtf(x * x + y * y + z * z);
}

float Vector4::SizeSquared() const {
	 return { x * x + y * y + z * z + w * w };
}

float Vector4::SizeSquared3() const {
	return { x * x + y * y + z * z };
}
