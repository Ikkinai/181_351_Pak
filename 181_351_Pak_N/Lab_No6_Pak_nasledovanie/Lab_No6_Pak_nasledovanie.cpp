// Lab_No6_Pak_nasledovanie.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "string"
//наследование - заимствование свойств и методов родительского класса в производном классе
//синтаксис
//class name_new_class : [type of наследования] имя родительского класса1,
	//[type of наследования] имя родительского класса2
//{
//...
//};

//в род.классе	public		protected	private
//public		public		protected	private
//protected		protected	private		protected
//private		недоступен	недоступен	недоступен
/*
Метод, переопределенный в доч классе полностью заменит унаследованный родит метод
чтобы при запуске нового доч метода*/
//можнов  дочернем классе объявить с тем же именем, он заменит.
//иначе, чтобы дополнить - надо явно вызвать родительский метод:
//в род классе - void weapon::reload(){};
//в дочернем классе - rifle::reload():weapon::reload(),...{};
/*Если объявить метод со словом virtual в данном классе 
можно явно не реализовывать, и определить его (привести 
реализацию) только в дочерних классах*/
/*4. //фии дб не больше 50-100 строк, дробить на маленькие нужно.
void fnc1(const тип1 параметр1, тип2 параметр2) 
{
//параметр1=10; //компилятор выдаст ошибку 
}
//объвление константного метода класса запрещает 
           ему менять какое-либо и св-ств объекта
											|
										   \/
void fnc2(тип1 параметр1, тип2 параметр2) const
{
//параметр1=10; //компилятор выдаст ошибку
}

*/
//
//
//
//
//
//

/**/
class Matrix {
private: 
	double arrayMatrix[10][10] = { 0 };
	unsigned short columns;
	unsigned short rows;
public:
	
	bool summMatrix(Matrix matr2);
	bool multMatrix(Matrix matr2);
	void transMatrix();
	//virtual double scalMultVector(vector vec2);
	//virtual double scalMultVector(vector vec2);
	void printMat();
	void readMatr();
	unsigned short getRows();
	unsigned short getColumns();
	double getElem(unsigned short rov, unsigned short col);
	Matrix(/*const unsigned int a, const unsigned int b*/) {
		/*arrayMatrix[a][b]={ 0 };
		columns = a;
		rows = b;*/
	}
	~Matrix() {
	}
};


int main()
{
	/*int i=-15;
	double d = 1000.5e+03; //= 1000.5 * 10 ^ 3 = 1000500;
	//d = 1000.5e-03; = 1000.5*0.1 ^ 3 = 1.0005;
	float result1;
	long long result2; //
	result1 = i + d;//преобразует к большему справа, а потом к левому урезается.
	result2 = i / d;//
	//"123"+ "456"
//	std::string : "123456"
	//char * + char *//*/сложатся как unsigned int
	/*const char * ch1 = "123.6";//='1','2','3','\0'
	const wchar_t * ch2 = L"456";//к юникоду
	//???=ch1+ch2;
	
    std::cout << *ch1+*ch2; 
	//strtod(); //srt TO double
	//double a=strtod(ch1);
	//strtol() //long
	//strtoul()//unsigned long 
	//									ctrl+SPACE вызвать дополнение кода intellisense
	//									strl+Shift+SPACE меню параметров
	i=atoi(ch1);
	d = atof((char*)ch2);
	//
	std::cout << " "<<i<< " "<<d;//двоичное число 
	//0.7=0.6999999999999999999999999999999999999999999.., //111001000
	//потому что двоичная алгебра за этим стоит
	char hhh[255] ="";
	char ggg[255] = "";

	std::cout << "\n first: ";
	std::cin >> hhh;
	std::cout << "\n second: ";
	std::cin >> ggg;
	std::cout << "\n";
	i = atoi(hhh);
	d = atof(ggg)*10/10;
	std::cout << i << "   " << d;

	//scanf_s("First ");

	//Создать клас матриц размера m*n 1<=m,n<=10 с операциями
	/*1) 	сложение
	a b   + k l   = a+k b+l
	c d     m n     c+m d+n //размеры матриц совпадают

	2)умножение

	а11 а12 а13			b11 b12
	а21 а22 а23 *		b21 b22 = c11 c12
						b31 b32   c21 c22 //c21=a21*b11+a22*b21+a23*b31
						cij=ai1*b1j+ai2*b2j+...ainbnj
						//столбцы а=строки б
	3)транспонирование

	4) печать
	5) ввод с клавы

	Создать класс наследник -вектор, длиной n,1<=n<=10, с дополнительными операциями
	1)скалярное поизведение
	2)умножение вектора на число
	
	*/
	//const int n = 10, m=10;

	//double mass[n]= 

	
	Matrix checking, checking2;
	checking.readMatr();
	checking2.readMatr();
	checking.printMat();
	checking2.printMat();

}




bool Matrix::summMatrix(Matrix matr2)
{
	double tempura[10][10] = { 0 };

	
	if (matr2.getColumns()==columns&&matr2.getRows()==rows)
	{
		for (int item = 0; item < columns; item++)
		 for (int gtom = 0; gtom < matr2.getRows(); gtom++)
			{
			 tempura[item][gtom] = arrayMatrix[item][gtom]+ matr2.getElem(item, gtom);
			}
		for (int item1 = 0; item1 < columns; item1++)
			for (int gtom1 = 0; gtom1 < matr2.getRows(); gtom1++)
			{
				arrayMatrix[item1][gtom1] = tempura[item1][gtom1];
			}

		return 1;
	}
	else
	{
		return 0;
	}
}
bool Matrix::multMatrix(Matrix matr2)
{
	if ((columns==matr2.rows)&&(matr2.rows<10)&&(matr2.rows<10)&&( matr2.columns > 0) && (matr2.rows >0) )
	{
		for (int item = 0; item < columns; item++)
		{
			for (int gtom = 0; gtom < matr2.rows; gtom++)
			{
				for (int k = 0; (item+k < columns)&&(gtom+k<rows); k++) {
					arrayMatrix[item][gtom] += arrayMatrix[item + k][gtom + k]*matr2.getElem(item+k, gtom+k);
				}
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
void Matrix::transMatrix()
{
		double temp = 0;
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			if ((j >= i) && (j + 1 < 3))
			{
				j++;
			}
			else
			{
				if ((j >= i) && (j + 1 >= 3)) {}
				else
				{
					temp = arrayMatrix[i][j];
					arrayMatrix[i][j] = arrayMatrix[j][i];
					arrayMatrix[j][i] = temp;
				}
			}
		}
	}
}
//virtual double scalMultVector(vector vec2);
//virtual double scalMultVector(vector vec2);
void Matrix::printMat()
{
	std::cout << "Array res: \n"<<std::endl;
	for (int itr = 0; itr < rows; itr++)
	{
		for (int jojo = 0; jojo < columns; jojo++)
		{
			std::cout << arrayMatrix[itr][jojo] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;


}
void Matrix::readMatr()
{
	std::cout << "Array: \n";
	columns = 10, rows = 10;

	std::cout << std::endl;
	std::cout << "If that the end of matrix",
		", please, write the \"endm\"";
	char * mass3[10][10] = {(char *) "0" };
	char stro[255] = { "0" };
	for (int lines = 0; lines < rows; lines++)
	{
		std::cout << "\nWrite the row of matrix in the" <<
			"column and write the \"end\":\n";
		for (int i = 0; i < columns; i++)
		{
			std::cin >> stro;
			if (stro[0] == 'e'&&stro[1] == 'n'&&stro[2] == 'd') 
			{ 
				columns = i; break; 
			}
			if (stro[0] == 'e'&&stro[1] == 'n'&&stro[2] == 'd'&&stro[3] == 'm') 
			{ 
				continue; 
			}
			arrayMatrix[lines][i] = atof(stro);
		}
		if (stro[0] == 'e'&&stro[1] == 'n'&&stro[2] == 'd'&&stro[3] == 'm') 
		{ 
			rows = lines+1;
			continue; 
		}
	}


	std::cout << std::endl<< std::endl;
	
}
unsigned short Matrix::getRows() {
	
	return rows;
}
unsigned short Matrix::getColumns()
{
	return columns;
}
double Matrix::getElem(unsigned short rov, unsigned short col)
{
	if ((rov<rows)&&(col<columns)&&(rov>=0&&col>=0))
	{
		return arrayMatrix[col][rov];
	}
	else
	{
		return 0;
	}
}