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
	// Description: DoVoteUI 클래스 선언. 
	// Created: 2017/5/28
	// Author: 임재형
	// Revsions : 
	//		When & Who :
	//      What : 

public:
    void startInterface(DoVoteControl* doVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // 투표 한 정보를 출력해준다.
	void clickVote(string voteTitle, int voteNum, DoVoteControl* doVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // 투표한 투표에 투표수를 올려주도록 DoVoteControl에 있는 함수를 호출한다.
};
