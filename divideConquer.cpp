//
// Created by Colby on 6/16/2022.
//
#include <iostream>
#include <chrono>
#include <iomanip>


int dcBinomialCoeff(int n, int k)
{
    //Base case
    if (k > n)
        return 0;
    if (k == 0 || k ==n)
        return 1;

    //Recursion
    return dcBinomialCoeff(n - 1, k -1)
           + dcBinomialCoeff(n - 1, k);
}

void logDcResult()
{
    int n{};
    int k{};
    std::cout << "Enter n value, followed by k value" << "\n";
    std::cin >> n;
    std::cin >> k;
    std::cout << "Using Divide and Conquer" << "\n";
    std::cout << "Value of C(" << n << ", " << k <<") is ";
    auto dcStart = std::chrono::steady_clock::now();
    std::cout << dcBinomialCoeff(n,k) << "\n";
    auto dcStop = std::chrono::steady_clock::now();
    std::chrono::duration<double> dcElapsedTime = dcStop-dcStart;
    std::cout << std::fixed;
    std::cout << std::setprecision(8);
    std::cout << "Divide and Conquer elapsed time: " << dcElapsedTime.count() << "s\n";
}

#include "divideConquer.h"
