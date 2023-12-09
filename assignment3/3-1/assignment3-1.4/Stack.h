#include <iostream>
using namespace std;

class Node
{
private:
    Node* m_pNext; //다음 노드 변수
    int m_Data; //노드 별 element

public:
    Node(); //생성자
    ~Node(); //소멸자

    void SetData(int n); //전달받은 n을 m_data에 set하는 함수
    void SetNext(Node* pNext); //다음 노드를 set하는 함수
    int GetData(); //m_Data값을 return하는 함수
    Node* GetNext(); //m_pNext 값을 return하는 함수
};

class Stack
{
private:
    Node* m_pHead; //head 노드
    int m_size; //Stack의 size 변수
    int m_NumElement; //element의 개수를 나타내는 변수

public:
    Stack(); //생성자
    ~Stack(); //소멸자
    void SetSize(int n); //전달받은 n으로 m_size를 설정하는 함수
    bool IsEmpty(); //Stack이 비었는지 알려주는 함수
    bool IsFull(); //Stack이 다 찼는지 알려주는 함수
    bool Push(Node* pNode); //Stack에 새로운 element를 Push하는 함수
    Node* Pop(); //Pop하는 함수
    void PrintStack(void); //Stack 요소들을 Print하는 함수
};