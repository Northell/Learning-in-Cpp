// Перегрузка различных операторов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

//перегрузка оператора []
class TestClass
{public:
	int &operator[](int index) { return arr[index]; }
private:
	int arr[7]{ 5,6,7,8,1,2 };
};
//Перегрузка оператора =
class MyClass {
	int Size;
	int *data;

public:
	MyClass & operator = (const MyClass &other);
	MyClass(int size) {
		this->Size = size;
		this->data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = i;
			std::cout << data[i] << "\t";
		}

	}
	~MyClass() {}
};



MyClass & MyClass::operator=(const MyClass & other)
{
	this->Size = other.Size;
	if (this->data != nullptr) {
		delete[] this->data;
	}
	this->data = new int[other.Size];
	for (int i = 0; i < other.Size; i++)
		this->data[i] = other.data[i];
	return *this;


	// TODO: вставьте здесь оператор return
}

//Перегрузка оператора == и !=

class Point
{
	int x;
	int y;
public:
	Point() { x = 0; y = 0;  }
	Point(int xx, int yy) { x = xx; y = yy; }
	bool operator == (const Point &other)
	{
		return this->x == other.x && this->y == other.y;

	}
	bool operator != (const Point &other)
	{
		return !(this->x == other.x && this->y == other.y);

	}
	Point operator +(const Point &other) 
	{
		Point temp;
		temp.x = this->x+other.x;
		temp.y = other.y + this->y;

		return temp;

	}
	
};
int main()
{
	TestClass a;
    std::cout << a[4]; 

	std::cout << "Hello World!\n";
	MyClass c(10); // Вызов для =
	MyClass d(20);
	c = d;


	Point e(5, 1);		//Вызов для == !=
	Point f(9, 4);
	Point g = f + e;
	bool result = e == f;

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
