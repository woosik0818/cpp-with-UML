#include "InquiryIngVoteUI.h"
#include "InquiryIngVoteControl.h"
#include "Vote.h"
#include "Timer.h"
#include "MainUserCollection.h"
#include "MainVoteCollection.h"
#include "User.h"

int calculateIng(string time, string time2) {

	// Function : calculateIng(string time, string time2)
	// Description: ù��° ���ڷ� �޾ƿ� �ð����� �ι�° ���ڷ� �޾ƿ� �ð��� ����.
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	string Time = time.substr(0, 4); // ���ο� ������ �Է¹��� ���� ���Ŀ� �°� �߶��ش�.
	Time += time.substr(5, 2);
	Time += time.substr(8, 2);
	Time += time.substr(11, 2);
	int timeInt = atoi(Time.c_str()); // int Ÿ������ �ٲ��ش�.
	Time = time.substr(14); // ������ 2���� ���ڷ� �ʱ�ȭ ���ش�.
	
	string Time2 = time2.substr(0, 4);
	Time2 += time2.substr(5, 2);
	Time2 += time2.substr(8, 2);
	Time2 += time2.substr(11, 2);
	int timeInt2 = atoi(Time2.c_str());
	Time2 = time2.substr(14);

	if (timeInt == timeInt2) { // ������ 2���� ���ڴ� ���� 10�ڸ��� ���ڰ� ���� �������� �����ش�.
		return atoi(Time.c_str()) - atoi(Time2.c_str());
	}
	
	else {
		return timeInt - timeInt2;
	}
}

void InquiryIngVoteUI::startInterface(InquiryIngVoteControl* ingVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer) {

	// Function : startInterface(InquiryIngVoteControl* ingVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer)
	// Description: �Է¹��� ������ ����ð��� ��ǥ ����Ʈ�� �ִ� ��ǥ���� ���۽ð��� ����ð��� ���Ͽ� ���� ���� ��ǥ ���� ����� �ش�. 
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	Vote* vote;
	int pastTime, remainTime;
	//int currentTimeInt, startTimeInt, finishTimeInt;
	string getcurrentTime, getstartTime, getfinishTime;
	getcurrentTime = timer->getCurrentTime();
	string currentTime = getcurrentTime.substr(0, 4);
	currentTime += getcurrentTime.substr(5, 2);
	currentTime += getcurrentTime.substr(8, 2);
	currentTime += getcurrentTime.substr(11, 2);
	currentTime += getcurrentTime.substr(14);
	//currentTimeInt = atoi(currentTime.c_str());

	User* tempUser; // ���� ������ ������ �����´�.
	int userCount = userCollect->getUserCount();
	for (int i = 0; i < userCount; i++) {
		if (userCollect->getUser(i)->isSession()) {
			tempUser = userCollect->getUser(i);
		}
	}
	string groupName = tempUser -> getGroupCollection()->getGroup(); // ������ ���� ������ ������ ������ �׷��� �̸��� �����´�.
	int voteCount = voteCollect->getVoteCount(); // �� ��ǥ�� ��� �ִ��� �޾ƿ´�.

	printf("4.1. ���� ���� ���� ��ǥ ����Ʈ\n");
	for (int i = 0; i < voteCount; i++) {
		if (groupName.compare(voteCollect->getvote(i)->getGroupName()) == 0) { // ��ǥ�� ���� �׷� �̸��� ������ ���� �׷��̸��� ������ ��ȸ�Ѵ�.
			getfinishTime = voteCollect->getvote(i)->getvoteFinishTime();
			//string finishTime = getfinishTime.substr(0, 4);
			//finishTime += getfinishTime.substr(5, 2);
			//finishTime += getfinishTime.substr(8, 2);
			//finishTime += getfinishTime.substr(11, 2);
			//finishTime += getfinishTime.substr(14);
			//finishTimeInt = atoi(finishTime.c_str());

			getstartTime = voteCollect->getvote(i)->getvoteStartTime();
			//string startTime = getstartTime.substr(0, 4);
			//startTime += getstartTime.substr(5, 2);
			//startTime += getstartTime.substr(8, 2);
			//startTime += getstartTime.substr(11, 2);
			//startTime += getstartTime.substr(14);
			//startTimeInt = atoi(startTime.c_str());��
			pastTime = calculateIng(getstartTime, getcurrentTime); // ����ð��� ��ǥ�� ���۽ð��� ���Ѵ�.
			remainTime = calculateIng(getcurrentTime, getfinishTime); // ����ð��� ��ǥ�� ����ð��� ���Ѵ�.
			
			vote = voteCollect->getvote(i);
			if (pastTime <= 0 && remainTime < 0) {
				printf("> %s %d %s\n\n", vote->getvoteTitle().c_str(), vote->getvoteItemSize(), vote->getvoteRemainingTime(currentTime).c_str());
			}

		}
	}

}