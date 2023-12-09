#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
protected:
	int age; //����
	char name[32]; //�̸�

public:
	Person(); //������
	~Person(); //�Ҹ���
	virtual void Say() = 0; //���� �����Լ�
};

class Student :public Person //Person Ŭ������ public ��ӹ��� Student Ŭ����
{
protected:
	char studentNum[11]; //�й�
	char major[32]; //�а�
	int schoolYear; //�г�

public:
	Student(); //������
	~Student(); //�Ҹ���
	int getAge();
	char* getName();
	char* getStudentNum();
	char* getMajor();
	int getSchoolYear(); //get�Լ��� - ������ ��� �������� return
	void setAge(int age);
	void setName(char* name);
	void setStudentNum(char* studentNum);
	void setMajor(char* major);
	void setSchoolYear(int year); //set�Լ��� - ������ ����������� set
	void Say(); //���� ������ ����ϴ� �Լ�
};

class Professor :public Person //Person Ŭ������ public ��ӹ��� Professor Ŭ����
{
protected:
	char professorNum[11]; //�й�
	char major[32]; //�а�

public:
	Professor(); //������
	~Professor(); //�Ҹ���
	int getAge();
	char* getName();
	char* getProfessorNum();
	char* getMajor(); //get�Լ��� - ������ ��� �������� return
	void setAge(int age);
	void setName(char* name);
	void setProfessorNum(char* professorNum);
	void setMajor(char* major); //set�Լ��� - ������ ��� �������� set
	void Say(); //���� ������ ����ϴ� �Լ�
};