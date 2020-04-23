#include <iostream>
#include "keygen.h"

sha1::ContactHistory *createDemoHistorys(){
    sha1::ContactHistory* histories = new sha1::ContactHistory[8];
    sha1::ContactHistory history0;
    history0.timestamp = 1587081600;
    history0.uuid = "3f61abcc4b29489ab84a759f9713bb2e";
    histories[0] = history0;

    sha1::ContactHistory history1;
    history1.timestamp = 1586648058;
    history1.uuid = "2fbd145d6eb0f034fd2da621e3c3f0b4";
    histories[1] = history1;

    sha1::ContactHistory history2;
    history2.timestamp = 1586646058;
    history2.uuid = "a224ededa16648a7af1f8e2eabf64991";
    histories[2] = history2;

    sha1::ContactHistory history3;
    history3.timestamp = 1587614521;
    history3.uuid = "8bab376ff176ac7be671bd932a74a4e9";
    histories[3] = history3;

    sha1::ContactHistory history4;
    history4.timestamp = 1587615302;
    history4.uuid = "963e9b127c7b1d5995807a2da68cea7d";
    histories[4] = history4;

    sha1::ContactHistory history5;
    history5.timestamp = 1587615902;
    history5.uuid = "5fce0b80c00732a44e014a9001f60516";
    histories[5] = history5;

    sha1::ContactHistory history6;
    history6.timestamp = 1587616900;
    history6.uuid = "5fce0b80c00732a44e014a9001f60516";
    histories[6] = history6;

    sha1::ContactHistory history7;
    history7.timestamp = 1587613000;
    history7.uuid = "5fce0b80c00732a44e014a9001f60516";
    histories[7] = history7;
    return histories;
}

int main(int argc, char *argv[]) {
    keygen generator;
    std::string sk = generator.generateSK(10);
    std::cout<<"Secret Key: " <<sk<<"\n";
    std::string demoKey = "719a288e3d8510";
    std::cout<<"Demo Secret Key: "<<demoKey<<"\n";

    std::set<std::string> EphIDs = generator.generateEphIDs(demoKey);
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

    sha1::ContactHistory *histories = new sha1::ContactHistory[8];
    histories = createDemoHistorys();
    std::cout<<"Contact List: \n";
    for (int i = 0; i < sizeof(histories); i++) {
        sha1::ContactHistory new_contact = histories[i];
        std::cout<<new_contact.timestamp<<": "<<new_contact.uuid<<"\n";
    }
    std::cout<<"\n";

    std::string close_contact = generator.detactContact(histories, sk);
    std::cout<<"Contact history: " <<close_contact<<"\n";
    std::cout<<"\/end";

    delete[] histories;
}
