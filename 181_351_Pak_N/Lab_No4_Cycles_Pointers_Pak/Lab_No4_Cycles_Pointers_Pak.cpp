// Lab_No4_Cycles_Pointers_Pak.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

char * readmass();
//void readarr(*);
int func(int* a, int b);

int main()
{
	//Указатель - переменная, хранящая адрес(смещение), каких-либо данных, переменных в ОЗУ
	int a=324;
	double dbl=10.2;
	int * ptr_a;
	ptr_a = &a;
	double * ptr_dbl = &dbl;
	//фактически указатель это unsigned int или unsigned long long, так как дробных или отрицательных адресов нет

	int int4 = 0;
	int * ptr_int4 = &int4;
	double double8 = 0.0;
	double * ptr_double8 = &double8;
	//int, double, char, long, bool
	std::cout << "|______________\t|_____\t|" << std::endl;
	std::cout << "|Type\t\t|Size\t|" << std::endl;
	std::cout << "|______________\t|_____\t|" << std::endl;
	std::cout << "|int\t\t|" << sizeof(int *) << "\t|" << std::endl;
	std::cout << "|double\t\t|" << sizeof(double *) << "\t|" << std::endl;
	std::cout << "|char\t\t|" << sizeof(char *) << "\t|" << std::endl;
	std::cout << "|long long\t|" << sizeof(long long *) << "\t|" << std::endl;
	std::cout << "|bool\t\t|" << sizeof(bool *) << "\t|" << std::endl;
	std::cout << "|______________\t|_____\t|" << std::endl;
	
	std::cout << "ptr_int = " << ptr_int4<<std::endl;
	std::cout << "ptr_dbl = " << ptr_double8 << std::endl;

	int arrr[10] = {1,2,3,4,5,6,7,8,9};
	std::cout << "arr = " << arrr << std::endl;
	std::cout << "*arr = arr[0] = " << *arrr << std::endl;
	std::cout << "*(arr+4)= arr[4] = " << *(arrr+4) << std::endl;

//объявляем? звездочку справа. Разыменовываем - слева
	


/*	setlocale(LC_ALL, "");
	//char str = {' '};
	char *str = readmass();
	readmass();
	
	int code = 0, key=3;
	for (int iter = 0; iter < 10; iter++)
	{
		code = str[iter] + key;
		if (code>122)
		{
			code -= 26;
		}
		str[iter] = char(code);
	}
	
	for (int iter = 0; iter < 10; iter++)
	{
		std::cout << str[iter];

	}
	*/
	int num1 = 1,num2 = 2, res = 0;
	res = func(&num1, num2);
	std::cout << res<<" "<<num1<< " " << num2;
	return 0;
}

char * readmass()
{
	char mass[10];

	//int Nommm;
	//std::cout << "Vvedite chiselku ";
	//std::cin >> Nommm;
	for (int iter=0; iter<10; iter++)
	{
		std::cin >> mass[iter];
	}
		



		return mass;
}



int func(int *a, int b)
{
	//int d = a + b;
	*a += 10;
	return *a + b;
}