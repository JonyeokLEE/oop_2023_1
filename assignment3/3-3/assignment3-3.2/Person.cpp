#include "Person.h"

Person::Person() //생성자
{
	age = 0;
	for (int i = 0; i < 32; i++)
		name[i] = '\0';
	//변수 초기화
}

Person::~Person() //소멸자
{
}

Student::Student() //생성자
{
	schoolYear = 0;
	for (int i = 0; i < 11; i++)
	{
		studentNum[i] = '\0';
	}
	for (int i = 0; i < 32; i++)
	{
		major[i] = '\0';
	}
	//변수 초기화
}

Student::~Student() //소멸자
{
}

int Student::getAge() //getAge 함수
{
	return age; //age 반환
}

char* Student::getName() //getName 함수
{
	return name; //name 반환
}

char* Student::getStudentNum() //getStudentNum 함수
{
	return studentNum; //studentNum 반환
}

char* Student::getMajor() //getMajor 함수
{
	return major; //major 반환
}

int Student::getSchoolYear() //getSchoolYear 함수
{
	return schoolYear; //schoolYear 반환
}

void Student::setAge(int age) //setAge 함수
{
	this->age = age; //전달된 값 저장
}

void Student::setName(char* name) //setName 함수
{
	strcpy(this->name, name); //전달된 값 저장
}

void Student::setStudentNum(char* studentNum) //setStudentNum 함수
{
	strcpy(this->studentNum, studentNum); //전달된 값 저장
}

void Student::setMajor(char* major) //setMajor 함수
{
	strcpy(this->major, major); //전달된 값 저장
}

void Student::setSchoolYear(int year) //setSchoolYear 함수
{
	schoolYear = year; //전달된 값 저장
}

void Student::Say() //Say 함수
{
	cout << "[Student]" << endl;
	cout << "Name: " << getName() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Student Number: " << getStudentNum() << endl;
	cout << "Major: " << getMajor() << endl;
	cout << "School Year: " << getSchoolYear() << endl;
	//변수 출력
}

Professor::Professor() //생성자
{
	for (int i = 0; i < 11; i++)
	{
		professorNum[i] = '\0';
	}
	for (int i = 0; i < 32; i++)
	{
		major[i] = '\0';
	}
	//변수 초기화
}

Professor::~Professor() //소멸자
{
}

int Professor::getAge() //getAge 함수
{
	return age; //age 반환
}

char* Professor::getName() //getName 함수
{
	return name; //name 반환
}

char* Professor::getProfessorNum() //getProfessorNum 함수
{
	return professorNum; //professorNum 반환
}

char* Professor::getMajor() //getMajor 함수
{
	return major; //major 반환
}

void Professor::setAge(int age) //setAge 함수
{
	this->age = age; //전달된 값 저장
}

void Professor::setName(char* name) //setName 함수
{
	strcpy(this->name, name); //전달된 값 저장
}

void Professor::setProfessorNum(char* professorNum) //setProfessorNum 함수
{
	strcpy(this->professorNum, professorNum); //전달된 값 저장
}

void Professor::setMajor(char* major) //setMajor 함수
{
	strcpy(this->major, major); //전달된 값 저장
}

void Professor::Say() //Say 함수
{
	cout << endl;
	cout << "[Professor]" << endl;
	cout << "Name: " << getName() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Professor Number: " << getProfessorNum() << endl;
	cout << "Major: " << getMajor() << endl;
	//변수 출력
}
