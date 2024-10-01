#include <iostream>
#include <locale.h>
#include <quadmath.h>
#include "../headers/calculation_e^x.h"

int main()
{
	while (true)
	{
		setlocale(LC_ALL, "Russian");

		string format = "%.31Qe";

		__float128 calculation_result;
		__float128 x;
		uint32_t n;

		cout << "Введите x: ";
		string in;
		cin >> in;
		x = strtoflt128(in.c_str(), NULL);

		cout << "Введите n: ";
		cin >> n;

		calculation_ex(x, n, &calculation_result);

		uint32_t amount_chars = (uint32_t)quadmath_snprintf(NULL, 0, format.c_str(), calculation_result);
		string out(amount_chars + 1, '\0');
		quadmath_snprintf(&out[0], out.capacity(), format.c_str(), calculation_result);
		cout << out << endl;

		cout << endl;
	}

	return 0;
}