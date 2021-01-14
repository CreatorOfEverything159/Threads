#include <iostream>
#include <ctime>
#include <pthread.h>
#include "src/calc.h"

int main() {
    const int FILES = 20;
    clock_t start, end;

    start = clock();
    std::cout << "Сумма в одном потоке: " << getSumOneThread(FILES) << std::endl;
    end = clock();
    std::cout << "Время в одном потоке: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    start = clock();
    std::cout << "Сумма в нескольких потоках: " << getSumUsingMultipleThreads(FILES) << std::endl;
    end = clock();
    std::cout << "Время в нескольких потоках (" << FILES << "): " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
}