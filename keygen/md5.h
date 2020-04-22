//
// Created by HU Siyan on 22/4/2020.
//

#ifndef KEYGEN_MD5_H
#define KEYGEN_MD5_H

//#include <stdlib.h>
#include <string>
#include <list>

//private type
typedef unsigned char byte;

class md5 {

    struct ContactHistory {
        std::string uuid;
        unsigned long long timestamp;
    };


    md5();
    ~md5();

public:
    std::string generateSK(unsigned long long timestamp);
    std::list<std::string> md5EphID(std::string sk);

private:
    bit32 state[4];
    static const byte PADDING[64];
    static const char HEX_NUMBERS[16];
};


#endif //KEYGEN_MD5_H
