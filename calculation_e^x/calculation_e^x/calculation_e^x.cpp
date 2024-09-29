#include <iostream>
#include <quadmath.h>
#include "../headers/calculation_e^x.h"

int main()
{
	while (true)
	{
		setlocale(LC_CTYPE, "Rus");
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

		n = quadmath_snprintf(NULL, 0, format.c_str(), calculation_result);
		if (n > 0)
		{
			string out(n + 1, '\0');
			quadmath_snprintf(&out[0], out.capacity(), format.c_str(), calculation_result);
			cout << out << endl;
		}

		string end;
		cin >> end;
	}

	return 0;
}