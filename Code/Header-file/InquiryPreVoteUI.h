#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_STRING 32

using namespace std;

class InquiryPreVoteControl;
class MainUserCollection;
class MainVoteCollection;
class Timer;

class InquiryPreVoteUI{ // ���� ������ ��ǥ���� �����ش�.

	// Class : InquiryPreVoteUI
	// Description: InquiryPreVoteUI Ŭ���� ����. 
	// Created: 2017/5/28
	// Author: ������
	// Revsions : 
	//		When & Who :
	//      What : 

public:
        void startInterface(InquiryPreVoteControl* preVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer);
};
