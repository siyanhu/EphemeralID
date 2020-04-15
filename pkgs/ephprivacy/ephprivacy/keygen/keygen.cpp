//
// Created by HU Siyan on 13/4/2020.
//

#include <iomanip>
#include <sstream>
#include <iostream>
#include "keygen.h"

keygen::keygen() {}
keygen::~keygen() {}

std::string keygen::generateKey(unsigned long long timeEpoch, unsigned pwd, bool bestPrint) {
    uuid.TimeEpoch = timeEpoch;

    static std::mt19937 PRNG(pwd);
    uuid.RandomNumber = randomNumGenerater(PRNG);
    uuid.PWD = pwdProcessor(PRNG);
    return GenerateUUID(bestPrint);
}

unsigned keygen::pwdProcessor(std::mt19937 &PRNG) {
    std::uniform_int_distribution<unsigned> uint_dist_long(0,UINT16_MAX);
    return uint_dist_long(PRNG) & 0xFFFF;
}

unsigned long long keygen::randomNumGenerater(std::mt19937& PRNG) {
    std::uniform_int_distribution<uint32_t> uint_dist_long(0, UINT32_MAX);
    unsigned long long rdmnum = uint_dist_long(PRNG);
    rdmnum <<= 32;
    rdmnum |= uint_dist_long(PRNG);
    rdmnum &= 0xFFFFFFFFFFFFFFF ;
    return rdmnum;
}

std::string keygen::GenerateUUID(bool bPrettyPrint) {

    std::stringstream ssUUID;
    ssUUID << std::hex << std::setfill('0');

    ssUUID << std::setw(15) << uuid.RandomNumber; // 15 hex digits = 60 bit binary number
    ssUUID << std::setw(13) << uuid.TimeEpoch;
    ssUUID << std::setw(4) << uuid.PWD;

    return bPrettyPrint ? (ssUUID.str().insert(8, 1, '-').insert(13, 1, '-').insert(18, 1, '-').insert(23, 1, '-')) : ssUUID.str();
}
