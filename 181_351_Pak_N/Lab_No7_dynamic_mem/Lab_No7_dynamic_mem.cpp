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
#include <iostream>
#include "string"
#include <stdio.h>
#include <stdlib.h>

class Matrix {
private:
	int n = 10;
	double * arrayMatrix;
	unsigned short columns = n;
	unsigned short rows = n;
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
	Matrix(/*const unsigned int a, const unsigned int b*/) 
	{
		std::cin >> rows;
		std::cin >> columns;
		double * arrayMatrix = new double[rows*columns];
		/*arrayMatrix[a][b]={ 0 };
		columns = a;
		rows = b;*/
	}
	~Matrix() 
	{
		delete[] arrayMatrix;
	}
};

class Vector : virtual public Matrix //что такое virtual тут
{
private:
	double * arrayVector;
	unsigned short columns = 10;
public:
	Vector constMultVector(double mnoj);
	Vector scalMultVector(Vector vec2);
	//void Matrix::readMatr();
	void printMat();
	void readMatr();
	Vector(){
		std::cin >> columns;
		double * arrayVector = new double[columns];
	}

	~Vector() {
		delete[] arrayVector;
	}
};

int main()
{
	/*
	Matrix checking = Matrix();
	Matrix checking2=Matrix();
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
	
	//delete checking;
	//delete checking2;
	*/




	Vector check1=Vector();
	Vector check2= Vector();
	check1.readMatr();
	check2.readMatr();
	check1.printMat();
	check2.printMat();

	std::cout << "Const mult vector:" << std::endl;
	check1.constMultVector(1.5).printMat();
	std::cout << "Scal mult of vectors:" << std::endl;
	check1.scalMultVector(check2).printMat();

	//delete check1; деструктор сам запускается с ретурном
	//delete check2;
	return 0;
}




bool Matrix::summMatrix(Matrix matr2)
{
	double * tempura= new double[n];


	if ((matr2.getColumns() == this->getColumns()) && (matr2.getRows() == this->getRows()))
	{
		for (int item = 0; item < matr2.getRows(); item++)
		{
			for (int gtom = 0; gtom < this->getColumns(); gtom++)
			{
				tempura[item*this->getColumns()+gtom] = this->getElem(item, gtom) + matr2.getElem(item, gtom);
			}
		}
		for (int item1 = 0; item1 < matr2.getRows(); item1++)
			for (int gtom1 = 0; gtom1 < this->getColumns(); gtom1++)
			{
				for (int pal = 0; pal < this->getColumns()*this->getRows();pal++) {
					this->arrayMatrix[item1*this->getColumns()+gtom1] = tempura[item1*this->getColumns()+gtom1];
				}
			}

		delete[] tempura;
		return 1;
	}
	else
	{
		delete tempura;
		return 0;
	}

}
bool Matrix::multMatrix(Matrix matr2)
{
	double tempura[10][10] = { 0 };
	if ((this->getColumns() == matr2.getRows()) && (matr2.getRows() < this->getColumns()) && (matr2.getColumns() < 10) && (matr2.getColumns() > 0) && (matr2.getRows() > 0))
	{
		for (int item = 0; item < matr2.getRows(); item++)
		{
			for (int gtom = 0; gtom < this->getColumns(); gtom++)
			{
				for (int k = 0; (k < this->getColumns()); k++) {
					tempura[item][gtom] += this->arrayMatrix[item*this->getColumns()+k] * matr2.getElem(k, gtom);
				}
			}
		}


		for (int i = 0; i < matr2.getRows(); i++)
			for (int g = 0; g < this->getColumns(); g++)
			{
				this->columns = matr2.getColumns();
				this->arrayMatrix[i*this->getColumns()+g] = tempura[i][g];
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
					temp = this->arrayMatrix[i*this->getColumns()+j];
					this->arrayMatrix[i*this->getColumns() + j] = this->arrayMatrix[j*this->getColumns() + i];
					this->arrayMatrix[j*this->getColumns() + i] = temp;

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
			std::cout << this->arrayMatrix[itr*columns + jojo] << "\t ";
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
				if ((this->arrayMatrix[0] != 0)) { b++; }
				break;
			}
			/////////////
			this->arrayMatrix[lines*this->columns +i] = (double)atof(stro);

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
		return this->arrayMatrix[rov*columns + col ];
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
	char stro[255] = { "0" };

	for (int i = 0; i < this->columns; i++)
	{
		std::cin >> stro;
		if (stro[0] == 'e'&&stro[1] == 'n'&&stro[2] == 'd')
		{
			this->columns = i;
			break;
		}
		this->arrayVector[i] = (double)atof(stro);
		if (stro[0] == 'e'&&stro[1] == 'n'&&stro[2] == 'd'&&stro[3] == 'm')
		{
			this->columns = i;
			break;
		}
	}
	std::cout << std::endl << std::endl;
}
//сделать дома 


