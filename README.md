# EphemeralID

1. Secret Key update:
	a. Updating frequency: every 30 days;
	b. Need to provide how many ephemeral ids that you need to generate:
			int num
	c. when you need to update secret Key: call function:
			std::string generateSK(int num)
	d. you need to save locally the following data:
			secret key: string
			timestamp: long, second, the time of generating the secret key.

2. Ephemeral IDs;
	a. Based on the secret key, we can generate num Ephemral IDs.
	b. function 
			std::set<std::string> generateEphIDs(std::string secretKey);
		returns a set of ephemeral ids that users can use to broadcast.
	c. Broadcast ephemeral ids by using:
			std::string randomPick(std::set<std::string> ephIds);
		input the ephemeral ids got in 2.b and output a ephemeral id that contained in the set.
	d. you need to save locally the following data:
			ephemeral id 0;
			ephemeral id 1;
			ephemeral id 2;
			......
	e. all ephemeral ids generated/imported/used will not contain connector "-".

3. Contact detection:
	a. when you receive other people's broadcast message, the message should be saved locally like:
			record no.0: ephemeral id 0, timestamp 0;
			record no.1: ephemeral id 1, timestamp 1;
			record no.2: ephemeral id 2, timestamp 2;
			......
	b. when you received confirmed case's secret keys from server:
			confirmed case's secret key: 
					secret key 0;
					secret key 1;
					secret key 2;
					......
	c. by using function:
			std::string detectContact(ContactHistory historyList[], std::string secretkey)
		you may be able to detect contact;
		input a list of contact history defined by struct:
			ContactHistory {
				std::string uuid;
        		unsigned long timestamp; //time of receiving the ephemeral id
    		};
	d. if there is a close contact record calculated, you will received a string containing the following information:
			"timestamp of receiving the contact uuid: duration"
		all in seconds.