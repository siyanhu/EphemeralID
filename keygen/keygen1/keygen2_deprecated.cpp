//
// Created by HU Siyan on 17/4/2020.
//

#include <iostream>
#include <sstream>
#include <math.h>
#include "../keygen.h"

struct UUID {
    std::string FLAG; //2 hex
    std::string timeEpoch; //8 hex
    std::string valid_period; //4
    std::string encrypted_sk; //22 hex
};

static std::string verify_code = "ce";
static std::string passbook = "60e447480faf4e7d";

keygen::keygen() {}
keygen::~keygen() {}

// timestamp Encryption
unsigned long long decompileUnsignedLL(std::string content) {
    unsigned long long num;
    const char *hexchar = content.c_str();
    num = strtoull(hexchar, NULL, 16);
    return num;
}

unsigned decompileUnsigned(std::string content) {
    unsigned num;
    const char *hexchar = content.c_str();
    num = strtoull(hexchar, NULL, 16);
    return num;
}

std::string compileUnsignedLL(unsigned long long content) {
    char buff[100];
    snprintf(buff, sizeof(buff), "%llx", content);
    std::string buffAsStdStr = buff;
    return buffAsStdStr;
}

std::string compileUnsigned(unsigned content) {
    char buff[100];
    snprintf(buff, sizeof(buff), "%llx", content);
    std::string buffAsStdStr = buff;
    return buffAsStdStr;
}

int get_length(unsigned long long x) {
    using namespace std;
    int leng=0;
    while(x) {
        x/=10;
        leng++;
    }
    return leng;
}


int generatePeriod () {
    int v1 = rand() % 10000;
    return v1;
}

// SK Generation
std::string convertToString(char* a, int size) {
    int i;
    std::string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

std::string ranHex(int length) {
    char str[length];
    //hexadecimal characters
    char hex_characters[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    int i;
    for(i=0;i<length;i++) {
        str[i]=hex_characters[rand()%16];
    }
    std::string rslt = convertToString(str, length);
    return rslt;
}

// sk encryption
int hex2Integer(char hex) {
    unsigned int x;
    std::stringstream ss;
    ss << std::hex << hex;
    ss >> x;
}

std::string encryptionSK(std::string sk) {
    return sk;
}

std::string decryptionSK(std::string content) {
    return content;
}

// Decompile interface
unsigned long long compareContact(std::string EphId, std::string sk) {
    std::string newEph = EphId;
    newEph.erase(std::remove(newEph.begin(), newEph.end(), '-'), newEph.end());
    if (newEph.size() < 32)
        return 0;

    std::string masterkey = newEph.substr(10,22);
    std::string timeEpoch = newEph.substr(2, 8);
    std::string decrypted_masterKye = decryptionSK(masterkey);
    if (decrypted_masterKye.compare(sk) == 0) {
        return decompileUnsignedLL(timeEpoch);
    }
    return 0;
}

// Public functions
std::string keygen::generateSK() {
    std::string sk = ranHex(22);
    return sk;
}

keygen::KEY keygen::refreshEphID(unsigned long long timeEpoch, std::string sk) {

    unsigned long long format_TE = timeEpoch;
    int te_length = get_length(format_TE);
    if (te_length > 10) {
        format_TE = format_TE / pow(10,(te_length - 10));
    } else if (te_length < 10) {
        format_TE = format_TE * pow(10,(10 - te_length));
    }

    UUID uuid;
    uuid.FLAG = verify_code;
    uuid.timeEpoch = compileUnsignedLL(format_TE);

    int period = generatePeriod();
    uuid.valid_period = compileUnsigned(period);
    uuid.encrypted_sk = encryptionSK(sk);

    std::string uuid_str = uuid.FLAG + uuid.timeEpoch + uuid.encrypted_sk;
    KEY key;
    key.uuid = uuid_str.insert(8, 1, '-').insert(13, 1, '-').insert(18, 1, '-').insert(23, 1, '-');
    key.valid_date = timeEpoch + period;
    return key;
}

std::string keygen::detectContact(std::string EphID_list[], std::string sk, int threshold) {
    int size = sizeof(EphID_list);
    int  i = 0;
    std::string confirmed[100];

    unsigned long long firstMet = 0;
    unsigned long long lastMet = 0;
    std::string matched_EphID;
    bool haveCloseContact = false;

    for (int i = 0; i < size; i++) {
        std::string key = EphID_list[i];
        unsigned long long date = compareContact(key, sk);
        if (date != 0) {

            if (firstMet == 0) {
                firstMet = date;
                lastMet = date;
                matched_EphID = key;
            } else {
                if (date>lastMet)
                    lastMet = date;
            }

            if (lastMet - firstMet > threshold) {
                haveCloseContact = true;
                break;
            }
        }
    }
    if (haveCloseContact) {
        if (matched_EphID.size() >= 32) {
            unsigned long long date = compareContact(matched_EphID, sk);
            std::string date_str = std::to_string(date);

            std::cout<<date_str;
            return date_str;
        }
    }

    return "";
}