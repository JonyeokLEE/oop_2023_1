#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream> //iostream 선언
#include <string.h> //string.h 선언
using namespace std; //namespace std 선언

class Student //Student 클래스
{
private: //private 구역
	char* name; //이름
	int age; //나이
	char* class_name; //분반

public: //public 구역
	Student(); //기본 생성자
	~Student(); //소멸자
	void insert(char* name, int age, char* class_name); //새로운 정보를 삽입하는 함수
	void print_stu(); //학생 정보를 출력하는 함수
	bool isNameCorrect(char* class_name); //이름을 찾기 위한 함수
	const char* nameforpublic() const; //private의 name을 반환하는 함수
};

class School //School 클래스
{
private: //private 구역
	class Student* student_list[100]; //Student 클래스 배열 선언
	int size = 0; //size 변수 선언

public:
	School(); //기본 생성자
	~School(); //소멸자
	void new_student(char* name, int age, char* class_name); //새로운 학생을 추가하는 함수
	void print_all(); //모든 학생 정보를 출력하는 함수
	void print_class(char* class_name); //해당 분반 학생 정보를 출력하는 함수
	void sort_by_name(); //이름을 정렬하는 함수
};

