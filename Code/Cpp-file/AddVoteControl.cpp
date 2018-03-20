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
	// Description: ���ο� ��ǥ �߰� �Լ��� ȣ�����ش�.
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	User* tempUser; // �ӽ� ȸ�� �����ͷ� ���� ������ ȸ���� ����ų ��
	int userCount = userCollect->getUserCount();
	for (int i = 0; i < userCount; i++) {
		if (userCollect->getUser(i)->isSession()) {
			tempUser = userCollect->getUser(i); //���� ������ ȸ���� ����Ų��
		}
	}
	string groupName= tempUser->getGroupCollection()->getGroup(); // �ش� �׷���� �׷� �̸� ������
		voteCollect->addVote(title, itemsize, starttime, finishtime, groupName);
}


void AddVoteControl::getMenuIndex(AddVoteUI addVoteUserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect){

	// Function : getMenuIndex(AddVoteUI addVoteUserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: ���� �߰��� ��ǥ �������� ����� �ֵ��� �������̽� �Լ��� ȣ�����ش�.
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	

	addVoteUserInterface.startInterface(this, userCollect, voteCollect);
}
