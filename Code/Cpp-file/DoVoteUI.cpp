#include "DoVoteUI.h"
#include "DoVoteControl.h"
#include "Vote.h"
#include "MainUserCollection.h"
#include "MainVoteCollection.h"

void DoVoteUI::startInterface(DoVoteControl* doVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect) {
	
	// Function : startInterface(DoVoteControl* doVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: 투표한 투표 정보들을 출력해주고 투표수를 하나 늘리도록 함수를 호출한다.
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	
	
	char title[MAX_STRING];
	int num;

	scanf("%s %d", title, &num);
	clickVote(title, num, doVote, userCollect, voteCollect); // 투표수 올리기 위한 함수 호출

	printf("4.2. 투표 \n");
	printf("> %s %d \n\n", title, num);
}

void DoVoteUI::clickVote(string voteTitle, int voteNum, DoVoteControl* _doVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect) {
	
	// Function : clickVote(string voteTitle, int voteNum, DoVoteControl* _doVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: 투표한 투표의 투표수를 올리기 위하여 DoVoteControl의 함수를 호출한다.
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	
	
	_doVote->doVote(voteTitle, voteNum, _doVote, userCollect, voteCollect);
}