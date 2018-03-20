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
	// Description: InquiryPostVoteControl Ŭ���� ����. 
	// Created: 2017/5/28
	// Author: ������
	// Revsions : 
	//		When & Who :
	//      What : 

private:
	Vote* voteList[MAX_STRING]; // ��ǥ���� �������� ������ �ִ� ����Ʈ.
	
public:
	Vote* getVote(int voteCount); // ��ǥ������ �޾ƿ��� �Լ�.
	void getMenuIndex(InquiryPostVoteUI UserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer); // ����� ��ǥ���� ȭ�鿡 ������ֵ��� �������̽��� ����ϴ� �Լ�.
};
