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

    enum SignalLevel {
        Near, //<50
        Medium, //50-60
        Distant, //60-70
        Unknown
    };

    struct ContactHistory {
        std::string uuid;
        unsigned long timestamp;
        int rssi;
    };

    struct close_contact {
        unsigned long timestamp;
        unsigned duration;
        std::string proximity;
    };

    std::string generateSK(int num); //maximum can generate 99 uuids per each secret key
    std::set<std::string> generateEphIDs(std::string secretKey);
    std::string randomPick(std::set<std::string> ephIds);

    std::vector<sha1::close_contact> detectContact(sha1::ContactHistory *historyList, int historyCount, std::string secretkey, int threshold);
};


#endif //KEYGEN_SHA1_H
