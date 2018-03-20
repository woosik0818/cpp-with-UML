#include "AddVoteUI.h"
#include "AddVoteControl.h"
#include "Vote.h"
#include "Group.h"
#include "MainUserCollection.h"
#include "MainVoteCollection.h"

void AddVoteUI::startInterface(AddVoteControl* addVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect) {
	
	// Function : startInterface(AddVoteControl* addVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: ��ǥ ���� ������ ������ش�.
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	
	
	char title[MAX_STRING], startTime[MAX_STRING], finishTime[MAX_STRING];
	int itemSize;
	scanf("%s %d %s %s\n", title, &itemSize, startTime, finishTime);
	createNewVote(title, itemSize, startTime, finishTime, addVote, userCollect, voteCollect); //��ǥ�߰� �Լ��� ������ֵ��� �Ѵ�.

	printf("3.1. ��ǥ ����\n");
	printf("> %s %d %s %s\n\n", title, itemSize, startTime, finishTime);
}


void AddVoteUI::createNewVote(string title, int itemsize, string starttime, string finishtime, AddVoteControl* addVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect) {
	

	// Function : createNewVote(string title, int itemsize, string starttime, string finishtime, AddVoteControl* addVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: AddVoteControl�� �ִ� ��ǥ �߰� �Լ��� ȣ�����ش�.
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	
	
	addVote->addNewVote(title, itemsize, starttime, finishtime, addVote, userCollect, voteCollect);
}