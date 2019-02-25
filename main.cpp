#include "Vector2.h"


int main()
{
	Vector2 v(0, 0);
	std::cin >> v;
	v = v * 3.f;
	std::cout << v << std::endl;
	system("pause");
}