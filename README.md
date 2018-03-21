# 투표 시스템(C++) 

### UML을 사용한 협업 투표 시스템 개발

-[diagram](https://github.com/woosik0818/cpp-with-UML/tree/master/diagram) - UML을 사용하여 만든 diagram들 입니다.

	- [Communication diagram 1](https://github.com/woosik0818/cpp-with-UML/tree/master/diagram/Communication-diagram-1.png) - 투표 제안, 투표 행사, 현재 진행 중인 투표 조회, 향후 진행 예정인 투표 조회 입니다.

		- [Communication diagram 2](https://github.com/woosik0818/cpp-with-UML/tree/master/diagram) - 종료된 투표 조회 입니다.

		- [Design class diagram_subsystem](https://github.com/woosik0818/cpp-with-UML/tree/master/diagram) - 투표관리 객체들의 관계도 입니다.

		- [Requirement List](https://github.com/woosik0818/cpp-with-UML/tree/master/diagram) - 투표 관리 시스템의 요구사항 입니다.

		- [Use case description_step by step breakdown](https://github.com/woosik0818/cpp-with-UML/tree/master/diagram) - 시스템 작동을 순서대로 나타낸 표 입니다.

		- [Use case diagram](https://github.com/woosik0818/cpp-with-UML/tree/master/diagram) - 유저 입장에서 시스템의 기능을 보여주는 diagram 입니다.

- [Code](https://github.com/woosik0818/cpp-with-UML/tree/master/Code) - diagram을 가지고 작성한 C++ 코드입니다.

	- [Header-file](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file) - 헤더 파일입니다.
	
		- [AddVoteControl.h](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file/AddVoteControl.h)
						
		- [AddVoteUI.h](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file/AddVoteUI.h)

		- [DoVoteControl.h](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file/DoVoteControl.h)
	
		- [DoVoteUI.h](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file/DoVoteUI.h)

		- [InquiryIngVoteControl.h](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file/InquiryIngVoteControl.h)

		- [InquiryIngVoteUI.h](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file/InquiryIngVoteUI.h)

		- [InquiryPostVoteControl.h](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file/InquiryPostVoteControl.h)

		- [InquiryPostVoteUI.h](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file/InquiryPostVoteUI.h)
				
		- [InquiryPreVoteControl.h](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file/InquiryPreVoteControl.h)

		- [InquiryPreVoteUI.h](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file/InquiryPreVoteUI.h)

		- [MainVoteCollection.h](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file/MainVoteCollection.h)

		- [Vote.h](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file/Vote.h)
	
	- [Cpp-file](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file) - C++ 파일입니다.
	
		- [AddVoteControl.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file/AddVoteControl.cpp) - 새로운 투표 추가를 관리하는 코드 입니다.

		- [AddVoteUI.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file/AddVoteUI.cpp) - 새로운 투표 추가의 인터페이스를 관리하는 코드 입니다.

		- [DoVoteControl.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file/DoVoteControl.cpp) - 투표하는 기능을 관리하는 코드 입니다.

		- [DoVoteUI.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file/DoVoteUI.cpp) - 투표하는 기능의 인터페이스를 관리하는 코드 입니다.

		- [InquiryIngVoteControl.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file/InquiryIngVoteControl.cpp) - 현재 진행 중인 투표를 관리하는 코드 입니다.

		- [InquiryIngVoteUI.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file/InquiryIngVoteUI.cpp) - 현재 진행 중인 투표의 인터페이스를 관리하는 코드 입니다.

		- [InquiryPostVoteControl.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file/InquiryPostVoteControl.cpp) - 종료된 투표를 관리하는 코드 입니다.

		- [InquiryPostVoteUI.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file/InquiryPostVoteUI.cpp) - 종료된 투표의 인터페이스를 관리하는 코드 입니다.

		- [InquiryPreVoteControl.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file/InquiryPreVoteControl.cpp) - 향후 진행될 투표를 관리하는 코드 입니다.

		- [InquiryPreVoteUI.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file/InquiryPreVoteUI.cpp) - 향후 진행될 투표의 인터페이스를 관리하는 코드 입니다.

		- [main.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file/main.cpp) - 전체적인 투표 관리 시스템 코드 입니다.

		- [MainVoteCollection.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file/MainVoteCollection.cpp) - 생성된 모든 투표들을 관리하는 코드 입니다.

		- [Vote.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file/Vote.cpp) - 투표들의 정보를 관리하는 코드 입니다.

				- UML을 사용하여 Water Fall 방식으로 Usecase Diagram, Communication Diagram을 만들고, C++언어를 
			      기반으로 프로그램을 만들었습니다. 
			
				- 회원가입 후 그룹 가입을 통해 그룹장이 만든 투표에 투표권을 행사할 수 있으며, 타이머를 작동시켜 일정 시간이 
			      지나면 투표가 종료되는 시스템 입니다.
