// Lab_No9_Overload_Pak.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Перегрузкой называется объявление нескольких функций или 
//операторов с одинаковыми именами. но разным набором аргументов
//Неважно, какой тип аргумента возвращает, важно, какие принимает - тогда перегруженная
//Если есть необяхзательные арги, то это перегруженная
//Важны и последовательность, и типы переменных.
//Компилятор: проверяет Совпадение- затем простейшее приведение типов - 
//затем, если нет того, то * в void, float в double
// Унарные операторы перегружаются внутри класса, 
//бинаные - как дружественные глобально. Потоковые как бин, равно как унарный
//Унарарные записывают в объект, который вызвал. Поэтому внутри класса писать. 
//+= унарный
//Sample_class & operator +=(const Sample_class & operand)
//{
//property1=property1+operand.property1;
//this->property2=this->property2+property1;

//}

#include "pch.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>


class Matrix {
private:
	int n = 1;

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
	void setElem(unsigned short rov, unsigned short col,double elem);

	void swaper(int i1, int j1, int i2, int j2);
	Matrix(/*const unsigned int a, const unsigned int b*/)
	{
		std::cout << "enter count of rows and columns" << std::endl;
		//std::cin >> 
		this->rows=3;
		//std::cin >> 
		this->columns=3;
		arrayMatrix = new double[this->getRows()*this->getColumns()];
		/*arrayMatrix[a][b]={ 0 };
		columns = a;
		rows = b;*/
	}

	Matrix(const unsigned int a, const unsigned int b)
	{
		//std::cout << "enter count of rows and columns" << std::endl;
		this->rows=a;
		this->columns=b;
		arrayMatrix = new double[this->getRows()*this->getColumns()];
		/*arrayMatrix[a][b]={ 0 };
		columns = a;
		rows = b;*/
	}

	~Matrix()
	{
		//delete[] arrayMatrix;
	}



	Matrix & operator +=(Matrix & second_matr);

	friend std::ostream & operator<<(std::ostream &os, Matrix & rhs);
	friend Matrix operator +(/*const */Matrix & first_matr,/* const*/ Matrix & second_matr);
	friend Matrix operator -(/*const */Matrix & first_matr,/* const*/ Matrix & second_matr);
	friend Matrix operator *(/*const */Matrix & first_matr,/* const*/ Matrix & second_matr);
	friend Matrix operator /(/*const */Matrix & first_matr,/* const*/ Matrix & second_matr);

};

void Matrix::setElem(unsigned short rov, unsigned short col, double elem) {

	this->arrayMatrix[rov*columns + col] = elem;
}



std::ostream & operator<<(std::ostream &os, Matrix & rhs)
{
	//	os << "res:" << std::endl;


	os << "Array res: \n" << std::endl;
	for (int itr = 0; ((rhs.getRows() > 1) ? (itr < rhs.getRows()) : (itr < rhs.getRows())); itr++)
	{
		for (int jojo = 0; jojo < (rhs.getColumns()); jojo++)
		{
			os << rhs.getElem(itr, jojo) << "\t ";
		}
		os << std::endl << std::endl;
	}

	os<< std::endl;
	os << std::endl;


	//os << rhs.getElem(i, j);
	return os;
}

Matrix & Matrix::operator +=(Matrix & second_matr)
{
	for (int i = 0; i < this->getRows(); i++) {
		for (int j = 0; j < this->getColumns(); j++) {
			this->arrayMatrix[i*this->getColumns() + j] += second_matr.getElem(i, j);
		}
	}
	return *this;
}
Matrix operator +(/*const */Matrix & first_matr,/* const*/ Matrix & second_matr)
{
	Matrix kek(first_matr.getRows(),first_matr.getColumns());
	for (int i = 0; i < first_matr.getRows(); i++) {
		for (int j = 0; j < first_matr.getColumns(); j++) {
			kek.setElem(i,j,first_matr.getElem(i,j)+ second_matr.getElem(i, j));
		}
	}
	return kek;
}


Matrix operator *(/*const */Matrix & first_matr,/* const*/ Matrix & second_matr)
{
	Matrix kek(first_matr.getRows(), second_matr.getColumns());
		double * tempura = new double[kek.getColumns()*kek.getRows()];
	if ((first_matr.getColumns() == second_matr.getRows()) /*&& (second_matr.getRows() < kek.getColumns())*/
		&& /*(matr2.getColumns() < 10) &&*/ (second_matr.getColumns() > 0) && (second_matr.getRows() > 0))
	{
		for (int item = 0; item < second_matr.getRows(); item++)
		{
			for (int gtom = 0; gtom < first_matr.getColumns(); gtom++)
			{
				for (int k = 0; (k < first_matr.getColumns()); k++) {
					tempura[item*first_matr.getColumns() + gtom] += first_matr.arrayMatrix[item*first_matr.getColumns() + k] * second_matr.getElem(k, gtom);
				}
			}
		}


		for (int i = 0; i < second_matr.getRows(); i++)
			for (int g = 0; g < first_matr.getColumns(); g++)
			{
				kek.columns =second_matr.getColumns();
				kek.setElem(i,g,tempura[i*first_matr.getColumns() + g]);
			}

		delete[] tempura;
		//return 1;
	}
	else
	{
		delete[] tempura;
		std::cout << "MULT ERROR";

		//return 0;
	}
	
	/*
	Matrix kek;
	for (int i = 0; i < kek.getRows(); i++) {
		for (int j = 0; j < kek.getColumns(); j++) {
			kek.arrayMatrix[i*kek.getColumns() + j] = first_matr.getElem(i, j) / second_matr.getElem(i, j);
		}
	}*/
	return kek;
}


Matrix operator -(/*const */Matrix & first_matr,/* const*/ Matrix & second_matr)
{
	Matrix kek(first_matr.getRows(), first_matr.getColumns());
	if (first_matr.getColumns() == second_matr.getColumns() && first_matr.getRows() == second_matr.getRows()) {
		for (int i = 0; i < kek.getRows(); i++) {
			for (int j = 0; j < kek.getColumns(); j++) {
				kek.setElem(i,j,first_matr.getElem(i, j) - second_matr.getElem(i, j));
			}
		}
	}
	else {
		std::cout << "MINUS ERROR";
	}
	return kek;
}

Matrix operator /(/*const */Matrix & first_matr,/* const*/ Matrix & second_matr)
{
	Matrix kek(first_matr.getRows(), first_matr.getColumns());
	if (first_matr.getColumns() == second_matr.getColumns() && first_matr.getRows() == second_matr.getRows()) {

			for (int i = 0; i < kek.getRows(); i++) {
				for (int j = 0; j < kek.getColumns(); j++) {
					kek.setElem(i,j,first_matr.getElem(i, j) / second_matr.getElem(i, j));
				}
			}
	}
	else {
	std::cout << "DIVIDION ERROR";
	}
	return kek;
}

class Vector : virtual public Matrix //что такое virtual тут
{
private:
	double * arrayVector;
	unsigned short columns = 0;
public:
	Vector constMultVector(double mnoj);
	Vector scalMultVector(Vector vec2);
	//void Matrix::readMatr();
	void printMat();
	void readMatr();
	Vector() {
		
		std::cin >> this->columns;
		arrayVector = new double[this->columns];
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

	/*if (checking.summMatrix(checking2))
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
	*/

	checking += checking2;
	std::cout << checking;//.printMat();
	std::cout << "summ" << std::endl;
	Matrix checking3 = checking + checking2;
	std::cout << checking3;
	//(checking + checking2).printMat();
	std::cout << "Mult"<<std::endl;
	//(checking*checking2).printMat();
	checking3 = checking * checking2;
	std::cout << checking3;
	std::cout << "Delenie" << std::endl;
	checking3 = checking / checking2;
	std::cout << checking3;
		//(checking / checking2).printMat();
	std::cout << "minus" << std::endl;
	checking3 = checking - checking2;

	std::cout << checking3;


	/*std::cout << "Transpon:" << std::endl;
	checking.transMatrix();
	checking.printMat();

	//delete checking;
	//delete checking2;

	
	Vector check1 = Vector();
	Vector check2 = Vector();
	check1.readMatr();
	check2.readMatr();
	check1.printMat();
	check2.printMat();

	std::cout << "Const mult vector:" << std::endl;
	check1.constMultVector(1.5).printMat();
	std::cout << "Scal mult of vectors:" << std::endl;
	check1.scalMultVector(check2).printMat();
	*/


	//delete check1; деструктор сам запускается с ретурном
	//delete check2;
	return 0;
}




bool Matrix::summMatrix(Matrix matr2)
{
	double * tempura = new double[matr2.getRows()*matr2.getColumns()];


	if ((matr2.getColumns() == this->getColumns()) && (matr2.getRows() == this->getRows()))
	{
		for (int item = 0; item < matr2.getRows(); item++)
		{
			for (int gtom = 0; gtom < this->getColumns(); gtom++)
			{
				tempura[item*this->getColumns() + gtom] = (this->getElem(item, gtom) + matr2.getElem(item, gtom));
			}
		}
		for (int item1 = 0; item1 < matr2.getRows()*matr2.getColumns(); item1++)
		{
			this->arrayMatrix[item1] = tempura[item1];
		}

		delete[] tempura;
		return 1;
	}
	else
	{
		delete[] tempura;
		return 0;
	}

}
bool Matrix::multMatrix(Matrix matr2)
{
	double * tempura = new double[n];
	if ((this->getColumns() == matr2.getRows()) && (matr2.getRows() < this->getColumns())
		&& /*(matr2.getColumns() < 10) &&*/ (matr2.getColumns() > 0) && (matr2.getRows() > 0))
	{
		for (int item = 0; item < matr2.getRows(); item++)
		{
			for (int gtom = 0; gtom < this->getColumns(); gtom++)
			{
				for (int k = 0; (k < this->getColumns()); k++) {
					tempura[item*this->getColumns() + gtom] += this->arrayMatrix[item*this->getColumns() + k] * matr2.getElem(k, gtom);
				}
			}
		}


		for (int i = 0; i < matr2.getRows(); i++)
			for (int g = 0; g < this->getColumns(); g++)
			{
				this->columns = matr2.getColumns();
				this->arrayMatrix[i*this->getColumns() + g] = tempura[i*this->getColumns() + g];
			}

		delete[] tempura;
		return 1;
	}
	else
	{
		delete[] tempura;
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
	for (int lines = 0; lines < this->getRows(); lines++)
	{
		std::cout << "\nWrite the row of matrix in the" <<
			"column and write the \"end\":\n";
		for (int i = 0; i < this->getColumns()/*&& lines*this->getColumns() + i<this->getColumns()*getRows()*/; i++)
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
			this->arrayMatrix[lines*this->getColumns() + i] = (double)atof(stro);

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
		std::cout << this->arrayVector[jojo] << " \t ";
	}
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;


}
void Vector::readMatr()
{
	std::cout << "Array: \n";
	//this->columns = 10, this->rows = 10;
	//int a;
	std::cout << std::endl;
	std::cout << "If that the end of matrix" <<
		", please, write the \"endm\"\n";
	char stro[255] = { "0" };

	for (int i = 0; i < this->getColumns(); i++)
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
void Matrix::swaper(int i1, int j1, int i2, int j2)
{
	double tempura = this->arrayMatrix[i1*this->getColumns() + j1];
	this->arrayMatrix[i1*this->getColumns() + j1] = this->arrayMatrix[i2*this->getColumns() + j2];
	this->arrayMatrix[i2*this->getColumns() + j2] = tempura;
}
