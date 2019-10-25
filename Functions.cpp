#include "Functions.h"
#include <iostream>

using namespace std;

/* 연결 리스트에 분실물을 등록하는 함수 */
void Management::enrollment() {
    cin.ignore(256, '\n');

    cout << endl << "분실물명 : ";
    getline(cin, listElement.name);

    cout << endl << "분실장소 : ";
    getline(cin, listElement.place);

    while(1) {
        cout << endl << "분실날짜 : ";
        cin >> listElement.date;
        if(cin.fail()) {
            cout << "잘못된 입력입니다." << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
        else {
            cin.ignore(256, '\n');
            break;
        }
    }

    stuffList.push_back(listElement);
    // 입력받은 데이터를 연결 리스트에 추가
}