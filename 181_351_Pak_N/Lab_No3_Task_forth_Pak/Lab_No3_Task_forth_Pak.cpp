// Lab_No3_Task_forth_Pak.cpp : 
//Лабораторная работа №3 Задание 4 Шейкерная сортировка

#include "pch.h"
#include <iostream>

void sortShaker(int * mass);
int main()
{
	int mass[10] = {8,3,7,4,5,5,43,0,22,4};
	int *ptr_mass = &mass[0];
	sortShaker(ptr_mass);

	for(int j=0; j<10;j++)
		std::cout << mass[j] << " ";
	return 0;
}


void sortShaker(int * mass)
{
	int temp = 0;
	for (int i = 0; i < 10 / 2; i++)
	{
		int nIter = 0;
		int endIter = 9;
		while (nIter < endIter)
		{
			if (mass[nIter] > mass[nIter + 1])
			{
				temp = mass[nIter];
				mass[nIter] = mass[nIter + 1];
				mass[nIter + 1] = temp;
			}

			nIter++;

			if (mass[endIter - 1] > mass[endIter])
			{
				temp = mass[endIter - 1];
				mass[endIter - 1] = mass[endIter];
				mass[endIter] = temp;
			}
			endIter--;
		}

	}
}