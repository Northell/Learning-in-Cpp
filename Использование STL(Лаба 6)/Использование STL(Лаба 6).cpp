#include <iostream>
#include "pch.h"
#include <algorithm>
#include <set>
#include <ctime>
#include <iterator>
#include <chrono>
#include <vector>
using namespace std;
typedef std::set<int> MySet;
typedef std::set<int>::iterator MyIt;
typedef std::vector<MyIt> MySeq;

const int lim = 16; //ОГРАНИЧИТЕЛЬ для множества ключей
class MyCont {
	int power;
	char tag;
	MySet A;
	MySeq sA;

	MyCont &operator=(const MyCont &);

	MyCont &operator=(MyCont &&);

public:
	MyCont(int, char);

	MyCont(const MyCont &

	);

	MyCont(MyCont &&);

	MyCont &operator|=(const MyCont &);

	MyCont operator|(const MyCont &rgt) const {
		MyCont result(*this);
		return (result |= rgt);
	}

	MyCont &operator&=(const MyCont &);

	MyCont operator&(const MyCont &rgt) const {
		MyCont result(*this);
		return (result &= rgt);
	}

	MyCont &operator-=(const MyCont &);

	MyCont operator-(const MyCont &rgt) const {
		MyCont result(*this);
		return (result -= rgt);
	}

	void Merge(const MyCont &

	);

	void Concat(const MyCont &

	);

	void Mul(int);

	void Erase(size_t, size_t);

	void Excl(const MyCont &

	);

	void Subst(const MyCont &, size_t);

	void Change(const MyCont &, size_t);

	void Show() const;

	size_t Power() const { return sA.size(); }

	void PrepareExcl(const MyCont &

	); //Подготовка excl
	friend void PrepareAnd(MyCont &,
		MyCont &, const int); //подготовка
};

MyCont::MyCont(int p, char t)
	: power(p), tag(t) {
	for (int i = 0; i < power; ++i) {
		sA.push_back(A.insert(std::rand(
		) % lim).first);
	}
}

MyCont::MyCont(MyCont &&source) //Конструктор копии "с
	: power(source.power), tag(source.tag), A(source.A), sA(source.sA) {
}

MyCont::MyCont(const MyCont &source) //Конструктор копии
	: power(source.power), tag(source.tag) {
	for (auto x : source.A) sA.push_back(A.insert(x).first);
}

void MyCont::Show() const {
	
	cout << "\n " << tag << ": ";
	for (auto x : A)
		cout << x << " "; //Выдача множества
	cout << "\n <";
	for (auto x : sA)
		cout << *x << " ";
	//Выдача последовательности
	cout << " >";
}

void PrepareAnd(MyCont &first, MyCont &second, const int quantity) {
	for (int i = 0; i < quantity; ++i) { //Подготовка пересечения:
		int x = rand() % lim; // добавление общих эл-тов
		first.sA.push_back(first.A.insert(x).first);
		second.sA.push_back(second.A.insert(x).first);
	}
}

MyCont &

MyCont::operator-=(const MyCont &rgt) { //Разность
	MySet temp;
	MySeq stemp;

	for (auto x : A)
		if (rgt.A.find(x) == rgt.A.end())
			stemp.push_back(temp.insert(x).first);
	temp.swap(A);
	stemp.swap(sA);
	return *this;
}

MyCont &MyCont::operator&=(const MyCont &rgt) { //Пересечение
	MySet temp;
	MySeq stemp;

	for (auto x : A)
		if (rgt.A.find(x) != rgt.A.end())
			stemp.push_back(temp.insert(x).first);
	temp.swap(A);
	stemp.swap(sA);
	return *this;
}

MyCont &

MyCont::operator|=(const MyCont &rgt) { //Объединение
	for (auto x : rgt.A)
		sA.push_back(A.insert(x).first);
	return *this;
}

void MyCont::Erase(size_t p, size_t q) { //Исключение фрагмента от p
	using std::min;
	size_t r(Power());
	p = min(p, r);
	q = min(q + 1, r);
	if (p <= q) {
		MySet
			temp;
		MySeq
			stemp;
		for (size_t i = 0; i < p;
			++i)
			stemp.push_back(temp.insert(*sA[i]).first);
		for (size_t i = q; i < r;
			++i)
			stemp.push_back(temp.insert(*sA[i]).first);

		A.swap(temp);
		sA.swap(stemp);
	}
}

void MyCont::Mul(int k) { //Размножение (не более чем в 5 раз)
	auto p = sA.begin(), q = sA.end();
	if (p != q && (k = k % 5) > 1) { //Пропуск, если множество пусто или k <
		std::vector<int>
			temp(A.begin(), A.end());
		MySeq res(sA);
		for (int i = 0; i < k - 1; ++i) {
			std::copy(p, q, back_inserter(res));
			A.insert(temp.begin(), temp.end());
		}
		sA.swap(res);
	}
}

void MyCont::Merge(const MyCont &rgt) { //Слияние
	using std::sort;
	MySeq temp(rgt.sA), res;
	auto le = [](MyIt a, MyIt b) -> bool { return *a < *b; };//Критерий

	sort(sA.begin(), sA.end(), le

	);
	sort(temp.begin(), temp.end(), le

	);
	std::merge(sA.begin(), sA.end(), temp.begin(), temp.end(),
		std::back_inserter(res), le

	); //Слияние для
	A.insert(rgt.A.begin(), rgt.A.end()); //... и объединение множеств
	sA.swap(res);
}

void MyCont::PrepareExcl(const MyCont &rgt) {
	//Подготовка объекта исключения в пустом контейнере...
	int a = rand() % rgt.Power(), b = rand() % rgt.Power();
	//... из случайного [a, b] отрезка rgt
	if (b > a) {
		for (int x = a; x <= b; ++x) {
			int y = *(rgt.sA[x]);
			sA.push_back(A.insert(y).first);
		}
	}
}

void MyCont::Excl(const MyCont &rgt) { //Исключение подпоследовательности
	size_t n(Power()), m(rgt.Power());
	if (m)
		for (size_t p = 0; p < n; ++p) { //Поиск первого элемента
			bool f(true);
			// int a(*sA[p]), b(*rgt.sA[0]); //ОТЛАДКА
			if (*sA[p] == *rgt.sA[0]) { //Проверка всей цепочки
				size_t q(p), r(0);
				if (m > 1)
					do {
						++q, ++r;
						size_t c(*sA[q]), d(*rgt.sA[r]);
						f &= c == d;
					} while ((r < m - 1) && f);
					if (f) {//Цепочки совпали, удаляем
						MySet temp;
						MySeq stemp;
						for (size_t i = 0; i < p; ++i)
							stemp.push_back(temp.insert(*sA[i]).first);
						for (size_t i = p + m; i < Power(); ++i)
							stemp.push_back(temp.insert(*sA[i]).first);
						A.swap(temp);
						sA.swap(stemp);
						break;
					}
			}
		}
}

void MyCont::Concat(const MyCont &rgt) { //Сцепление
	for (auto x : rgt.sA)sA.push_back(A.insert(*x).first);
}

void MyCont::Subst(const MyCont &rgt, size_t p) { //Подстановка
	if (p >= Power())
		Concat(rgt);
	else {
		MySeq stemp(sA.begin(), sA.begin() + p); //Начало
		std::copy(rgt.sA.
			begin(), rgt.sA.
			end(), back_inserter(stemp)
		);
		//Вставка
		std::copy(sA.begin() + p, sA.end(), back_inserter(stemp)
		);
		//Окончание
		MySet temp;
		sA.clear();

		for (auto x : stemp) sA.push_back(temp.insert(*x).first);
		A.swap(temp);
	}
}

void MyCont::Change(const MyCont &rgt, size_t p) {
	//Замена
	if (p >= Power())
		Concat(rgt);
	else {
		MySeq stemp(sA.begin(), sA.begin() + p); //Начало
		std::copy(rgt.sA.begin(), rgt.sA.end(), back_inserter(stemp));
		//Замена
		size_t q = p + rgt.Power();
		if (q < Power())
			std::copy(sA.begin() + q, sA.end(), back_inserter(stemp));
		//Окончание
		MySet temp;
		sA.clear();

		for (auto x : stemp)
			sA.push_back(temp.insert(*x).first);
		A.swap(temp);
	}
}

using namespace std;

int main() {

	using std::cout;

	int p = 5;
	bool debug = false;
	bool present = true;
	srand((unsigned int)time(nullptr));
	unsigned __int64 t1, t2;

	auto MaxMul = 5;
	int middle_power = 0, set_count = 0;

	auto rand = [](int d) {
		int i = std::rand();
		return i % d;
	};

	MyCont A(p, 'A');
	MyCont B(p, 'B');
	MyCont C(p, 'C');
	MyCont D(p, 'D');
	MyCont E(p, 'E');

	MyCont M(p, 'M');
	MyCont N(p, 'N');
	MyCont S(p, 'S');
	MyCont T(p, 'T');

	MyCont R(0, 'R');
	MyCont P(0, 'P');

	// Part 1

	A.Show();
	B.Show();
	C.Show();
	D.Show();
	E.Show();

	// получаем конечное множество (A | B - C & D) & E
	R |= A;
	R |= B;
	R -= C;
	R &= D;
	R &= E;

	cout << "\nR = (A ∪ B ⊕ C ∩ D) ∩ E ";
	R.Show();

	// Part 2
	M.Show();
	N.Show();
	S.Show();
	T.Show();

	// merge
	M.Merge(N);
	M.Show();

	// excl
	N.Excl(S);

	// subst
	int d = rand(S.Power());
	cout << "\n=== S.Subst (T, " << d << ") ===";
	S.Subst(T, d);

	cout << "\n M merged with N";
	M.Show();
	cout << "\n N EXCL with S";
	N.Show();
	cout << "\n S substringed with T from position " << d;
	S.Show();

	return 0;
}
