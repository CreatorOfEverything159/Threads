#ifndef THREADS_CALCULATION_H
#define THREADS_CALCULATION_H

struct Args {
    std::string path{};
    int sum{};
};

int getSumUsingMultipleThreads(int files);
int getSumOneThread(int files);

#endif