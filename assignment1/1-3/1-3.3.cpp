#include <iostream>
using namespace std;
/*
대략적인 아이디어: 10진수가 다른 진수로 변환하기 쉬우니, 우선 무조건 10진수로 변환하고 그 다음 진수로 변환하기!
*/

int getarrsize(char* arr) //getarrsize 함수 시작
{
	int size = 0; //size 변수 선언

	while (arr[size] != '\0') //arr이 끝날 때 까지
	{
		size++; //size 증가
	}
	return size; //size 반환
} //getarrsize 함수 종료


int transferto10(char* before, int specbase) //입력값을 10진수로 바꾸는 함수
{
    int res = 0; //결과값 변수
    int plus = 0; //연산과정에서 한번에 모아서 더하기 위한 변수
    if (specbase == 16) //16진수일 때
    {
        for (int i = 0; i < getarrsize(before); i++) //문자의 길이만큼 반복
        {
            plus = 0;
            if (before[i] >= '0' && before[i] <= '9') //숫자로 이루어져 있을 때는
            {
                plus = before[i] - '0'; //'0'을 빼고 plus에 저장
            }
            else if (before[i] >= 'A' && before[i] <= 'F') //대문자 A B C D E F 인 경우
            {
                plus = before[i] - 'A' + 10; //'A'를 빼고 10을 더하기
            }
            else if (before[i] >= 'a' && before[i] <= 'f') //소문자 a b c d e f 인 경우
            {
                plus = before[i] - 'a' + 10; //'a'를 빼고 10을 더하기
            }
            else
            {
                return -1; //범위를 초과한 경우 -1을 반환
            }
            res = res * specbase + plus; //결과값을 계속해서 최신화하기
        }
    }
    else if (specbase == 8) //8진수인 경우
    {
        for (int i = 0; i < getarrsize(before); i++) //문자의 길이만큼 반복
        {
            plus = 0;
            if (before[i] >= '0' && before[i] <= '7') //8진수 범위 안에 있으면
            {
                plus = before[i] - '0'; //'0'을 빼고 plus에 저장
            }
            else //범위를 초과한 경우 -1을 반환
                return -1;
            res = res * specbase + plus; //결과값을 계속해서 최신화하기
        }
    }
    else if (specbase == 2) //2진수인 경우
    {
        for (int i = 0; i < getarrsize(before); i++) //문자의 길이만큼 반복
        {
            plus = 0;
            if (before[i] >= '0' && before[i] <= '1') //2진수 범위 안에 있으면
            {
                plus = before[i] - '0'; //'0'을 빼고 plus에 저장
            }
            else //범위를 초과한 경우 -1을 반환
                return -1;
            res = res * specbase + plus; //결과값을 계속해서 최신화하기
        }
    }
    else if (specbase == 10) //10진수인 경우
    {
        for (int i = 0; i < getarrsize(before); i++) //문자의 길이만큼 반복
        {
            res = res * 10 + (before[i] - 48); //정수로 바꿔주는 작업
        }
    }
    
    else //그 외의 경우 -1을 반환
        return -1;

    return res; //결과값을 반환
}

int count(int a, int divide) //10진수에서 다른 진수로 변환하는 과정에서 몇번 횟수를 반복해야하는지 계산하는 함수
{
    int countnum = 0;
    while (a != 0) //a가 0이 아닐 때까지
    {
        a /= divide; //해당 진수로 나누어준다
        countnum++; //그 횟수를 센다
    }
    return countnum; //그 횟수를 반환
}

void transferfrom10(int beforenum, int newbase, char* resarr) //10진수에서 다른 진수로 변환하는 함수
{
    for (int i = count(beforenum, newbase); beforenum != 0; i--) //beforenum이 0이 될때까지 i는 계속 감소한다.
    {
       
        if ((beforenum % newbase) < 10) //나눈 나머지 값이 0 ~ 9일 때
        {
            resarr[i - 1] = (beforenum % newbase) + '0'; //'0'을 더한 후 resarr에 저장
        }
        else //그 이상일 경우에는
        {
            resarr[i - 1] = (beforenum % newbase) - 10 + 'A'; //숫자를 알파벳으로 변환해서 저장한다.
        }
        beforenum /= newbase; //beforenum을 계속해서 최신화
    }
    return;
}




int main()
{
	char original[300] = {0,}; //처음 수를 입력받을 배열
	int formerform = 0; //입력 수의 진수
	int afterform = 0; //바꿀 진수
    int num = 0; //입력 수를 10진수로 바꾼 상태를 저장할 변수
    char after[300] = { 0, }; //결과값이 담길 배열

	cout << "Original Number: ";
	cin >> original;
	cout << "Specific base of Original Number: ";
	cin >> formerform;
	cout << "Desired base of Original Number: ";
    cin >> afterform;
    //입력받기


	num = transferto10(original, formerform); //10진수로 변환하기
    transferfrom10(num, afterform,after); //원하는 진수로 바꾸기

    cout << endl << "Result: " << after << endl; //결과값 출력

	
	return 0;
}