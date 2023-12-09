#include "Clock.h" //Clock.h 헤더파일 선언
#include <iostream> //iostream 선언
using namespace std; //namespace std 선언

Clock::Clock() //클래스 생성자
{
	hour = 0;
	minute = 0;
	second = 0; //각각의 변수들을 초기화
}

Clock::~Clock() //클래스 소멸자
{
	hour = 0;
	minute = 0;
	second = 0; //각각의 변수들을 초기화
}

void Clock::increaseHour() //시간을 증가시키는 함수
{
	hour++; //시간을 1 증가
	if (hour == 24) //만약 시간이 24가 되면
	{
		hour = 0; //0으로 초기화
	}
	setHour(hour); //변화된 시간을 다시 setHour로 전달

	cout << hour << ":" << minute << ":" << second << endl; //변화된 시간을 출력
}

void Clock::increaseMinute() //분을 증가시키는 함수
{
	minute++; //분을 1 증가
	if (minute == 60) //만약 분이 60이 되면
	{
		minute = 0; //분을 0으로 초기화
		increaseHour(); //그에 따라 시간도 증가
	}
	setMinute(minute); //변화된 분을 다시 setMinute으로 전달

	cout << hour << ":" << minute << ":" << second << endl; //변화된 시간을 출력
}

void Clock::increaseSecond() //초를 증가시키는 함수
{
	second++; //초를 1 증가
	if (second == 60) //만약 초가 60이 되면
	{
		second = 0; //초를 0으로 초기화
		increaseMinute(); //그에 따라 분도 증가
	}
	setSecond(second); //변화된 초를 다시 setSecond로 전달

	cout << hour << ":" << minute << ":" << second << endl; //변화된 시간을 출력
}

void Clock::setTime(int second) //전달받은 second를 각 함수로 전달해주는 역할
{
	setHour(second / 3600); //second를 3600으로 나눈 값을 setHour로 전달
	second %= 3600; //second는 3600으로 나눈 나머지값으로 변화
	setMinute(second / 60); //second를 60으로 나눈 값을 setMinute로 전달
	second %= 60; //second는 60으로 나눈 나머지값으로 변화
	setSecond(second); //second를 setSecond로 전달

	cout << hour << ":" << minute << ":" << second << endl; //변환된 시간 출력
}

void Clock::setHour(int hour) //시간 단위를 설정하는 함수
{
	if (hour > 24) //만약 24보다 크면
		hour %= 24; //24로 나눈 나머지 값이 hour
	this->hour = hour; //멤버 변수를 참조하기 위해 this 포인터 사용
}

void Clock::setMinute(int minute) //분 단위를 설정하는 함수
{
	if (minute > 60) //만약 60보다 크면
		minute %= 60; //60으로 나눈 나머지 값이 minute
	this->minute = minute; //멤버 변수를 참조하기 위해 this 포인터 사용
}

void Clock::setSecond(int second) //초 단위를 설정하는 함수
{
	if (second > 60) //만약 60보다 크면
		second %= 60; //60으로 나눈 나머지 값이 second
	this->second = second; //멤버 변수를 참조하기 위해 this 포인터 사용
}
