#pragma once

using namespace std;

void base_main(double* x, uint64_t* n)
{
	setlocale(LC_CTYPE, "Russian");

	cout << "������� x: ";
	cin >> *x;

	cout << "������� n: ";
	cin >> *n;

	cout.precision(31);
}
