// Lab_No6_Pak_nasledovanie.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include "pch.h"
//
#include <iostream>
#include "string"
#include <stdio.h>
#include <stdlib.h>

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
	double arrayMatrix[10][10] = { 0.0 };
	unsigned short columns = 10;
	unsigned short rows = 10;
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

class Vector : virtual public Matrix //что такое virtual тут
{
private:
	double arrayVector[10] = { 0.0 };
	unsigned short columns = 10;
public:
	Vector constMultVector(double mnoj);
	Vector scalMultVector(Vector vec2);
	//void Matrix::readMatr();
	void printMat();
	void readMatr();
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


	if (checking.summMatrix(checking2))
	{
		std::cout << "Summa:" << std::endl;
		checking.printMat();
	}
	else {
		std::cout << "error summ\n";
	}
	if (checking.multMatrix(checking2))
	{
		std::cout << "Mult:" << std::endl;
		checking.printMat();
	}
	else {
		std::cout << "error mult\n";
	}

	std::cout << "Transpon:" << std::endl;
	checking.transMatrix();
	checking.printMat();

	
	Vector check1, check2;
	check1.readMatr();
	check2.readMatr();
	check1.printMat();
	check2.printMat();

	std::cout << "Const mult vector:" << std::endl;
	check1.constMultVector(1.5).printMat();
	std::cout << "Scal mult of vectors:" << std::endl;
	check1.scalMultVector(check2).printMat();
	
}




bool Matrix::summMatrix(Matrix matr2)
{
	double tempura[10][10] = { 0 };


	if ((matr2.getColumns() == this->getColumns()) && (matr2.getRows() == this->getRows()))
	{
		for (int item = 0; item < matr2.getRows(); item++)
		{
			for (int gtom = 0; gtom < this->getColumns(); gtom++)
			{
				tempura[item][gtom] = this->getElem(item, gtom) + matr2.getElem(item, gtom);
			}
		}
		for (int item1 = 0; item1 < matr2.getRows(); item1++)
			for (int gtom1 = 0; gtom1 < this->getColumns(); gtom1++)
			{
				this->arrayMatrix[item1][gtom1] = tempura[item1][gtom1];
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
	double tempura[10][10] = { 0 };
	if ((this->getColumns() == matr2.getRows()) && (matr2.getRows() < 10) && (matr2.getColumns() < 10) && (matr2.getColumns() > 0) && (matr2.getRows() > 0))
	{
		for (int item = 0; item < matr2.getRows(); item++)
		{
			for (int gtom = 0; gtom < this->getColumns(); gtom++)
			{
				for (int k = 0; (k < this->columns); k++) {
					tempura[item][gtom] += this->arrayMatrix[item][k] * matr2.getElem(k, gtom);
				}
			}
		}


		for (int i = 0; i < matr2.getRows(); i++)
			for (int g = 0; g < this->getColumns(); g++)
			{
				this->columns = matr2.getColumns();
				this->arrayMatrix[i][g] = tempura[i][g];
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
	int r = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((j >= i) && (j + 1 < 3))
			{
				j++;
			}
			else
			{
				if ((j >= i) && (j + 1 >= 3)) {}
				else
				{
					temp = this->arrayMatrix[i][j];
					this->arrayMatrix[i][j] = this->arrayMatrix[j][i];
					this->arrayMatrix[j][i] = temp;

				}
			}
		}

	}
	r = this->getRows();
	rows = ((true) ? this->getColumns() : this->getColumns());
	columns = ((this->getColumns() == 0) ? r + 1 : r);
}

void Matrix::printMat()
{
	std::cout << "Array res: \n" << std::endl;
	for (int itr = 0; ((this->rows > 1) ? (itr < this->rows) : (itr < this->rows)); itr++)
	{
		for (int jojo = 0; jojo < (this->columns); jojo++)
		{
			std::cout << this->arrayMatrix[itr][jojo] << "\t ";
		}
		std::cout << std::endl << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;


}
void Matrix::readMatr()
{
	std::cout << "Array: \n";
	//this->columns = 10, this->rows = 10;
	int a, b;
	std::cout << std::endl;
	std::cout << "If that the end of matrix",
		", please, write the \"endm\"";
	char * mass3[10][10] = { (char *) "0" };
	char stro[255] = { "0" };
	for (int lines = 0; lines < this->rows; lines++)
	{
		std::cout << "\nWrite the row of matrix in the" <<
			"column and write the \"end\":\n";
		for (int i = 0; i < this->columns; i++)
		{
			//////////////
			std::cin >> stro;
			if (stro[0] == 'e'&&stro[1] == 'n'&&stro[2] == 'd')
			{
				a = i; b = lines;//lines; 
				if ((this->arrayMatrix[0][0] != 0)) { b++; }
				break;
			}
			/////////////
			this->arrayMatrix[lines][i] = (double)atof(stro);

		}
		if (stro[0] == 'e'&&stro[1] == 'n'&&stro[2] == 'd'&&stro[3] == 'm')
		{
			this->rows = b;
			this->columns = a;
			break;
		}
	}


	std::cout << std::endl << std::endl;

}
unsigned short Matrix::getRows() {

	return this->rows;
}
unsigned short Matrix::getColumns()
{
	return this->columns;
}
double Matrix::getElem(unsigned short rov, unsigned short col)
{
	if ((rov < this->rows) && (col < this->columns) && (rov >= 0 && col >= 0))
	{
		return this->arrayMatrix[rov][col];
	}
	else
	{
		return 0;
	}
}

Vector Vector::constMultVector(double mnoj)
{
	for (unsigned short iterka = 0; iterka < this->getColumns(); iterka++)
	{
		this->arrayVector[iterka] = this->arrayVector[iterka] * mnoj;
	}

	return *this;
}
Vector Vector::scalMultVector(Vector vec2)
{
	if (this->getColumns() == vec2.getColumns())
	{
		for (unsigned short iterka = 0; iterka < this->getColumns(); iterka++)
		{
			this->arrayVector[iterka] *= vec2.arrayVector[iterka];
		}
		return *this;
	}
	else
	{
		std::cout << "ERROR ;-;" << std::endl;

		return *this;
	}


}

void Vector::printMat()
{
	std::cout << "Vector res: \n" << std::endl;
	for (int jojo = 0; jojo < (this->columns); jojo++)
	{
		std::cout << this->arrayVector[jojo] << "\t ";
	}
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;


}
void Vector::readMatr()
{
	std::cout << "Array: \n";
	//this->columns = 10, this->rows = 10;
	int a;
	std::cout << std::endl;
	std::cout << "If that the end of matrix" <<
		", please, write the \"endm\"\n";
	char * mass3[10][10] = { (char *) "0" };
	char stro[255] = { "0" };

	for (int i = 0; i < this->columns; i++)
	{
		//////////////
		std::cin >> stro;
		if (stro[0] == 'e'&&stro[1] == 'n'&&stro[2] == 'd')
		{
			this->columns = i;
			break;
		}
		/////////////
		this->arrayVector[i] = (double)atof(stro);
		if (stro[0] == 'e'&&stro[1] == 'n'&&stro[2] == 'd'&&stro[3] == 'm')
		{
			this->columns = i;
			break;
		}

	}



	std::cout << std::endl << std::endl;

}