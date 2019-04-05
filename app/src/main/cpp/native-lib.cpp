#include <jni.h>
#include <string>
#include <thread>
#include <vector>
#include <iostream>
#include <sstream>
#include <chrono>


int main() {

    bool stop = false ;



    auto func1 = [&stop]() {
        std::cout << "begin of thread " << std::endl;
        int j = 0;
        while (!stop) {
            j++;
        }
        std::stringstream temp ;
        temp << "end of thread j = " << j << std::endl;
        std::cout << temp.str();
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < 8; ++i) {
        threads.push_back(std::thread(func1));
    }

    std::cout << "sleep begin" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(30));
    std::cout << "sleep done" << std::endl;
    stop = true ;

    for (auto &thread : threads) {
        thread.join();
    }
    std::cout << "end of main" << std::endl;


    return 0;
}