#include <iostream>
using namespace std;

/* 빈칸 1: 반환값이 없는 함수 */ void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    /* 빈칸 2: 포인터가 가리키는 값에 접근 */ *p_HPPotion = count;
    /* 빈칸 3: 포인터가 가리키는 값에 접근 */ *p_MPPotion = count;
}
int choice = 0;
int HPPotion = 0;
int MPPotion = 0;
int Level = 1; //도전 구현1. 레밸 변수

int addPotion()  //도전 구현2. 포션 충전 함수
{
    HPPotion++;
    MPPotion++;
    return 0;
}

int main()
{
    /* 빈칸 4: 상수를 만드는 키워드 */const int SIZE = 5;
    int stat[SIZE] = { 0 };

    while (1) {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> stat[0] >> stat[1];

        /* 빈칸 5: HP와 MP가 모두 50을 초과하는 조건 */
        if (stat[0] > 50 && stat[1] > 50) {
            break;
        }
        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }

    while (1) {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> stat[2] >> stat[3];

        if (stat[2] > 0 && stat[3] > 0) {
            /* 빈칸 6: 반복문 탈출 */
            break;
        }
        cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }
    stat[4] = Level;
  
    
    setPotion(5, /* 빈칸 7: 변수의 주소 */ &HPPotion, /* 빈칸 8: 변수의 주소 */&MPPotion);

    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
    cout << "=============================================" << endl;
    cout << "<스탯 관리 시스템>" << endl;
    // ... (메뉴 출력)

    while (1) {
        cout << "1.HP UP" << endl;
        cout << "2.MP UP" << endl;
        cout << "3.공격력 UP" << endl;
        cout << "4.방어력 UP" << endl;
        cout << "5.현재 능력치" << endl;
        cout << "6.Level Up" << endl;
        cout << "0.나가기" << endl;
        cin >> choice;

        if (choice == 0) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }

        /* 빈칸 9: 분기할 기준이 되는 변수 */
        switch (choice) {
        case 1:
            if (HPPotion <= 0) {
                cout << "포션이 부족합니다." << endl;
                continue;
            }
            stat[0] += 20;
            /* 빈칸 10: 포션 개수 1 감소 */;
            HPPotion--;
            cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
            cout << "현재 HP: " << stat[0] << endl;
            cout << "남은 HP포션 수: " << HPPotion << endl;
            break;
            // ... (다른 case들)
        case 2:
            if (MPPotion <= 0) {
                cout << "포션이 부족합니다." << endl;
                continue;
            }
            stat[1] += 20;
            MPPotion--;
            cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
            cout << "현재 MP: " << stat[1] << endl;
            cout << "남은 MP포션 수: " << MPPotion << endl;
            break;
        case 3:
            stat[2] *= 2;
            cout << "* 현재 공격력: " << stat[2] << endl;
            break;
        case 4:
            stat[3] *= 2;
            cout << "* 현재 방어력: " << stat[3] << endl;
            break;
            /* 빈칸 11: 정해진 case 외의 모든 경우 */
        case 5:
            cout << "현재 HP: " << stat[0] << endl;
            cout << "현재 MP: " << stat[1] << endl;
            cout << "현재 공격력: " << stat[2] << endl;
            cout << "현재 방어력: " << stat[3] << endl;
            cout << "현재 레밸: " << stat[4] << endl;  //도전 구현3. 현재 레밸
            cout << "남은 HP포션: " << HPPotion << " 남은 MP포션: " << MPPotion << endl; //도전 구현4, 남은 포션
            break;
        case 6:
            cout << "LEVEL UP! 포션이 1개씩 추가됩니다!" << endl;
            stat[4] = ++Level;
            addPotion();
            break;
        default:
            cout << "다시 입력해주세요." << endl;
            break;
        }
    }
    return 0;
}