// Lab_No3_Task_third_Pak.cpp : 
// Лабораторная работа №3 Задание 3 сортировка пузырьком

#include "pch.h"
#include <iostream>

void bubble_sort(int * mass);

int main()
{
	int mass[10] = { 0,6,1,8,5,3,2,45,5,9 }; 
	
	bubble_sort(mass);

	for (int i = 0; i < 10; i++)
	{
		std::cout << mass[i] << " ";
	}
}


void bubble_sort(int * mass)
{
	int temp = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 1; j < 10 - i - 1; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
			}
		}

	}

}