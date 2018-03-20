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

class InquiryPostVoteUI{ // 종료된 투표들을 보여준다.

	// Class : InquiryPostVoteUI
	// Description: InquiryPostVoteUI 클래스 선언. 
	// Created: 2017/5/28
	// Author: 임재형
	// Revsions : 
	//		When & Who :
	//      What : 

public:
        void startInterface(InquiryPostVoteControl* postVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer);
};
