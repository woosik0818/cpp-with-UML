#include <string>

using namespace std;

class DoVoteUI;
class MainUserCollection;
class MainVoteCollection;
class DoVoteControl{

	// Class : DoVoteControl
	// Description: DoVoteControl Ŭ���� ����. 
	// Created: 2017/5/28
	// Author: ������
	// Revsions : 
	//		When & Who :
	//      What : 

public:
	void doVote(string title, int votenum, DoVoteControl* dovote, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // ���� ������ ȸ���� ������ �׷쳻�� �ش� ��ǥ�� ��ǥ���� �÷��ش�.
	void getMenuIndex(DoVoteUI doVoteUserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // ��ǥ�� ������ ����ϵ��� �������̽��� �Լ��� ȣ�����ش�.
};

