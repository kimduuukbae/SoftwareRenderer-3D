#pragma once

#include "Vector4.h"

struct Matrix {	
	/*    Row major Matrix
			  m[x][y]

			11 12 13 14
			21 22 23 24
			31 32 33 34
			41 42 43 44
	*/

	alignas(16) float m[4][4]{};

	Matrix() = default;
	Matrix(const Vector4& newX, const Vector4& newY, const Vector4& newZ, const Vector4& newW);
	Matrix(const Vector3& newX, const Vector3& newY, const Vector3& newZ);

	inline Matrix operator*(const Matrix& other) const;
	inline Matrix operator+(const Matrix& other) const;
	inline Matrix operator-(const Matrix& other) const;

	inline bool operator==(const Matrix& other) const;
	inline bool operator!=(const Matrix& other) const;

	inline float& operator()(size_t row, size_t column);
	inline float operator()(size_t row, size_t column) const;
	inline Matrix Inverse() const;

	inline float GetDeterminant() const;
	inline void Transpose();
	inline Matrix GetTranspose();

	inline static Matrix GetTranspose(const Matrix& target);
};


Matrix::Matrix(const Vector4& newX, const Vector4& newY, const Vector4& newZ, const Vector4& newW) {
	memcpy(m[0], &newX, sizeof(Vector4));
	memcpy(m[1], &newY, sizeof(Vector4));
	memcpy(m[2], &newZ, sizeof(Vector4));
	memcpy(m[3], &newW, sizeof(Vector4));
}

Matrix::Matrix(const Vector3& newX, const Vector3& newY, const Vector3& newZ) {
	memcpy(m[0], &newX, sizeof(Vector3));
	memcpy(m[1], &newY, sizeof(Vector3));
	memcpy(m[2], &newZ, sizeof(Vector3));
}

Matrix Matrix::operator*(const Matrix& other) const {
	Matrix newMat{};

	for (size_t x{ 0 }; x < 4; ++x) {
		for (size_t y{ 0 }; y < 4; ++y) 
			newMat(x,y) = m[x][y] * other.m[x][y];	
	}

	return newMat;
}

Matrix Matrix::operator+(const Matrix& other) const {
	Matrix newMat{};

	for (size_t x{ 0 }; x < 4; ++x) {
		for (size_t y{ 0 }; y < 4; ++y)
			newMat(x, y) = m[x][y] + other.m[x][y];
	}

	return newMat;
}

Matrix Matrix::operator-(const Matrix& other) const {
	Matrix newMat{};

	for (size_t x{ 0 }; x < 4; ++x) {
		for (size_t y{ 0 }; y < 4; ++y)
			newMat(x, y) = m[x][y] - other.m[x][y];
	}

	return newMat;
}

bool Matrix::operator==(const Matrix& other) const {
	for (size_t x{ 0 }; x < 4; ++x) {
		for (size_t y{ 0 }; y < 4; ++y) 
			if (m[x][y] != other.m[x][y]) return false;
	}
	return true;
}

bool Matrix::operator!=(const Matrix& other) const {
	return !(*this == other);
}

inline float& Matrix::operator()(size_t row, size_t column){
	return m[row][column];
}

inline float Matrix::operator()(size_t row, size_t column) const {
	return m[row][column];
}

Matrix Matrix::Inverse() const {

}

float Matrix::GetDeterminant() const {

}

void Matrix::Transpose() {
	Matrix other{ *this };
	
	m[0][0] = other(0, 0);	m[1][0] = other(0, 1);	m[2][0] = other(0, 2);	m[3][0] = other(0, 3);
	m[0][1] = other(1, 0);	m[1][1] = other(1, 1);	m[2][1] = other(1, 2);	m[3][1] = other(1, 3);
	m[0][2] = other(2, 0);	m[1][2] = other(2, 1);	m[2][2] = other(2, 2);	m[3][2] = other(2, 3);
	m[0][3] = other(3, 0);	m[1][3] = other(3, 1);	m[2][3] = other(3, 2);	m[3][3] = other(3, 3);
}

Matrix Matrix::GetTranspose() {
	Matrix other = *this;
	other.Transpose();

	return other;
}

Matrix Matrix::GetTranspose(const Matrix& target){
	Matrix newMat{ target };
	newMat.Transpose();

	return newMat;
}
