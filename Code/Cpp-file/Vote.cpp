#include <stdio.h>
#include <string>
#include "Vote.h"

Vote::Vote() {

	// Function : Vote()
	// Description: 투표들을 초기화 해준다.
	// Created: 2017/5/28
	// Author: 임재형

	voteCount = 0;
	for (int i = 0; i < MAX_STRING; i++) {
		voteItem[i] = 0;
	}
}

void Vote::doVote(string _voteTitle, int _voteNum) {

	// Function : doVote(string _voteTitle, int _voteNum)
	// Description: 투표를 행사한다.
	// Created: 2017/5/28
	// Author: 임재형

	this->voteTitle = _voteTitle; // 투표 주제를 저장한다.
	this->voteNum = _voteNum; // 투표 항목번호를 저장한다.
	this->voteItem[_voteNum - 1]++; // 투표 항목의 투표수를 1 증가 시킨다.
}

void Vote::createVote(string _voteTitle, int _voteItemSize, string _voteStartTime, string _voteFinishTime, string _groupName) {

		// Function : createVote(string _voteTitle, int _voteItemSize, string _voteStartTime, string _voteFinishTime, string _groupName)
	// Description: 투표를 생성한다.
	// Created: 2017/5/28
	// Author: 임재형

	this->voteTitle = _voteTitle; // 투표 주제를 저장한다.
	this->voteItemSize = _voteItemSize; // 투표 항목수를 저장한다.
	this->voteStartTime = _voteStartTime; // 투표 시작시간을 저장한다.
	this->voteFinishTime = _voteFinishTime; // 투표 마감시간을 저장한다.
	this->groupName = _groupName; // 투표가 속한 그룹이름을 저장한다.
	voteCount++; // 총 투표 수를 1 증가시킨다.
}

Vote* Vote::getVote() {

	// Function : getVote()
	// Description: 투표 객체를 반환한다.
	// Created: 2017/5/28
	// Author: 임재형

	return this;
}

string Vote::getGroupName() {

	// Function : getGroupName()
	// Description: 투표가 속한 그룹이름을 반환한다.
	// Created: 2017/5/28
	// Author: 임재형

	return groupName;
}

string Vote::getvoteRemainingTime(string currentTime) {

	// Function : getvoteRemainingTime(string currentTime)
	// Description: 진행중인 투표의 남은시간을 계산하여 반환한다.
	// Created: 2017/5/28
	// Author: 임재형

	string getfinishTime, getcurrentTime, remainingTime;
	int finishYear, finishMonth, finishDate, finishHour, finishMinute;
	int currentYear, currentMonth, currentDate, currentHour, currentMinute;
	int remainingYear, remainingMonth, remainingDate, remainingHour, remainingMinute;
	getfinishTime = this->voteFinishTime;
	string temp;

	temp = getfinishTime.substr(0, 4);
	finishYear = atoi(temp.c_str());
	temp = getfinishTime.substr(5, 2);
	finishMonth = atoi(temp.c_str());
	temp = getfinishTime.substr(8, 2);
	finishDate = atoi(temp.c_str());
	temp = getfinishTime.substr(11, 2);
	finishHour = atoi(temp.c_str());
	temp = getfinishTime.substr(14);
	finishMinute = atoi(temp.c_str());

	temp = getfinishTime.substr(0, 4);
	currentYear = atoi(temp.c_str());
	temp = getfinishTime.substr(5, 2);
	currentMonth = atoi(temp.c_str());
	temp = getfinishTime.substr(8, 2);
	currentDate = atoi(temp.c_str());
	temp = getfinishTime.substr(11, 2);
	currentHour = atoi(temp.c_str());
	temp = getfinishTime.substr(14);
	currentMinute = atoi(temp.c_str());


	remainingYear = currentYear - finishYear;
	remainingMonth = currentMonth - finishMonth;
	remainingDate = currentDate - finishDate;
	remainingHour = currentHour - finishHour;
	remainingMinute = currentMinute - finishMinute;

	remainingTime = to_string(remainingYear);
	remainingTime += ":";
	remainingTime += to_string(remainingMonth);
	remainingTime += ":";
	remainingTime += to_string(remainingDate);
	remainingTime += ":";
	remainingTime += to_string(remainingHour);
	remainingTime += ":";
	remainingTime += to_string(remainingMinute);

	voteRemainingTime = remainingTime;
	return voteRemainingTime;
}

void Vote::deleteVote() {

	// Function : deleteVote()
	// Description: 해당 투표를 소멸 시킨다.
	// Created: 2017/5/28
	// Author: 임재형

	this->~Vote();
}