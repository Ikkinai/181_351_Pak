#include "Strochka.h"
#include <iostream>
Strochka operator+(Strochka & first, Strochka &second)
{
	Strochka kldw;
	char f[255];// = new char[first.get_len_str() + second.get_len_str() + 1];
	//int s=0,n=0;
	for (int iter = 0; iter <255; iter++)
	{
		f[iter] = '0';
	}
	//f = first.samas;// first.get_stroku();
	for (int iter = 0; iter < first.get_len_str(); iter++)
	{
		f[iter] = first.samas[iter];
	}
	for (int iter1 = first.get_len_str(); iter1 < first.get_len_str()+ second.get_len_str() ; iter1++)
	{
		f[iter1] = second.samas[iter1];
	}

	//strcat_s(f, (first.get_len_str() + second.get_len_str() + 1)*8, first.get_stroku());
	//std::cout<<"hr: "<<;
	//strcat_s(f, (first.get_len_str() + 	second.get_len_str() + 1) * 8, 	second.get_stroku());

	//std::cout << "jjj" << f << std::endl;
	/*for (int iter = 0; iter < first.get_len_str(); iter++)
	{
		f[iter] = first.samas[iter];
	}_MBCS;%(PreprocessorDefinitions)

	for (int iter = first.get_len_str() -1; iter < second.get_len_str() + first.get_len_str(); iter++)
	{
		f[iter] = second.samas[iter];
	}*/
	//f[second.get_len_str()]= second.get_stroku();
//	char * ttt2 = &second.get_stroku();
	kldw = f;//irst.get_stroku();// (char *)(first.get_stroku() + second.get_stroku());
	std::cout << f << kldw;
	//delete[] f;
	return kldw;
}

std::ostream & operator<<(std::ostream & os, const Strochka & first)
{
	os << first.samas;
	os << std::endl;
	return os;
}

 char * Strochka::get_stroku()
{
	 return &samas[0];
	// b = sizeof(samas) / 4 - 1;
	//return this.samas[0];
}

 int Strochka::get_len_str()
 {
	 
	 return strlen(this->samas);
 }

 Strochka & Strochka::operator=(const char second[255])
{
	this->samas = (char *)second;

	return *this;
}


std::istream & operator>>(std::istream & os,  Strochka & first)
{
	char a[255];
	os >> &a[0];
	//std::cout <<std::endl<< a;
	first = a;
	//std::cout << first;
	return os;
}



