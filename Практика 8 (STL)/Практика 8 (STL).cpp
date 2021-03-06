// Практика 8 (STL).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	//Создаем векторное поле
	vector<int> vec;
	int i;

	//Показать оригинальный размер вектора
	cout << "vector size: " << vec.size() << endl;

	//Добавить 5 значений в вектор:
	for (i = 0; i < 5; i++)
		vec.push_back(i);

	//Показать изменение размера вектора: 
	cout << "Vector extended size: " << vec.size() << endl;

	//Пройтись по 5 значениям вектора:

	for (i = 0; i < 5; i++)
		cout << "value of vec [" << i << "] =" << vec[i] << endl;

	// Использование итератора для прохода по вектору:
	vector<int>::iterator v = vec.begin();
	while (v != vec.end()) {
		cout << "value of v: " << *v << endl;
		v++;
	}
	return 0;
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
