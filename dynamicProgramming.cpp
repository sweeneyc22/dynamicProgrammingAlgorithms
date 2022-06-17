#include <iostream>
#include <chrono>
#include <iomanip>

//
// Created by dxfan on 6/16/2022.
//
// A utility function to return
// minimum of two integers
int min(int a, int b)
{
    return (a < b) ? a : b;
}

int dpBinomialCoeff(int n, int k)
{
    int C[n + 1][k + 1];
    int i, j;

    // Calculate value of Binomial Coefficient
    // in bottom up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

                // Calculate value using previously stored values

            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

void logDpResult()
{
    int n{};
    int k{};
    std::cout << "Enter n value, followed by k value" << "\n";
    std::cin >> n;
    std::cin >> k;
    std::cout << "Using Dynamic Programming(Tabulation)" << "\n";
    std::cout << "Value of C(" << n << ", " << k <<") is ";
    auto dpStart = std::chrono::steady_clock::now();
    std::cout << dpBinomialCoeff(n,k) << "\n";
    auto dpStop = std::chrono::steady_clock::now();
    std::chrono::duration<double> dpElapsedTime = dpStop-dpStart;
    std::cout << std::fixed;
    std::cout << std::setprecision(8);
    std::cout << "Dynamic Programming(Tabulation) elapsed time: " << dpElapsedTime.count() << "s\n";
}




#include "dynamicProgramming.h"
