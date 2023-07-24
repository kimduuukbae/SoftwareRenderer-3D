#pragma once

#include "Vector4.h"
#include "Matrix3x3.h"

struct Matrix3x3;

struct Matrix4x4 {	
	/*    Row major Matrix4x4
			  m[x][y]

			11 12 13 14
			21 22 23 24
			31 32 33 34
			41 42 43 44
	*/

	alignas(16) float m[4][4]{};

	inline Matrix4x4() = default;
	inline Matrix4x4(const Vector4& newX, const Vector4& newY, const Vector4& newZ, const Vector4& newW);
	inline Matrix4x4(const Vector3& newX, const Vector3& newY, const Vector3& newZ);
	inline Matrix4x4(
		   float m11, float m12, float m13, float m14,
		   float m21, float m22, float m23, float m24,
		   float m31, float m32, float m33, float m34,
		   float m41, float m42, float m43, float m44);

	inline Matrix4x4 operator*(const Matrix4x4& other) const;
	inline Matrix4x4 operator+(const Matrix4x4& other) const;
	inline Matrix4x4 operator-(const Matrix4x4& other) const;

	inline bool operator==(const Matrix4x4& other) const;
	inline bool operator!=(const Matrix4x4& other) const;

	inline float& operator()(size_t row, size_t column);
	inline float operator()(size_t row, size_t column) const;
	inline Matrix4x4 Inverse() const;
	inline bool Invert();

	inline float GetDeterminant() const;
	inline void Transpose();
	inline Matrix4x4 GetTranspose();

	inline static Matrix4x4 GetTranspose(const Matrix4x4& target);
};


inline Matrix4x4::Matrix4x4(const Vector4& newX, const Vector4& newY, const Vector4& newZ, const Vector4& newW) {
	memcpy(m[0], &newX, sizeof(Vector4));
	memcpy(m[1], &newY, sizeof(Vector4));
	memcpy(m[2], &newZ, sizeof(Vector4));
	memcpy(m[3], &newW, sizeof(Vector4));
}

inline Matrix4x4::Matrix4x4(const Vector3& newX, const Vector3& newY, const Vector3& newZ) {
	memcpy(m[0], &newX, sizeof(Vector3));
	memcpy(m[1], &newY, sizeof(Vector3));
	memcpy(m[2], &newZ, sizeof(Vector3));
}

inline Matrix4x4::Matrix4x4(float m11, float m12, float m13, float m14,
			   float m21, float m22, float m23, float m24,
			   float m31, float m32, float m33, float m34,
			   float m41, float m42, float m43, float m44) {
	m[0][0] = m11; m[0][1] = m12; m[0][2] = m13; m[0][3] = m14;
	m[1][0] = m21; m[1][1] = m22; m[1][2] = m23; m[1][3] = m24;
	m[2][0] = m31; m[2][1] = m32; m[2][2] = m33; m[2][3] = m34;
	m[3][0] = m41; m[3][1] = m42; m[3][2] = m43; m[3][3] = m44;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& other) const {
	Matrix4x4 newMat{};

	for (size_t x{ 0 }; x < 4; ++x) {
		for (size_t y{ 0 }; y < 4; ++y) 
			newMat(x,y) = m[x][y] * other.m[x][y];	
	}

	return newMat;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& other) const {
	Matrix4x4 newMat{};

	for (size_t x{ 0 }; x < 4; ++x) {
		for (size_t y{ 0 }; y < 4; ++y)
			newMat(x, y) = m[x][y] + other.m[x][y];
	}

	return newMat;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& other) const {
	Matrix4x4 newMat{};

	for (size_t x{ 0 }; x < 4; ++x) {
		for (size_t y{ 0 }; y < 4; ++y)
			newMat(x, y) = m[x][y] - other.m[x][y];
	}

	return newMat;
}

bool Matrix4x4::operator==(const Matrix4x4& other) const {
	for (size_t x{ 0 }; x < 4; ++x) {
		for (size_t y{ 0 }; y < 4; ++y) 
			if (m[x][y] != other.m[x][y]) return false;
	}
	return true;
}

bool Matrix4x4::operator!=(const Matrix4x4& other) const {
	return !(*this == other);
}

inline float& Matrix4x4::operator()(size_t row, size_t column) {
	return m[row][column];
}

inline float Matrix4x4::operator()(size_t row, size_t column) const {
	return m[row][column];
}

Matrix4x4 Matrix4x4::Inverse() const {
	Matrix4x4 m{ *this };
	bool bIsSuccess = m.Invert();

	if (bIsSuccess == false) {
		constexpr auto nan = std::numeric_limits<float>::max();

		return Matrix4x4{
			nan,	nan,	nan,	nan,
			nan,	nan,	nan,	nan,
			nan,	nan,	nan,	nan,
			nan,	nan,	nan,	nan
		};
	}

	return m;
}

inline bool Matrix4x4::Invert()
{
	/*
		Comment : 전치를 하는 이유
		내 렌더러는 보기 쉽게 하기 위해 row major 를 사용하고있다. ( m[row][column] 형식이다 )
		하지만, 역행렬을 계산하는 방식은 대부분 column major 형식으로만 되어있다..
		그래서 계산하기전 row major 를 column major 로 변경해주기 위해 전치시킨다. ( 계산식을 해괴하게 만드는것보단 보기좋을것이다 )
	*/

	Transpose();

	float sub3412 = m[2][0] * m[3][1] - m[2][1] * m[3][0];
	float sub3413 = m[2][0] * m[3][2] - m[2][2] * m[3][0];
	float sub3414 = m[2][0] * m[3][3] - m[2][3] * m[3][0];
	float sub3423 = m[2][1] * m[3][2] - m[2][2] * m[3][1];
	float sub3424 = m[2][1] * m[3][3] - m[2][3] * m[3][1];
	float sub3434 = m[2][2] * m[3][3] - m[2][3] * m[3][2];
	float sub2412 = m[1][0] * m[3][1] - m[1][1] * m[3][0];
	float sub2413 = m[1][0] * m[3][2] - m[1][2] * m[3][0];
	float sub2414 = m[1][0] * m[3][3] - m[1][3] * m[3][0];
	float sub2423 = m[1][1] * m[3][2] - m[1][2] * m[3][1];
	float sub2424 = m[1][1] * m[3][3] - m[1][3] * m[3][2];
	float sub2434 = m[1][2] * m[3][3] - m[1][3] * m[3][2];
	float sub2312 = m[1][0] * m[2][1] - m[1][1] * m[2][0];
	float sub2313 = m[1][0] * m[2][2] - m[1][1] * m[2][0];
	float sub2314 = m[1][0] * m[2][3] - m[1][3] * m[2][0];
	float sub2323 = m[1][1] * m[2][2] - m[1][2] * m[2][1];
	float sub2324 = m[1][1] * m[2][3] - m[1][3] * m[2][1];
	float sub2334 = m[1][2] * m[2][3] - m[1][3] * m[2][2];

	float sd11 = m[1][1] * sub3434 - m[1][2] * sub3424 + m[1][3] * sub3423;
	float sd12 = m[1][0] * sub3434 - m[1][2] * sub3414 + m[1][3] * sub3413;
	float sd13 = m[1][0] * sub3424 - m[1][1] * sub3414 + m[1][3] * sub3412;
	float sd14 = m[1][0] * sub3423 - m[1][1] * sub3413 + m[1][2] * sub3412;

	float sd21 = m[0][1] * sub3434 - m[0][2] * sub3424 + m[0][3] * sub3423;
	float sd22 = m[0][0] * sub3434 - m[0][2] * sub3414 + m[0][3] * sub3413;
	float sd23 = m[0][0] * sub3424 - m[0][1] * sub3414 + m[0][3] * sub3412;
	float sd24 = m[0][0] * sub3423 - m[0][1] * sub3413 + m[0][2] * sub3412;

	float sd31 = m[0][1] * sub2434 - m[0][2] * sub2424 + m[0][3] * sub2423;
	float sd32 = m[0][0] * sub2434 - m[0][2] * sub2414 + m[0][3] * sub2413;
	float sd33 = m[0][0] * sub2424 - m[0][2] * sub2414 + m[0][3] * sub2412;
	float sd34 = m[0][0] * sub2423 - m[0][1] * sub2413 + m[0][2] * sub2412;

	float sd41 = m[0][1] * sub2334 - m[0][2] * sub2324 + m[0][3] * sub2323;
	float sd42 = m[0][0] * sub2334 - m[0][2] * sub2314 + m[0][3] * sub2313;
	float sd43 = m[0][0] * sub2324 - m[0][1] * sub2314 + m[0][3] * sub2312;
	float sd44 = m[0][0] * sub2323 - m[0][1] * sub2313 + m[0][2] * sub2312;

	float devInv = 1.0f / (m[0][0] * sd11 - m[0][1] * sd12 + m[0][2] * sd13 - m[0][3] * sd14);

	if (devInv == 0.0f) 
		return false;

	m[0][0] = sd11 * devInv;	m[0][1] = -sd12 * devInv;	m[0][2] = sd13 * devInv;	m[0][3] = -sd14 * devInv;
	m[1][0] = -sd21 * devInv;	m[1][1] = sd22 * devInv;	m[1][2] = -sd23 * devInv;	m[1][3] = sd24 * devInv;
	m[2][0] = sd31 * devInv;	m[2][1] = -sd32 * devInv;	m[2][2] = sd33 * devInv;	m[2][3] = -sd34 * devInv;
	m[3][0] = -sd41 * devInv;	m[3][1] = sd42 * devInv;	m[3][2] = -sd43 * devInv;	m[3][3] = sd44 * devInv;

	return true;
}

float Matrix4x4::GetDeterminant() const {
	Matrix3x3 a11 {
		m[1][1], m[1][2], m[1][3],
		m[2][1], m[2][2], m[2][3],
		m[3][1], m[3][2], m[3][3],
	};

	Matrix3x3 a12 {
		m[1][0], m[1][2], m[1][3],
		m[2][0], m[2][2], m[2][3],
		m[3][0], m[3][2], m[3][3],
	};

	Matrix3x3 a13 {
		m[1][0], m[1][1], m[1][3],
		m[2][0], m[2][1], m[2][3],
		m[3][0], m[3][1], m[3][3],
	};

	Matrix3x3 a14{
		m[1][0], m[1][1], m[1][2],
		m[2][0], m[2][1], m[2][2],
		m[3][0], m[3][1], m[3][2],
	};

	return  m[0][0] * a11.GetDeterminant() -
			m[0][1] * a12.GetDeterminant() +
			m[0][2] * a13.GetDeterminant() -
			m[0][3] * a14.GetDeterminant();
}

void Matrix4x4::Transpose() {
	Matrix4x4 other{ *this };
	
	m[0][0] = other(0, 0);	m[1][0] = other(0, 1);	m[2][0] = other(0, 2);	m[3][0] = other(0, 3);
	m[0][1] = other(1, 0);	m[1][1] = other(1, 1);	m[2][1] = other(1, 2);	m[3][1] = other(1, 3);
	m[0][2] = other(2, 0);	m[1][2] = other(2, 1);	m[2][2] = other(2, 2);	m[3][2] = other(2, 3);
	m[0][3] = other(3, 0);	m[1][3] = other(3, 1);	m[2][3] = other(3, 2);	m[3][3] = other(3, 3);
}

Matrix4x4 Matrix4x4::GetTranspose() {
	Matrix4x4 other = *this;
	other.Transpose();

	return other;
}

Matrix4x4 Matrix4x4::GetTranspose(const Matrix4x4& target){
	Matrix4x4 newMat{ target };
	newMat.Transpose();

	return newMat;
}
