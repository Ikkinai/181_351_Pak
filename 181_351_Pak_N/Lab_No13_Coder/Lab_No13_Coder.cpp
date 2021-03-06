#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <openssl/conf.h> // функции, структуры и константы настройки OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // сами криптогрфические функции https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // коды внутренних ошибок OpenSSL и их расшифровка
#include <openssl/aes.h>
#include <fstream>
#include <string>
//скачиваем ссл библиотеку, распаковываем, скачиваем страуберри перл, устанавливаем
//perl cmd -   perl Configure VC-WIN64A   --debug no-asm
//cmd VS developer -  nmake
//nmake install
//всё делается из адреса, где расположена сслка


#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")
#pragma comment (lib, "C:/Users/N/Desktop/openssl/libcrypto.lib")
#pragma comment (lib, "C:/Users/N/Desktop/openssl/libssl.lib")

// библиотеки OpenSSL (openssl.org) подключаются неявно динамически (см. конспект лаб. по библиотекам)

using namespace std;

int main()
{
	// работа с криптофункциями OpenSSL:
	// 1) создание объекта с настройками
	// 2) собственно, шифрование
	// 3) финализация
	// 4) и вывод зашифрованных данных

	// как правило, в литературе, структуры используются для хранения только данных
	// ни слова о методах и конструкторах/деструкторах
	/*struct name_of_my_struct // сродни классу
	{
		name_of_my_struct()
		{

		}

		int a;
		double b;
		int fnc1()
		{
			return a;
		}
	};
	*/
	std::fstream filik, filik2, filik3;
	filik.open("sometextfile.txt", std::fstream::in| std::fstream::binary);
	filik2.open("sometextfile2.txt", std::fstream::out| std::fstream::ate| std::fstream::binary);//std::fstream::binary
	
	//filik3.open("sometextfile3.txt", std::fstream::out | std::fstream::app| std::fstream::binary| std::fstream::trunc);

	string tempura="";
	unsigned char *plaintext = (unsigned char *)"";
	int plaintext_len;//= strlen((char *)plaintext); // длина текста
	unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
	unsigned char cryptedtext[256]; // зашифрованный результат
	unsigned char decryptedtext[256];
	EVP_CIPHER_CTX *ctx; // structure
	int len;
	int cryptedtext_len;
	ctx = EVP_CIPHER_CTX_new();
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	while (!filik.eof())
	{
		tempura = "";
		len = 0;
		cryptedtext_len = 0;
		//filik.get((char*)plaintext, 255);
		//filik >> (char*)plaintext;
		filik >> tempura;
		plaintext_len = strlen((char*)plaintext); // длина текста
		
		std::cout << "&tempura[0]\n"<<&tempura[0]<<std::endl;
		plaintext = (unsigned char *) &tempura[0];
		EVP_EncryptUpdate(ctx, cryptedtext, &len, plaintext, plaintext_len);
		filik2 << *cryptedtext;
		//std::cout << *cryptedtext;////////////////////////////////////////////////////////////////////

		cryptedtext_len = len;
		EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
		cryptedtext_len += len;

		
	}
	filik.close();
	memset(cryptedtext, 0, 256);
	EVP_CIPHER_CTX_free(ctx);

	////////////////////////////////
/*	unsigned char *plaintext =
		(unsigned char *)"hjghjhkjkkljm";// исходный текст
	int plaintext_len = strlen((char *)plaintext); // длина текста
	unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
	unsigned char cryptedtext[256]; // зашифрованный результат
	unsigned char decryptedtext[256]; // расшифрованный результат

	EVP_CIPHER_CTX *ctx; // structure
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key,iv);
	int len;
	EVP_EncryptUpdate(ctx,cryptedtext,&len, plaintext, plaintext_len); // входной параметр : длина входных данных
	int cryptedtext_len = len;
		EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;
	EVP_CIPHER_CTX_free(ctx);
	*/
	////////////////////////////////
	filik2.close();
	filik2.open("sometextfile2.txt",  std::fstream::in | std::fstream::binary);//std::fstream::binary
	len = 0;

	filik3.open("sometextfile3.txt", std::fstream::out | std::fstream::ate | std::fstream::binary);


	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // инициализация методом AES, ключом и вектором


	while (!filik2.eof())
	{
		//filik2 >> *plaintext;//get((char*)plaintext, 256);
		//tempura = "";
		filik2 >> *cryptedtext;// tempura;
	
		//*cryptedtext = (unsigned char)&tempura[0];

		EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);  // СОБСТВЕННО, ШИФРОВАНИЕ
		filik3 << *decryptedtext;
		std::cout <<  *decryptedtext;////////////////////////////////////////////////////////////////////

		int dectypted_len = len;
		EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

		dectypted_len += len;

		decryptedtext[dectypted_len] = '\0';
	}
	EVP_CIPHER_CTX_free(ctx);

	memset(cryptedtext, 0, 256);
	memset(decryptedtext, 0, 256);
	filik2.close();
	filik3.close();


	

/*	unsigned char *plaintext =
		(unsigned char *)"EVP_EncryptUpdate() encrypts inl bytes from the buffer in and writes the encrypted version to out";// исходный текст
	int plaintext_len = strlen((char *)plaintext); // длина текста
	unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
	unsigned char cryptedtext[256]; // зашифрованный результат
	unsigned char decryptedtext[256]; // расшифрованный результат
*/
	// 1. Создаётся указатель на несуществующую структуру
	// структура - тип данных в C++, близка к КЛАССУ, различия минимальны
	/*EVP_CIPHER_CTX *ctx; // structure

	// 2. Для указателя создаётся пустая структура настроек (метод, ключ, вектор инициализации и т.д.)
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	// 3. Структура EVP_CIPHER_CTX заполняется настройками
	EVP_EncryptInit_ex(ctx, // ссылка на объект/структуру, куда заносятся параметры
		EVP_aes_256_cbc(), // ссылка на шифрующее ядро AES 256 (функцию с алгоритмом)
		NULL,
		key, // ключ/пароль/секрет
		iv); // рандомайзер (случайный начальный вектор)

	// 4. САМ ПРОЦЕСС ШИФРОВАНИЯ - ФУКНЦИЯ EVP_EncryptUpdate
	int len;
	EVP_EncryptUpdate(ctx, // объект с настройками
		cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
		&len, // выходной параметр: длина полученного шифра
		plaintext, // входной параметр: что шифровать
		plaintext_len); // входной параметр : длина входных данных
	int cryptedtext_len = len;

	// 5. Финализация процесса шифрования
	// необходима, если последний блок заполнен данными не полностью
	EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;

	// 6. Удаление структуры
	EVP_CIPHER_CTX_free(ctx);

	// вывод зашифрованных данных
	for (int i = 0; i < cryptedtext_len; i++)
	{
		cout << hex << cryptedtext[i];
		if ((i + 1) % 32 == 0) cout << endl;
	}
	cout << endl;
	*/
	// РАСШИФРОВКА

	// 1.
	/*ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // инициализация методом AES, ключом и вектором

	// 3.
	EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);  // СОБСТВЕННО, ШИФРОВАНИЕ

	// 4.
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

	// 5.
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	cout << decryptedtext << endl;
	*/
	// --- шифрование файла
	// производится точно так же, но порциями, в цикле
	// в цикле
	/*
		1) открытие файлов и настройка параметров OpenSSL
		2) считывание первого блока
		3) while(считанный_фрагмент > 0)
		{
			4) шифрование считанного
			5) запись зашифрованного массива в файл
			6) считывание следующего фрагмента
		}
		7) применение финализирующей фукнции
		8) запись финализирующего блока в файл
		9) закрытие файлов
	*/
	//getchar();
	return 0;
}
//дб 3 файла - исходник, шифрованное и дешифрованное