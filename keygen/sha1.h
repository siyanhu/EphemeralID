//
// Created by HU Siyan on 23/4/2020.
//

#ifndef KEYGEN_SHA1_H
#define KEYGEN_SHA1_H

#include <string>
#include <set>

class sha1 {

public:
    sha1();
    ~sha1();

    struct ContactHistory {
        std::string uuid;
        unsigned long timestamp;
    };

    struct close_contact {
        unsigned long timestamp;
        unsigned duration;
    };

    std::string generateSK(int num); //maximum can generate 99 uuids per each secret key
    std::set<std::string> generateEphIDs(std::string secretKey);
    std::string randomPick(std::set<std::string> ephIds);

    std::vector<sha1::close_contact> detectContact(ContactHistory historyList[], std::string secretkey);
};


#endif //KEYGEN_SHA1_H
