#include "DoVoteControl.h"
#include "Vote.h"
#include "User.h"
#include "DoVoteUI.h"
#include "MainUserCollection.h"
#include "MainVoteCollection.h"


void DoVoteControl::doVote(string title, int votenum, DoVoteControl* dovote, MainUserCollection* userCollect, MainVoteCollection* voteCollect){
	
	// Function : doVote(string title, int votenum, DoVoteControl* dovote, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: ���� ������ ȸ���� ������ �׷� ���� �ش� ��ǥ�� ��ǥ���� �÷��ش�.
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
	string groupName = tempUser->getGroupCollection()->getGroup(); // �ش� �׷���� �׷� �̸� ������
	int voteCount = voteCollect->getVoteCount();
	for (int i = 0; i < voteCount; i++) {
		if (groupName.compare(voteCollect->getvote(i)->getGroupName()) == 0) {
			if (title == voteCollect->getvote(i)->getvoteTitle()) {
				voteCollect->getvote(i)->doVote(title, votenum);
			}

		}
	}
}

void DoVoteControl::getMenuIndex(DoVoteUI doVoteUserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect){
	
	// Function : getMenuIndex(DoVoteUI doVoteUserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: ��ǥ�� ������ ����ϵ��� �������̽� �Լ��� ȣ�����ش�.
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who :
	//      What : 	
	doVoteUserInterface.startInterface(this, userCollect, voteCollect);
}
