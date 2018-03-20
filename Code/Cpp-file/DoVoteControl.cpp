#include "DoVoteControl.h"
#include "Vote.h"
#include "User.h"
#include "DoVoteUI.h"
#include "MainUserCollection.h"
#include "MainVoteCollection.h"


void DoVoteControl::doVote(string title, int votenum, DoVoteControl* dovote, MainUserCollection* userCollect, MainVoteCollection* voteCollect){
	
	// Function : doVote(string title, int votenum, DoVoteControl* dovote, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: 현재 세션의 회원이 가입한 그룹 내의 해당 투표의 투표수를 올려준다.
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	User* tempUser; // 임시 회원 포인터로 현재 세션의 회원을 가리킬 것
	int userCount = userCollect->getUserCount();
	for (int i = 0; i < userCount; i++) {
		if (userCollect->getUser(i)->isSession()) {
			tempUser = userCollect->getUser(i); //현재 세션의 회원을 가리킨다
		}
	}
	string groupName = tempUser->getGroupCollection()->getGroup(); // 해당 그룹원의 그룹 이름 가져옴
	int voteCount = voteCollect->getVoteCount();
	for (int i = 0; i < voteCount; i++) {
		if (groupName.compare(voteCollect->getvote(i)->getGroupName()) == 0) {
			if (title == voteCollect->getvote(i)->getvoteTitle()) {
				voteCollect->getvote(i)->doVote(title, votenum);
			}

		}
	}
}

void DoVoteControl::getMenuIndex(DoVoteUI doVoteUserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect){
	
	// Function : getMenuIndex(DoVoteUI doVoteUserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: 투표한 정보를 출력하도록 인터페이스 함수를 호출해준다.
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	
	doVoteUserInterface.startInterface(this, userCollect, voteCollect);
}
