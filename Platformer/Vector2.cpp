#include "Vector2.h"

Vector2 Vector2::operator+(Vector2 other)
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(Vector2 other)
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(Vector2 other)
{
	return Vector2(x * other.x, y * other.y);
}

Vector2 Vector2::operator*(float num)
{
	return Vector2(x * num, y * num);
}

Vector2 Vector2::operator/(Vector2 other)
{
	return Vector2(x / other.x, y / other.y);
}