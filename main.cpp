#include "Functions.h"
#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

void interface_top();
void interface_bottom();

int main() {
	system("clear");

	Management manage;
	// Management 객체
	string menu_number;
	// 사용자 입력을 저장하는 문자열 변수

	while(1) {
		interface_top();
		// 인터페이스 윗부분 출력
		interface_bottom();
		// 인터페이스 아랫부분 출력

		cout << ">> ";
		while(cin >> menu_number)
		// 사용자 입력
		{
			if (menu_number == "1") {
				manage.enrollment();
				break;
			} // 1번 : 분실물 등록
			else if (menu_number == "2") {
				assert(0);
			} // 2번 : 분실물 삭제
			else if (menu_number == "3") {
				assert(0);
			} // 3번 : 분실물 검색
			else if (menu_number == "4") {
				assert(0);
			} // 4번 : 공지 확인
			else if (menu_number == "5") {
				system("clear");
				return 0;
			} // 5번 : 프로그램 종료
			else {
				cout << "잘못된 입력입니다." << endl;
				cout << endl << ">> ";
			} // 잘못된 입력 시
		}

		system("clear");
	}
}

/* 인터페이스의 윗부분 출력 */
void interface_top() {
	cout << "┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐" << endl;
	cout << "│                                       Lost-and-Found Mangement System (가제)                                      │" << endl;
	cout << "└───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘" << endl;
	cout << "┌────────────────────────────┬────────────────────────────┬────────────────────────────┬────────────────────────────┐" << endl;
	cout << "│          관리번호          │          분실물명          │          분실장소          │          분실일자          │" << endl;
	cout << "└────────────────────────────┴────────────────────────────┴────────────────────────────┴────────────────────────────┘" << endl;
}

/* 인터페이스의 아랫부분 출력 */
void interface_bottom() {
	cout << "─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
	cout << "┌──────────────────────────────────┐" << endl;
	cout << "│ [ 1 ] 분실물 등록                │" << endl;
	cout << "│ [ 2 ] 분실물 삭제 (가칭, 미구현) │" << endl;
	cout << "│ [ 3 ] 분실물 검색 (가칭, 미구현) │" << endl;
	cout << "│ [ 4 ] 공지 확인 (가칭, 미구현)   │" << endl;
	cout << "│ [ 5 ] 종료                       │" << endl;
	cout << "└──────────────────────────────────┘" << endl;
	cout << endl;
}