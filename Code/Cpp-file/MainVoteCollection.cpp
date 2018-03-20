#include "MainVoteCollection.h"
#include "Vote.h"

MainVoteCollection::MainVoteCollection(Vote _vote[MAX_STRING]){

	// Function : MainVoteCollection(Vote _vote[MAX_STRING])
	// Description: ��ǥ ����Ʈ���� �ּҰ��� �����´�.
	// Created: 2017/5/28
	// Author: ������

	voteCount = 0;
	for(int i = 0; i < MAX_STRING; i++){
		ownedVote[i] = &_vote[i];
	}
}

void MainVoteCollection::addVote(string _voteTitle, int _voteItemSize, string _voteStartTime, string _voteFinishTime, string _groupName){

	// Function : addVote(string _voteTitle, int _voteItemSize, string _voteStartTime, string _voteFinishTime, string _groupName)
	// Description: ��ǥ���� �߰��� ���ش�.
	// Created: 2017/5/28
	// Author: ������

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
	// Description: ��ǥ ����Ʈ���� �ش� index�� ��ǥ������ �����´�.
	// Created: 2017/5/28
	// Author: ������	

	return ownedVote[voteCount];
}

int MainVoteCollection::getVoteCount(){

	// Function : getVoteCount()
	// Description: ��ǥ�� index���� �����´�.
	// Created: 2017/5/28
	// Author: ������

	return voteCount;
}

void MainVoteCollection::setVoteCount(int _voteCount){

	// Function : setVoteCount(int _voteCount)
	// Description: ��ǥ�� index���� ������ �ش�.
	// Created: 2017/5/28
	// Author: ������

	voteCount = _voteCount;
}

void MainVoteCollection::deletevote(int voteIndex) {

	// Function : deletevote(int voteIndex)
	// Description: ��ǥ���� ���� ���ش�.
	// Created: 2017/5/28
	// Author: ������
	// 
	// Revsions : 
	//   1. When & Who : 2007/05/29 by ������
	//      What : �����Ͱ� �������θ� ����.

	ownedVote[voteIndex]->deleteVote();
	for (int i = voteIndex; i < this->voteCount; i++)
	{
		ownedVote[i+1] = ownedVote[i];
	}
	voteCount--;
}
