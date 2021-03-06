// Lab_No5_class.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>


class Vehicle
{
	//только внутри класса

private:
protected://
public://общедоступный
	double speed;
	char regnumber[6] = {0};
	unsigned char capacity;

	bool check_reg_num()
	{
		for (int i=0;i<6;i++)
		{
			if (regnumber[i] != 0)
			{
				return true;

			}
		
		}
		return false;

	}



};

class User_data
{
private:
	char str_passport[10] = { ' ' };
	char first_name[255] = { ' ' };
	char second_name[255] = { ' ' };
	char str_birthdate[10] = { ' ' };
	
protected:
public:
	User_data();
	User_data(char p_f_name[255], char p_second_name[255], char p_str_passport[10], char p_str_birthdate[10]);
	User_data(char p_f_name[255], char p_second_name[255]);
	

	~User_data();
	bool set_birthdatee(char p_birthdate[10])
	{
		
		if ( p_birthdate[2] == '.'&&  p_birthdate[5] == '.')//00.00.0000
		{
			for (int i=0; i<10;i++)
			{
				if(p_birthdate[i]>='0'&&p_birthdate[i]<='9')
				{
					str_birthdate[i] = p_birthdate[i];

				}
				else
				{
					return 0;
				}
				
				if (i == 1 || i == 4)
				{
					str_birthdate[i] = '.';
					i++;
				}
			}
		}
		else { return 0; }
		return 1;
		
		//return 0;
	};
	//bool flag = 0;
	bool set_passport(char p_passport[10])
	{
		for (int i = 0; i < 10; i++)
		{
			//if ()//10 чиселок без ничего
			
			if(p_passport[i]>='0'&&p_passport[i]<='9')
			{
				str_passport[i] = p_passport[i];
			}
			else
			{
				return 0;
			}
			
		}return true;
		
	};
	bool set_f_name(char p_f_name[255])
	{
		int i = 0;
		while(p_f_name[i]!='\0')
		{
			if ((p_f_name[i] >= 97 && p_f_name[i] <= 122) || (p_f_name[i] == '-'))
			{
				first_name[i] = p_f_name[i];
			}
			else {
				return 0;
			}
			i++;
		}
		return 1;
		//тире или букавы
	};

	bool set_s_name(char p_s_name[255])
	{//тире или букавы
		int i = 0;
		while (p_s_name[i] != '\0')
		{
			if ((p_s_name[i] >= 97 && p_s_name[i] <= 122) || (p_s_name[i] == '-'))
			{
				second_name[i] = p_s_name[i];
			}
			else {
				return 0;
			}
			i++;
		}
		return 1;
	};
};


int main()
{
	//setlocale(LC_ALL, "rus");
	Vehicle car;
	setlocale(LC_ALL, "");
	//объект1.свойство1=0;
	//объект1.метод3();
    
	car.speed = 10.0;
	car.capacity = '6';
	car.regnumber[0] = 'K';
	car.regnumber[1] = '0';
	car.regnumber[2] = '1';
	car.regnumber[3] = '2';
	car.regnumber[4] = 'H';
	car.regnumber[5] = 'C';

	if (car.check_reg_num())
	{
		std::cout << "Рег номер есть"<<std::endl;
	}
	else {
		std::cout << "Рег номера нет" << std::endl;
	}

	User_data character, r_char;

	const char * mass_birth_r = "22.02.1997";

	/*for (int i = 0; i < 10;i++) {
		character.set_birthdate[i] = '7';
		r_char.set_birthdate[i] = ;
	}*/
	std::cout << "День рождения ";
	if (character.set_birthdatee((char*)"22.02.19p7"))
		std::cout << "верный."; 
	else 
		std::cout << "НЕверный.";
	std::cout << std::endl;
	std::cout << "Паспорт ";
	std::cout << ((character.set_passport((char*)"093344*046")) ? "верный." : "НЕверный.") << std::endl;

	std::cout << "Имя " << ((character.set_f_name((char*)"gh0g"))? "верное." : "НЕверное.") << std::endl;
	std::cout << "Фамилия " << ((character.set_s_name((char*)"gohhg")) ? "верная." : "НЕверная.") << std::endl;

	User_data pers((char*)"ghfh", (char*) "efsr");
	User_data pers2((char*)"ghfh",(char*) "efsr", (char*)"12345678900",(char*)"12.44.7777");

	//r_char.set_birthdate[2] = '.';
	//r_char.set_birthdate[5] = '.';
}

//метод - функция в составе класса
//свойство - переменная в составе класса
//инкапсуляция - объединение вовнутрь
//наследование - создание производных классов от родительского с заимствованием
//полиморфизм - экземпляры одного и того же класса будут вести себя по-разному

//действия прописываются в методе - конструкторе 
//User_data();
//~User_data();
//
//можно перезагрузить конструктор, а деструктор нельзя
//структура - то же, что и класс, но без прайвата

User_data::User_data()
{

};

User_data::User_data(char p_f_name[255], char p_second_name[255], char p_str_passport[10],char p_str_birthdate[10])
{
	set_f_name(p_f_name);
	set_s_name(p_second_name);
	set_passport(p_str_passport);
	set_birthdatee(p_str_birthdate);
	if (first_name != (char*)' '&& second_name != (char*) ' '&& str_passport != (char*)' '&& str_birthdate !=(char*) ' ')
		std::cout << "user OK\n";

};

User_data::User_data(char p_f_name[255], char p_second_name[255])
{
	set_f_name(p_f_name);
	set_s_name(p_second_name);
	if (first_name != (char*)' '&& second_name != (char*) ' ')
		std::cout << "user OK\n";
};
User_data::~User_data()
{

};

//спроси, можно ли писать неплоный конспект

