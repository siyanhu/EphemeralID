#include <iostream>
#include "keygen.h"

int main(int argc, char *argv[]) {

    std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch());
    unsigned long long timeEpoch = ns.count() & 0xFFFFFFFFFFFFF;
    unsigned pwd = 3; //16 bit integer
    keygen keygenerator;
    std::string key = keygenerator.generateKey(timeEpoch, pwd, true);
    std::cout<<key;
    return 0;
}
