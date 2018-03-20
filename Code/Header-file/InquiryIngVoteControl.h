#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_STRING 32

using namespace std;

class MainVoteCollection;
class MainUserCollection;
class Vote;
class InquiryIngVoteUI;
class Timer;

class InquiryIngVoteControl{

	// Class : InquiryIngVoteControl
	// Description: InquiryIngVoteControl 클래스 선언. 
	// Created: 2017/5/28
	// Author: 임재형
	// Revsions : 
	//		When & Who :
	//      What : 


private:
	Vote* voteList[MAX_STRING]; // 투표 정보들을 가지고 있는 투표 리스트
	
public:
	Vote* getVote(int voteCount); // 해당 투표 정보들을 불러온다.
	void getMenuIndex(InquiryIngVoteUI UserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer); // 인터페이스에 전달해주는 함수.
};
