// Lab_No7_dynamic_mem.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Динамическое выделение памяти
//type * name_value = new type;
//Для испзия свободной памяти ОС (куча heap)
// объявлся дин перем по синтаксису
// 
//работа с дин памятью происходит через указатели
//
//преимущества:
//доступно гораздо больше памяти, нежели в стеке
//размеры массивов и структур данных м опредть и менять во время работы
//особенность: 
// если приложение для длительной работы чтобы не переполнитьь нужно delete 

#include "pch.h"
// Lab_No7_dynamic_mem.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Динамическое выделение памяти
//type * name_value = new type;
//Для испзия свободной памяти ОС (куча heap)
// объявлся дин перем по синтаксису
// 
//работа с дин памятью происходит через указатели
//
//преимущества:
//доступно гораздо больше памяти, нежели в стеке
//размеры массивов и структур данных м опредть и менять во время работы
//особенность: 
// если приложение для длительной работы чтобы не переполнитьь нужно delete 

//#include "pch.h"
#include <iostream>
#include "string"
#include <stdio.h>
#include <stdlib.h>

class Matrix {
private:
	bool vect=0;
	bool exist=0;
	double * arrayMatrix;
	unsigned short columns = 1;
	unsigned short rows = 1;
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
	void swaper(int i1, int j1, int i2, int j2);
	Matrix(/*const unsigned int a, const unsigned int b*/)
	{
		std::cout << "Rows: ";
		std::cin >> this->rows;
		std::cout << "\nColumns: ";
		std::cin >> this->columns;
		
		if (this->columns==0||this->rows==0) vect = 1; else vect = 0;
		arrayMatrix = ((vect)?new double[this->columns]: new double[this->rows*this->columns]);
		/*arrayMatrix[a][b]={ 0 };
		columns = a;
		rows = b;*/
	}

	~Matrix()
	{
		delete[] arrayMatrix;
	}
};

class Vector : public Matrix //что такое virtual тут
{
private:
	double * arrayVector;
	unsigned short columns =  1;
	bool exist;
	bool vect;
public:
	Vector constMultVector(double mnoj);
	double scalMultVector(Vector vec2);
	//void Matrix::readMatr();
	//void printMat();
	//void readMatr();

	Vector(bool t) {
		std::cout << "Vector: ";
		std::cout << "\nColumns: ";
		std::cin >> this->columns;
		if (this->columns == 0) exist = 0; else exist = 1;
		arrayVector = ((exist)?new double[this->columns]:new double);
		
	}

	~Vector() {
		delete[] arrayVector;
	}
};

int main()
{
	Matrix checking;
	Matrix checking2;
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
		std::cout << "ERROR summ\n";
	}
	if (checking.multMatrix(checking2))
	{
		std::cout << "Mult:" << std::endl;
		checking.printMat();
	}
	else {
		std::cout << "ERROR mult\n";
	}

	std::cout << "Transpon:" << std::endl;
	checking.transMatrix();
	checking.printMat();

	//delete checking;
	//delete checking2;


	Vector check1(1);
	Vector check2(1);
	check1.readMatr();
	check2.readMatr();
	check1.printMat();
	check2.printMat();

	std::cout << "Const mult vector:" << std::endl;
	check1.constMultVector(1.5).printMat();
	std::cout << "Scal mult of vectors:" << std::endl;
	std::cout << check1.scalMultVector(check2);

	//delete check1; деструктор сам запускается с ретурном 0
	//delete check2;
	return 0;
}




bool Matrix::summMatrix(Matrix matr2)
{

	double * tempura = new double[this->getRows()*this->getColumns()];

	if ((matr2.getColumns() == this->getColumns()) && (matr2.getRows() == this->getRows()))
	{
		for (int item = 0; item < this->getRows(); item++)
		{
			for (int gtom = 0; gtom < this->getColumns(); gtom++)
			{
				tempura[item*this->getColumns() + gtom] = this->getElem(item, gtom) + matr2.getElem(item, gtom);
			}
		}
		for (int item1 = 0; item1 < this->getRows()*this->getColumns(); item1++)
		{
			this->arrayMatrix[item1] = tempura[item1];
		}

		delete[] tempura;
		return 1;
	}
	else
	{
		//delete[] tempura;
		return 0;
	}

}
bool Matrix::multMatrix(Matrix matr2)
{
	double * tempura = new double[matr2.getRows()*this->getColumns()];
	double tempura1 = 0;
	tempura[0] = 0;
	if (this->getRows() == 1 || this->getColumns() == 1)
	{
		
		for (int k = 0; k < this->getColumns(); k++) {
			tempura1 += this->arrayMatrix[k] * matr2.getElem(k, 0);
		}

		this->arrayMatrix[0] = 0;
		this->arrayMatrix[0] = tempura1;
		return 1;
	}else
	if ((this->getColumns() == matr2.getRows()&& matr2.getRows()!=1)/* && (matr2.getRows() < this->getColumns()*/
		&& /*(matr2.getColumns() < 10) &&*/ (this->getColumns() > 0) && (matr2.getRows() > 0))
	{
		for (int item = 0; item < matr2.getRows(); item++)
		{
			for (int gtom = 0; gtom < this->getColumns(); gtom++)
			{
				for (int k = 0; k < this->getColumns(); k++) {
					tempura[item*this->getColumns() + gtom]+=
						this->arrayMatrix[item*this->getColumns() + k] 
						* matr2.getElem(k, gtom);
				}

			}
		}

		//delete[] this->arrayMatrix;
		this->rows = matr2.getRows();
		//this->arrayMatrix=new double[this->getColumns()*matr2.getRows()];
		{
			for (int i = 0; i < matr2.getRows(); i++)
				for (int g = 0; g < this->getColumns(); g++)
				{
					this->arrayMatrix[i*this->getColumns() + g] = 0;
				}

			for (int i = 0; i < matr2.getRows(); i++)
				for (int g = 0; g < this->getColumns(); g++)
				{
					this->arrayMatrix[i*this->getColumns() + g] = tempura[i*this->getColumns() + g];
				}
		}
		//delete[] tempura;
		return 1;
	}
	else
	{
		//delete[] tempura;
		return 0;
	}
}
void Matrix::transMatrix()
{
	double temp = 0;
	int r = 0;
	for (int i = 0; i < this->getRows(); i++) {
		for (int j = 0; j < this->getColumns(); j++) {
			if ((j >= i) && (j + 1 < this->getColumns()))
			{
				j++;
			}
			else
			{
				if ((j >= i) && (j + 1 >= this->getColumns())) {}
				else
				{
					swaper(i, j, j, i);
					/*temp = this->arrayMatrix[i*this->getColumns() + j];
					this->arrayMatrix[i*this->getColumns() + j] = this->arrayMatrix[j*this->getColumns() + i];
					this->arrayMatrix[j*this->getColumns() + i] = temp;*/

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
	if (vect||exist) {
		for (int jojo = 0; jojo < (this->columns); jojo++)
		{
			std::cout << this->arrayMatrix[jojo] << "\t ";
		}
	}else
	for (int itr = 0; ((this->rows > 0) ? (itr < this->rows) : (itr < this->rows)); itr++)
	{
		for (int jojo = 0; jojo < (this->columns); jojo++)
		{
			std::cout << this->arrayMatrix[itr*this->columns + jojo] << "\t ";
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
	//int a, b;
	std::cout << std::endl;
	std::cout << "Input matrix\n";//If that the end of matrix",
	//	", please, write the \"endm\"";
	char stro[255] = { "0" };
	if (vect||exist) 
	{
		for (int i = 0; i < this->getColumns()/*&& lines*this->getColumns() + i<this->getColumns()*getRows()*/; i++)
		{
			std::cin >> stro;
			this->arrayMatrix[i] = (double)atof(stro);
		}
	}
	else
	for (int lines = 0; lines < this->getRows(); lines++)
	{
		std::cout << "New line: \n";//\nWrite the row of matrix in the" <<
			//"column and write the \"end\":\n";
		for (int i = 0; i < this->getColumns()/*&& lines*this->getColumns() + i<this->getColumns()*getRows()*/; i++)
		{
			//////////////
			std::cin >> stro;
			/*if (stro[0] == 'e'&&stro[1] == 'n'&&stro[2] == 'd')
			{
				a = i; b = lines;//lines; 
				if ((this->arrayMatrix[0] != 0)) { b++; }
				break;
			}*/
			/////////////
			this->arrayMatrix[lines*this->getColumns() + i] = (double)atof(stro);

		}

	/*	if (stro[0] == 'e'&&stro[1] == 'n'&&stro[2] == 'd'&&stro[3] == 'm')
		{
			this->rows = b;
			this->columns = a;
			break;
		}*/
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
		return this->arrayMatrix[rov*this->columns + col];
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
double Vector::scalMultVector(Vector vec2)
{
	double summ = 0;
	if (this->getColumns() == vec2.getColumns())
	{
		
		for (unsigned short iterka = 0; iterka < this->getColumns(); iterka++)
		{
			summ+= this->arrayVector[iterka] * vec2.arrayVector[iterka];
		}

		return summ;
	}
	else
	{
		std::cout << "ERROR ;-;" << std::endl;

		return summ;
	}


}

void Matrix::swaper(int i1, int j1, int i2, int j2)
{
	double tempura = this->arrayMatrix[i1*this->getColumns() + j1];
	this->arrayMatrix[i1*this->getColumns() + j1] = this->arrayMatrix[i2*this->getColumns() + j2];
	this->arrayMatrix[i2*this->getColumns() + j2] = tempura;
}


