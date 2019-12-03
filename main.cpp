#include "Functions.h"
#include <cassert>
#include <iostream>
#include <unistd.h>

void interface_top(bool num, bool name, bool place, bool date);			// 특정 컬럼의 출력 여부를 결정하는 매개변수
void interface_bottom();

std::string clear, status;

void getOSVersion() {
#ifdef _WIN32
	::clear = "cls";
#endif
#ifdef _WIN64
	::clear = "cls";
#endif
#ifdef __linux__
	::clear = "clear";
#endif
#ifdef linux
	::clear = "clear";
#endif
#ifdef __linux
	::clear = "clear";
#endif
}

int main() {
	getOSVersion();
	
	system(::clear.c_str());
	
	Management manage;					// Management 객체
	std::string menu_number;			// 사용자 입력을 저장하는 문자열 변수
	
	while (true) {
		interface_top(true, true, true, true);				// 인터페이스 윗부분 출력
		interface_bottom();									// 인터페이스 아랫부분 출력
		
		std::cout << ">> ";
		while (std::cin >> menu_number) {		// 사용자 입력
			if (menu_number == "1") {						// 1번 : 분실물 등록
				manage.enrollment();
				break;
			}
			else if (menu_number == "2") {					// 2번 : 분실물 조회
				manage.status();
				break;
			}
			else if (menu_number == "3") assert(0);			// 3번 : 분실물 삭제
			else if (menu_number == "4") {					// 4번 : 분실물 검색
				while (true) {
					std::string select;
					std::cout << std::endl << "[a] 일반 탐색\t[b] 세부 탐색 >> ";
					std::cin >> select;
					if (select == "a") {
						::status = manage.search();
						break;
					}
					else if (select == "b") {
						::status = manage.deepSearch();
						break;
					}
					else std::cout << "올바른 기호를 입력해주세요." << std::endl << std::endl;
				}
				break;
			}
			else if (menu_number == "5") {					// 5번 : 공지 확인
				while (true) {
               		std::string select;
               		std::cout << "\n[공지사항]";
               		manage.notices();
               		std::cout << std::endl << "[a] 로그인 [b] 종료 >> ";
               		std::cin >> select;
               		if (select == "a") {
                  		manage.login();
                  		break;
               	 	}
                	else if (select == "b") {
            			break;
                	}
                	else std::cout << "올바른 기호를 입력해주세요." << std::endl << std::endl;
				}
				break;
			}
			else if (menu_number == "6") {					// 6번 : 프로그램 종료
				system(::clear.c_str());
				std::cout << " *** 분실물 관리 프로그램을 이용해주셔서 감사합니다. 프로그램은 3초 후 자동으로 종료됩니다. ***" << std::endl;

				sleep(3);
				system(::clear.c_str());				

				return 0;
			}
			else {											// 잘못된 입력 시
				std::cout << "잘못된 입력입니다." << std::endl;
				std::cout << std::endl << ">> ";
			}
		}

		system(::clear.c_str());
	}
}

/* 인터페이스의 윗부분 출력 */
void interface_top(bool num, bool name, bool place, bool date) {
	std::cout << "┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐" << std::endl;
	std::cout << "│                                           Lost-and-Found Mangement System                                         │" << std::endl;
	std::cout << "└───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘" << std::endl;
	if (num || name || place || date) {
		std::cout << "┌";
		if (num) std::cout << "────────────────────────────┬";
		if (name) std::cout << "────────────────────────────┬";
		if (place) std::cout << "────────────────────────────┬";
		if (date) std::cout << "────────────────────────────";
		std::cout << "┐" << std::endl << "│";
		if (num) std::cout << "          관리번호          │";
		if (name) std::cout << "          분실물명          │";
		if (place) std::cout << "          분실장소          │";
		if (date) std::cout << "          분실일자          ";
		std::cout << "│" << std::endl;
		std::cout << ::status;				// 분실물 현황 또는 분실물 탐색 결과 출력
		std::cout << "└";
		if (num) std::cout << "────────────────────────────┴";
		if (name) std::cout << "────────────────────────────┴";
		if (place) std::cout << "────────────────────────────┴";
		if (date) std::cout << "────────────────────────────";
		std::cout << "┘" << std::endl;
		::status.clear();					// 문자열 비우기
	}
}

/* 인터페이스의 아랫부분 출력 */
void interface_bottom() {
	std::cout << "─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "┌──────────────────────────────────┐" << std::endl;
	std::cout << "│ [ 1 ] 분실물 등록                │" << std::endl;
	std::cout << "│ [ 2 ] 분실물 현황                │" << std::endl;
	std::cout << "│ [ 3 ] 분실물 삭제 (가칭, 미구현) │" << std::endl;
	std::cout << "│ [ 4 ] 분실물 탐색                │" << std::endl;
	std::cout << "│ [ 5 ] 공지 확인                  │" << std::endl;
	std::cout << "│ [ 6 ] 종료                       │" << std::endl;
	std::cout << "└──────────────────────────────────┘" << std::endl;
	std::cout << std::endl;
}