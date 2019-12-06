#include "Functions.h"
#include <iostream>
using namespace std;

extern void interface_top(bool num, bool name, bool place, bool date);
extern void interface_bottom();
extern string clear, status;


void Management::notices() {
   cout << "\n\n" << notice << "\n\n" << endl;
}


void Management::login() {
	while(1) {
    	cout << endl << "비밀번호를 입력하시오. >> ";
    	cin >> password;

  		if (password == "1234") {
     		cout << endl << "변경할 공지사항을 입력하세요 : ";
    		cin.ignore(1,'\n');
    		getline(cin, notice);
			break;
    	}
		else if (password == "B" || password == "b") {
			break;
		}
    	else {
			cout << "비밀번호가 틀렸습니다!" << endl;
    	}
	}
}
