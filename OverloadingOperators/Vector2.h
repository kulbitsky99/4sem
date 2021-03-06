#pragma once
#include <iostream>
#include <typeinfo>


class Vector2
{
private:
	float x, y;
public:
	Vector2(float x1, float y1);
	float Len() const;
	float SquareLen() const;
	float operator*(const Vector2& other) const;
	float operator^(const Vector2& other) const;
	const float getX() const
	{
		//std::cout << typeid(*this).name() << std::endl;
		return this->x;
	}
	const float getY() const
	{
		return this->y;
	}

	float & getRX()
	{
		return this->x;
	}
	float & getRY()
	{
		return this->y;
	}

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator-() const;
	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	Vector2 norm() const;
	Vector2 perpend() const;
	Vector2& rotate(float angle);
	Vector2 getRotated(float angle) const;



friend  std::ostream & operator<<(std::ostream& stream, const Vector2 & v);
friend  std::istream & operator>>(std::istream& stream, Vector2 & v);
friend	Vector2 operator*(const Vector2& v, float k);
friend	Vector2 operator*(float k, const Vector2& v);
friend	Vector2 operator/(const Vector2& v, float k);

};