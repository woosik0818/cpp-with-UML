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
	// Description: ��ǥ �������� �������̽��� ���� �������̽��� ���� �ð��� ���Ͽ� ����� ��ǥ���� ������ֵ��� �Ѵ�.
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	int voteCount = voteCollect->getVoteCount(); // ��ǥ ������ �޾ƿ´�.

	for(int i = 0; i < voteCount; i++){ // ��ǥ �������� ����Ʈ�� �����Ѵ�.
		voteList[i] = voteCollect->getvote(i);

	}
	UserInterface.startInterface(this, userCollect, voteCollect, timer); // ���� �ð��� ���Ͽ� ����� ��ǥ���� ȭ�鿡 ����ϵ��� �������̽��� ����Ѵ�.
}

Vote* InquiryPostVoteControl::getVote(int voteCount){

	// Function : getVote(int voteCount)
	// Description: ��ǥ �������� ����Ʈ�� ��ȯ�Ѵ�.
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	return voteList[voteCount];
}
