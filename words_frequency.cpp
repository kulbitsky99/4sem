// ConsoleApplic


ation2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

typedef struct statistics
{
	std::string word;
	int count;
}Statistics;

std::string prepare(const std::string& s)
{
	std::string result;
	result = s;
	std::transform(s.begin(), s.end(), result.begin(), ::tolower);
	(ispunct(*(--result.end())))
	{
		result.pop_back();
	}
	return result;

}
bool compare(const Statistics & lhs, const Statistics & rhs)
{
	if (lhs.count > rhs.count)
		return true;
	else
		return false;
}

int main()
{
	int i = 0;

	/*FILE* file;
	fopen_s(&file, "onegin.txt", "r");
	if (file == NULL)
		std::cout << "error!" << std::endl;

	if (file.fail())
	{
		std::cout << "fail!" << std::endl;
	}*/
	std::ifstream file("errr.txt");
	if (file.is_open())
	{
		std::string word;
		std::map<std::string, int> rating;
		while (!file.eof())
		{
			file >> word;
			word = prepare(word);
			rating[word]++;

		}


		std::vector<Statistics> stat;
		for (auto it : rating)
		{
			Statistics kvantum = { it.first, it.second };
			stat.push_back(kvantum);
		}
		std::sort(stat.begin(), stat.end(), compare);
		i = 0;
		for (auto it : stat)
		{
			if (it.count >= 100)
				std::cout << it.word << "   " << it.count << std::endl;
		}
		file.close();
	}
	else std::cout << "File was not opened!!!" << std::endl;
	system("pause");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
