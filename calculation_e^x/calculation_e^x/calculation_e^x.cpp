﻿#include <iostream>
#include "../headers/base_main.h"
#include "../headers/calculation_e^x.h"

int main()
{
	double calculation_result = 0;
	double x;
	uint64_t n;

	base_main(&x, &n);

	//calculation_ex(x, n, &calculation_result);
	calculation_ex_inf(x, n, &calculation_result);
	cout << "e^" << x << " = " << calculation_result << endl;

	return 0;
}