// Lab_NoXX_ex.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
//#include <iostream>


#include <iostream>

class Strochka {
protected:
private:
	char * samas = (char *) "";
public:
	//char * samas_ptr =;
	Strochka()
	{
		samas = (char *)"";
	};
	Strochka(const char a[255])
	{
		samas = (char *)a;
	};
	void get_stroku(char & a, int & b);
	//char & get_stroku();
	friend Strochka operator+(Strochka & first, Strochka & second);

	Strochka & operator =(const char second[255]);
	friend std::istream & operator >>(std::istream &os, Strochka & first);
	//Strochka & operator >>(std::istream &os);

	friend std::ostream & operator <<(std::ostream &os, const Strochka & first);


};


int main()
{
    std::cout << "Hello World!\n"; 
	setlocale(LC_ALL, "");
	Strochka aaa = "msnd";
	std::cout << std::endl << aaa;
	Strochka bbb = aaa;
	aaa = "jefkjekjfk";
	std::cout << std::endl << bbb;
	std::cout << std::endl << aaa;
	//
	//std::cout << std::endl << bbb;

	Strochka ccc;
	ccc = aaa + bbb;
	std::cout << "summa: " << ccc;
	aaa = bbb;
	std::cout << std::endl << aaa;

	aaa = "";
	std::cin >> aaa;
	std::cout << std::endl << "input-output: " << aaa;
	system("pause");
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
Strochka operator+(Strochka & first, Strochka &second)
{
	Strochka kldw;
	//int end = sizeof(first.get_stroku(f))/4;
	char f[255] = { "" };
	int s = 0;
	first.get_stroku(f[0], s);
	//for (int inter = 0; inter < end;inter++) {

	//}
	second.get_stroku(f[s], s);
	if (s > 255) std::cout << "fail";
	//	char * ttt2 = &second.get_stroku();
	kldw = f;// (char *)(first.get_stroku() + second.get_stroku());
	return kldw;
}

std::ostream & operator<<(std::ostream & os, const Strochka & first)
{
	os << first.samas;
	os << std::endl;
	return os;
}

void Strochka::get_stroku(char & a, int & b)
{
	a = samas[0];
	b = sizeof(samas) / 4 - 1;
	//return this.samas[0];
}

Strochka & Strochka::operator=(const char second[255])
{
	this->samas = (char *)second;

	return *this;
}


std::istream & operator>>(std::istream & os, Strochka & first)
{
	char a[255];
	os >> &a[0];
	//std::cout <<std::endl<< a;
	first = a;
	//std::cout << first;
	return os;
}



