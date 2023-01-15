#pragma once

#include "Matrix4x4.h"

struct Matrix3x3 {
	/*  Row major Matrix
			 m[row(x)][column(y)]

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


inline Matrix3x3::Matrix3x3(const Matrix4x4& mat) {

}

inline Matrix3x3::Matrix3x3(const Vector3& newX, const Vector3& newY, const Vector3& newZ) {

}

inline Matrix3x3::Matrix3x3(
	float m11, float m12, float m13,
	float m21, float m22, float m23, 
	float m31, float m32, float m33) {

	m[0][0] = m11;	m[0][1] = m12;	m[0][2] = m13;
	m[1][0] = m21;	m[1][1] = m22;	m[1][2] = m23;
	m[2][0] = m31;	m[2][1] = m32;	m[2][2] = m33;
}

inline Matrix3x3 Matrix3x3::operator*(const Matrix3x3& other) const
{
	return Matrix3x3();
}

inline Matrix3x3 Matrix3x3::operator+(const Matrix3x3& other) const
{
	return Matrix3x3();
}

inline Matrix3x3 Matrix3x3::operator-(const Matrix3x3& other) const
{
	return Matrix3x3();
}

inline bool Matrix3x3::operator==(const Matrix3x3& other) const
{
	return false;
}

inline bool Matrix3x3::operator!=(const Matrix3x3& other) const
{
	return false;
}

inline float& Matrix3x3::operator()(size_t row, size_t column)
{
	// TODO: 여기에 return 문을 삽입합니다.
}

inline float Matrix3x3::operator()(size_t row, size_t column) const
{
	return 0.0f;
}

inline Matrix3x3 Matrix3x3::Inverse() const
{
	return Matrix3x3();
}

inline float Matrix3x3::GetDeterminant() const
{
	return 0.0f;
}

inline void Matrix3x3::Transpose()
{
}

inline Matrix3x3 Matrix3x3::GetTranspose()
{
	return Matrix3x3();
}
