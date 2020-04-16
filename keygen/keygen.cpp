//
// Created by HU Siyan on 13/4/2020.
//

#include <iomanip>
#include <sstream>
#include "keygen.h"

// private functions
struct UUID {
    unsigned flag;
    unsigned long long timeEpoch;
    std::string sk;
};

std::string forward(std::string pwdKey, std::string content) {
    char *cid = (char*)&content;
    char *ckey = (char*)&pwdKey;
    std::string output;
    output.resize(24, '\0');
    for (int i = 0; i < 24; i++) {
        output[i] = cid[i] ^ ckey[i%2];
    }
    return output;
}

UUID* backward(std::string pwdKey, std::string pwd) {
    char *cid = (char *)malloc(sizeof(int) * 16);
    char *ckey = (char*)&pwdKey;
    for (int i = 0; i < 24; i++) {
        cid[i] = pwd[i] ^ ckey[i % 2];
    }
    return (UUID*)cid;
}

std::string xorProcess(std::string content) {
    return "";
}

std::string xorReverse(std::string xord_content) {
    return "";
}

std::string compileFlag(std::string idcode) {
    return "";
}

std::string compressSK(std::string sk_content) {

}

// public apis
keygen::keygen() {}
keygen::~keygen() {}

std::string keygen::refreshEphID(unsigned long long timeEpoch, std::string sk) {
    std::stringstream ssUUID;
    ssUUID << std::hex << std::setfill('0');

    ssUUID << std::setw(15) << ""; // 15 hex digits = 60 bit binary number
    ssUUID << std::setw(13) << "";
    ssUUID << std::setw(4) << "uuid.PWD";

//    return ssUUID.str().insert(8, 1, '-').insert(13, 1, '-').insert(18, 1, '-').insert(23, 1, '-'));
    return "00a78fdc-7f1c-11ea-bc55-0242ac130003";
}

std::string keygen::detectContact(std::string EphIDs[], std::string sk) {
    return "Alert Message";
}