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
	m[0][0] = mat(0, 0);	m[0][1] = mat(0, 1);	m[0][2] = mat(0, 2);
	m[1][0] = mat(1, 0);	m[1][1] = mat(1, 1);	m[1][2] = mat(1, 2);
	m[2][0] = mat(2, 0);	m[2][1] = mat(2, 1);	m[2][2] = mat(2, 2);
}

inline Matrix3x3::Matrix3x3(const Vector3& newX, const Vector3& newY, const Vector3& newZ) {
	memcpy(m[0], &newX, sizeof(Vector3));
	memcpy(m[1], &newY, sizeof(Vector3));
	memcpy(m[1], &newZ, sizeof(Vector3));
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
	Matrix3x3 newMat{};

	for (std::size_t x = 0; x < 3; ++x) {
		for (std::size_t y = 0; y < 3; ++y) {
			newMat(x, y) = m[x][y] * other(x, y);
		}
	}

	return newMat;
}

inline Matrix3x3 Matrix3x3::operator+(const Matrix3x3& other) const
{
	Matrix3x3 newMat{};

	for (std::size_t x = 0; x < 3; ++x) {
		for (std::size_t y = 0; y < 3; ++y) {
			newMat(x, y) = m[x][y] + other(x, y);
		}
	}

	return newMat;
}

inline Matrix3x3 Matrix3x3::operator-(const Matrix3x3& other) const
{
	Matrix3x3 newMat{};

	for (std::size_t x = 0; x < 3; ++x) {
		for (std::size_t y = 0; y < 3; ++y) {
			newMat(x, y) = m[x][y] - other(x, y);
		}
	}

	return newMat;
}

inline bool Matrix3x3::operator==(const Matrix3x3& other) const
{
	for (std::size_t x = 0; x < 3; ++x) {
		for (std::size_t y = 0; y < 3; ++y) {
			if (m[x][y] != other(x, y)) return false;
		}
	}

	return true;
}

inline bool Matrix3x3::operator!=(const Matrix3x3& other) const {
	return !(*this == other);
}

inline float& Matrix3x3::operator()(size_t row, size_t column) {
	return m[row][column];
}

inline float Matrix3x3::operator()(size_t row, size_t column) const {
	return m[row][column];
}

inline Matrix3x3 Matrix3x3::Inverse() const {
	return Matrix3x3();
}

inline float Matrix3x3::GetDeterminant() const {
	return 0.0f;
}

inline void Matrix3x3::Transpose() {
	Matrix3x3 other{ *this };

	m[0][0] = other(0, 0);	m[0][1] = other(1, 0);	m[0][2] = other(2, 0);
	m[1][0] = other(0, 1);	m[1][1] = other(1, 1);	m[1][2] = other(2, 1);
	m[2][0] = other(0, 2);	m[1][1] = other(1, 2);	m[1][2] = other(2, 2);
}

inline Matrix3x3 Matrix3x3::GetTranspose()
{
	Matrix3x3 newMat{ *this };
	newMat.Transpose();

	return newMat;
}
