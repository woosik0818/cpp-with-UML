#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_STRING 32

using namespace std;

class InquiryIngVoteControl;
class MainUserCollection;
class MainVoteCollection;
class Timer;

class InquiryIngVoteUI{

	// Class : InquiryIngVoteUI
	// Description: InquiryIngVoteUI Ŭ���� ����. 
	// Created: 2017/5/28
	// Author: ������
	// Revsions : 
	//		When & Who :
	//      What : 

public:
        void startInterface(InquiryIngVoteControl* ingVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer); // ���� �ð��� ���Ͽ� ���۽ð��� ������ ���ᰡ �������� ���� �������� ��ǥ���� ����ϵ��� �������̽��� ����Ѵ�.
};
