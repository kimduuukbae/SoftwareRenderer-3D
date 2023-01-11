#pragma once

#include "Matrix4x4.h"

struct Matrix3x3 {
	/*  Row major Matrix
			 m[x][y]

			11 12 13 
			21 22 23 
			31 32 33 
	*/

	float m[3][3]{};

	inline Matrix3x3() = default;
	inline Matrix3x3(const Matrix4x4& mat);
	inline Matrix3x3(const Vector3& newX, const Vector3& newY, const Vector3& newZ);
	inline Matrix3x3
	(float m11, float m12, float m13, 
	 float m21, float m22, float m23,
	 float m31, float m32, float m33);

	inline Matrix3x3 operator*(const Matrix3x3& other) const;
	inline Matrix3x3 operator+(const Matrix3x3& other) const;
	inline Matrix3x3 operator-(const Matrix3x3& other) const;

	inline bool operator==(const Matrix3x3& other) const;
	inline bool operator!=(const Matrix3x3& other) const;

	inline float& operator()(size_t row, size_t column);
	inline float operator()(size_t row, size_t column) const;
	inline Matrix3x3 Inverse() const;

	inline float GetDeterminant() const;
	inline void Transpose();
	inline Matrix3x3 GetTranspose();

	inline static Matrix3x3 GetTranspose(const Matrix3x3& target);
};