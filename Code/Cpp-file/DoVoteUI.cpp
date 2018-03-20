#include "DoVoteUI.h"
#include "DoVoteControl.h"
#include "Vote.h"
#include "MainUserCollection.h"
#include "MainVoteCollection.h"

void DoVoteUI::startInterface(DoVoteControl* doVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect) {
	
	// Function : startInterface(DoVoteControl* doVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: ��ǥ�� ��ǥ �������� ������ְ� ��ǥ���� �ϳ� �ø����� �Լ��� ȣ���Ѵ�.
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	
	
	char title[MAX_STRING];
	int num;

	scanf("%s %d", title, &num);
	clickVote(title, num, doVote, userCollect, voteCollect); // ��ǥ�� �ø��� ���� �Լ� ȣ��

	printf("4.2. ��ǥ \n");
	printf("> %s %d \n\n", title, num);
}

void DoVoteUI::clickVote(string voteTitle, int voteNum, DoVoteControl* _doVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect) {
	
	// Function : clickVote(string voteTitle, int voteNum, DoVoteControl* _doVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: ��ǥ�� ��ǥ�� ��ǥ���� �ø��� ���Ͽ� DoVoteControl�� �Լ��� ȣ���Ѵ�.
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	
	
	_doVote->doVote(voteTitle, voteNum, _doVote, userCollect, voteCollect);
}