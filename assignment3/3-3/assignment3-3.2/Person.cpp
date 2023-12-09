#include "Person.h"

Person::Person() //������
{
	age = 0;
	for (int i = 0; i < 32; i++)
		name[i] = '\0';
	//���� �ʱ�ȭ
}

Person::~Person() //�Ҹ���
{
}

Student::Student() //������
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
	//���� �ʱ�ȭ
}

Student::~Student() //�Ҹ���
{
}

int Student::getAge() //getAge �Լ�
{
	return age; //age ��ȯ
}

char* Student::getName() //getName �Լ�
{
	return name; //name ��ȯ
}

char* Student::getStudentNum() //getStudentNum �Լ�
{
	return studentNum; //studentNum ��ȯ
}

char* Student::getMajor() //getMajor �Լ�
{
	return major; //major ��ȯ
}

int Student::getSchoolYear() //getSchoolYear �Լ�
{
	return schoolYear; //schoolYear ��ȯ
}

void Student::setAge(int age) //setAge �Լ�
{
	this->age = age; //���޵� �� ����
}

void Student::setName(char* name) //setName �Լ�
{
	strcpy(this->name, name); //���޵� �� ����
}

void Student::setStudentNum(char* studentNum) //setStudentNum �Լ�
{
	strcpy(this->studentNum, studentNum); //���޵� �� ����
}

void Student::setMajor(char* major) //setMajor �Լ�
{
	strcpy(this->major, major); //���޵� �� ����
}

void Student::setSchoolYear(int year) //setSchoolYear �Լ�
{
	schoolYear = year; //���޵� �� ����
}

void Student::Say() //Say �Լ�
{
	cout << "[Student]" << endl;
	cout << "Name: " << getName() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Student Number: " << getStudentNum() << endl;
	cout << "Major: " << getMajor() << endl;
	cout << "School Year: " << getSchoolYear() << endl;
	//���� ���
}

Professor::Professor() //������
{
	for (int i = 0; i < 11; i++)
	{
		professorNum[i] = '\0';
	}
	for (int i = 0; i < 32; i++)
	{
		major[i] = '\0';
	}
	//���� �ʱ�ȭ
}

Professor::~Professor() //�Ҹ���
{
}

int Professor::getAge() //getAge �Լ�
{
	return age; //age ��ȯ
}

char* Professor::getName() //getName �Լ�
{
	return name; //name ��ȯ
}

char* Professor::getProfessorNum() //getProfessorNum �Լ�
{
	return professorNum; //professorNum ��ȯ
}

char* Professor::getMajor() //getMajor �Լ�
{
	return major; //major ��ȯ
}

void Professor::setAge(int age) //setAge �Լ�
{
	this->age = age; //���޵� �� ����
}

void Professor::setName(char* name) //setName �Լ�
{
	strcpy(this->name, name); //���޵� �� ����
}

void Professor::setProfessorNum(char* professorNum) //setProfessorNum �Լ�
{
	strcpy(this->professorNum, professorNum); //���޵� �� ����
}

void Professor::setMajor(char* major) //setMajor �Լ�
{
	strcpy(this->major, major); //���޵� �� ����
}

void Professor::Say() //Say �Լ�
{
	cout << endl;
	cout << "[Professor]" << endl;
	cout << "Name: " << getName() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Professor Number: " << getProfessorNum() << endl;
	cout << "Major: " << getMajor() << endl;
	//���� ���
}
