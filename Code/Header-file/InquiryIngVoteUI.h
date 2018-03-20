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
	// Description: InquiryIngVoteUI 클래스 선언. 
	// Created: 2017/5/28
	// Author: 임재형
	// Revsions : 
	//		When & Who :
	//      What : 

public:
        void startInterface(InquiryIngVoteControl* ingVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer); // 현재 시간과 비교하여 시작시간이 지나고 종료가 아직되지 않은 진행중인 투표들을 출력하도록 인터페이스에 명령한다.
};
