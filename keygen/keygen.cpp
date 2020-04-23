//
// Created by HU Siyan on 17/4/2020.
//

#include "keygen.h"

keygen::keygen() {

}

keygen::~keygen() {

}

std::string keygen::generateSK(int num) {
    std::string sk = sha1_generator.generateSK(num);
    return sk;
}

std::set<std::string> keygen::generateEphIDs(std::string secretKey) {
    return sha1_generator.generateEphIDs(secretKey);
}

std::string keygen::randomPick(std::set<std::string> ephIds) {
    return sha1_generator.randomPick(ephIds);
}

std::string keygen::detactContact(sha1::ContactHistory *historyList, std::string secretkey) {
    return sha1_generator.detectContact(historyList, secretkey);
}
