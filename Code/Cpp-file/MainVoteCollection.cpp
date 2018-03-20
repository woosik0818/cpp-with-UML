#include "MainVoteCollection.h"
#include "Vote.h"

MainVoteCollection::MainVoteCollection(Vote _vote[MAX_STRING]){

	// Function : MainVoteCollection(Vote _vote[MAX_STRING])
	// Description: 투표 리스트들의 주소값을 가져온다.
	// Created: 2017/5/28
	// Author: 임재형

	voteCount = 0;
	for(int i = 0; i < MAX_STRING; i++){
		ownedVote[i] = &_vote[i];
	}
}

void MainVoteCollection::addVote(string _voteTitle, int _voteItemSize, string _voteStartTime, string _voteFinishTime, string _groupName){

	// Function : addVote(string _voteTitle, int _voteItemSize, string _voteStartTime, string _voteFinishTime, string _groupName)
	// Description: 투표들을 추가해 해준다.
	// Created: 2017/5/28
	// Author: 임재형

	string title, startTime, finishTime;
	int itemSize;
	Vote v;
	title = _voteTitle;
	itemSize = _voteItemSize;
	startTime = _voteStartTime;
	finishTime = _voteFinishTime;
	ownedVote[voteCount]->createVote(title, itemSize, startTime, finishTime, _groupName);
	voteCount++;
}


Vote* MainVoteCollection::getvote(int voteCount){

	// Function : getvote(int voteCount)
	// Description: 투표 리스트에서 해당 index의 투표정보를 가져온다.
	// Created: 2017/5/28
	// Author: 임재형	

	return ownedVote[voteCount];
}

int MainVoteCollection::getVoteCount(){

	// Function : getVoteCount()
	// Description: 투표의 index값을 가져온다.
	// Created: 2017/5/28
	// Author: 임재형

	return voteCount;
}

void MainVoteCollection::setVoteCount(int _voteCount){

	// Function : setVoteCount(int _voteCount)
	// Description: 투표의 index값을 설정해 준다.
	// Created: 2017/5/28
	// Author: 임재형

	voteCount = _voteCount;
}

void MainVoteCollection::deletevote(int voteIndex) {

	// Function : deletevote(int voteIndex)
	// Description: 투표들을 삭제 해준다.
	// Created: 2017/5/28
	// Author: 임재형
	// 
	// Revsions : 
	//   1. When & Who : 2007/05/29 by 임재형
	//      What : 포인터값 변경으로만 삭제.

	ownedVote[voteIndex]->deleteVote();
	for (int i = voteIndex; i < this->voteCount; i++)
	{
		ownedVote[i+1] = ownedVote[i];
	}
	voteCount--;
}
