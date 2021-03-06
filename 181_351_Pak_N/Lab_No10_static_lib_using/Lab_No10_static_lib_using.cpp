// Lab_No10_static_lib_using.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//alt+enter
// .dll, .lib
// .a, .so
// библиотеки - файлы, содержащие готовый машинный код для многократного использования
// разница между динамической и статической библиотекой.
// динамическую могут юзать несоклько прог одновременно
// 
//дин: явные и неявные 
//неявные exe ставится в зависимость от dll в момент компиляции. 
//подключается маленькая либка, где написано, где длл находится
//ЯВНЫЕ
//если длл не найдена, то прога технически может продолжать работу но без фионала длл.
//
//унифицированность
//меньше весят ехе
//
//либ лучше длл
//если один проект
//если нужно удобно портабельную версию
//если МОЯ библиотечка никаму ни дам1111
//
//3.1. Динамические библиотеки преимущества и недостатки
//это .dll dinemic link library
//.so source object
//+-поставляются отдельно
//+одним и тем же длл файлом на машине 
//+пользователя могут пользоваться несколько 
//+приложений одновременно(системные длл, библиотеки ИДЕ)
//-хранятся в виде отдельных файлах и могут потеряться
//+отдельным файлом могут пользоваться сразу несколько приложений
//+размер самого ехе файла не увеличивается при использовании длл функций, в отличие от либ
//+длл может быть загружена в память только в тот момент, когда она потребуется
//+и затем выгружена
//- требует наличия инсталятора 
//- более сложная структура кода  и более сложное подключение  в ехе
//
//3.2. два типа подключения длл к приложению
//статическое и дин связывание
//стат: длл грузится в ОЗУ сразу при запуске приложения
//при отсутсвии длл происходит сбой и приложение не работает
//также такой подход требует наличия трёх файлов: саму готовую .dll, хидер .h,и промежуточный .lib библиотеки, 
//которая хранит для сборщика приложения адреса используемых функций в длл (таблица отсылок)
//динамическое подключение длл
//длл подключается не при запуске приложения,  
//а в тот момент, который определил прогер в коде с помозщью вызова спец фии loadlibrary
//третий либ файл с таблицей соответствия не нужен, фия внутри длл ищутся по имени getprocaddress
//+отпадает третий файл(промежуточный)
//+можем грузить библиотеку, а можем не грузить, грузим по необходимости только тогда, когда нужно
//-усложняется рабоат с кодом приложения
//3.3. подключение длл в проект приложения
//в случае статического связывания:
//в исходный код подключается хедер с объявлениями
//в настройки компоновщика подключается либ с таблицами и
//прописывается путь
//длл дб размещена рядом с ехе либо в системных директориях
//динамическое связывание
//в исходный код приложения дб подключен хедер, длл должен лежать рядом с ехе
//в коде перед использвоанием какой=-либо из библиотечных функций вызыыаается лоадлайбрарри
//перед использовнаием каждой библиотечной функции ищется с помощью гетпроцадресс
//
//ТОЧКА ВХОДА БИБЛИОТЕКИ
//длл можно определить специальную функцию - дллмейн, 
//котоая будет вызываться автоматически при загрузке библиотеки
//и еще можно прописать функцию, которая будет работать на выходе
//
//
//
//






#include "pch.h"
//#include "Lab_No10_first_header.h"
#include <iostream>


extern class Matrix
{
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
//extern Matrix::readMatr();




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
	std::cout << "Mult" << std::endl;
	(checking*checking2).printMat();
	//checking3 = checking * checking2;
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
