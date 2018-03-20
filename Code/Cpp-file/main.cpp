#include<iostream>
#include<string>
#include "User.h"
#include "Group.h"
#include "Vote.h"
#include "Timer.h"

// ȸ�� ���� ��� ����
#include "RegisterUI.h"
#include "RegisterControl.h"
#include "UnRegisterUI.h"
#include "UnRegisterControl.h"
#include "LoginUI.h"
#include "LoginControl.h"
#include "LogoutUI.h"
#include "LogoutControl.h"


// �׷� ���� ��� ����
#include "GroupCreateControl.h"
#include "GroupCreateUI.h"
#include "GroupJoinControl.h"
#include "GroupJoinUI.h"
#include "GroupListControl.h"
#include "GroupListUI.h"
#include "SetCurrentTimeControl.h"
#include "SetCurrentTimeUI.h"
#include "AutoDeleteControl.h"
#include "AutoDeleteUI.h"
#include "CheckGroupListControl.h"
#include "CheckGroupListUI.h"
#include "LeaveGroupControl.h"
#include "LeaveGroupUI.h"

// ��ǥ ���� ��� ����
#include "AddVoteControl.h"
#include "AddVoteUI.h"
#include "DoVoteControl.h"
#include "DoVoteUI.h"
#include "InquiryIngVoteUI.h"
#include "InquiryIngVoteControl.h"
#include "InquiryPreVoteControl.h"
#include "InquiryPreVoteUI.h"
#include "InquiryPostVoteControl.h"
#include "InquiryPostVoteUI.h"

#include "MainUserCollection.h" //  ��ü ��������Ʈ�� ������ �ִ� Ŭ����
#include "MainGroupCollection.h" // ��ü �׷츮��Ʈ�� ������ �ִ� Ŭ����
#include "MainVoteCollection.h" // ��ü ��ǥ����Ʈ�� ������ �ִ� Ŭ����

using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"


void doTask(MainUserCollection* userCollect, MainGroupCollection* groupCollect, MainVoteCollection* voteCollect, Timer* timer);

// ȸ������
void join(MainUserCollection* userCollect);
void unregister(MainUserCollection* userCollect);
void login(MainUserCollection* userCollect);
void logout(MainUserCollection* userCollect);

// �׷� ����
void groupCreate(MainUserCollection* userCollect, MainGroupCollection* groupCollect);
void groupJoin(MainUserCollection* userCollect, MainGroupCollection* groupCollect);
void groupList(MainGroupCollection *groupCollect);
void checkGroupList(MainUserCollection* userCollect);
void leaveGroup(MainUserCollection* userCollect);

// ��ǥ����
void addvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect);
void prevote(MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer);
void ingvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer);
void postvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer);
void dovote(MainUserCollection* userCollect, MainVoteCollection* voteCollect);

// ���� �ð� ����
void setCurrentTime(MainGroupCollection* groupCollect, MainVoteCollection* voteCollect, Timer* timer);

// ���� ����
void changeSession(MainUserCollection* userCollect);
void guestSession(MainUserCollection* userCollect);

void programExit();



int main()
{
	User user[MAX_STRING]; // ���� ��ü��
	Group group[MAX_STRING];
	Vote  vote[MAX_STRING];
	MainUserCollection userCollect(user); 
	MainGroupCollection groupCollect(group);
	MainVoteCollection voteCollect(vote);
	Timer timer; // timer�� �ϳ� ����

	freopen(INPUT_FILE_NAME, "r", stdin); // scanf�ÿ� input.txt���� �о��
	freopen(OUTPUT_FILE_NAME, "w", stdout); // printf�ÿ� output.txt���� ��


	doTask(&userCollect, &groupCollect, &voteCollect, &timer);

	return 0;
}

void doTask(MainUserCollection* userCollect, MainGroupCollection* groupCollect, MainVoteCollection* voteCollect, Timer *timer)
{
	// �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0;

	// ���� �޴�(8.1)�� �ԷµǱ� ������ �ݺ���
	while (menu_level_1 != 8 || menu_level_2 != 1)
	{
		// �Է����Ͽ��� �޴� ���� 2���� �б�
		scanf("%d", &menu_level_1);
		scanf("%d", &menu_level_2);

		switch (menu_level_1)
		{
		case 1: 
		{
			switch (menu_level_2) 
			{
			case 1: {	// "1.1. ȸ������" �޴� �κ� 
				join(userCollect);	// join() �Լ����� �ش� ��� ����
				break;
			}
			case 2: {	// "1.2. ȸ�� Ż��" �޴� �κ�
				unregister(userCollect);	// unregister() �Լ����� �ش� ��� ����
				break;
			}
			}
			break;
		}

			case 2: 
			{
				switch (menu_level_2) 
				{
				case 1: {	// "2.1. �α���" �޴� �κ� 
					login(userCollect);	// login() �Լ����� �ش� ��� ����
					break;
				}
				case 2: {	// "2.2. �α׾ƿ�" �޴� �κ�
					logout(userCollect);	// logout() �Լ����� �ش� ��� ����
					break;
				}
				}
				break;
			}
			case 3: {
				switch (menu_level_2) {
				case 1: {   // "3.1. ��ǥ ���ȡ� �޴� �κ�
					addvote(userCollect, voteCollect);
					break;
				}
				}
				break;
			}

			case 4: {
				switch (menu_level_2) {
				case 1: {   // "4.1. ���� ���� ���� ��ǥ ����Ʈ�� �޴� �κ�
							ingvote(userCollect, voteCollect, timer);
					break;
				}
				case 2: {   // "4.2. ��ǥ" �޴� �κ�
							dovote(userCollect, voteCollect);
					break;
				}
				case 3: {   // "4.3. ���� ���� ������ ��ǥ ����Ʈ" �޴� �κ�
							prevote(userCollect, voteCollect, timer);
					break;
				}
				case 4: {   // "4.4. ����� ��ǥ ����Ʈ" �޴� �κ�
							postvote(userCollect, voteCollect, timer);
					break;
				}

				}
				break;
			}
			case 5:
			{
				switch (menu_level_2)
				{
					case 1:
					{	
						groupList(groupCollect); // " 5.1. ��ü�׷� ��ȸ " �޴� �κ�
						break;
					}
					case 2:
					{

						groupJoin(userCollect, groupCollect); // " 5.2. �׷� ���� " �޴� �κ�
						break;
					}

					case 3:
					{

						groupCreate(userCollect, groupCollect); // " 5.3. �׷� ���� " �޴� �κ�
						break;
					}

					case 4:
					{
						checkGroupList(userCollect); // " 5.4. ���Ա׷� ��ȸ " �޴� �κ�
						break;
					}

					case 5:
					{
						leaveGroup(userCollect); // " 5.5. �׷� Ż�� " �޴� �κ�
						break;
					}
				}
				break;
			}

			case 6:
			{
				switch (menu_level_2)
				{
				case 1:
				{

					setCurrentTime(groupCollect, voteCollect, timer); // " 6.1. ����ð� ���� " �޴� �κ�
					break;
				}
				}
				break;
			}
			case 7:
			{
				switch (menu_level_2) {
				case 1: {	// "7.1. Session ����" �޴� �κ�
					changeSession(userCollect);	//changeSession() �Լ����� �ش� ��� ����
					break;
				}
				case 2: {	// "7.2. Session ����" �޴� �κ�
					guestSession(userCollect);	//guestSession() �Լ����� �ش� ��� ����
					break;
				}
				}
				break;
			}
			case 8:
			{
				switch (menu_level_2)
				{
					case 1:   // "8.1. ���ᡰ �޴� �κ�
					{
					programExit();
					break;
					}
				}
				break;
			}
		}
	}
}




void join(MainUserCollection* userCollect) {

	// Function :join(MainUserCollection* userCollect)
	// Description: ȸ�� ���� ��� ������ ���� join�Լ�. ȸ������ control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� ȸ�������� �����Ѵ�.
	// Created: 2017/5/28
	// Author: �赿��

	RegisterControl Register;
	RegisterUI RegisterUserInterface;
	Register.getMenuIndex(RegisterUserInterface, userCollect);
}

void unregister(MainUserCollection* userCollect) {

	// Function :unregister(MainUserCollection* userCollect)
	// Description: ȸ�� Ż�� ��� ������ ���� unregister�Լ�. ȸ��Ż�� control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� ȸ��Ż�� �����Ѵ�.
	// Created: 2017/5/28
	// Author: �赿��

	UnRegisterControl UnRegister;
	UnRegisterUI UnRegisterUserInterface;
	UnRegister.getMenuIndex(UnRegisterUserInterface,userCollect);
}

void login(MainUserCollection* userCollect) {

	// Function :login(MainUserCollection* userCollect)
	// Description: �α��� ��� ������ ���� login�Լ�. �α��� control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� �α����� �����Ѵ�.
	// Created: 2017/5/28
	// Author: �赿��

	LoginControl login;
	LoginUI loginUserInterface;
	login.getMenuIndex(loginUserInterface, userCollect);
	
}

void logout(MainUserCollection* userCollect) {

	// Function :logout(MainUserCollection* userCollect)
	// Description: �α׾ƿ� ��� ������ ���� logout�Լ�. �α׾ƿ� control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� �α׾ƿ��� �����Ѵ�.
	// Created: 2017/5/28
	// Author: �赿��

	LogoutControl logout;
	LogoutUI logoutUserInterface;
	logout.getMenuIndex(logoutUserInterface, userCollect);
}



void groupCreate(MainUserCollection* userCollect, MainGroupCollection* groupCollect){

	// Function :groupCreate(MainUserCollection* userCollect, MainGroupCollection* groupCollect)
	// Description: �׷� ������ ���� groupCreate�Լ�. control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� �׷� ������ �����Ѵ�.
	// Created: 2017/5/28
	// Author: �̺�ȣ

	GroupCreateUI UserInterface;
	GroupCreateControl control;
	control.getMenuIndex(UserInterface, userCollect, groupCollect);
}

void groupJoin(MainUserCollection* userCollect, MainGroupCollection* groupCollect){

	// Function :groupJoin(MainUserCollection* userCollect, MainGroupCollection* groupCollect)
	// Description: �׷� ������ ���� groupJoin�Լ�. control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� �׷� ������ �����Ѵ�.
	// Created: 2017/5/28
	// Author: �̺�ȣ

	GroupJoinUI UserInterface;
	GroupJoinControl control;
	control.getMenuIndex(UserInterface, userCollect, groupCollect);
}


void groupList(MainGroupCollection *groupCollect){

	// Function :groupList(MainGroupCollection *groupCollect)
	// Description: ��ü�׷� ��ȸ�� ���� groupList�Լ�. control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� ��ü�׷� ��ȸ�� �����Ѵ�.
	// Created: 2017/5/28
	// Author: �̺�ȣ

	GroupListUI UserInterface;
	GroupListControl control;
	control.getMenuIndex(UserInterface, groupCollect);
	
}

void checkGroupList(MainUserCollection* userCollect){

	// Function :checkGroupList(MainUserCollection* userCollect)
	// Description: ���Ա׷� ��ȸ�� ���� groupList�Լ�. control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� ���Ա׷� ��ȸ�� �����Ѵ�.
	// Created: 2017/5/28
	// Author: ������

	CheckGroupListUI UserInterface;
	CheckGroupListControl control;
	control.getMenuIndex(UserInterface, userCollect);
}

void leaveGroup(MainUserCollection* userCollect) {

	// Function :leaveGroup(MainUserCollection* userCollect)
	// Description: �׷� Ż�� ���� groupList�Լ�. control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� �׷� Ż�� �����Ѵ�.
	// Created: 2017/5/28
	// Author: ������

	LeaveGroupUI UserInterface;
	LeaveGroupControl control;
	control.getMenuIndex(UserInterface, userCollect);
}



void addvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect) {

	// Function :addvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: ��ǥ ���� ��� ������ ���� addvote�Լ�. control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� ��ǥ ������ �����Ѵ�.
	// Created: 2017/5/28
	// Author: ������

	AddVoteControl AddVote;
	AddVoteUI AddVoteUserInterface;
	AddVote.getMenuIndex(AddVoteUserInterface, userCollect, voteCollect);
}

void ingvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer) {

	// Function :ingvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: ���� �������� ��ǥ ����Ʈ�� ���� ingvote�Լ�. control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� ingvote�� �����Ѵ�.
	// Created: 2017/5/28
	// Author: ������

	InquiryIngVoteControl InquiryIngVote;
	InquiryIngVoteUI InquiryIngVoteUserInterface;
	InquiryIngVote.getMenuIndex(InquiryIngVoteUserInterface, userCollect, voteCollect, timer);
}

void prevote(MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer) {

	// Function :prevote(MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: ���� ���� ������ ��ǥ ����Ʈ�� ���� prevote�Լ�.  control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� prevote�� �����Ѵ�.
	// Created: 2017/5/28
	// Author: ������

	InquiryPreVoteControl InquiryPreVote;
	InquiryPreVoteUI InquiryPreVoteUserInterface;
	InquiryPreVote.getMenuIndex(InquiryPreVoteUserInterface, userCollect, voteCollect, timer);
}

void postvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer) {

	// Function :postvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: ����� ��ǥ ����Ʈ�� ���� postvote�Լ�.  control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� postvote�� �����Ѵ�.
	// Created: 2017/5/28
	// Author: ������

	InquiryPostVoteControl InquiryPostVote;
	InquiryPostVoteUI InquiryPostVoteUserInterface;
	InquiryPostVote.getMenuIndex(InquiryPostVoteUserInterface, userCollect, voteCollect, timer);
}

void dovote(MainUserCollection* userCollect, MainVoteCollection* voteCollect) {

	// Function : dovote(MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: ��ǥ�� ���� dovote�Լ�.  control, UI ��ü�� �ϳ��� �������� ��Ʈ�� ��ü�� getMenuIndex�� dovote�� �����Ѵ�.
	// Created: 2017/5/28
	// Author: ������

	DoVoteControl DoVote;
	DoVoteUI DoVoteUserInterface;
	DoVote.getMenuIndex(DoVoteUserInterface, userCollect, voteCollect);
}


void setCurrentTime(MainGroupCollection* groupCollect, MainVoteCollection* voteCollect, Timer* timer){
	
	// Function :setCurrentTime(MainGroupCollection* groupCollect, MainVoteCollection* voteCollect, Timer* timer)
	// Description: ����ð� ����, ��ǥ �ڵ������� ���� setCurrentTime�Լ�.  control, UI ��ü�� �ΰ��� �������� ��Ʈ�� ��ü�� getMenuIndex��
	// setCurrentTime,AutoDelete�� �����Ѵ�.
	// Created: 2017/5/28
	// Author: �̺�ȣ
	
	SetCurrentTimeUI UserInterface;
	SetCurrentTimeControl control;
	control.getMenuIndex(UserInterface, timer);

	AutoDeleteUI EventInterface;
	AutoDeleteControl control2;
	control2.getMenuIndex(EventInterface, voteCollect, timer);
}

void changeSession(MainUserCollection* userCollect) {

	// Function :changeSession(MainUserCollection* userCollect)
	// Description: ���� ������ ���� changeSession �Լ�. userCollect�� memberList�� �����Ͽ� �Է¹��� ID�� ���� ȸ���� sessionOn ������ true�� ��ȯ, �������� false�� ��ȯ
	// Created: 2017/5/31
	// Author: �赿��

	char ID[MAX_STRING];
	// �Է� ���� : 
	scanf("%s\n", ID);

	// �ش� ��� ����
	int userCount = userCollect->getUserCount();
	for (int i = 0; i < userCount; i++)
		if (userCollect->getUser(i)->getID() == ID)
			userCollect->getUser(i)->changeSessionTrue();
		else
			userCollect->getUser(i)->changeSessionFalse();
	// ��� ����
	printf("7.1. Session ����\n");
	printf("> %s \n\n", ID);
}


void guestSession(MainUserCollection* userCollect) {

	// Function : guestSession(MainUserCollection* userCollect
	// Description: �Խ�Ʈ ���� ������ ���� guestSession �Լ�. userCollect�� ��� memberList�� sessionOn ������ false�� ��ȯ
	// Created: 2017/5/31
	// Author: �赿��

	// �ش� ��� ����
	int userCount = userCollect->getUserCount();
	for (int i = 0; i < userCount; i++)
		userCollect->getUser(i)->changeSessionFalse();

	// ��� ����
	printf("7.2. guest Session���� ����\n\n");
}


void programExit(){

	// Function :programExit()
	// Description: ���α׷� ����
	// Created: 2017/5/28
	// Author: �̺�ȣ

	printf("8.1. ����\n");
	exit(0);
}
