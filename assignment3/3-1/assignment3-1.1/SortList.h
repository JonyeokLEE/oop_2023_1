#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node //Node Ŭ����
{
private:
    Node* m_pNext; //���� ��带 ���� ����
    string m_Data; //���ڿ��� ���� ����

public:
    Node(); //������
    ~Node(); //�Ҹ���

    void SetData(string data); //���޹��� ���ڿ��� �����ϴ� �Լ�
    void SetNext(Node* pNext); //���� ��带 ����Ű�� ���� �Լ�
    string GetData() const; //m_Data�� ��ȯ�ϴ� �Լ�
    Node* GetNext() const; //m_pNext�� ��ȯ�ϴ� �Լ�
};

class LinkedList //LinkedList Ŭ����
{
private:
    Node* m_pHead; //head�� ��Ÿ���� ����

public:
    LinkedList(); //������
    ~LinkedList(); //�Ҹ���
    void setHead(Node* pHead); //head�� �����ϴ� �Լ�
    void Merge_List(Node* p1, Node* p2, Node* p3); //Merge_Sort�� ������ �Լ�
    void printList(void); //List�� ����ϴ� �Լ�
};