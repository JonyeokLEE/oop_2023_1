#include "Person.h"

int main()
{
	Student stuobj; 
	Professor proobj; //객체 생성

	char name[32];
	int age = 0;
	char num[11];
	char major[32];
	int year = 0; //입력받을 변수 생성

	cout << "[Input Student's Information]" << endl;
	cout << "Name: "; cin >> name; stuobj.setName(name);
	cout << "Age: "; cin >> age; stuobj.setAge(age);
	cout << "Student Number: "; cin >> num; stuobj.setStudentNum(num);
	cout << "Major: "; cin >> major; stuobj.setMajor(major);
	cout << "School Year: "; cin >> year; stuobj.setSchoolYear(year);
	//입력받기

	cout << "[Input Professor's Information]" << endl;
	cout << "Name: "; cin >> name; proobj.setName(name);
	cout << "Age: "; cin >> age; proobj.setAge(age);
	cout << "Professor Number: "; cin >> num; proobj.setProfessorNum(num);
	cout << "Major: "; cin >> major; proobj.setMajor(major);
	//입력받기

	cout << endl<< "[Print Information]" << endl;
	stuobj.Say();
	proobj.Say(); //각각의 입력된 정보 출력
	return 0;
}