#include "Vector2.h"
#include <cmath>
#include <string>
float Vector2::Len() const
{
	return sqrt(x * x + y * y);
}
//Vector2::~Vector2()
//{
//}
Vector2::Vector2(float x1, float y1)
{
	x = x1;
	y = y1;
}

float Vector2::SquareLen() const
{
	return (x * x + y * y);
}

float Vector2::operator*(const Vector2 & other) const
{
	return x * other.x + y * other.y;
}

float Vector2::operator^(const Vector2 & other) const
{
	return fabs(x * other.y - y * other.x);
}

Vector2 Vector2::operator+(const Vector2 & other) const
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2 & other) const
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}

Vector2 & Vector2::operator+=(const Vector2 & other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2 & Vector2::operator-=(const Vector2 & other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2 Vector2::norm() const
{
	return Vector2(x / Len(), y / Len());
}

Vector2 Vector2::perpend() const
{
	return Vector2(y, -x);
}

Vector2 & Vector2::rotate(float angle)
{
	x = x * cos(angle) - y * sin(angle);
	y = x * sin(angle) + y * cos(angle);
	return *this;
}

Vector2 Vector2::getRotated(float angle) const
{
	return Vector2(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
}

Vector2 operator*(const Vector2 & v, float k)
{
	return Vector2((v.getX()) * k, (v.getY()) * k);//why v.x(v -> x)??
}

Vector2 operator*(float k, const Vector2 & v)
{
	return Vector2((v.getX()) * k, (v.getY()) * k);//why v.x(v -> x)??
}

Vector2 operator/(const Vector2 & v, float k)
{
	return Vector2((v.getX()) / k, (v.getY()) / k);//why v.x(v -> x)??
}

std::ostream & operator<<(std::ostream& stream, const Vector2 & v)
{
	//std::cout << v.x << " " << v.y << std::endl;
	
	return stream << v.getX() << " " << v.getY();
}

std::istream & operator>>(std::istream& stream, Vector2 & v)  //why not const Vector2???
{
	return stream >> v.getRX() >> v.getRY();
}



