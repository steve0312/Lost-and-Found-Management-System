#ifndef _FUNCTION_H
#define _FUNCTION_H

#include <string>
#include <list>

/* 분실물 하나의 정보를 담는 구조체 */
struct LostStuff {
	std::string name, place;				// 분실물명, 분실장소
	int num, date;							// 관리번호, 분실날짜
};




/* 분실물 관리 클래스 */
class Management {
	LostStuff listElement;								// 분실물 하나의 정보를 담는 구조체
	std::list<LostStuff> stuffList;						// 분실물 목록을 저장하는 연결 리스트
	std::list<LostStuff>::iterator it;					// 분실물 목록의 iterator
public:
	std::string password; //비밀번호
	std::string notice;   //공지사항
	void enrollment();									// 연결 리스트에 분실물을 등록하는 함수
	void status();										// 연결 리스트에 저장된 분실물 현황을 문자열로 반환하는 함수
	void login();
	void notices();
	std::string search();								// 연결 리스트에 저장된 분실물을 탐색하는 함수
	std::string deepSearch();							// 연결 리스트에 저장된 분실물을 세부적으로 탐색하는 함수
private:
	std::string status(std::list<LostStuff> list, 
		bool num, bool name, bool place, bool date);	// 분실물 목록을 출력하기 위한 문자열을 생성, 특정 컬럼의 출력 여부 결정 가능
	std::string toString(int n);						// 정수->문자열 변환
	std::string fillBlank(std::string s);				// 출력 시 리스트 테이블의 위치에 맞도록 해당 문자열의 양쪽에 공백 채우기
	int getManageNum();									// 분실물 탐색 시 관리번호를 입력하는 함수
	std::string getName();								// 분실물 탐색 시 분실물명을 입력하는 함수
	std::string getPlace();								// 분실물 탐색 시 분실장소를 입력하는 함수
	int getDate();										// 분실물 탐색 시 분실날짜를 입력하는 함수
	std::list<LostStuff> search(
		std::list<LostStuff> _list, 
		int* num, 
		std::string* name, 
		std::string* place, 
		int* date);
	// 매개변수 쿼리
};

#endif
