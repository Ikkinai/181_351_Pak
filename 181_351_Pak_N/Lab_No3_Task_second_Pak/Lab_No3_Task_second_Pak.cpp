// Lab_No3_Task_second_Pak.cpp : 


#include "pch.h"
#include <iostream>

int main()
{
	char alphabet[26 + 1] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char text[76 + 1] = {'A','p','t','a',' ','F','o','r','t','r','e','s','s','.',' ','A',' ','b','o','r','d','e','r',' ','c','i','t','a','d','e','l',' ','l','o','c','a','t','e','d',' ','i','n',' ','t','h','e',' ','S','o','u','t','h','-','W','e','s','t',' ','r','e','g','i','o','n',' ','o','f',' ','M','e','p','h','i','u','s','.' };
	int i = 0, sdvig=3;

	bool reg = false;

	while (text[i] != '\0') 
	{
		for (int j = 0; j < 26; j++)
		{
			if (tolower(text[i]) == alphabet[j])
			{
				//ставим флажочек, мол, большая буква, или нет
				if (isupper(text[i]))
				{
					reg = true;
				}
				if (j+sdvig>25)
				{
					//если большая буква, то большую, иначе - маленькую
								if (reg)
								{
									text[i] = toupper(alphabet[j - 25 + sdvig]);
									reg = false;
								}
								else
								{
									text[i] = alphabet[j - 25 + sdvig];
								}
				}
				else
				{
								if (reg)
								{
									text[i] = toupper(alphabet[j + sdvig]);
									reg = false;
								}
								else
								{
									text[i] = alphabet[j + sdvig];

								}
				}//нашли нужную букву и заменили? Не надо дальше сравнивать, заменяем следующую.
				break;
			}
		}
		//к следующей букве текста
		i++;
		
	}

	std::cout << text;
	return 0;
}