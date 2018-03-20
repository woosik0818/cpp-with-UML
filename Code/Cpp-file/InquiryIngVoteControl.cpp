#include <stdio.h>
#include <string>
#include "InquiryIngVoteControl.h"
#include "InquiryIngVoteUI.h"
#include "Group.h"
#include "Timer.h"
#include "MainVoteCollection.h"
#include "MainGroupCollection.h"

void InquiryIngVoteControl::getMenuIndex(InquiryIngVoteUI UserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer){


	// Function : getMenuIndex(InquiryIngVoteUI UserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer)
	// Description: �������̽����� startInterface�� �����ϵ��� �Լ� ȣ���� ���ش�.
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	int voteCount = voteCollect->getVoteCount(); // ��ǥ�� ������ �޾ƿ´�.

	for(int i = 0; i < voteCount; i++){ // ��ǥ����Ʈ�� ���� �湮�� ��ǥ ������ �޾ƿ´�.
		voteList[i] = voteCollect->getvote(i);

	}
	UserInterface.startInterface(this, userCollect, voteCollect, timer); // ��ǥ ����Ʈ���� ���� �����ְ� ����ؼ� ����ϵ��� �Լ��� �θ���.
}

Vote* InquiryIngVoteControl::getVote(int voteCount){ // ��ǥ ����Ʈ�� ��ȯ�Ѵ�.

	// Function : getVote(int voteCount)
	// Description: ��ǥ ����Ʈ�� ��ȯ�Ѵ�.
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	return voteList[voteCount];
}
