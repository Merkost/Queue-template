#include <Windows.h>
#include <string>
#include "Tourist.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
//#include <queue>
using namespace std;

istream& operator >> (istream& in, Tourist& n)
{
	string first_name;
	in >> first_name;
	string second_name;
	in >> second_name;
	string third_name;
	in >> third_name;
	string country;
	in >> country;
	short day;
	in >> day;
	n = { first_name, second_name, third_name, country, day };
	return in;
}
ostream& operator << (ostream& out, Tourist n)
{
	out << n.getf() << " " << n.gets() << " " << n.gett() << " " << n.getd() << endl;
	return out;
}


int main()
{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		ifstream f;
		do {
			string name;
			cout << "Введите имя файла: ";
			cin >> name;
			f.open(name);
			if (!f) cerr << "Не удалось открыть файл под именем: " << name << endl;
		} while (!f);
		Queue<Tourist> a;
		for (Tourist x; f >> x; ) a.push(x);
		if (!f.eof()) {
			cerr << "Неверный формат файла! Завершение программы..."; return 1;
		}
		cout << "Данные успешно считаны!" << endl;
		f.close();

		cout << "size=" << a.size() << endl;
		cout << "First " << a.front() << endl;
		cout << "Last " << a.back() << endl;
		a.pop();
		cout << "size=" << a.size() << endl;
		cout << "First " << a.front() << endl;
		cout << "Last " << a.back() << endl;

		while (!a.empty())
		{
			cout << a.front() << endl;
			a.pop();
		}
	system("pause");
}