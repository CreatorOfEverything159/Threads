#include <iostream>
#include <fstream>
#include <sstream>
#include "calc.h"


void* calculateSum(void* args) {
    int sum;
    std::ifstream infile;
    std::stringstream thread;

    Args *data = (Args*) args;
    infile.open(data->path);
    thread.str(std::string());
    data->sum = 0;
    while (!infile.eof()) {
        infile >> sum;
        data->sum += sum;
    }
    infile.close();
}

int getSumUsingMultipleThreads(int files) {
    int sum = 0;
    pthread_t threads[files];
    Args* args = new Args[files];

    for (int i = 0; i < files; ++i) {
        args[i].path = "../files/" + std::to_string(i + 1) + ".txt";
        pthread_create(&(threads[i]), nullptr, calculateSum, &args[i]);
    }
    for (int i = 0; i < files; i++) {
        pthread_join(threads[i], nullptr);
        sum += args[i].sum;
    }
    delete[] args;
    return sum;
}

int getSumOneThread(int files) {
    int sum = 0;
    Args args;

    for (int i = 0; i < files; ++i) {
        args.path = "../files/" + std::to_string(i + 1) + ".txt";
        calculateSum(&args);
        sum += args.sum;
    }
    return sum;
}
