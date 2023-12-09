#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
    Node* m_pNext; //���� ��带 ���� ����
    int m_Data; //��� �� Element

public:
    Node(); //������
    ~Node(); //�Ҹ���

    void SetData(int n); //���޹��� ������ m_Data�� set�ϴ� �Լ�
    void SetNext(Node* pNext); //���� ��带 set�ϴ� �Լ�
    int GetData(); //m_Data�� ��ȯ�ϴ� �Լ�
    Node* GetNext(); //m_pNext�� ��ȯ�ϴ� �Լ�
};
class Queue
{
private:
    Node* m_pHead; //head���
    Node* m_pTail; //tail���
    int m_size; //Queue�� ������ ����
    int m_NumElement; //element�� ������ ��Ÿ���� ����

public:
    Queue(); //������
    ~Queue(); //�Ҹ���

    void SetSize(int n); //m_size�� ���޹��� n���� set�ϴ� �Լ�
    bool IsEmpty(); //Queue�� ������� Ȯ���ϴ� �Լ�
    bool IsFull(); //Queue�� �� á���� Ȯ���ϴ� �Լ�
    bool Push(Node* pNode); //���ο� ����� pNode�� Push�ϴ� �Լ�
    Node* Pop(); //Node�� Pop�ϴ� �Լ�
    void PrintQueue(); //Queue�� element���� Print�ϴ� �Լ�
};
