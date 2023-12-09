#include <iostream> //iostream 선언
#include "Clock.h" //Clock.h 헤더파일 선언

using namespace std; //namespace std 선언

int main() //main함수
{
	cout << "Enter the second: "; //안내문 출력
	Clock clock; //Clock 클래스 clock 객체 생성
	int input = 0; //input을 위한 변수 선언
	cin >> input; //입력 받기
	clock.setTime(input); //입력받은 수를 setTime에 전달
	int command = 0; //커맨드 변수 선언
	while (1) //break 조건 전까지 무한 반복
	{
		cout << "[Command for Clock.h]" << endl;
		cout << "1: Increase Hour / 2: Increase Minute / 3: Increase Second / 4: Exit"<< endl;
		cout << "Enter the command: "; //커맨드 설명문 및 입력을 위한 안내문 출력
		cin >> command; //커맨드 입력받기
		if (command == 1) //시간을 증가하는 커맨드
		{
			clock.increaseHour(); //increaseHour 실행
		}
		else if (command == 2) //분을 증가하는 커맨드
		{
			clock.increaseMinute(); //increaseMinute 실행
		}
		else if (command == 3) //초를 증가하는 커맨드
		{
			clock.increaseSecond(); //increaseSecond 실행
		}
		else if (command == 4) //종료 커맨드
		{
			break; //반복문 종료
		}
		else //그 외 커맨드
		{
			cout << "Wrong Command" << endl; //잘못 입력했다는 안내문 출력
		}
	}

	return 0; //0의 반환
}