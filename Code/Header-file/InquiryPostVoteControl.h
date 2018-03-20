#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_STRING 32

using namespace std;

class MainVoteCollection;
class MainUserCollection;
class Vote;
class InquiryPostVoteUI;
class Timer;

class InquiryPostVoteControl{

	// Class : InquiryPostVoteControl
	// Description: InquiryPostVoteControl 클래스 선언. 
	// Created: 2017/5/28
	// Author: 임재형
	// Revsions : 
	//		When & Who :
	//      What : 

private:
	Vote* voteList[MAX_STRING]; // 투표들의 정보들을 가지고 있는 리스트.
	
public:
	Vote* getVote(int voteCount); // 투표정보를 받아오는 함수.
	void getMenuIndex(InquiryPostVoteUI UserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer); // 종료된 투표들을 화면에 출력해주도록 인터페이스에 명령하는 함수.
};
