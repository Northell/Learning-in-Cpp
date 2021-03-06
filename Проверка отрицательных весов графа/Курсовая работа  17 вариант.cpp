// Курсовая работа  17 вариант.cpp: определяет точку входа для консольного приложения.
//


// Проверка на наличие отрицательных весов ребер в графе
#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;

const int INF = 1000000000;
int m, n;
bool check = false;
int min(int a, int b) {
	if (a < b)
		return a;
	if (b < a)
		return b;
}
void graph() {
	setlocale(LC_ALL, "Russian");
	int vershina = 0;		//количество вершин			k
	int n = 0;				//Связь 
	int m = 0;				//Вес
	int k = 0;				//счетчик для перечисления вершин графа
	int s = 0;
	int a[21];	//вершины графа

	int b[10][11]; //весовая матрица
	cout << "Вершины графа: \n    ";
	for (k = 1; k < 21; k++)
	{
		a[k] = k;
		cout << a[k] << " ";
	}
	cout << "\n=================\n Матрица веса :\n";
	for (n = 1; n < 10; n++) 
	{
		
		b[n][0] = n;
		cout << b[n][0] << " | ";
		
		for (m = 1; m < 10; m++)
		{
			
			
				b[n][m] = rand() % 11;
				if (m == n) {
					b[n][m] = 0;
				}
				/*if (b[n][m] % 4 == 0) {		//Забивание для проверки на отрицательные циклы
					b[n][m] = -b[n][m];
				}*/
				if ((b[n][m] == 10)||(b[n][m] == -10)) {
					cout << "- ";
					b[n][m] = INF;
				}
				
				else
				cout << b[n][m] << " ";
			
				
			
		}
		cout << endl;
		
	}
	
	s = 0;
	n = 10;
	for (int k = 1; k < n; ++k) {
		cout << "\n\n";
		for (int i = 1; i < n; ++i) {
			b[i][0] = i;
			cout << b[i][0] <<" | ";
			for (int j = 1; j < n; ++j) {
				if (b[i][k] < INF && b[i][j] < INF)
					b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
				if (b[i][j] == INF)
					cout << "- ";
				else
				cout << b[i][j] << " ";
				
			}
			cout << "\n";
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n+1; ++j)
		{
			for (int t = 1; t < n; ++t)
				if (b[i][t] < INF && b[t][t] < 0 && b[t][j] < INF)
			//	if (b[i][j] == INF &&b[t][t] != 0 ) 
				{
					b[i][j] = -INF;
					
					check = true;
				}
		}
	}
	//cout << "\n количество бесконечных  путей: " << s;
	if (check == true) {
		cout << "Внимание, есть отрицательные циклы!\n";
	}
	else
		cout << "отрицательных циклов нет.";
}

	
int main()
{
	graph();
	getchar();
    return 0;
}

