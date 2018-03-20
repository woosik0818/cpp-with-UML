#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_STRING 32

using namespace std;

class Vote;
class AddVoteControl;
class MainUserCollection;
class MainVoteCollection;

class AddVoteUI{

	// Class : AddVoteUI
	// Description: AddVoteUI Ŭ���� ����. 
	// Created: 2017/5/28
	// Author: ������
	// Revsions : 
	//		When & Who :
	//      What :

public:
	void startInterface(AddVoteControl* addVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // ��ǥ ���������� ������ش�.
	void createNewVote(string title, int itemsize, string starttime, string finishtime, AddVoteControl* addVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // AddVoteControl�� �ִ� ��ǥ �߰� �Լ��� ȣ�����ش�.
};
