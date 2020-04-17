#include <iostream>
#include "keygen.h"

int main(int argc, char *argv[]) {

    unsigned long long timeEpoch = 1587039132;
    keygen keygenerator;
    std::string secret_key = keygenerator.generateSK();
    keygen::KEY output;
    output = keygenerator.refreshEphID(timeEpoch, secret_key);

    unsigned long long timeEpoch1 = 1587204610;
    std::string secret_key1 = keygenerator.generateSK();
    keygen::KEY output1;
    output1 = keygenerator.refreshEphID(timeEpoch1, secret_key1);

    keygen::KEY outputs[2];
    outputs[0] = output;
    outputs[1] = output1;

    std::string contact_timeslot = keygenerator.detectContact(outputs, secret_key1);
    if (contact_timeslot.size() <= 1) {
        std::cout<<"There is a contact happend at " + contact_timeslot;
    }

    return 0;
}
