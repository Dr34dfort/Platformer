#pragma once
class Vector2
{
public:
	Vector2() : x(0), y(0) {};
	Vector2(float x, float y) : x(x), y(y) {};
	float x;
	float y;
	Vector2 operator+(const Vector2 other);
	Vector2 operator-(const Vector2 other);
	Vector2 operator*(const Vector2 other);
	Vector2 operator*(const float num);
	Vector2 operator/(const Vector2 other);
};

