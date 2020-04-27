//
// Created by HU Siyan on 17/4/2020.
//

#include <vector>
#include "keygen.h"

//Public functions
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

std::vector<sha1::close_contact> keygen::detectContact(sha1::ContactHistory *historyList, int historyCount, std::string secretkey, int threshold)  {
    return sha1_generator.detectContact(historyList, historyCount, secretkey, threshold);
}
