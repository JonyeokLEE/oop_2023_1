#pragma once //헤더파일이 한번만 포함되도록 만드는 선언
#include <iostream> //iostream 선언
using namespace std; //namespace std 선언

class A //class A 선언
{
private: //private 구역
	double value; //value 변수 선언

public: //public 구역
	A(double num); //A 클래스 생성자(double형 num을 전달받음)

	~A(); //A 클래스 소멸자
}; //class A 선언 종료