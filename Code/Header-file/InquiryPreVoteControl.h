#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_STRING 32

using namespace std;

class MainVoteCollection;
class MainUserCollection;
class Vote;
class InquiryPreVoteUI;
class Timer;

class InquiryPreVoteControl{

	// Class : InquiryPreVoteControl
	// Description: InquiryPreVoteControl Ŭ���� ����. 
	// Created: 2017/5/28
	// Author: ������
	// Revsions : 
	//		When & Who :
	//      What : 

private:
	Vote* voteList[MAX_STRING]; // ��ǥ �������� ������ �ִ� ��ǥ ����Ʈ
	
public:
	Vote* getVote(int voteCount); // �ش� ��ǥ �������� �ҷ��´�.
	void getMenuIndex(InquiryPreVoteUI UserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer); // �������̽��� �������ִ� �Լ�
};
