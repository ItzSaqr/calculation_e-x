#pragma once

#include <iostream>
#include <chrono>
#include <cmath>
#include <omp.h>

using namespace std;
using namespace chrono;

static void calculation_ex_optimization(__float128 x, uint32_t n, __float128* out, int threads_number)
{
    __float128 result = 1;
    auto time_start = high_resolution_clock::now();
    bool negative_x = false;
    omp_set_num_threads(threads_number);

    if (x == 0)
    {
        result = 1;
    }
    else
    {
        if (x < 0) {
            x *= -1;
            negative_x = true;
        }

        // Используем переменную для хранения промежуточного результата
        __float128 partial_result = 0;

#pragma omp parallel for reduction(+:partial_result)
        for (uint32_t i = n; i > 0; i--)
        {
            __float128 term = (x / i);
            partial_result += term;
        }

        // Добавляем 1 к результату
        result += partial_result;

        if (result != INFINITY && negative_x)
        {
            result = 1 / result;
        }

        auto time_end = high_resolution_clock::now();
        duration<double> time = time_end - time_start;
        cout << "time = " << time.count() << " s" << endl;
    }

    *out = result;
}