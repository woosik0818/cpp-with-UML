#include <stdio.h>
#include <string>
#include "InquiryPostVoteControl.h"
#include "InquiryPostVoteUI.h"
#include "Group.h"
#include "Timer.h"
#include "MainVoteCollection.h"
#include "MainGroupCollection.h"

void InquiryPostVoteControl::getMenuIndex(InquiryPostVoteUI UserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer){

	// Function : getMenuIndex(InquiryPostVoteUI UserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer)
	// Description: 투표 정보들을 인터페이스에 보내 인터페이스가 현재 시간과 비교하여 종료된 투표들을 출력해주도록 한다.
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	int voteCount = voteCollect->getVoteCount(); // 투표 개수를 받아온다.

	for(int i = 0; i < voteCount; i++){ // 투표 정보들을 리스트에 저장한다.
		voteList[i] = voteCollect->getvote(i);

	}
	UserInterface.startInterface(this, userCollect, voteCollect, timer); // 종료 시간과 비교하여 종료된 투표들을 화면에 출력하도록 인터페이스에 명령한다.
}

Vote* InquiryPostVoteControl::getVote(int voteCount){

	// Function : getVote(int voteCount)
	// Description: 투표 정보들을 리스트로 반환한다.
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	return voteList[voteCount];
}
