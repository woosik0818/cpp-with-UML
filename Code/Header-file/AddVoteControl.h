#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_STRING 32

using namespace std;

class Vote;
class AddVoteUI;
class MainUserCollection;
class MainVoteCollection;

class AddVoteControl{

	// Class : AddVoteControl
	// Description: AddVoteControl Ŭ���� ����. 
	// Created: 2017/5/28
	// Author: ������
	// Revsions : 
	//		When & Who :
	//      What :

private:
	Vote* vote;
public:
	void addNewVote(string title, int itemsize, string starttime, string finishtime, AddVoteControl* addvote, MainUserCollection* userCollect, MainVoteCollection* voteCollect); //���ο� ��ǥ �߰� �Լ��� ȣ�����ش�.
	void getMenuIndex(AddVoteUI addVoteUserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // ���� �߰��� ��ǥ �������� ����� �ֵ��� �������̽��� �Լ��� ȣ�����ش�.
};
