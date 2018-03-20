#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_STRING 32

using namespace std;

class Vote;
class AddVoteUI;
class MainUserCollection;
class MainVoteCollection;

class AddVoteControl{

	// Class : AddVoteControl
	// Description: AddVoteControl 클래스 선언. 
	// Created: 2017/5/28
	// Author: 임재형
	// Revsions : 
	//		When & Who :
	//      What :

private:
	Vote* vote;
public:
	void addNewVote(string title, int itemsize, string starttime, string finishtime, AddVoteControl* addvote, MainUserCollection* userCollect, MainVoteCollection* voteCollect); //새로운 투표 추가 함수를 호출해준다.
	void getMenuIndex(AddVoteUI addVoteUserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // 새로 추가된 투표 정보들을 출력해 주도록 인터페이스에 함수를 호출해준다.
};
