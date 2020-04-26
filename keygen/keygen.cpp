//
// Created by HU Siyan on 17/4/2020.
//

#include <sstream>
#include <vector>
#include "keygen.h"

//Private functions
std::vector<std::string> split(const std::string &str, const char pattern) {
    std::vector<std::string> res;
    std::stringstream input(str);   //读取str到字符串流中
    std::string temp;
    //使用getline函数从字符串流中读取,遇到分隔符时停止,和从cin中读取类似
    //注意,getline默认是可以读取空格的
    while(getline(input, temp, pattern)) {
        res.push_back(temp);
    }
    return res;
}

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
