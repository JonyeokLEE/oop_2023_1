#pragma once
#include <iostream>
using namespace std;

class Term
{
private:
	int m_Coefficient; //���
	int m_Exponent; //����
	Term* m_pNext; //���� ��带 ���� ����

public:
	Term(); //������
	~Term(); //�Ҹ���

	void SetCoeff(int coeff); //����� �����ϴ� �Լ�
	void SetExponent(int exponent); //������ �����ϴ� �Լ�
	int GetCoeff(); //����� ��ȯ�ϴ� �Լ�
	int GetExponent(); //������ ��ȯ�ϴ� �Լ�
	void SetNext(Term* pNext); //���� ��带 �����ϴ� �Լ�
	Term* GetNext(); //m_pNext�� ��ȯ�ϴ� �Լ�
};


class Polynomial
{
private:
	Term* m_pHead; //��� ���
	char varible; //���� ����

public:
	Polynomial(); //������
	~Polynomial(); //�Ҹ���

	void Insert(Term* pTerm); //��带 �����ϴ� �Լ�
	void PrintList(); //����Ʈ�� ����ϴ� �Լ�
	void setvarible(char set); //���ڸ� �����ϴ� �Լ�
	void Add(Polynomial& poly);
	void Sub(Polynomial& poly); //���ϱ�� ���� �Լ�
};
