//
// Created by HU Siyan on 13/4/2020.
//

#ifndef KEYGEN_H
#define KEYGEN_H

#include <string>
#include <random>

class keygen {

public:
    struct KEY {
        std::string uuid;
        unsigned valid_date; //millisecond timestamp
    };

    keygen();
    ~keygen();

    std::string generateSK();

    KEY refreshEphID(unsigned long long timeEpoch, std::string sk);
    std::string detectContact(KEY EphID_list[], std::string sk);
};


#endif //KEYGEN_H
