#include "Functions.h"
#include <iostream>

extern void interface_top(bool num, bool name, bool place, bool date);
extern void interface_bottom();
extern std::string clear, status;

using namespace std;

/* 연결 리스트에 분실물을 등록하는 함수 */
void Management::enrollment() {
	std::cin.ignore(256, '\n');

	// 분실물명 입력
	std::cout << std::endl << "분실물명 : ";
	getline(std::cin, this->listElement.name);			// 한 줄 입력

	// 분실장소 입력
	std::cout << std::endl << "분실장소 : ";
	getline(std::cin, this->listElement.place);			// 한 줄 입력

	// 분실날짜 입력
	while (true) {
		std::cout << std::endl << "분실날짜 : ";
		std::cin >> this->listElement.date;
		if (std::cin.fail()) {							// 잘못된 입력
			std::cout << "잘못된 입력입니다." << std::endl;
			std::cin.clear();							// 입력 스트림 비우기
			std::cin.ignore(256, '\n');
		}
		else {
			std::cin.ignore(256, '\n');
			break;
		}
	}

	// 관리번호 할당, 연결 리스트의 가장 마지막 원소의 관리번호 + 1로 할당
	// 리스트가 비어있을 경우 가장 첫 번째 관리번호인 1로 할당
	if (this->stuffList.empty()) this->listElement.num = 1;
	else this->listElement.num = this->stuffList.back().num + 1;
	this->stuffList.push_back(this->listElement);			// 입력받은 데이터를 연결 리스트에 추가
}

/* 연결 리스트에 저장된 분실물 현황을 문자열로 반환하는 함수 */
void Management::status() {
	::status = status(this->stuffList, true, true, true, true);
}

/* 연결 리스트에 저장된 분실물을 탐색하는 함수 */
std::string Management::search() {
	std::list<LostStuff> list;
	while (true) {
		std::string select, keyword;
		std::cout << "[1] 관리번호  [2] 분실물명  [3] 분실장소  [4] 분실날짜  [5] 뒤로가기\n>> ";
		std::cin >> select;
		getchar();			// getline 함수 사용 시 입력 이전에 getchar를 통해 버퍼를 비워주는 단계 필요
		// 관리번호를 이용한 탐색
		if (select == "1") {
			int num = getManageNum();
			list = search(this->stuffList, &num, nullptr, nullptr, nullptr);			// 쿼리 결과 반환
			break;
		}
		// 분실물명을 이용한 탐색
		else if (select == "2") {
			std::string name = getName();
			list = search(this->stuffList, nullptr, &name, nullptr, nullptr);				// 쿼리 결과 반환
			break;
		}
		// 분실장소를 이용한 탐색
		else if (select == "3") {
			std::string place = getPlace();
			list = search(this->stuffList, nullptr, nullptr, &place, nullptr);				// 쿼리 결과 반환
			break;
		}
		// 분실날짜를 이용한 탐색
		else if (select == "4") {
			int date = getDate();
			list = search(this->stuffList, nullptr, nullptr, nullptr, &date);				// 쿼리 결과 반환
			break;
		}
		// 뒤로가기
		else if (select == "5") return "";
		else std::cout << "올바른 숫자를 입력해주세요." << std::endl << std::endl;			// 잘못된 입력
	}
	return status(list, true, true, true, true);
}

/* 연결 리스트에 저장된 분실물을 세부적으로 탐색하는 함수 */
std::string Management::deepSearch() {
	std::list<LostStuff> list = this->stuffList;
	std::string select;
	bool print[] = { true, true, true, true };

	getchar();
	std::string name = getName();
	while (true) {
		std::cout << "[1] 출력  [2] 모두 출력 >> ";
		std::cin >> select;
		if (select == "1") {
			print[0] = print[1] = false;						// 관리번호, 분실물명 제외
			break;
		}
		else if (select == "2") break;
		else std::cout << "올바른 숫자를 입력해주세요." << std::endl << std::endl;
	}
	list = search(list, nullptr, &name, nullptr, nullptr);				// 쿼리 결과 반환
	::status = status(list, print[0], print[1], print[2], print[3]);

	if(::status.empty()) {
		return ::status;
	}

	// 인터페이스 초기화
	system(::clear.c_str());
	::interface_top(print[0], print[1], print[2], print[3]);
	::interface_bottom();
	print[0] = true; print[1] = true;							// 초기화

	getchar();
	std::string place = getPlace();
	while (true) {
		std::cout << "[1] 출력  [2] 모두 출력 >> ";
		std::cin >> select;
		if (select == "1") {
			print[0] = print[1] = print[2] = false;				// 관리번호, 분실물명, 분실장소 제외
			break;
		}
		else if (select == "2") break;
		else std::cout << "올바른 숫자를 입력해주세요." << std::endl << std::endl;
	}
	list = search(list, nullptr, nullptr, &place, nullptr);				// 쿼리 결과 반환
	::status = status(list, print[0], print[1], print[2], print[3]);

	if(::status.empty()) {
		return ::status;
	}

	// 인터페이스 초기화
	system(::clear.c_str());
	::interface_top(print[0], print[1], print[2], print[3]);
	::interface_bottom();
	print[0] = true; print[1] = true; print[2] = true;			// 초기화

	getchar();
	int date = getDate();
	list = search(list, nullptr, nullptr, nullptr, &date);				// 쿼리 결과 반환
	::status = status(list, print[0], print[1], print[2], print[3]);

	if(::status.empty()) {
		return ::status;
	}

	// 인터페이스 초기화
	system(::clear.c_str());
	::interface_top(print[0], print[1], print[2], print[3]);
	::interface_bottom();

	return status(list, true, true, true, true);			// 마지막에는 모두 출력되는 형태로 반환
}

std::string Management::status(std::list<LostStuff> list, bool num, bool name, bool place, bool date) {
	std::string status;
	for (this->it = list.begin(); this->it != list.end() && 
		(num || name || place || date); ++this->it) {
		status.append("├");
		if (num) status.append("────────────────────────────┼");
		if (name) status.append("────────────────────────────┼");
		if (place) status.append("────────────────────────────┼");
		if (date) status.append("────────────────────────────┤");
		status.push_back('\n');
		if (num) status.append("│").append(fillBlank(toString(this->it->num)));
		if (name) status.append("│").append(fillBlank(this->it->name));
		if (place) status.append("│").append(fillBlank(this->it->place));
		if (date) status.append("│").append(fillBlank(toString(this->it->date))).append("│");
		status.push_back('\n');
	}
	return status;
}

/* 정수->문자열 변환 */
std::string Management::toString(int n) {
	std::string s;
	if (n != 0) {
		s.append(toString(n / 10));						// 일의 자리를 제외한 나머지 자리
		s.push_back(n - ((n / 10) * 10) + '0');			// 일의 자리
	}
	return s;
}

/* 출력 시 리스트 테이블의 위치에 맞도록 해당 문자열의 양쪽에 공백 채우기 */
std::string Management::fillBlank(std::string s) {
	int korCount = 0;
	for (int i = 0; i < s.size(); ++i)
		if (i < s.size() && i + 1 < s.size() && i + 2 < s.size() && 
			s[i] < 0 && s[i + 1] < 0 && s[i + 2] < 0) {
			++korCount;
			i += 2;
		}
	std::string content = s;
	// "│" 과 "│" 사이의 바이트 길이가 총 28이므로
	// 문자열 s를 포함한 총 길이가 28을 넘지 않을 때까지 양쪽에 공백 채우기
	while (content.size() < 28 + korCount) {
		content.insert(content.begin(), ' ');					// 문자열의 왼쪽(처음)에 공백 채우기
		// 왼쪽에 공백을 채운 직후 문자열의 총 길이가 28이 될 가능성 존재
		if (content.size() != 28 + korCount) content.push_back(' ');		// 문자열의 오른쪽(마지막)에 공백 채우기
		else break;
	}
	
	return content;				// 문자열 반환
}

/* 분실물 탐색 시 관리번호를 입력하는 함수 */
int Management::getManageNum() {
	std::string keyword;
	int num = 0;
	while (true) {
		std::cout << "조회할 관리번호를 입력하세요 >> ";
		getline(std::cin, keyword);
		if ((num = atoi(keyword.c_str())) == 0)
			std::cout << "올바른 번호를 입력해주세요." << std::endl << std::endl;
		else break;
	}
	return num;
}

/* 분실물 탐색 시 분실물명을 입력하는 함수 */
std::string Management::getName() {
	std::string keyword;
	std::cout << "조회할 분실물명을 입력하세요 >> ";
	getline(std::cin, keyword);
	return keyword;
}

/* 분실물 탐색 시 분실장소를 입력하는 함수 */
std::string Management::getPlace() {
	std::string keyword;
	std::cout << "조회할 분실장소를 입력하세요 >> ";
	getline(std::cin, keyword);
	return keyword;
}

/* 분실물 탐색 시 분실날짜를 입력하는 함수 */
int Management::getDate() {
	std::string keyword;
	int date = 0;
	while (true) {
		std::cout << "조회할 분실날짜를 입력하세요 >> ";
		getline(std::cin, keyword);
		if ((date = atoi(keyword.c_str())) == 0)
			std::cout << "올바른 번호를 입력해주세요." << std::endl << std::endl;
		else break;
	}
	return date;
}

/* 매개변수 쿼리 */
std::list<LostStuff> Management::search(
	std::list<LostStuff> _list, 
	int* num, 
	std::string* name, 
	std::string* place, 
	int* date) {
	std::list<LostStuff> searchList = _list, list;
	if (num) {			// num != nullptr
		for (auto iter = searchList.begin(); iter != searchList.end(); ++iter)
			if (iter->num == *num) {
				list.push_back(*iter);
				break;
			}
		searchList = list;					// list를 searchList에 덮어쓰고
		list.clear();						// 다음 쿼리를 위해 list 비우기
	}
	if (name) {			// name != nullptr
		for (auto iter = searchList.begin(); iter != searchList.end(); ++iter)
			if (iter->name == *name) list.push_back(*iter);
		searchList = list;					// list를 searchList에 덮어쓰고
		list.clear();						// 다음 쿼리를 위해 list 비우기
	}
	if (place) {		// place != nullptr
		for (auto iter = searchList.begin(); iter != searchList.end(); ++iter)
			if (iter->place == *place) list.push_back(*iter);
		searchList = list;					// list를 searchList에 덮어쓰고
		list.clear();						// 다음 쿼리를 위해 list 비우기
	}
	if (date) {			// date != nullptr
		for (auto iter = searchList.begin(); iter != searchList.end(); ++iter)
			if (iter->date == *date) list.push_back(*iter);
		searchList = list;					// list를 searchList에 덮어쓰고
		list.clear();						// 다음 쿼리를 위해 list 비우기
	}
	return searchList;			// 리스트 반환
}

/* 분실물 삭제 함수 */
void Management::removeList() {
	if (stuffList.size() == 0) return;

	int n;
	list<LostStuff>::iterator iter = stuffList.begin();

	cout << "삭제할 분실물의 관리 번호를 입력하세요. >> ";
	cin >> n;

	if (n == 0 || n > stuffList.size()) return;
	
	for (int i = 0; i < n-1; i++) {
		iter++;
	}

	iter = stuffList.erase(iter);

	for (iter; iter != stuffList.end(); iter++) {
		iter->num = iter->num - 1;
	}
}