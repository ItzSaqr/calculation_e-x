#pragma once

#define _USE_MATH_DEFINES

#include <chrono>
#include <cmath>

using namespace std;
using namespace chrono;

static double fact(uint64_t n)
{
	double result = 1;

	for (uint64_t i = 2; i <= n; i++)
	{
		result *= i;
	}

	return result;
}

static void calculation_ex(double x, uint64_t n, double* out)
{
	double result = 0;

	auto time_start = high_resolution_clock::now();

	for (uint64_t i = 0; i <= n; i++)
	{	

		result += pow(x, i) / fact(i);
	}
	*out = result;

	auto time_end = high_resolution_clock::now();
	duration<double> time = time_end - time_start;
	cout << time.count() << endl;
}

static void calculation_ex_inf(double x, uint64_t n, double* out)
{
	double result = 0;

	auto time_start = high_resolution_clock::now();

	double pow_number;
	double fact_number;
	for (uint64_t i = 0; i <= n; i++)
	{
		pow_number = pow(x, i);
		fact_number = fact(i);

		if (fact_number == HUGE_VAL || pow_number == HUGE_VAL)
		{
			cout << i << endl;
			break;
		}

		result += pow_number / fact_number;
	}
	cout << "pow_number = " << pow_number << endl;
	cout << "fact_number = " << fact_number << endl;
	*out = result;

	auto time_end = high_resolution_clock::now();
	duration<double> time = time_end - time_start;
	cout << "time = " << time.count() << endl;
}