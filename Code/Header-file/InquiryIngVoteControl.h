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
	// Description: InquiryIngVoteControl Ŭ���� ����. 
	// Created: 2017/5/28
	// Author: ������
	// Revsions : 
	//		When & Who :
	//      What : 


private:
	Vote* voteList[MAX_STRING]; // ��ǥ �������� ������ �ִ� ��ǥ ����Ʈ
	
public:
	Vote* getVote(int voteCount); // �ش� ��ǥ �������� �ҷ��´�.
	void getMenuIndex(InquiryIngVoteUI UserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer); // �������̽��� �������ִ� �Լ�.
};
