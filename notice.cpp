#include "Functions.h"
#include <iostream>
using namespace std;

extern void interface_top(bool num, bool name, bool place, bool date);
extern void interface_bottom();
extern string clear, status;


void Management::notices() {
   cout << "\n\n" << notice << "\n\n" << std::endl;
}


void Management::login() {
	while(1) {
    	std::cout << std::endl << "비밀번호를 입력하시오. >> ";
    	std::cin >> password;

  		if (password == "1234") {
     		std::cout << endl << "변경할 공지사항을 입력하세요 : ";
    		std::cin.ignore(1,'\n');
    		std::getline(std::cin, notice);
			break;
    	}
		else if (password == "B" || password == "b") {
			break;
		}
    	else {
			std::cout << "비밀번호가 틀렸습니다!" << std::endl;
    	}
	}
}
