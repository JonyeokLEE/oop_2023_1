#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream> //iostream ����
#include <string.h> //string.h ����
using namespace std; //namespace std ����

class Student //Student Ŭ����
{
private: //private ����
	char* name; //�̸�
	int age; //����
	char* class_name; //�й�

public: //public ����
	Student(); //�⺻ ������
	~Student(); //�Ҹ���
	void insert(char* name, int age, char* class_name); //���ο� ������ �����ϴ� �Լ�
	void print_stu(); //�л� ������ ����ϴ� �Լ�
	bool isNameCorrect(char* class_name); //�̸��� ã�� ���� �Լ�
	const char* nameforpublic() const; //private�� name�� ��ȯ�ϴ� �Լ�
};

class School //School Ŭ����
{
private: //private ����
	class Student* student_list[100]; //Student Ŭ���� �迭 ����
	int size = 0; //size ���� ����

public:
	School(); //�⺻ ������
	~School(); //�Ҹ���
	void new_student(char* name, int age, char* class_name); //���ο� �л��� �߰��ϴ� �Լ�
	void print_all(); //��� �л� ������ ����ϴ� �Լ�
	void print_class(char* class_name); //�ش� �й� �л� ������ ����ϴ� �Լ�
	void sort_by_name(); //�̸��� �����ϴ� �Լ�
};

