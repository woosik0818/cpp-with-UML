#include "InquiryPreVoteUI.h"
#include "InquiryPreVoteControl.h"
#include "Vote.h"
#include "TImer.h"
#include "MainUserCollection.h"
#include "MainVoteCollection.h"
#include "User.h"

int calculatePre(string time, string time2) {

	// Function : calculatePre(string time, string time2)
	// Description: 첫번째 인자로 받아온 시간에서 두번째 인자로 받아온 시간을 뺀다
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What 

	string Time = time.substr(0, 4); // 새로운 변수에 입력받은 값을 형식에 맞게 잘라준다.
	Time += time.substr(5, 2);
	Time += time.substr(8, 2);
	Time += time.substr(11, 2);
	int timeInt = atoi(Time.c_str()); // int 타입으로 바꿔준다.
	Time = time.substr(14); // 마지막 2개의 숫자로 초기화해준다.

	string Time2 = time2.substr(0, 4);
	Time2 += time2.substr(5, 2);
	Time2 += time2.substr(8, 2);
	Time2 += time2.substr(11, 2);
	int timeInt2 = atoi(Time2.c_str());
	Time2 = time2.substr(14);

	if (timeInt == timeInt2) { // 마지막 2개의 숫자는 앞의 10자리 숫자가 서로 같을때만 비교해준다.
		return atoi(Time.c_str()) - atoi(Time2.c_str());
	}

	else {
		return timeInt - timeInt2;
	}
}


void InquiryPreVoteUI::startInterface(InquiryPreVoteControl* preVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer) {

	// Function : startInterface(InquiryPreVoteControl* preVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer)
	// Description: 입력받은 정보로 현재시간과 투표 리스트에 있는 투표들의 시작 시간을 비교하여 향후 진행 예정인 투표들을 출력해준다.
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What 

	Vote* vote;
	int preTime;
	//int currentTimeInt, startTimeInt;
	string getcurrentTime, getstartTime, getfinishTime;
	getcurrentTime = timer->getCurrentTime();
	string currentTime = getcurrentTime.substr(0, 4);
	currentTime += getcurrentTime.substr(5, 2);
	currentTime += getcurrentTime.substr(8, 2);
	currentTime += getcurrentTime.substr(11, 2);
	currentTime += getcurrentTime.substr(14);
	//currentTimeInt = atoi(currentTime.c_str());

	User* tempUser; // 현재 유저의 정보를 가져온다.
	for (int i = 0; i < userCollect->getUserCount(); i++) {
		if (userCollect->getUser(i)->isSession()) {
			tempUser = userCollect->getUser(i);
		}
	}
	string groupName = tempUser->getGroupCollection()->getGroup(); // 가져온 유저 정보로 유저가 가입한 그룹의 이름을 가져온다.
	int voteCount = voteCollect->getVoteCount(); // 총 투표가 몇개가 있는지 받아온다.

	printf("4.3. 향후 진행 예정인 투표 리스트\n");
	for (int i = 0; i < voteCount; i++) {
		if (groupName.compare(voteCollect->getvote(i)->getGroupName()) == 0) { // 투표가 속한 그룹이름과 유저가 속한 그룹이름이 같으면 조회한다.
			getstartTime = voteCollect->getvote(i)->getvoteStartTime();
			//string startTime = getstartTime.substr(0, 4);
			//startTime += getstartTime.substr(5, 2);
			//startTime += getstartTime.substr(8, 2);
			//startTime += getstartTime.substr(11, 2);
			//startTime += getstartTime.substr(14);
			//startTimeInt = atoi(startTime.c_str());
			preTime = calculatePre(getcurrentTime, getstartTime); //현재시간과 투표의 시작시간을 비교한다.
			vote = voteCollect->getvote(i);
			if (preTime < 0) {
				printf(" %s %d %s %s\n\n", vote->getvoteTitle().c_str(), vote->getvoteItemSize(), vote->getvoteStartTime().c_str(), vote->getvoteFinishTime().c_str());
			}
		}
	}
}