#include <string>

using namespace std;

class DoVoteUI;
class MainUserCollection;
class MainVoteCollection;
class DoVoteControl{

	// Class : DoVoteControl
	// Description: DoVoteControl 클래스 선언. 
	// Created: 2017/5/28
	// Author: 임재형
	// Revsions : 
	//		When & Who :
	//      What : 

public:
	void doVote(string title, int votenum, DoVoteControl* dovote, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // 현재 세션의 회원이 가입한 그룹내의 해당 투표의 투표수를 올려준다.
	void getMenuIndex(DoVoteUI doVoteUserInterface, MainUserCollection* userCollect, MainVoteCollection* voteCollect); // 투표한 정보를 출력하도록 인터페이스의 함수를 호출해준다.
};

