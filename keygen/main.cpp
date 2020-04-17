#include <iostream>
#include "keygen.h"

int main(int argc, char *argv[]) {

    unsigned long long timeEpoch = 1587039132; //10
    std::string sk = "4b3864de-7faa-11ea-bc55-0242ac130003";
    keygen keygenerator;
    std::string key = keygenerator.refreshEphID(timeEpoch, sk);
    std::cout<<key;
    return 0;
}
