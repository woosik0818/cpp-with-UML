#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_STRING 32

using namespace std;

class InquiryPostVoteControl;
class MainUserCollection;
class MainVoteCollection;
class Timer;

class InquiryPostVoteUI{ // ����� ��ǥ���� �����ش�.

	// Class : InquiryPostVoteUI
	// Description: InquiryPostVoteUI Ŭ���� ����. 
	// Created: 2017/5/28
	// Author: ������
	// Revsions : 
	//		When & Who :
	//      What : 

public:
        void startInterface(InquiryPostVoteControl* postVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer);
};
