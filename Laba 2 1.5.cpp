#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

void checkValidInput()
{
	if (cin.fail())
		throw "Incorrect input";
}

void checkValidParam(int n)
{
	if (n <= 2)
		throw "Incorrect param";
}
double calculate(double x, int n)
{
	double y;
	if (x <= 0)//Расчет y если х<=0
	{
		y = 0;
		for (int i = 2; i <= n - 1; i++) {
			y += x / i;

		}
	}

	else {//Расчет y если х>0
		y = 1;
		double e;
		for (int i = 1; i <= n - 1; i++) {
			e = 0;
			for (int j = 0; j <= i; j++) {
				e += i / (j + x);

			}
			y *= e;
		}
	}
	return y;
}


int main()
{
	try {
		setlocale(LC_ALL, "RUS");
		int  n, a;
		double  x, h, b;


		cout << "Введите n>=3: n= ";//Вводим значения
		cin >> n;
		cout << "Введите x: x= ";
		cin >> x;
		cout << "Введите шаг h: h= ";
		cin >> h;
		cout << "Введите b, диапазона (x...b) = ";
		cin >> b;
		checkValidInput();
		checkValidParam(n);

		cout << "Хотите сохранить значение y ? \n1 - Да\n0-Нет\n"; //Запись результата (по желанию пользователя
		cin >> a;
		checkValidInput();

		ofstream fout; //открытие потока на запись в файле
		fout.open("test.txt", ofstream::app);// Создание файла




		for (x; x <= b; x += h) {
			double y = calculate(x, n);
			cout << "x = " << x << "; y = " << y << endl;
			if (a) {//Запись y в файл
				fout << "y = " << y << endl;
			}
		}
	}
	catch (char* err) {
		cout << err << endl;
		return -1;
	}
	catch (...) {
		cout << "Something is going wrong" << endl;
		return -2;
	}
	return 0;
}

	
