#include <string>
#include <list>

using namespace std;

/* 분실물 하나의 정보를 담는 구조체 */
struct LostStuff
{
    string name; // 분실물명
    string place; // 분실장소
    int date; // 분실날짜
};

/* 분실물 관리 클래스 */
class Management {
private:
    struct LostStuff listElement;
    // 분실물 하나의 정보를 담는 구조체

    list<LostStuff> stuffList;
    // 분실물 목록을 저장하는 연결 리스트

    list<LostStuff>::iterator it;
    // 분실물 목록의 iterator

public:
    void enrollment();
    // 연결 리스트에 분실물을 등록하는 함수
};