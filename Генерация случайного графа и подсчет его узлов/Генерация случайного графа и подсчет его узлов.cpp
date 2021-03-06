// Генерация случайного графа и подсчет его узлов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;
void RandGenGraph() { // генерация случайного графа
	setlocale(LC_ALL, "Rus");
	//узел
	//связь между узлами(прочерк - нет связи)
	const int XMAX = 20;	//макс ограничение графа
	srand(time(0));
	int graph[XMAX][XMAX]; //выделение памяти под граф
		int Size = rand() % XMAX; //Генерация размера случайного графа, 0 - пути нет
		int check = 0;			//Подсчет узлов графа
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				graph[i][j] = rand() % XMAX;
				if (graph[i][j] < 10)
					cout << " ";
				if (graph[i][j] != 0)
					check++;
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				if (graph[i][j] == graph[j][i])
					check--;
			}
		}
		cout << "Количество подключенных узлов " << check << endl;
}

int main()
{
	RandGenGraph();
  
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
