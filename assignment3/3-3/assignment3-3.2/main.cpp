#include "Person.h"

int main()
{
	Student stuobj; 
	Professor proobj; //��ü ����

	char name[32];
	int age = 0;
	char num[11];
	char major[32];
	int year = 0; //�Է¹��� ���� ����

	cout << "[Input Student's Information]" << endl;
	cout << "Name: "; cin >> name; stuobj.setName(name);
	cout << "Age: "; cin >> age; stuobj.setAge(age);
	cout << "Student Number: "; cin >> num; stuobj.setStudentNum(num);
	cout << "Major: "; cin >> major; stuobj.setMajor(major);
	cout << "School Year: "; cin >> year; stuobj.setSchoolYear(year);
	//�Է¹ޱ�

	cout << "[Input Professor's Information]" << endl;
	cout << "Name: "; cin >> name; proobj.setName(name);
	cout << "Age: "; cin >> age; proobj.setAge(age);
	cout << "Professor Number: "; cin >> num; proobj.setProfessorNum(num);
	cout << "Major: "; cin >> major; proobj.setMajor(major);
	//�Է¹ޱ�

	cout << endl<< "[Print Information]" << endl;
	stuobj.Say();
	proobj.Say(); //������ �Էµ� ���� ���
	return 0;
}