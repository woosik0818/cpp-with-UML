#include "InquiryPostVoteUI.h"
#include "InquiryPostVoteControl.h"
#include "Vote.h"
#include "Timer.h"
#include "MainUserCollection.h"
#include "MainVoteCollection.h"
#include "User.h"

int calculatePast(string time, string time2) {

	// Function : calculatePast(string time, string time2)
	// Description: 
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	string Time = time.substr(0, 4);
	Time += time.substr(5, 2);
	Time += time.substr(8, 2);
	Time += time.substr(11, 2);
	int timeInt = atoi(Time.c_str());
	Time = time.substr(14);

	string Time2 = time2.substr(0, 4);
	Time2 += time2.substr(5, 2);
	Time2 += time2.substr(8, 2);
	Time2 += time2.substr(11, 2);
	int timeInt2 = atoi(Time2.c_str());
	Time2 = time2.substr(14);

	if (timeInt == timeInt2) {
		return atoi(Time.c_str()) - atoi(Time2.c_str());
	}

	else {
		return timeInt - timeInt2;
	}
}



void InquiryPostVoteUI::startInterface(InquiryPostVoteControl* postVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer) {
	

	// Function : startInterface(InquiryPostVoteControl* postVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer)
	// Description: 입력받은 정보로 현재시간과 투표 리스트에 있는 투표들의 끝난 시간을 비교하여 종료된 투표들을 출력해 준다.
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	


	Vote* vote;
	int pastTime;
	//int currentTimeInt, finishTimeInt;
	string getcurrentTime, getfinishTime;
	getcurrentTime = timer->getCurrentTime();
	string currentTime = getcurrentTime.substr(0, 4);
	currentTime += getcurrentTime.substr(5, 2);
	currentTime += getcurrentTime.substr(8, 2);
	currentTime += getcurrentTime.substr(11, 2);
	currentTime += getcurrentTime.substr(14);
	//currentTimeInt = atoi(currentTime.c_str());

	User* tempUser;
	for (int i = 0; i < userCollect->getUserCount(); i++) {
		if (userCollect->getUser(i)->isSession()) {
			tempUser = userCollect->getUser(i);
		}
	}
	string groupName = tempUser->getGroupCollection()->getGroup();
	int voteCount = voteCollect->getVoteCount();

	printf("4.4. 종료된 투표 리스트\n");
	for (int i = 0; i < voteCount; i++) {
		if (groupName.compare(voteCollect->getvote(i)->getGroupName()) == 0) {
			getfinishTime = voteCollect->getvote(i)->getvoteFinishTime();
			//string finishTime = getfinishTime.substr(0, 4);
			//finishTime += getfinishTime.substr(5, 2);
			//finishTime += getfinishTime.substr(8, 2);
			//finishTime += getfinishTime.substr(11, 2);
			//finishTime += getfinishTime.substr(14);
			//finishTimeInt = atoi(finishTime.c_str());
			pastTime = calculatePast(getfinishTime, getcurrentTime);
			vote = voteCollect->getvote(i);
			
			if (pastTime < 0) {
				printf("> %s", vote->getvoteTitle().c_str());
				for (int j = 0; j < vote->getvoteItemSize(); j++) {
					printf(" %d:%d", j + 1, vote->getvoteItem(j));
				}
			}
		}
	}
	printf("\n");

}