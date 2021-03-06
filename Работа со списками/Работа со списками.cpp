// Работа со списками.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;
template <class T>
class List
{
public:
	List();
	~List();
	void push_back(T data); // Добавление  элемента в список
	void pop_front(); // Удаление 1-го элемента из списка
	void clear();    //Очистка элементов списка
	int GetSize() { return Size; }
	T& operator[] (const int index);
	

	void push_front(T data);	//Добавление в начало списка
	void insert(T data, int index); // Добавление в определенное место списка
	void removeAt(int index);
	void pop_back();			//удаление последнего элемента

	void GetList();

private:
	template <class T>
	class Node
	{
	public:
		Node *pnext;
		T data;
		Node(T data = T(), Node *pnext = nullptr) {
			this->data = data;
			this->pnext = pnext;
		}
	};
	int Size;
	Node<T> *head;
};

template <class T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template <class T>
List<T>::~List()
{
	clear();
	cout <<endl<< "Вызвался деструктор!" << endl;
}

template<class T>
void List<T>::push_back(T data)
{
	Size++;
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T> *current = this->head;
		
		while (current->pnext != nullptr) {
			current = current->pnext;
		}
		current->pnext = new Node<T>(data);
	}
}

template<class T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pnext;
	delete temp;
	Size--;
}

template<class T>
void List<T>::clear()
{
	Node<T> *cur = this->head;
	while (Size) {
		pop_front();
	}
}

template<class T>
T& List<T>::operator[](const int index)
{
	int point = 0;
	Node<T> *cur = this->head;
	while (cur != nullptr)
	{
		
		if (point == index) {
			return cur->data;
		}
		
			cur = cur->pnext;
			point++;
		
	}

	
	
}




template<class T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;

}

template<class T>
void List<T>::insert(T data, int index)
{
	if (index == 0) {
		push_front(data);
	}
	else 
	{
		Node<T> *prew = this->head;
		for (int i = 0; i < index - 1; i++) {
			prew = prew->pnext;
		}
		
		prew->pnext = new Node<T>(data, prew->pnext);
	}

	Size++;
}

template<class T>
void List<T>::removeAt(int index)
{
	if (index == 0) {
		pop_front();
	}
	else
	{
		Node<T> *prew = this->head;
		for (int i = 0; i < index - 1; i++) {
			prew = prew->pnext;
		}
		Node<T> *del = prew->pnext;
		prew->pnext = del->pnext;
		delete del;
	}
	Size--;


}

template<class T>
void List<T>::pop_back()
{
	removeAt(Size - 1);

}

template<class T>
void List<T>::GetList()
{
	Node <T> *cur = head;
	for (int i = 0; i < GetSize(); i++) {
		cout << cur->data << "\t";
		cur = cur->pnext;
	}

}


int main()
{
	setlocale(LC_ALL, "ru");
	List <int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(15);
	lst.push_front(7);
	lst.push_front(100);
	lst.GetList();
	cout << endl << "Элементов в списке: " << lst.GetSize() << endl << "Выполнение метода pop_front(): " << endl << endl;
	lst.pop_front();
	lst.GetList();

	cout << endl << "Элементов в списке: " << lst.GetSize() << endl;
	cout << "Вызывем метод insert:" << endl;
	lst.insert(99, 3);
	lst.insert(115, 4);
	lst.insert(0, 2);
	lst.GetList();

	cout << endl << "Вызов метода removeAt(); " << endl;
	lst.removeAt(5);
	cout << "То что осталось: " << endl;
	lst.GetList();

	cout <<endl << "Вызов метода pop_back" << endl;
	lst.pop_back();
	lst.GetList();

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

