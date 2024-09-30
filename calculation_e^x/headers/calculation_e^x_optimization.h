#pragma once

#include <time.h>
#include <cmath>

using namespace std;

static void calculation_ex_optimization(__float128 x, uint32_t n, __float128* out)
{
	clock_t time_start, time_end;
	double elapsed;

	__float128 result = 1;

	time_start = clock();

	bool negative_x = false;

	if (x < 0)
	{
		x *= -1;
		negative_x = true;
	}

	for (uint32_t i = n; result != INFINITY && i > 0; i--)
	{
		result *= x / i;
		result += 1;
	}

	if (result != INFINITY && negative_x)
	{
		result = 1 / result;
	}

	time_end = clock();
	elapsed = ((double)(time_end - time_start)) / CLOCKS_PER_SEC;
	cout << "time = " << elapsed << endl;

	*out = result;
}