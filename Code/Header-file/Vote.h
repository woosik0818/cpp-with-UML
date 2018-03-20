#include <string>
#define MAX_STRING 32

using namespace std;

class Vote{


private: 
	string groupName;
	string voteTitle;
	string voteStartTime;
	string voteFinishTime;
	string voteRemainingTime;
	int voteCount;
	int voteNum;
	int voteItem[MAX_STRING];
	int voteItemSize;

public: 
	Vote();
	int getvoteItem(int _voteNum){

    		return voteItem[_voteNum];
    	}
    
	int getvoteItemSize(){

		return voteItemSize;
	}

	string getvoteTitle(){

		return voteTitle;
	}

	string getvoteStartTime(){

		return voteStartTime;
	}
	
	string getvoteFinishTime(){

		return voteFinishTime;
	}
	 
	string getvoteRemainingTime(string currentTime);
	
	int getvoteCount(){

		return voteCount;
	}
	
	int getvoteNum(){

		return voteNum;
	}
	void deleteVote();
	void createVote(string _voteTitle, int _voteItemSize, string _voteStartTime, string _voteFinishTime, string _groupName);
	void doVote(string _voteTitle, int _voteNum);
	string getGroupName();
	Vote* getVote(); 
	~Vote() {};
};
