// Основы STL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>

#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <set>
#include <map>
#include <stack>

//#include <multiset>
using namespace std;
/*STL:
Vector - работа с векторами
List - работа с динамической структурой данных(двусвязный список)
Forward_list - односвязный список (преимущество в скорости работы с началом списка, нет методов push_back и pop_back
Array - статический массив из STL
Deque - Двусторонняя очередь(двусвязный список векторов)
Set - основан на бинарном дереве (хранят упорядоченное множество, причем хранит уникальные значения в отличие от multiset)
Map - хранит ключ значение
Stack - Адаптация под стек (задача в том, чтобы организовать определенный порядок работы с элементами, которые мы туда помещаем)
*/

void Vector() {						//работа с векторами
	vector<int> Myvector;			//вектор это шаблон

	Myvector.push_back(5);
	Myvector.push_back(2);
	Myvector.push_back(3);
	Myvector.push_back(8);


	cout << Myvector.size() << endl;			// размер вектора

	Myvector.reserve(100); //Выделяет заранее для ветора 100 элементов(для скорости работы)
	Myvector.capacity();//Показывает выделенную память под вектор
	Myvector.shrink_to_fit();// Освобождает неиспользованную память
	Myvector.empty();//Показывает пустой ли вектор ( 0 1)
	Myvector.resize(20, 100); //забивает 20 элементов числами 100

	vector<int>::iterator it = Myvector.begin();	// объявляем итератор вектора и ставим его в начало
	auto it0 = Myvector.begin();					//одинаковые записи с точки зрения синтаксиса как и выше


	for (int i = 0; i < Myvector.size(); i++) {
		cout << Myvector[i] << ", ";
	}
	cout << endl;
	for (auto i = Myvector.begin(); i != Myvector.end(); i++) {		//Аналог написанного выше
		cout << *i << ", ";
	}
	it = Myvector.begin();
	advance(it, 3);
	
	Myvector.insert(it, 243);					//Добавление элемента
	cout << endl;
	for (it = Myvector.begin(); it != Myvector.end(); it++) {
		cout << *it << ", ";
	}
	it = Myvector.begin();
	advance(it, 5);

	Myvector.erase(it);							//Удаление элемента
	it = Myvector.begin();
	advance(it, 3);
	Myvector.erase(it, it + 4);					//Удаление нескольких элементов 
	cout << endl;
	for (it = Myvector.begin(); it != Myvector.end(); it++) {
		cout << *it << ", ";
	}
}
void List() {

	list<int> Mylist{ 5,5,5,1,2,3,0 };

	Mylist.push_back(5);// Добавление в начало списка
	Mylist.push_front(10); //Добавление в конец списка
	Mylist.unique(); //Удаляет идущие подряд элементы
	Mylist.reverse(); //делает список обратным
	for (auto it = Mylist.begin(); it != Mylist.end(); it++) {
		cout << *it << ", ";
	}
}
void Forward_list()
{
	forward_list<int> Fl = { 500,300,200,500,1000 }; //есть почти те же методы, что и у листа
	forward_list<int>::iterator fl = Fl.begin();

	fl++;	//fl--;//т.к список односвязный, мы не можем этого сделать


	Fl.push_front(1200);

	Fl.insert_after(fl, 2000);			//Вставка в список по индексу fl(Добавляет после этого элемента
	Fl.erase_after(fl);					//Соответственно такое же удаление элемента
	for (auto i : Fl) { cout << i << " "; }


}
void Array() {
	array<int, 4> Arr = { 2,800,300,1000 };

	cout << Arr.at(4);				//аналог с Arr[4] Отличие - at всегда выкинет ошибку при превышении размера массива
		
	for (auto i : Arr) {
		cout << i << " ";
	}

}
void Deque() {
	deque<int> dec = { 1,15,24 };


}
void Set() {
	set<int> st = { 1,4,5,8 };
	st.insert(2);
	st.insert(80);
	for (auto i : st) {
		cout << i << " ";
	}
	cout << endl;
	if (st.find(8) != st.end())
		cout << "OK";
	else
		cout << "no OK";
}
void Map() {
	map <string, int> mp;
	mp.emplace("Petya", 333);				//Добавление в контейнер
	mp.emplace("Vasya", 2323);
	mp.emplace("Lena", 4242);
	mp.emplace("Kostya", 5321);
	mp.emplace("Ashan", 4356);
	
	auto it = mp.find("Ashan");
	//cout << it->first << " --> " << it->second;
	//cout << endl << mp["Vasya"];				//Удобство в том, что скобки тоже перегружены, возвращает значение по ключу
	mp["Kris"] = 3000;
	for (auto itt = mp.begin(); itt!= mp.end(); itt++)
		cout << itt->first << " --> " << itt->second << endl;


}

void Stack() {
	stack<int> st;
	st.push(4);
	st.push(42);
	st.push(314);
	st.push(442);
	st.push(22134);

	st.emplace(400);		//Более бысьрая скорость вставки
	auto deq = st._Get_container();			//этот метод позволяет весь стек перевести в формат deque, если это нужно.
	cout << deq[2] << endl;
	while (!st.empty()) {		//Процесс извлечения из стека. empty - проверка на наличие данных в стеке
		cout << st.top() << " ";
		st.pop();
	}

	stack <int, list<int>>  St;	//отличие только в скорости работы. а также в методе getcontainer.
	auto lst = St._Get_container(); //т.к мы явно указали лист, то гетконт будет возвращать тип данных лист


}

int main()
{
	//Vector();
	//List(); //Очень быстро работает с удалением и добавлением элемента в любое место структуры
	//Forward_list();
	//Array();
	//Deque();
	//Set();
	//Map();
	Stack();
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
