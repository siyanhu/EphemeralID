#include <iostream>
#include "../keygen.h"

int main(int argc, char *argv[]) {

//    unsigned long long timeEpoch = 1587039132;
    unsigned long long timeEpoch = 1587259998075313;
    keygen keygenerator;
    std::string secret_key = keygenerator.generateSK();
    keygen::KEY output;
    output = keygenerator.refreshEphID(timeEpoch, secret_key);

    unsigned long long timeEpoch1 = 1587259254;
    std::string secret_key1 = keygenerator.generateSK();
    keygen::KEY output1;
    output1 = keygenerator.refreshEphID(timeEpoch1, secret_key1);

    unsigned long long timeEpoch2 = 1587473473;
    std::string secret_key2 = secret_key1;
    keygen::KEY output2;
    output2 = keygenerator.refreshEphID(timeEpoch2, secret_key2);

    std::string outputs[3];
    outputs[0] = output.uuid;
    outputs[1] = output1.uuid;
    outputs[2] = output2.uuid;

    std::string contact_timeslot = keygenerator.detectContact(outputs, secret_key1, 900); // 15min
    if (contact_timeslot.size() <= 1) {
        std::cout<<"There is a contact happend at " + contact_timeslot;
    }

    return 0;
}
