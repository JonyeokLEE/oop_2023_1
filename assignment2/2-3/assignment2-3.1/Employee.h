#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h> //string.h 선언
#include <iostream> //iostream 선언
using namespace std; //namespace std 선언
class Employee //Employee 클래스
{
private: //private 구역
	char* name;
	int age;
	char* country;
	char* job; //이름, 나이, 국적, 직업 변수 선언

public:
	Employee(); //기본 생성자
	Employee(Employee& A); //copy생성자
	Employee(char* name, int age, char* country, char* job); //매게변수가 있는 생성자
	~Employee(); //소멸자
	bool isNameCorrect(char* name); //이름을 찾기 위한 함수
	void print(); //정보를 출력하는 함수
	void change(char* name, int age, char* country, char* job); //정보를 변경하는 함수
};