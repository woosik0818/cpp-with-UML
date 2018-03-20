#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#define MAX_STRING 32

using namespace std;
class Vote;


class MainVoteCollection{

	// Class : MainVoteCollection
	// Description: ��ǥ ����Ʈ�� �������ִ� MainVoteCollection ����
	// Created: 2017/5/28
	// Author: ������

private:
	Vote* ownedVote[MAX_STRING];
	int voteCount;

public:

	MainVoteCollection(Vote vote[MAX_STRING]);
	void addVote(string _voteTitle, int _voteItemSize, string _voteStartTime, string _voteFinishTime, string _groupName);
	Vote* getvote(int voteCount);
	void deletevote(int voteIndex);
	int getVoteCount();
	void setVoteCount(int _voteCount);
};
