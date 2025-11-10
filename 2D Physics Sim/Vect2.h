#pragma once
class Vect2
{
public:
	float X, Y;
	Vect2(float x, float y);
	~Vect2();
	float Length();
	void Normalize();
	float Dot(Vect2& other);
	float Cross(Vect2& other);
	float SquareSum();
	void Flip();
	Vect2 operator+(const Vect2& other);
	Vect2 operator-(const Vect2& other);
	Vect2 operator*(const float& scale);
	Vect2 operator/(const float& scale);
	Vect2& operator+=(const Vect2& other);
	Vect2& operator-=(const Vect2& other);
	Vect2& operator*=(const float& scale);
	Vect2& operator/=(const float& scale);
};

