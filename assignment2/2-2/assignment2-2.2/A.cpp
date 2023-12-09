#include "A.h" //A 헤더파일 선언


A::A(double num) //A 클래스 생성자(double형 num을 전달받음)
{
	value = num; //private 변수 value에 num값을 넣어준다.
	cout << "Class A is created with " << value << endl; //value를 이용하여 문장 출력
} //A 클래스 생성자 종료

A::~A() //A 클래스 소멸자
{
	cout << "Class A is destroyed with " << value << endl; //value를 이용하여 문장 출력
} //A 클래스 소멸자 종료