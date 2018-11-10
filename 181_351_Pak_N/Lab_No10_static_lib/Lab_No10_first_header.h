#pragma once

//#include "pch.h"
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
	void setElem(unsigned short rov, unsigned short col, double elem);

	void swaper(int i1, int j1, int i2, int j2);
	Matrix(/*const unsigned int a, const unsigned int b*/)
	{
		std::cout << "enter count of rows and columns" << std::endl;
		//std::cin >> 
		this->rows = 3;
		//std::cin >> 
		this->columns = 3;
		arrayMatrix = new double[this->getRows()*this->getColumns()];
		/*arrayMatrix[a][b]={ 0 };
		columns = a;
		rows = b;*/
	}

	Matrix(const unsigned int a, const unsigned int b)
	{
		//std::cout << "enter count of rows and columns" << std::endl;
		this->rows = a;
		this->columns = b;
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
