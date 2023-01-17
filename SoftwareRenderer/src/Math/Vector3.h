#pragma once

#include <cmath>

struct Vector3 {
public:
	/* components */

	float x{};
	float y{};
	float z{};

	inline Vector3();
	inline Vector3(float inX, float inY, float inZ);

	/* element operations */
	inline void Add(const Vector3& other);
	inline void Multiply(const Vector3& other);
	inline void Subtract(const Vector3& other);

	/* add by components */
	inline Vector3 operator+(const Vector3& other);
	inline Vector3 operator-(const Vector3& other);
	inline Vector3 operator*(const Vector3& other);
	inline Vector3 operator*(float scalar);
	inline Vector3 operator/(const Vector3& other);
	inline Vector3 operator/(float scalar);

	/* cross product */
	inline Vector3 operator^(const Vector3& other);

	/* dot product */
	inline float operator|(const Vector3& other);

	/* Access components*/
	inline float operator[](std::int32_t componentIndex) const;
	inline float& operator[](std::int32_t componentIndex);

	/* Set all of the vectors coordinates */
	inline void Set(float newX, float newY, float newZ);

	inline static float DotProduct(const Vector3& lhs, const Vector3& rhs);
	inline static Vector3 CrossProduct(const Vector3& lhs, const Vector3& rhs);

	inline void Normalize();
	inline bool IsNormalized();
	inline float Size() const;
	inline float SizeSquared() const;

	static const Vector3 ZeroVector;
	static const Vector3 OneVector;
	static const Vector3 UpVector;
	static const Vector3 DownVector;
	static const Vector3 ForwardVector;
	static const Vector3 BackwardVector;
	static const Vector3 RightVector;
	static const Vector3 LeftVector;
};

inline const Vector3 Vector3::ZeroVector{ 0.0f, 0.0f, 0.0f };
inline const Vector3 Vector3::OneVector{ 1.0f, 1.0f, 1.0f };
inline const Vector3 Vector3::UpVector{ 0.0f, 1.0f, 0.0f };
inline const Vector3 Vector3::DownVector{ 0.0f, -1.0f, 0.0f };
inline const Vector3 Vector3::ForwardVector{ 0.0f, 0.0f, 1.0f };
inline const Vector3 Vector3::BackwardVector{ 0.0f, 0.0f, -1.0f };
inline const Vector3 Vector3::RightVector{ 1.0f, 0.0f, 0.0f };
inline const Vector3 Vector3::LeftVector{ -1.0f, 0.0f, 0.0f };


inline Vector3::Vector3() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

inline Vector3::Vector3(float inX, float inY, float inZ){
	x = inX;
	y = inY;
	z = inZ;
}

inline void Vector3::Add(const Vector3& other) {
	x += other.x;
	y += other.y;
	z += other.z;
}

inline void Vector3::Multiply(const Vector3& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
}

inline void Vector3::Subtract(const Vector3& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
}

Vector3 Vector3::operator+(const Vector3& other) {
	return { x + other.x, y + other.y, z + other.z };
}

Vector3 Vector3::operator-(const Vector3& other) {
	return { x - other.x, y - other.y, z - other.z };
}

Vector3 Vector3::operator*(const Vector3& other) {
	return { x * other.x, y * other.y, z * other.z };
}

inline Vector3 Vector3::operator*(float scalar) {
	return { x * scalar, y * scalar, z * scalar };
}

Vector3 Vector3::operator/(const Vector3& other) {
	return { x / other.x, y / other.y, z / other.z };
}

Vector3 Vector3::operator/(float scalar) {
	return { x / scalar, y / scalar, z / scalar };
}

Vector3 Vector3::operator^(const Vector3& other) {
	return CrossProduct(*this, other);
}

float Vector3::operator|(const Vector3& other) {
	return DotProduct(*this, other);
}

float Vector3::operator[](int32_t componentIndex) const {
	return (&x)[componentIndex];
}
float& Vector3::operator[](int32_t componentIndex) {
	return (&x)[componentIndex];
}

void Vector3::Set(float newX, float newY, float newZ) {
	x = newX;
	y = newY;
	z = newZ;
}

void Vector3::Normalize() {
	float power{ Size() };
	x /= power;
	y /= power;
	z /= power;
}

bool Vector3::IsNormalized() {
	return std::abs(1.0f - SizeSquared()) < 0.01f;
}

float Vector3::Size() const {
	return std::sqrtf(x * x + y * y + z * z);
}

float Vector3::SizeSquared() const {
	return x * x + y * y + z * z;
}

float Vector3::DotProduct(const Vector3& lhs, const Vector3& rhs) {
	return { lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z };
}

Vector3 Vector3::CrossProduct(const Vector3& lhs, const Vector3& rhs) {
	return {
		lhs.y * rhs.z - lhs.z * rhs.y,
		lhs.z * rhs.x - lhs.x * rhs.z,
		lhs.x * rhs.y - lhs.y * rhs.x
	};
}