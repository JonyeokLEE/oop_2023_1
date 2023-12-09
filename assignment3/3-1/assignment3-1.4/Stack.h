#include <iostream>
using namespace std;

class Node
{
private:
    Node* m_pNext; //���� ��� ����
    int m_Data; //��� �� element

public:
    Node(); //������
    ~Node(); //�Ҹ���

    void SetData(int n); //���޹��� n�� m_data�� set�ϴ� �Լ�
    void SetNext(Node* pNext); //���� ��带 set�ϴ� �Լ�
    int GetData(); //m_Data���� return�ϴ� �Լ�
    Node* GetNext(); //m_pNext ���� return�ϴ� �Լ�
};

class Stack
{
private:
    Node* m_pHead; //head ���
    int m_size; //Stack�� size ����
    int m_NumElement; //element�� ������ ��Ÿ���� ����

public:
    Stack(); //������
    ~Stack(); //�Ҹ���
    void SetSize(int n); //���޹��� n���� m_size�� �����ϴ� �Լ�
    bool IsEmpty(); //Stack�� ������� �˷��ִ� �Լ�
    bool IsFull(); //Stack�� �� á���� �˷��ִ� �Լ�
    bool Push(Node* pNode); //Stack�� ���ο� element�� Push�ϴ� �Լ�
    Node* Pop(); //Pop�ϴ� �Լ�
    void PrintStack(void); //Stack ��ҵ��� Print�ϴ� �Լ�
};