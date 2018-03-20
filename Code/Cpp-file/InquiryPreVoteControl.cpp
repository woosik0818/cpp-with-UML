#include <stdio.h>
#include <string>
#include "InquiryPreVoteControl.h"
#include "InquiryPreVoteUI.h"
#include "Group.h"
#include "Timer.h"
#include "MainVoteCollection.h"
#include "MainGroupCollection.h"

void InquiryPreVoteControl::getMenuIndex(InquiryPreVoteUI UserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer){

	// Function : getMenuIndex(InquiryPreVoteUI UserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer)
	// Description: 인터페이스에서 startInterface를 실행하도록 함수 호출을 해준다.
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	int voteCount = voteCollect->getVoteCount(); // 투표의 개수를 받아온다.

	for(int i = 0; i < voteCount; i++){ // 투표리스트를 전부 방문해 투표 정보를 받아온다.
		voteList[i] = voteCollect->getvote(i);
	}
	UserInterface.startInterface(this, userCollect, voteCollect, timer); // 투표 리스트를 전부 보내주고 계산해서 출력하도록 함수를 부른다.
}

Vote* InquiryPreVoteControl::getVote(int voteCount){ 

	// Function : getVote(int voteCount)
	// Description: 투표 리스트를 반환한다
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	return voteList[voteCount];
}
