#include "A.h" //A ������� ����


A::A(double num) //A Ŭ���� ������(double�� num�� ���޹���)
{
	value = num; //private ���� value�� num���� �־��ش�.
	cout << "Class A is created with " << value << endl; //value�� �̿��Ͽ� ���� ���
} //A Ŭ���� ������ ����

A::~A() //A Ŭ���� �Ҹ���
{
	cout << "Class A is destroyed with " << value << endl; //value�� �̿��Ͽ� ���� ���
} //A Ŭ���� �Ҹ��� ����