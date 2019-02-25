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



