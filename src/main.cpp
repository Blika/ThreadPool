#include "threadpool.hpp"
#include <mutex>
#include <functional>
#include <iostream>

std::mutex coutMutex;
int t = 0;

void test(const int& a, const int& b){
    std::lock_guard<std::mutex> lock(coutMutex);
    std::cout << a << " " << b << " " << a + b << std::endl;
    t++;
}

int main(){
    threadpool::ThreadPool pool = threadpool::ThreadPool();
    for(int i = 0; i < 20; ++i){
        std::function<void()> f = std::bind(&test, i, i*3);
        pool.assignNewTask(std::move(f),5);
    }
    pool.wait();
    std::cout << t << '\n';
    return 1;
}