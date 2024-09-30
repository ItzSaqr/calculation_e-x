#pragma once

#include <time.h>
#include <cmath>
#include <quadmath.h>

using namespace std;

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

	clock_t time_start, time_end;
	double elapsed;

	time_start = clock();

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

	time_end = clock();
	elapsed = ((double)(time_end - time_start)) / CLOCKS_PER_SEC;
	cout << "time = " << elapsed << endl;

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