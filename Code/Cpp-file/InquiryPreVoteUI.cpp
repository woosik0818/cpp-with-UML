#include "InquiryPreVoteUI.h"
#include "InquiryPreVoteControl.h"
#include "Vote.h"
#include "TImer.h"
#include "MainUserCollection.h"
#include "MainVoteCollection.h"
#include "User.h"

int calculatePre(string time, string time2) {

	// Function : calculatePre(string time, string time2)
	// Description: ù��° ���ڷ� �޾ƿ� �ð����� �ι�° ���ڷ� �޾ƿ� �ð��� ����
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What 

	string Time = time.substr(0, 4); // ���ο� ������ �Է¹��� ���� ���Ŀ� �°� �߶��ش�.
	Time += time.substr(5, 2);
	Time += time.substr(8, 2);
	Time += time.substr(11, 2);
	int timeInt = atoi(Time.c_str()); // int Ÿ������ �ٲ��ش�.
	Time = time.substr(14); // ������ 2���� ���ڷ� �ʱ�ȭ���ش�.

	string Time2 = time2.substr(0, 4);
	Time2 += time2.substr(5, 2);
	Time2 += time2.substr(8, 2);
	Time2 += time2.substr(11, 2);
	int timeInt2 = atoi(Time2.c_str());
	Time2 = time2.substr(14);

	if (timeInt == timeInt2) { // ������ 2���� ���ڴ� ���� 10�ڸ� ���ڰ� ���� �������� �����ش�.
		return atoi(Time.c_str()) - atoi(Time2.c_str());
	}

	else {
		return timeInt - timeInt2;
	}
}


void InquiryPreVoteUI::startInterface(InquiryPreVoteControl* preVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer) {

	// Function : startInterface(InquiryPreVoteControl* preVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer)
	// Description: �Է¹��� ������ ����ð��� ��ǥ ����Ʈ�� �ִ� ��ǥ���� ���� �ð��� ���Ͽ� ���� ���� ������ ��ǥ���� ������ش�.
	// Created: 2017/5/28
	// Author: ������
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

	User* tempUser; // ���� ������ ������ �����´�.
	for (int i = 0; i < userCollect->getUserCount(); i++) {
		if (userCollect->getUser(i)->isSession()) {
			tempUser = userCollect->getUser(i);
		}
	}
	string groupName = tempUser->getGroupCollection()->getGroup(); // ������ ���� ������ ������ ������ �׷��� �̸��� �����´�.
	int voteCount = voteCollect->getVoteCount(); // �� ��ǥ�� ��� �ִ��� �޾ƿ´�.

	printf("4.3. ���� ���� ������ ��ǥ ����Ʈ\n");
	for (int i = 0; i < voteCount; i++) {
		if (groupName.compare(voteCollect->getvote(i)->getGroupName()) == 0) { // ��ǥ�� ���� �׷��̸��� ������ ���� �׷��̸��� ������ ��ȸ�Ѵ�.
			getstartTime = voteCollect->getvote(i)->getvoteStartTime();
			//string startTime = getstartTime.substr(0, 4);
			//startTime += getstartTime.substr(5, 2);
			//startTime += getstartTime.substr(8, 2);
			//startTime += getstartTime.substr(11, 2);
			//startTime += getstartTime.substr(14);
			//startTimeInt = atoi(startTime.c_str());
			preTime = calculatePre(getcurrentTime, getstartTime); //����ð��� ��ǥ�� ���۽ð��� ���Ѵ�.
			vote = voteCollect->getvote(i);
			if (preTime < 0) {
				printf(" %s %d %s %s\n\n", vote->getvoteTitle().c_str(), vote->getvoteItemSize(), vote->getvoteStartTime().c_str(), vote->getvoteFinishTime().c_str());
			}
		}
	}
}