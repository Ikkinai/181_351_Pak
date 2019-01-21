#include <iostream>

class Strochka {
protected:
private:
	char * samas = (char *)"";
public:
	//char * samas_ptr =;
	Strochka()
	{
		samas = (char *)"";
	};
	Strochka(const char a[255])
	{
		samas = (char *)a;
	};
	~Strochka()
	{
		
	};
	char * get_stroku();
	int get_len_str();

	//char & get_stroku();
	friend Strochka operator+(Strochka & first, Strochka & second);

	Strochka & operator =(const char second[255]);
	friend std::istream & operator >>(std::istream &os,  Strochka & first);
	//Strochka & operator >>(std::istream &os);

	friend std::ostream & operator <<(std::ostream &os, const Strochka & first);
	
	
};
