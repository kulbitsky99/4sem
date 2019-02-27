#include "Vector2.h"


int main()
{
	Vector2 v(0, 0);
	Vector2 other(5, 10);
	std::cout << "Enter coordinates of v: " << std::endl;
	std::cin >> v;
	std::cout << "Checking of how overloading operators and basic functions work: " << std::endl;
	other = v + other;
	std::cout << other << std::endl;
	other = other - v;
	std::cout << other << std::endl;
	v += other;
	std::cout << v << std::endl;
	v -= other;
	std::cout << v << std::endl;
	float sqal_result = v * other;
	std::cout << sqal_result << std::endl;
	float vect_result = v ^ other;
	std::cout << vect_result << std::endl;
	v = v * 3;
	std::cout << v << std::endl;
	v = 5 * v;
	std::cout << v << std::endl;
	v = v / 15;
	std::cout << v << std::endl;
	std::cout << v.norm() << std::endl;
	std::cout << v.perpend() << std::endl;
	std::cout << v.Len() << std::endl;
	std::cout << v.SquareLen() << std::endl;
	other = -v;
	std::cout << other << std::endl;
	std::cout << v.getRotated(0.52) << std::endl;
	std::cout << v << std::endl;
	std::cout << v.rotate(0.52) << std::endl;
	std::cout << v << std::endl;
	system("pause");
}