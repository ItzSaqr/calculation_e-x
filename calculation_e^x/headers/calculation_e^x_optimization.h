#pragma once

#include <chrono>
#include <cmath>

using namespace std;
using namespace chrono;

static void calculation_ex_optimization(__float128 x, uint32_t n, __float128* out)
{
	auto time_start = high_resolution_clock::now();

	__float128 result = 1;

	for (uint32_t i = n; i > 0; i--)
	{
		result *= x / i;
		result += 1;
	}

	auto time_end = high_resolution_clock::now();
	duration<double> time = time_end - time_start;
	cout << "time = " << time.count() << endl;

	*out = result;
}