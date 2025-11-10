#include "Vect2.h"
#include <cmath>
#include <iostream>

Vect2::Vect2(float x, float y) : X(x), Y(y) {}
Vect2::~Vect2() {}

float Vect2::Length()
{
	return sqrtf(X*X + Y*Y);
}

void Vect2::Normalize()
{
	float length = Length();
	X /= length;
	Y /= length;
}

float Vect2::Dot(Vect2& other)
{
	return X * other.X + Y * other.Y;
}

float Vect2::Cross(Vect2& other)
{
	return X * other.Y - Y * other.X;
}

float Vect2::SquareSum()
{
	return X * X + Y * Y;
}

void Vect2::Flip()
{
	X *= -1;
	Y *= -1;
}

Vect2 Vect2::operator+(const Vect2& other)
{
	return Vect2(X + other.X, Y + other.Y);
}

Vect2 Vect2::operator-(const Vect2& other)
{
	return Vect2(X - other.X, Y - other.Y);
}

Vect2 Vect2::operator*(const float& scale)
{
	return Vect2(X * scale, Y * scale);
}

Vect2 Vect2::operator/(const float& scale)
{
	return Vect2(X / scale, Y * scale);
}

Vect2& Vect2::operator+=(const Vect2& other)
{
	X += other.X;
	Y += other.Y;
	return *this;
}

Vect2& Vect2::operator-=(const Vect2& other)
{
	X -= other.X;
	Y -= other.Y;
	return *this;
}

Vect2& Vect2::operator*=(const float& scale)
{
	X *= scale;
	Y *= scale;
	return *this;
}

Vect2& Vect2::operator/=(const float& scale)
{
	X /= scale;
	Y /= scale;
	return *this;
}