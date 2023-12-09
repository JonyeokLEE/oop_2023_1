#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Node //Node Ŭ����
{
private:
	Node* pNext; //������ ����Ű�� ����
	int data; //������ ������ ����

public:
	Node(); //������
	~Node(); //�Ҹ���

	void setdata(int n); //data�� n���� �����ϴ� �Լ�
	void setNext(Node* next); //���� ��带 �����ϴ� �Լ�
	int getdata(); //data�� return�ϴ� �Լ�
	Node* getNext(); //pNext�� return�ϴ� �Լ�
};

class LinkedList //LinkedList Ŭ����
{
private:
	Node* pHead; //head ���
	Node* pTail; //tail ���

public:
	LinkedList(); //������
	~LinkedList(); //�Ҹ���
	Node* getHead(); //pHead�� return�ϴ� �Լ�
	void insertsort(); //insertsort�� �����ϴ� �Լ�
	Node* Binary_Search(Node* p, int n); //BinarySearch�� �����ϴ� �Լ�
	void insertNew(Node* next); //���ο� ��带 �����ϴ� �Լ�
	void printlist(); //��ũ�帮��Ʈ ��ü�� ����ϴ� �Լ�
	Node* setMiddle(Node* start, int size); //��� ��带 set�ϴ� �Լ�
};