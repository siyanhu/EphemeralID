//
// Created by HU Siyan on 17/4/2020.
//

#include "strcompile.h"

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

std::string strcompile::compileStr(std::string content) {
    std::string newSK = content;
    newSK.erase(std::remove(newSK.begin(), newSK.end(), '-'), newSK.end()); // if have separator like '-'
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

std::string strcompile::decompile(std::string content) {

}
