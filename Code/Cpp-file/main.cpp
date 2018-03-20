#include<iostream>
#include<string>
#include "User.h"
#include "Group.h"
#include "Vote.h"
#include "Timer.h"

// 회원 관리 헤더 센언
#include "RegisterUI.h"
#include "RegisterControl.h"
#include "UnRegisterUI.h"
#include "UnRegisterControl.h"
#include "LoginUI.h"
#include "LoginControl.h"
#include "LogoutUI.h"
#include "LogoutControl.h"


// 그룹 관리 헤더 선언
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

// 투표 관리 헤더 선언
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

#include "MainUserCollection.h" //  전체 유저리스트를 가지고 있는 클래스
#include "MainGroupCollection.h" // 전체 그룹리스트를 가지고 있는 클래스
#include "MainVoteCollection.h" // 전체 투표리스트를 가지고 있는 클래스

using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"


void doTask(MainUserCollection* userCollect, MainGroupCollection* groupCollect, MainVoteCollection* voteCollect, Timer* timer);

// 회원관리
void join(MainUserCollection* userCollect);
void unregister(MainUserCollection* userCollect);
void login(MainUserCollection* userCollect);
void logout(MainUserCollection* userCollect);

// 그룹 관리
void groupCreate(MainUserCollection* userCollect, MainGroupCollection* groupCollect);
void groupJoin(MainUserCollection* userCollect, MainGroupCollection* groupCollect);
void groupList(MainGroupCollection *groupCollect);
void checkGroupList(MainUserCollection* userCollect);
void leaveGroup(MainUserCollection* userCollect);

// 투표관리
void addvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect);
void prevote(MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer);
void ingvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer);
void postvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer);
void dovote(MainUserCollection* userCollect, MainVoteCollection* voteCollect);

// 현재 시간 설정
void setCurrentTime(MainGroupCollection* groupCollect, MainVoteCollection* voteCollect, Timer* timer);

// 세션 변경
void changeSession(MainUserCollection* userCollect);
void guestSession(MainUserCollection* userCollect);

void programExit();



int main()
{
	User user[MAX_STRING]; // 실제 객체들
	Group group[MAX_STRING];
	Vote  vote[MAX_STRING];
	MainUserCollection userCollect(user); 
	MainGroupCollection groupCollect(group);
	MainVoteCollection voteCollect(vote);
	Timer timer; // timer를 하나 설정

	freopen(INPUT_FILE_NAME, "r", stdin); // scanf시에 input.txt에서 읽어옴
	freopen(OUTPUT_FILE_NAME, "w", stdout); // printf시에 output.txt에서 씀


	doTask(&userCollect, &groupCollect, &voteCollect, &timer);

	return 0;
}

void doTask(MainUserCollection* userCollect, MainGroupCollection* groupCollect, MainVoteCollection* voteCollect, Timer *timer)
{
	// 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;

	// 종료 메뉴(8.1)가 입력되기 전까지 반복함
	while (menu_level_1 != 8 || menu_level_2 != 1)
	{
		// 입력파일에서 메뉴 숫자 2개를 읽기
		scanf("%d", &menu_level_1);
		scanf("%d", &menu_level_2);

		switch (menu_level_1)
		{
		case 1: 
		{
			switch (menu_level_2) 
			{
			case 1: {	// "1.1. 회원가입" 메뉴 부분 
				join(userCollect);	// join() 함수에서 해당 기능 수행
				break;
			}
			case 2: {	// "1.2. 회원 탈퇴" 메뉴 부분
				unregister(userCollect);	// unregister() 함수에서 해당 기능 수행
				break;
			}
			}
			break;
		}

			case 2: 
			{
				switch (menu_level_2) 
				{
				case 1: {	// "2.1. 로그인" 메뉴 부분 
					login(userCollect);	// login() 함수에서 해당 기능 수행
					break;
				}
				case 2: {	// "2.2. 로그아웃" 메뉴 부분
					logout(userCollect);	// logout() 함수에서 해당 기능 수행
					break;
				}
				}
				break;
			}
			case 3: {
				switch (menu_level_2) {
				case 1: {   // "3.1. 투표 제안“ 메뉴 부분
					addvote(userCollect, voteCollect);
					break;
				}
				}
				break;
			}

			case 4: {
				switch (menu_level_2) {
				case 1: {   // "4.1. 현재 진행 중인 투표 리스트“ 메뉴 부분
							ingvote(userCollect, voteCollect, timer);
					break;
				}
				case 2: {   // "4.2. 투표" 메뉴 부분
							dovote(userCollect, voteCollect);
					break;
				}
				case 3: {   // "4.3. 향후 진행 예정인 투표 리스트" 메뉴 부분
							prevote(userCollect, voteCollect, timer);
					break;
				}
				case 4: {   // "4.4. 종료된 투표 리스트" 메뉴 부분
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
						groupList(groupCollect); // " 5.1. 전체그룹 조회 " 메뉴 부분
						break;
					}
					case 2:
					{

						groupJoin(userCollect, groupCollect); // " 5.2. 그룹 가입 " 메뉴 부분
						break;
					}

					case 3:
					{

						groupCreate(userCollect, groupCollect); // " 5.3. 그룹 생성 " 메뉴 부분
						break;
					}

					case 4:
					{
						checkGroupList(userCollect); // " 5.4. 가입그룹 조회 " 메뉴 부분
						break;
					}

					case 5:
					{
						leaveGroup(userCollect); // " 5.5. 그룹 탈퇴 " 메뉴 부분
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

					setCurrentTime(groupCollect, voteCollect, timer); // " 6.1. 현재시간 설정 " 메뉴 부분
					break;
				}
				}
				break;
			}
			case 7:
			{
				switch (menu_level_2) {
				case 1: {	// "7.1. Session 변경" 메뉴 부분
					changeSession(userCollect);	//changeSession() 함수에서 해당 기능 수행
					break;
				}
				case 2: {	// "7.2. Session 변경" 메뉴 부분
					guestSession(userCollect);	//guestSession() 함수에서 해당 기능 수행
					break;
				}
				}
				break;
			}
			case 8:
			{
				switch (menu_level_2)
				{
					case 1:   // "8.1. 종료“ 메뉴 부분
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
	// Description: 회원 가입 기능 실행을 위한 join함수. 회원가입 control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 회원가입을 실행한다.
	// Created: 2017/5/28
	// Author: 김동찬

	RegisterControl Register;
	RegisterUI RegisterUserInterface;
	Register.getMenuIndex(RegisterUserInterface, userCollect);
}

void unregister(MainUserCollection* userCollect) {

	// Function :unregister(MainUserCollection* userCollect)
	// Description: 회원 탈퇴 기능 실행을 위한 unregister함수. 회원탈퇴 control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 회원탈퇴를 실행한다.
	// Created: 2017/5/28
	// Author: 김동찬

	UnRegisterControl UnRegister;
	UnRegisterUI UnRegisterUserInterface;
	UnRegister.getMenuIndex(UnRegisterUserInterface,userCollect);
}

void login(MainUserCollection* userCollect) {

	// Function :login(MainUserCollection* userCollect)
	// Description: 로그인 기능 실행을 위한 login함수. 로그인 control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 로그인을 실행한다.
	// Created: 2017/5/28
	// Author: 김동찬

	LoginControl login;
	LoginUI loginUserInterface;
	login.getMenuIndex(loginUserInterface, userCollect);
	
}

void logout(MainUserCollection* userCollect) {

	// Function :logout(MainUserCollection* userCollect)
	// Description: 로그아웃 기능 실행을 위한 logout함수. 로그아웃 control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 로그아웃을 실행한다.
	// Created: 2017/5/28
	// Author: 김동찬

	LogoutControl logout;
	LogoutUI logoutUserInterface;
	logout.getMenuIndex(logoutUserInterface, userCollect);
}



void groupCreate(MainUserCollection* userCollect, MainGroupCollection* groupCollect){

	// Function :groupCreate(MainUserCollection* userCollect, MainGroupCollection* groupCollect)
	// Description: 그룹 생성을 위한 groupCreate함수. control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 그룹 생성을 실행한다.
	// Created: 2017/5/28
	// Author: 이병호

	GroupCreateUI UserInterface;
	GroupCreateControl control;
	control.getMenuIndex(UserInterface, userCollect, groupCollect);
}

void groupJoin(MainUserCollection* userCollect, MainGroupCollection* groupCollect){

	// Function :groupJoin(MainUserCollection* userCollect, MainGroupCollection* groupCollect)
	// Description: 그룹 가입을 위한 groupJoin함수. control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 그룹 가입을 실행한다.
	// Created: 2017/5/28
	// Author: 이병호

	GroupJoinUI UserInterface;
	GroupJoinControl control;
	control.getMenuIndex(UserInterface, userCollect, groupCollect);
}


void groupList(MainGroupCollection *groupCollect){

	// Function :groupList(MainGroupCollection *groupCollect)
	// Description: 전체그룹 조회를 위한 groupList함수. control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 전체그룹 조회를 실행한다.
	// Created: 2017/5/28
	// Author: 이병호

	GroupListUI UserInterface;
	GroupListControl control;
	control.getMenuIndex(UserInterface, groupCollect);
	
}

void checkGroupList(MainUserCollection* userCollect){

	// Function :checkGroupList(MainUserCollection* userCollect)
	// Description: 가입그룹 조회를 위한 groupList함수. control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 가입그룹 조회를 실행한다.
	// Created: 2017/5/28
	// Author: 김휘진

	CheckGroupListUI UserInterface;
	CheckGroupListControl control;
	control.getMenuIndex(UserInterface, userCollect);
}

void leaveGroup(MainUserCollection* userCollect) {

	// Function :leaveGroup(MainUserCollection* userCollect)
	// Description: 그룹 탈퇴를 위한 groupList함수. control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 그룹 탈퇴를 실행한다.
	// Created: 2017/5/28
	// Author: 김휘진

	LeaveGroupUI UserInterface;
	LeaveGroupControl control;
	control.getMenuIndex(UserInterface, userCollect);
}



void addvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect) {

	// Function :addvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: 투표 제안 기능 실행을 위한 addvote함수. control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 투표 제안을 실행한다.
	// Created: 2017/5/28
	// Author: 임재형

	AddVoteControl AddVote;
	AddVoteUI AddVoteUserInterface;
	AddVote.getMenuIndex(AddVoteUserInterface, userCollect, voteCollect);
}

void ingvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer) {

	// Function :ingvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: 현재 진행중인 투표 리스트를 위한 ingvote함수. control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 ingvote을 실행한다.
	// Created: 2017/5/28
	// Author: 임재형

	InquiryIngVoteControl InquiryIngVote;
	InquiryIngVoteUI InquiryIngVoteUserInterface;
	InquiryIngVote.getMenuIndex(InquiryIngVoteUserInterface, userCollect, voteCollect, timer);
}

void prevote(MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer) {

	// Function :prevote(MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: 향후 진행 예정인 투표 리스트를 위한 prevote함수.  control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 prevote을 실행한다.
	// Created: 2017/5/28
	// Author: 임재형

	InquiryPreVoteControl InquiryPreVote;
	InquiryPreVoteUI InquiryPreVoteUserInterface;
	InquiryPreVote.getMenuIndex(InquiryPreVoteUserInterface, userCollect, voteCollect, timer);
}

void postvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect, Timer* timer) {

	// Function :postvote(MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: 종료된 투표 리스트를 위한 postvote함수.  control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 postvote을 실행한다.
	// Created: 2017/5/28
	// Author: 임재형

	InquiryPostVoteControl InquiryPostVote;
	InquiryPostVoteUI InquiryPostVoteUserInterface;
	InquiryPostVote.getMenuIndex(InquiryPostVoteUserInterface, userCollect, voteCollect, timer);
}

void dovote(MainUserCollection* userCollect, MainVoteCollection* voteCollect) {

	// Function : dovote(MainUserCollection* userCollect, MainVoteCollection* voteCollect)
	// Description: 투표를 위한 dovote함수.  control, UI 객체를 하나씩 생성한후 컨트롤 객체의 getMenuIndex로 dovote을 실행한다.
	// Created: 2017/5/28
	// Author: 임재형

	DoVoteControl DoVote;
	DoVoteUI DoVoteUserInterface;
	DoVote.getMenuIndex(DoVoteUserInterface, userCollect, voteCollect);
}


void setCurrentTime(MainGroupCollection* groupCollect, MainVoteCollection* voteCollect, Timer* timer){
	
	// Function :setCurrentTime(MainGroupCollection* groupCollect, MainVoteCollection* voteCollect, Timer* timer)
	// Description: 현재시간 설정, 투표 자동삭제를 위한 setCurrentTime함수.  control, UI 객체를 두개씩 생성한후 컨트롤 객체의 getMenuIndex로
	// setCurrentTime,AutoDelete을 실행한다.
	// Created: 2017/5/28
	// Author: 이병호
	
	SetCurrentTimeUI UserInterface;
	SetCurrentTimeControl control;
	control.getMenuIndex(UserInterface, timer);

	AutoDeleteUI EventInterface;
	AutoDeleteControl control2;
	control2.getMenuIndex(EventInterface, voteCollect, timer);
}

void changeSession(MainUserCollection* userCollect) {

	// Function :changeSession(MainUserCollection* userCollect)
	// Description: 세션 변경을 위한 changeSession 함수. userCollect의 memberList에 접근하여 입력받은 ID와 같은 회원의 sessionOn 변수를 true로 변환, 나머지는 false로 변환
	// Created: 2017/5/31
	// Author: 김동찬

	char ID[MAX_STRING];
	// 입력 형식 : 
	scanf("%s\n", ID);

	// 해당 기능 수행
	int userCount = userCollect->getUserCount();
	for (int i = 0; i < userCount; i++)
		if (userCollect->getUser(i)->getID() == ID)
			userCollect->getUser(i)->changeSessionTrue();
		else
			userCollect->getUser(i)->changeSessionFalse();
	// 출력 형식
	printf("7.1. Session 변경\n");
	printf("> %s \n\n", ID);
}


void guestSession(MainUserCollection* userCollect) {

	// Function : guestSession(MainUserCollection* userCollect
	// Description: 게스트 세션 변경을 위한 guestSession 함수. userCollect의 모든 memberList의 sessionOn 변수를 false로 변환
	// Created: 2017/5/31
	// Author: 김동찬

	// 해당 기능 수행
	int userCount = userCollect->getUserCount();
	for (int i = 0; i < userCount; i++)
		userCollect->getUser(i)->changeSessionFalse();

	// 출력 형식
	printf("7.2. guest Session으로 변경\n\n");
}


void programExit(){

	// Function :programExit()
	// Description: 프로그램 종료
	// Created: 2017/5/28
	// Author: 이병호

	printf("8.1. 종료\n");
	exit(0);
}
