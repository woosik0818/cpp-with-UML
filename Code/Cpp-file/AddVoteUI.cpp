#include "AddVoteUI.h"
#include "AddVoteControl.h"
#include "Vote.h"
#include "Group.h"
#include "MainUserCollection.h"
#include "MainVoteCollection.h"

void AddVoteUI::startInterface(AddVoteControl* addVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect) {
	
	// Function : startInterface(AddVoteControl* addVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: 투표 제안 정보를 출력해준다.
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	
	
	char title[MAX_STRING], startTime[MAX_STRING], finishTime[MAX_STRING];
	int itemSize;
	scanf("%s %d %s %s\n", title, &itemSize, startTime, finishTime);
	createNewVote(title, itemSize, startTime, finishTime, addVote, userCollect, voteCollect); //투표추가 함수를 출력해주도록 한다.

	printf("3.1. 투표 제안\n");
	printf("> %s %d %s %s\n\n", title, itemSize, startTime, finishTime);
}


void AddVoteUI::createNewVote(string title, int itemsize, string starttime, string finishtime, AddVoteControl* addVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect) {
	

	// Function : createNewVote(string title, int itemsize, string starttime, string finishtime, AddVoteControl* addVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: AddVoteControl에 있는 투표 추가 함수를 호출해준다.
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	
	
	addVote->addNewVote(title, itemsize, starttime, finishtime, addVote, userCollect, voteCollect);
}