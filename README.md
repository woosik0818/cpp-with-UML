# 투표 시스템(C++) 

### UML을 사용한 협업 투표 시스템 개발

- [Code](https://github.com/woosik0818/cpp-with-UML/tree/master/Code) - diagram을 가지고 작성한 C++ 코드입니다.

	- [Header-file](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Header-file) - 헤더 파일입니다.
	
	- [Cpp-file](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/Cpp-file) - C++ 파일입니다.
	
		- [AddVoteControl.cpp](https://github.com/woosik0818/cpp-with-UML/tree/master/Code/AddVoteControl.cpp) - 새로운 투표 추가를 관리하는 코드 입니다.

				* AddVoteControl.h
						
				* AddVoteUI.cpp - 새로운 투표 추가의 인터페이스를 관리하는 코드 입니다.

				* AddVoteUI.h

				* DoVoteControl.cpp - 투표하는 기능을 관리하는 코드 입니다.

				* DoVoteControl.h
	
				* DoVoteUI.cpp - 투표하는 기능의 인터페이스를 관리하는 코드 입니다.

				* DoVoteUI.h

				* InquiryIngVoteControl.cpp - 현재 진행 중인 투표를 관리하는 코드 입니다.

				* InquiryIngVoteControl.h

				* InquiryIngVoteUI.cpp - 현재 진행 중인 투표의 인터페이스를 관리하는 코드 입니다.

				* InquiryIngVoteUI.h

				* InquiryPostVoteControl.cpp - 종료된 투표를 관리하는 코드 입니다.

				* InquiryPostVoteControl.h

				* InquiryPostVoteUI.cpp - 종료된 투표의 인터페이스를 관리하는 코드 입니다.

				* InquiryPostVoteUI.h
				
				* InquiryPreVoteControl.cpp - 향후 진행될 투표를 관리하는 코드 입니다.

				* InquiryPreVoteControl.h

				* InquiryPreVoteUI.cpp - 향후 진행될 투표의 인터페이스를 관리하는 코드 입니다.

				* InquiryPreVoteUI.h

				* main.cpp - 전체적인 투표 관리 시스템 코드 입니다.

				* MainVoteCollection.cpp - 생성된 모든 투표들을 관리하는 코드 입니다.

				* MainVoteCollection.h

				* Vote.cpp - 투표들의 정보를 관리하는 코드 입니다.

				* Vote.h

			- UML을 사용하여 Water Fall 방식으로 Usecase Diagram, Communication Diagram을 만들고, C++언어를 
			  기반으로 프로그램을 만들었습니다. 
			
			- 회원가입 후 그룹 가입을 통해 그룹장이 만든 투표에 투표권을 행사할 수 있으며, 타이머를 작동시켜 일정 시간이 
			  지나면 투표가 종료되는 시스템 입니다.
