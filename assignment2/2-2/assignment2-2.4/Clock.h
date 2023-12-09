#pragma once //헤더파일이 한번만 포함되도록 만드는 선언

class Clock //Clock 클래스
{
private: //private 구역
	void setHour(int hour); //시간을 설정하는 함수
	void setMinute(int minute); //분을 설정하는 함수
	void setSecond(int second); //초를 설정하는 함수

	int hour;
	int minute;
	int second; //각각 시간, 분, 초 변수들

public:
	Clock(); //클래스 생성자
	~Clock(); //클래스 소멸자

	void increaseHour();
	void increaseMinute();
	void increaseSecond(); //각각 시간, 분, 초를 1씩 증가시키는 함수

	void setTime(int second); //입력받은 second를 연산과정을 거친 후 setHour,setMinute,setSecond로 전달하는 함수
};