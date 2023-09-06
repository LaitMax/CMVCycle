#include <iostream>
#include <cmath>
#define eps 0.00001
using namespace std;

//Определим функцию, возвращающую точное значение функции y
double y(double x) { return 0.5 * (exp(x) - exp(-x)); }

//Функция CMV возвращает значение суммы ряда, вычисленной с контролем
//за модулем разности точного и приближенного значения суммы ряда
double CMV(double x) {
	int i = 0;
	double s = 0, a = x;

	while (abs(y(x) - s) > eps) {
		s += a;
		a *= x * x / 2 / (i + 1) / (2 * i + 3);
		i++;
	}
	return s;
}

void main() {
	double x;
	cout << "\nx==\t";
	cin >> x;
	cout << "\nsum=\t" << CMV(x);
	system("Pause");
}
