// Многопоточность. Работа с потоками.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>

#include <thread>	//предназначена для работы с потоками

#include <chrono>	//Предназначена для работы со временем

using namespace std;

/*
DodoWorks,DoWork - пробы работы с многопоточностью
AtributsPlus(), Plus - работа потоков с параметрами
LinksDoworks(), Lnk - работа потоков с параметрами в виде ссылок
*/


	void DoWork() { //имитация бурной деятельности

		for (size_t i = 0; i < 10; i++) {
			cout << "\t ID Потока:\t" << this_thread::get_id() << "\t DoWork \t" << i << endl;	//Выводит идентификатор потока
			this_thread::sleep_for(chrono::milliseconds(200));
		}
	}
	void DodoWorks() {
		cout << "Start" << endl;
		thread th(DoWork);

		thread th2(DoWork);

		//th.detach();//не дожидается выполнения не главного потока, заврешает программу по завершении выполнения основы




		th.join();		//Ждет окончания всех потоков, но нужно вызывать там, где нужно дождаться, иначе не выполняется по очереди
		th2.join();
		cout << "End" << endl;

	}

	void Plus(int a, int b, string msg)
	{
		cout << msg << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "==========Plus Start==========" << endl;
		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "a+b\t" << a + b << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "==========Plus END==========" << endl;


	}
	void AtributsPlus()
	{
		thread th(Plus, 2, 3, "our message"); //для передачи в поток функции с параметрами вот такой синтаксис
		for (size_t i = 0; true; i++) {
			this_thread::sleep_for(chrono::milliseconds(200));
			cout << "ID Потока:\t " << this_thread::get_id() << "\t" << i << endl;
		}
		th.join();
	}
	
	void Lnk(int &temp){
		
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "==========Plus Start==========" << endl;
		this_thread::sleep_for(chrono::milliseconds(5000));
		 temp *= 2;
		 cout << temp<<endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "==========Plus END==========" << endl;
	
	}
	void LinksDoworks() {
		int temp = 5;
		Lnk(temp);
	}


	int Sum(int a, int b) {
		return a + b;
	}
int main()
{
	setlocale(LC_ALL, "ru");
	int result = 0;
	thread Summ([&result]() {result = Sum(2, 4); });				//лямбда выражение
	DodoWorks();
	//LinksDoworks();
	Summ.join();
	cout << "\nresult:\t" << result;
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
