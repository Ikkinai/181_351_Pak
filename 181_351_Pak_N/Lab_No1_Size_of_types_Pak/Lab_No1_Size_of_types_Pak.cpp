// Lab_No1_Size_of_types_Pak.cpp : 
/* Лабораторная работа номер 1 (Версия 1 - та, что первое домашнее задание, и версия 2 - 
та, что сделана на занятии в рамках пары по заданию - уже рассчитанная 
с помощью функций библиотеки С++ limits.h
*/
#include "pch.h"
#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
		
		int a1 = 1, a2 = 2, a4 = 4, a8 = 8;
		
		cout << endl << "Таблица типов данных С++, с рассчитанными самостоятельно размерами типов";
		cout << " - Table of types C++ No1" << endl << endl;

			cout << "Объем int = " << a4 << " байт" << " = " << a4 * 8 << " бит" << " В диапазоне -(2^32)..0..2^32-1" << endl;
			cout << "Объем bool = " << a1 << " байт" << " = " << a1 * 8 << " бит" << " - 0 или 1" << endl;
			cout << "Объем unsigned int = " << a1 << " байт" << " = " << a1 * 8 << " бит" << " В диапазоне 0..2^33-1" << endl;
			cout << "Объем long long = " << a8 << " байт" << " = " << a8 * 8 << " бит" << " В диапазоне -(2^64)..0..2^64-1" << endl;
			cout << "Объем char = " << a1 << " байт" << " = " << a1 * 8 << " бит" << " В диапазоне 0-255 символов" << endl;
			cout << "Объем short = " << a2 << " байт" << " = " << a2 * 8 << " бит" << " В диапазоне -(2^15)..0..2^15-1" << endl;
			cout << "Объем long = " << a4 << " байт" << " = " << a4 * 8 << " бит" << " В диапазоне -(2^32)..0..2^32-1" << endl;
			cout << "Объем float = " << a4 << " байт" << " = " << a4 * 8 << " бит" << " В диапазоне 3,4*10^(-38)..1,7^10^38" << endl;
			cout << "Объем double = " << a8 << " байт" << " = " << a8 * 8 << " бит" << " В диапазоне 1,7*10(-308)..1,7*10^308" << endl << endl;

		cout << endl << "Задание на паре по \"освоению\" синтаксиса арифметических действий в С++ и ";
		cout<<"функции sizeof() - Syntax of *,/,% and function sizeof()" << endl << endl;

		long long int a = 300, b = 560;
			cout << "a*a*b*b=" << a * b*a*b << endl;

		char symbol_A = 'A';
			cout << "b/a =" << b / a << endl << "b%a = " << b % a << endl;

			cout << symbol_A + a << endl << "A" << a << endl;
			cout << "size of int = " << sizeof(int) << endl;

		int max_int = 0b01111111111111111111111111111111;
			cout << max_int << endl;

		int min_int = 0b10000000000000000000000000000000;
			cout << min_int << endl;

		//тип - размер - мин значение - макс значение
		cout << endl << "Таблица типов данных С++, с рассчитанными полуавтоматически размерами типов\n";
		cout<<" - Table of types C++ No2" << endl << endl;

			cout << "name\t\t|size of|min\t\t\t|max\t\t\n";
			cout << "int\t\t|" << sizeof(int) << "\t|" << INT_MIN << "\t\t|" << INT_MAX << "\t\n";
			cout << "char\t\t|" << sizeof(char) << "\t|" << CHAR_MIN << "\t\t\t|" << CHAR_MAX << "\t\n";
			cout << "bool\t\t|" << sizeof(bool) << "\t|" << 0b0000000 << "\t\t\t|" << 0b100000000 << "\t\n";
			cout << "long\t\t|" << sizeof(long) << "\t|" << LONG_MIN << "\t\t|" << LONG_MAX << "\t\n";
			cout << "short\t\t|" << sizeof(short) << "\t|" << SHRT_MIN << "\t\t\t|" << SHRT_MAX << "\t\n";
			cout << "unsigned char\t|" << sizeof(unsigned char) << "\t|" << 0 << "\t\t\t|" << UCHAR_MAX << "\t\n";
			cout << "unsigned int\t|" << sizeof(unsigned int) << "\t|" << 0 << "\t\t\t|" << UINT_MAX << "\t\n";
			cout << "unsigned long\t|" << sizeof(unsigned long) << "\t|" << 0 << "\t\t\t|" << ULONG_MAX << "\t\n";
			cout << "float\t\t|" << sizeof(float) << "\t|" << FLT_MIN << "\t\t|" << FLT_MAX << "\t\n";
			cout << "double\t\t|" << sizeof(double) << "\t|" << DBL_MIN << "\t\t|" << DBL_MAX << "\t\n";
			cout << "long long\t|" << sizeof(long long) << "\t|" << LLONG_MIN << "\t|" << LLONG_MAX << "\t\n";

		cout << endl << "Таблица ASCII-кодов - Table of ASCII" << endl << endl;

			cout << " № |0	|1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9" << endl;
			cout << " 0 |nul|sox|stx|etx|eot|enq|ack|bel|bs |ht" << endl;
			cout << " 1 |nl |vt |ff |cr |so |si |dle|dc1|dc2|dc3" << endl;
			cout << " 2 |dc4|nak|syn|etb|can|em | sub|esc|fs |gs" << endl;
			cout << " 3 |rs |us |space| ! | « | # | $ | % | & | ‘" << endl;
			cout << " 4 | (  | ) | * | + | , | — | . | / |0 | 1" << endl;
			cout << " 5 | 2  | 3 | 4 | 5 | 6 | 7 | 8 | 9 | : | ;" << endl;
			cout << " 6 | <  | = | > | ? | @ | A | B | C | D | E" << endl;
			cout << " 7 | F  | G | H | I | J | K | L | M | N | O" << endl;
			cout << " 8 | P  | Q | R | S | T | U | V | W | X | Y" << endl;
			cout << " 9 | Z  | [ | \\ | ] | ^ | _ | ‘ | a | b | c" << endl;
			cout << "10 | d  | e | f | g | h | i | j | k | l | m" << endl;
			cout << "11 | n  | o | p | q | r | s | t | u | v | w" << endl;
			cout << "12 | x  | y | z | { | | | } |~del| А | Б" << endl;
			cout << "13 | В  | Г | Д | Е | Ж | З | И | Й | К | Л" << endl;
			cout << "14 | М  | Н | О | П | Р | С | Т | У | Ф | Х" << endl;
			cout << "15 | Ц  | Ч | Ш | Щ | ъ | Ы | Ь | Э | Ю | Я" << endl;
			cout << "16 | а  | б | в | г | д | е | ж | з | и | й" << endl;
			cout << "17 | к  | л | м | н | о | п | | | | " << endl;
			cout << "18 |	|	|	|	|	| " << endl;
			cout << "19 |	|	|	|	|	| " << endl;
			cout << "20 |	|	|	|	|	| " << endl;
			cout << "21 |	|	|	|	|	| " << endl;
			cout << "22 | р  | с | т | у | ф | х | " << endl;
			cout << "23 | ц  | ч | ш | щ | ъ | ы | ь | э | ю | я" << endl;
			cout << "24 | Ё  | ё | Є | є | Ї | ї | Ў | ў | ° | ·" << endl;
			cout << "25 | ·  | № | ¤ |" << endl;
		return 0;
}
