#include <iostream>
#include <string>
#include"header.h"
using namespace std;

void readit(string s, int coeff[], int exp[], int& index,char&returnit)
{
    s += '+'; //마지막 항 처리를 위해 끝에 + 달기
    int sign = 1; //부호
    string num = ""; //숫자

    for (int i = 0; i < s.size(); i++) //'+' 또는 '-'인 경우
    {
        if (s[i] == '+' || s[i] == '-')
        {
            if (!num.empty()) // 이전에 읽은 숫자가 있다면
            {
                coeff[index] = sign * stoi(num); // 상수항 추가
                exp[index] = 0; //0으로 설정
                index++;
            }
            num = ""; //초기화
            sign = (s[i] == '+') ? 1 : -1; //+면 sign을 1, 아니면 -1로 설정
        }
        else if ((s[i] >= 'a') && (s[i] <= 'z') || (s[i] >= 'A') && (s[i] <= 'Z') || s[i] == '-')
        {   //문자인 경우
            returnit = s[i]; //해당 문자를 returnit에 저장 -> 어떤 문자가 입력되었는지 알 수 있다.
            if (num.empty()) //이전에 읽은 숫자가 없다면(계수가 1인 경우)
            {
                coeff[index] = sign; 
            }
            else //이전에 읽은 숫자가 있다면
            {
                coeff[index] = sign * stoi(num); //num을 숫자로 바꿔서 sign을 곱한 값을 저장
            }
            num = ""; //num 초기화
            if (s[i + 1] == '^') //다음 문자가 지수의 시작이면
            {
                i += 2; //2 증가해서 넘어가기
                int expSign = 1; //지수 부호
                if (s[i] == '-')
                {
                    expSign = -1; //음수면 -1로 설정
                    i++; //i증가
                }
                while (i < s.size() && isdigit(s[i])) //지수의 모든 숫자를 읽기
                {
                    num += s[i]; //num에 추가
                    i++; //i 증가
                }
                exp[index] = expSign * stoi(num); //읽은 지수를 저장
                num = ""; //초기화
                i--; //1 감소시키면 반복문이 반복될때 적절한 위치로 갈 수 있다. 위에 +2 고려
            }
            else //지수가 1이면
            {
                exp[index] = 1; //지수에 1 저장
            }
            index++; //index 증가
        }
        else //상수항 처리
        {
            num += s[i]; //num에 추가
        }
    }
}

int main() {
    string s;
    cout << "Input equation 1: ";
    cin >> s;
    string s2;
    cout << "Input equation 2: ";
    cin >> s2; //두 식 입력받기
    int coeff[100];
    int exp[100]; //계수와 지수를 저장할 배열 선언
    int index = 0; //얼마나 저장되었는지 알기 위해서 선언
    char c = 0; //어떤 문자가 사용되었는지 저장하기 위한 변수
    readit(s, coeff, exp, index,c); //readit 함수를 통해 두 배열에 지수와 계수를 저장하고, 문자도 저장
    Polynomial equ1;
    equ1.setvarible(c); //c를 equ1의 문자로 설정

    for (int i = 0; i < index; i++) //index까지 반복
    {
        Term* node = new Term;
        node->SetCoeff(coeff[i]);
        node->SetExponent(exp[i]);
        equ1.Insert(node); //저장된 값들을 node에 넣어서 equ1 리스트에 삽입
    }
    cout << endl;
    index = 0;
    c = 0; //변수 초기화 후
    readit(s2, coeff, exp, index,c); //두번째 식도 동일하게 수행
    
    Polynomial equ2;
    equ2.setvarible(c);

    for (int i = 0; i < index; i++)
    {
        Term* node2 = new Term;
        node2->SetCoeff(coeff[i]);
        node2->SetExponent(exp[i]);
        equ2.Insert(node2);
    } //두번째 식도 동일하게 수행해서 리스트 생성

    Polynomial save; //한번 연산하고 나서 식 1의 값이 날라가버리기에 저장해놓기 위해서 생성
    save = equ1; //식1의 값을 저장

    cout << "Equation 1: ";
    equ1.PrintList();
    cout << endl;
    cout << "Equation 2: ";
    equ2.PrintList();
    cout << endl; //두 식의 값을 출력
    
    equ1.Add(equ2);
    cout << "Add result: ";
    equ1.PrintList(); //equ1에 equ1+equ2 값이 저장되어 출력
    cout << endl;
    equ1 = save; //equ1을 save해놨던 값으로 다시 복구
    equ1.Sub(equ2);
    cout << "Sub result: ";
    equ1.PrintList(); //equ1에 equ1-equ2 값이 저장되어 출력


    return 0;
}