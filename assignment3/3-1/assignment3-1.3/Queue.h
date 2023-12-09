#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
    Node* m_pNext; //다음 노드를 위한 변수
    int m_Data; //노드 별 Element

public:
    Node(); //생성자
    ~Node(); //소멸자

    void SetData(int n); //전달받은 정수를 m_Data에 set하는 함수
    void SetNext(Node* pNext); //다음 노드를 set하는 함수
    int GetData(); //m_Data를 반환하는 함수
    Node* GetNext(); //m_pNext를 반환하는 함수
};
class Queue
{
private:
    Node* m_pHead; //head노드
    Node* m_pTail; //tail노드
    int m_size; //Queue의 사이즈 변수
    int m_NumElement; //element의 개수를 나타내는 변수

public:
    Queue(); //생성자
    ~Queue(); //소멸자

    void SetSize(int n); //m_size를 전달받은 n으로 set하는 함수
    bool IsEmpty(); //Queue가 비었는지 확인하는 함수
    bool IsFull(); //Queue가 다 찼는지 확인하는 함수
    bool Push(Node* pNode); //새로운 노드인 pNode를 Push하는 함수
    Node* Pop(); //Node를 Pop하는 함수
    void PrintQueue(); //Queue의 element들을 Print하는 함수
};
