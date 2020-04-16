//
// Created by HU Siyan on 13/4/2020.
//

#ifndef KEYGEN_H
#define KEYGEN_H

#include <string>
#include <random>

class keygen {

public:
    keygen();
    ~keygen();

    std::string refreshEphID(unsigned long long timeEpoch, std::string sk);
    std::string detectContact(std::string EphIDs[], std::string sk);
};


#endif //KEYGEN_H
