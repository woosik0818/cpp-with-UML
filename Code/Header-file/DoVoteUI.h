#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_STRING 32

using namespace std;
class MainVoteCollection;
class MainUserCollection;
class DoVoteControl;

class DoVoteUI{

	// Class : DoVoteUI
	// Description: DoVoteUI Ŭ���� ����. 
	// Created: 2017/5/28
	// Author: ������
	// Revsions : 
	//		When & Who :
	//      What : 

public:
    void startInterface(DoVoteControl* doVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // ��ǥ �� ������ ������ش�.
	void clickVote(string voteTitle, int voteNum, DoVoteControl* doVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // ��ǥ�� ��ǥ�� ��ǥ���� �÷��ֵ��� DoVoteControl�� �ִ� �Լ��� ȣ���Ѵ�.
};
