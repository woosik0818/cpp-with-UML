#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_STRING 32

using namespace std;

class Vote;
class AddVoteControl;
class MainUserCollection;
class MainVoteCollection;

class AddVoteUI{

	// Class : AddVoteUI
	// Description: AddVoteUI 클래스 선언. 
	// Created: 2017/5/28
	// Author: 임재형
	// Revsions : 
	//		When & Who :
	//      What :

public:
	void startInterface(AddVoteControl* addVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // 투표 제안정보를 출력해준다.
	void createNewVote(string title, int itemsize, string starttime, string finishtime, AddVoteControl* addVote, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // AddVoteControl에 있는 투표 추가 함수를 호출해준다.
};
