//
// Created by HU Siyan on 13/4/2020.
//

#ifndef KEYGEN_H
#define KEYGEN_H

#include <string>
#include <random>

class keygen {
    struct UUID {
        unsigned PWD;//16 bits
        unsigned long long TimeEpoch; //52 bits
        unsigned long long RandomNumber; //60 bits
    };

public:
    keygen();
    ~keygen();
    std::string generateKey(unsigned long long timeEpoch, unsigned pwd, bool bestPrint);

private:
    unsigned long long randomNumGenerater(std::mt19937& PRNG);
    unsigned pwdProcessor(std::mt19937& PRNG);
    std::string GenerateUUID(bool bPrettyPrint=true);
    UUID uuid;
};


#endif //KEYGEN_H
