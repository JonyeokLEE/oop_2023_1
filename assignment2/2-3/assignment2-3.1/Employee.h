#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h> //string.h ����
#include <iostream> //iostream ����
using namespace std; //namespace std ����
class Employee //Employee Ŭ����
{
private: //private ����
	char* name;
	int age;
	char* country;
	char* job; //�̸�, ����, ����, ���� ���� ����

public:
	Employee(); //�⺻ ������
	Employee(Employee& A); //copy������
	Employee(char* name, int age, char* country, char* job); //�ŰԺ����� �ִ� ������
	~Employee(); //�Ҹ���
	bool isNameCorrect(char* name); //�̸��� ã�� ���� �Լ�
	void print(); //������ ����ϴ� �Լ�
	void change(char* name, int age, char* country, char* job); //������ �����ϴ� �Լ�
};