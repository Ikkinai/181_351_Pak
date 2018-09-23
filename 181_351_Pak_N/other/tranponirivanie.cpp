// tranponirivanie.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
 //транспонирование
		//std::cout << std::endl;
			   
		int matrix3x3[3][3] = { {1,2,3},
								{4,5,6},
								{7,8,9} };

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				std::cout << matrix3x3[i][j] << " ";

			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

		int temp = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if ((j >= i) && (j + 1 < 3))
				{
					j++; 
				}
				else
				{
					if ((j >= i) && (j + 1 >= 3)){}
					else
					{
						temp = matrix3x3[i][j];
						matrix3x3[i][j] = matrix3x3[j][i];
						matrix3x3[j][i] = temp;
					}
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				std::cout << matrix3x3[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;


		//return 0;
}