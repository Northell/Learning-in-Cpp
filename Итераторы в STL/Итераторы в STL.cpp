﻿// Итераторы в STL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;


/*Итераторы*/


void Iterator()
{

	vector<int> MyVect = {1,4,3,45,487};
	vector<int>::iterator it = MyVect.begin();	//итератор
	advance(it, 3);				//Сдвигает итератор на указанное кол-во ячеек

	cout << *it << endl;
	*it = 1000;			//присваивание других данных
	cout << endl << *it<<endl;
	it++;					//т.к это итератор, то инкремент смещает итератор на 1, т.е мы получим 4 а не 1001
	cout << *it;

	for (vector<int>::const_iterator itt = MyVect.cbegin(); itt != MyVect.cend(); itt++) {	//пример работы с контстантным итератором(запрещает изменять данные в памяти)
		cout << *itt << ", ";
	}
}
int main()
{
	Iterator();
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
