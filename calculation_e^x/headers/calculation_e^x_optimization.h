#pragma once

#define _USE_MATH_DEFINES

#include <chrono>
#include <cmath>

using namespace std;
using namespace chrono;

static void calculation_ex_optimization(double x, uint64_t n, double* out)
{
	double result = 0;
	double pow = 1;
	double fact = 1;

	auto time_start = high_resolution_clock::now();

	for (uint64_t i = 0; pow != HUGE_VAL && fact != HUGE_VAL && i <= n; i++, pow *= x, fact *= i)
	{
		result += pow / fact;
	}
	*out = result;

	auto time_end = high_resolution_clock::now();
	duration<double> time = time_end - time_start;
	cout << "time = " << time.count() << endl;
}
