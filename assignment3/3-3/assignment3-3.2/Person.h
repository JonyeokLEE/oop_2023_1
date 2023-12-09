#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
protected:
	int age; //나이
	char name[32]; //이름

public:
	Person(); //생성자
	~Person(); //소멸자
	virtual void Say() = 0; //순수 가상함수
};

class Student :public Person //Person 클래스를 public 상속받은 Student 클래스
{
protected:
	char studentNum[11]; //학번
	char major[32]; //학과
	int schoolYear; //학년

public:
	Student(); //생성자
	~Student(); //소멸자
	int getAge();
	char* getName();
	char* getStudentNum();
	char* getMajor();
	int getSchoolYear(); //get함수들 - 각각의 멤버 변수들을 return
	void setAge(int age);
	void setName(char* name);
	void setStudentNum(char* studentNum);
	void setMajor(char* major);
	void setSchoolYear(int year); //set함수들 - 각각의 멤버변수들을 set
	void Say(); //변수 정보를 출력하는 함수
};

class Professor :public Person //Person 클래스를 public 상속받은 Professor 클래스
{
protected:
	char professorNum[11]; //학번
	char major[32]; //학과

public:
	Professor(); //생성자
	~Professor(); //소멸자
	int getAge();
	char* getName();
	char* getProfessorNum();
	char* getMajor(); //get함수들 - 각각의 멤버 변수들을 return
	void setAge(int age);
	void setName(char* name);
	void setProfessorNum(char* professorNum);
	void setMajor(char* major); //set함수들 - 각각의 멤버 변수들을 set
	void Say(); //변수 정보를 출력하는 함수
};