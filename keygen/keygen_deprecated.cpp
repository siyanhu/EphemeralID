//
// Created by HU Siyan on 13/4/2020.
//

#include <iomanip>
#include <sstream>
#include <iostream>
#include "keygen.h"

struct UUID {
    unsigned flag; //2
    unsigned long long timeEpoch; //8
    unsigned long long invalidEpoch; //2
    std::string sk; //22
};

// tools
int getIndexOfSigns(char ch) {
    if(ch >= '0' && ch <= '9') {
        return ch - '0';
    }
    if(ch >= 'A' && ch <='F') {
        return ch - 'A' + 10;
    }
    if(ch >= 'a' && ch <= 'f') {
        return ch - 'a' + 10;
    }
    return -1;
}

std::string str2bin(char n) {
    switch (n) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'a': return "1010";
        case 'A': return "1010";
        case 'b': return "1011";
        case 'B': return "1011";
        case 'c': return "1100";
        case 'C': return "1100";
        case 'd': return "1101";
        case 'D': return "1101";
        case 'e': return "1110";
        case 'E': return "1110";
        case 'f': return "1111";
        case 'F': return "1111";
    }
    return "0000";
}

char dec2base64(int n) {
    if (n < 26) {
        return (n + 'A');
    } else if (n < 52) {
        return (n - 26 + 'a');
    } else if (n < 62) {
        return (n - 52 + '0');
    } else if (n == 62) {
        return '+';
    }
    return '/';
}

int bin2dec(std::string b) {
    int result = 0;
    for (size_t i = 0; i < 6; i++) {
        if(b[i] == '1') {
            result += (1 << (5-i));
        }
    }
    return result;
}


// Timestamp functions
std::string compileTimeEpoch(unsigned long long timeEpoch) {
    char buff[100];
    snprintf(buff, sizeof(buff), "%llx", timeEpoch);
    std::string buffAsStdStr = buff;
    return buffAsStdStr;
}

unsigned long long decompileToTimeEpoch(std::string content) {
    long sum = 0;
    long t = 1;
    int i, len;
    const char *source = content.c_str();
    len = strlen(source);
    for(i=len-1; i>=0; i--) {
        sum += t * getIndexOfSigns(*(source + i));
        t *= 16;
    }
    return sum;
}

// uuid functions
std::string compressSK(std::string content) {
    std::string newSK = content;
    newSK.erase(std::remove(newSK.begin(), newSK.end(), '-'), newSK.end());
    std::string bin = "";
    for (size_t i = 0; i < newSK.size(); i++) {
        bin += str2bin(newSK[i]);
    }
    std::string base64;
    for (size_t i = 0; i < bin.size(); i+=6) {
        base64 += dec2base64(bin2dec(bin.substr(i,6)));
    }
    return base64;
}

std::string decompressToSK(std::string content) {
return "";
}

// public apis
keygen::keygen() {}
keygen::~keygen() {}

std::string keygen::refreshEphID(unsigned long long timeEpoch, std::string sk) {
    std::string zippedTime = compileTimeEpoch(timeEpoch);
    unsigned long long testDecompile = decompileToTimeEpoch(zippedTime);

    std::string zippedSK = compressSK(sk);

    std::string newuuid = "hk" + zippedTime + zippedSK;
    std::string formatuuid = newuuid.insert(8, 1, '-').insert(13, 1, '-').insert(18, 1, '-').insert(23, 1, '-');
    return newuuid;
}

std::string keygen::detectContact(std::string EphIDs[], std::string sk) {
    return "";
}