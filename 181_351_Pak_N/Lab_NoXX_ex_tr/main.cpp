#include <iostream>
#include "Strochka.h"

int main()
{
	setlocale(LC_ALL, "");
	Strochka aaa="msnd";
	std::cout << std::endl << aaa;
	Strochka bbb=aaa;
	aaa ="hero";
	std::cout << std::endl << bbb;
	std::cout << std::endl << aaa;
	//
	//std::cout << std::endl << bbb;

	Strochka ccc;
	ccc= aaa + bbb;
	std::cout <<"summa: "<< ccc;
	aaa = bbb;
	std::cout << std::endl << aaa;

	aaa = "";
	std::cin >> aaa;
	std::cout << std::endl<<"input-output: "<< aaa;
	system("pause");
	return 0;
}