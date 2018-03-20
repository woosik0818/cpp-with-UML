#include "Vote.h"
#include "User.h"
#include "Group.h"
#include "AddVoteUI.h"
#include "AddVoteControl.h"
#include "MainUserCollection.h"
#include "GroupCollection.h"
#include "MainVoteCollection.h"

void AddVoteControl::addNewVote(string title, int itemsize, string starttime, string finishtime, AddVoteControl* addvote, MainUserCollection* userCollect, MainVoteCollection* voteCollect){
	
	// Function : addNewVote(string title, int itemsize, string starttime, string finishtime, AddVoteControl* addvote, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: 새로운 투표 추가 함수를 호출해준다.
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
	string groupName= tempUser->getGroupCollection()->getGroup(); // 해당 그룹원의 그룹 이름 가져옴
		voteCollect->addVote(title, itemsize, starttime, finishtime, groupName);
}


void AddVoteControl::getMenuIndex(AddVoteUI addVoteUserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect){

	// Function : getMenuIndex(AddVoteUI addVoteUserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: 새로 추가된 투표 정보들을 출력해 주도록 인터페이스 함수를 호출해준다.
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	addVoteUserInterface.startInterface(this, userCollect, voteCollect);
}
