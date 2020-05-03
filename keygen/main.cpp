#include <iostream>
#include <vector>
#include "keygen.h"

sha1::ContactHistory *createDemoHistorys(){
    sha1::ContactHistory* histories = new sha1::ContactHistory[11];
    sha1::ContactHistory history0;
    history0.timestamp = 1587907816;
    history0.uuid = "5fce0b80c00732a44e014a9001f60516";
    history0.rssi = -50;
    histories[0] = history0;

    sha1::ContactHistory history1;
    history1.timestamp = 1587724901;
    history1.uuid = "97e6d8ac13104c4286deda255b23a325";
    history1.rssi = -55;
    histories[1] = history1;

    sha1::ContactHistory history2;
    history2.timestamp = 1586646058;
    history2.rssi = -80;
    history2.uuid = "97e6d8ac13104c4286deda255b23a325";
    histories[2] = history2;

    sha1::ContactHistory history3;
    history3.timestamp = 1587908856;
    history3.uuid = "8bab376ff176ac7be671bd932a74a4e9";
    history3.rssi = -30;
    histories[3] = history3;

    sha1::ContactHistory history4;
    history4.timestamp = 1587615302;
    history4.uuid = "97e6d8ac13104c4286deda255b23a325";
    history4.rssi = -45;
    histories[4] = history4;

    sha1::ContactHistory history5;
    history5.timestamp = 1587908500;
    history5.uuid = "31c69f866b671081a900aee6a93a520e";
    history5.rssi = 55;
    histories[5] = history5;

    sha1::ContactHistory history6;
    history6.timestamp = 1588080616;
    history6.uuid = "31c69f866b671081a900aee6a93a520e";
    history6.rssi = -65;
    histories[6] = history6;

    sha1::ContactHistory history7;
    history7.timestamp = 1588081616;
    history7.uuid = "97e6d8ac13104c4286deda255b23a325";
    history7.rssi = 37;
    histories[7] = history7;

    sha1::ContactHistory history8;
    history8.timestamp = 1587723600;
    history8.uuid = "97e6d8ac13104c4286deda255b23a325";
    histories[8] = history8;

    sha1::ContactHistory history9;
    history9.timestamp = 1587723900;
    history9.uuid = "97e6d8ac13104c4286deda255b23a325";
    histories[9] = history9;

    sha1::ContactHistory history10;
    history10.timestamp = 1587725990;
    history10.uuid = "5fce0b80c00732a44e014a9001f60516";
    histories[10] = history10;
    return histories;
}

int main(int argc, char *argv[]) {

    keygen generator;
    std::string sk = generator.generateSK(10); // 1 - 99
    std::cout<<"Secret Key: " <<sk<<"\n";
    std::string demoKey = "719a288e3d8550";
    std::cout<<"Demo Secret Key: "<<demoKey<<"\n";

    std::set<std::string> EphIDs = generator.generateEphIDs(sk);
    std::set<std::string>::iterator iter = EphIDs.begin();
    std::cout<<"Ephemeral IDs: " <<"\n";
    while(iter != EphIDs.end()) {
        std::string ephid = *iter;
        std::cout<<"\t"<<ephid<<";\n";
        ++iter;
    }
    std::cout<<"\n";

    std::string pick_one_for_broadcast = generator.randomPick(EphIDs);
    std::cout<<"Broadcast UUIDs: " <<pick_one_for_broadcast<<"\n";
    std::cout<<"\n";

    int size = 11;
    sha1::ContactHistory *histories = new sha1::ContactHistory[size];
    histories = createDemoHistorys();
    std::cout<<"Contact List: \n";
    for (int i = 0; i < size; i++) {
        sha1::ContactHistory new_contact = histories[i];
        std::cout<<"\t"<<new_contact.timestamp<<": "<<new_contact.uuid<<"\n";
    }
    std::cout<<"\n";

    int threshold = 900; //900s
    std::vector<sha1::close_contact> close_contacts = generator.detectContact(histories, size, sk, threshold);
    if (close_contacts.size()) {
        std::cout<<"Close Contact: "<<"\n";
        for(std::vector<sha1::close_contact>::iterator begin = close_contacts.begin();begin!=close_contacts.end();begin++) {
            std::cout<<"\t"<<(*begin).timestamp<<": "<<(*begin).duration<<" - proximity: "<<(*begin).proximity<<"\n";
        }

        std::cout<<"\/end";
    }

    delete[] histories;
}
