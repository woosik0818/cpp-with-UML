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

class InquiryPreVoteUI{ // 진행 예정인 투표들을 보여준다.

	// Class : InquiryPreVoteUI
	// Description: InquiryPreVoteUI 클래스 선언. 
	// Created: 2017/5/28
	// Author: 임재형
	// Revsions : 
	//		When & Who :
	//      What : 

public:
        void startInterface(InquiryPreVoteControl* preVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer);
};
