// Lab_No2_Escape_sequence_Pak.cpp : 
// Лабораторная работа номер 2 - домашнее задание - распечатать список Escape-последовательностей

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << endl << "Escape-последовательности - Escape sequence" << endl << endl;

		cout << "\\a	Звонок(предупреждение)" << endl;
		cout << "\\b	Backspace" << endl;
		cout << "\\f	Перевод страницы" << endl;
		cout << "\\n	Новая строка" << endl;
		cout << "\\r	Возврат каретки" << endl;
		cout << "\\t	Горизонтальная табуляция" << endl;
		cout << "\\v	Вертикальная табуляция" << endl;
		cout << "\\'	Одиночная кавычка" << endl;
		cout << "\"	Двойная кавычка" << endl;
		cout << "\\	Обратная косая черта" << endl;
		cout << "\\ ? Литерал вопросительного знака" << endl;
	return 0;
}
