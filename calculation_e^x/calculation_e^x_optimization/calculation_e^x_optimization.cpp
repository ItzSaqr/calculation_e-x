#include <iostream>
#include <quadmath.h>
#include "../headers/calculation_e^x_optimization.h"

int main()
{
	string format = "%.31Qg";

	__float128 calculation_result;
	__float128 x;
	uint32_t n;
	uint32_t amount_chars;

	while (true)
	{
		cout << "Enter x: ";
		string in;
		cin >> in;
		x = strtoflt128(in.c_str(), NULL);

		cout << "Enter n: ";
		cin >> n;

		int threads_number;
		cout << "Enter number of threads: ";
		cin >> threads_number;

		calculation_ex_optimization(x, n, &calculation_result, threads_number);

		amount_chars = (uint32_t)quadmath_snprintf(NULL, 0, format.c_str(), calculation_result);
		string out(amount_chars + 1, '\0');
		quadmath_snprintf(&out[0], out.capacity(), format.c_str(), calculation_result);
		cout << out << endl;

		cout << endl;
	}

	return 0;
}
