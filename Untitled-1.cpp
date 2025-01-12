#include <iostream>
#include <locale.h>
#include <quadmath.h>
#include <chrono>
#include <cmath>

using namespace std;
using namespace chrono;

static __float128 fact(uint32_t n)
{
	__float128 result = 1;

	for (uint32_t i = 2; i <= n; i++)
	{
		result *= i;
	}

	return result;
}

static void calculation_ex(__float128 x, uint32_t n, __float128* out)
{
	__float128 result = 0;

	auto time_start = high_resolution_clock::now();

	bool negative_x = false;

	if (x < 0)
	{
		x *= -1;
		negative_x = true;
	}

	uint32_t i = 0;
	__float128 pow_number = powq(x, i);
	__float128 fact_number = fact(i);
	do
	{
		result += pow_number / fact_number;

		i++;
		pow_number = powq(x, i);
		fact_number = fact(i);
	} while (pow_number != INFINITY && fact_number != INFINITY && i <= n);

	if (negative_x)
	{
		result = 1 / result;
	}

	auto time_end = high_resolution_clock::now();
	duration<double> time = time_end - time_start;
	cout << "t = " << time.count() << " s" << endl;

	/*информация для отслеживания закономерностей*/
	if (pow_number == INFINITY || fact_number == INFINITY)
	{
		cout << "i = " << i << endl;

		if (pow_number == INFINITY)
		{
			cout << "pow = infinity" << endl;
		}
		if (fact_number == INFINITY)
		{
			cout << "fact = infinity" << endl;
		}
	}

	*out = result;
}

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