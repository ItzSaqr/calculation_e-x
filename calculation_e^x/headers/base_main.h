#pragma once

using namespace std;

void base_main(double* x, uint64_t* n)
{
	setlocale(LC_CTYPE, "Russian");

	cout << "¬ведите x: ";
	cin >> *x;

	cout << "¬ведите n: ";
	cin >> *n;

	cout.precision(31);
}
