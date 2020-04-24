//
// Created by HU Siyan on 13/4/2020.
//

#ifndef KEYGEN_H
#define KEYGEN_H

#include "sha1.h"

class keygen {
public:
    keygen();
    ~keygen();

    std::string generateSK(int num); //maximum can generate 99 uuids per each secret key
    std::set<std::string> generateEphIDs(std::string secretKey);
    std::string randomPick(std::set<std::string> ephIds);

    std::vector<sha1::close_contact> detactContact(sha1::ContactHistory historyList[], std::string secretkey, int threshold);

private:
    sha1 sha1_generator;
};


#endif //KEYGEN_H
