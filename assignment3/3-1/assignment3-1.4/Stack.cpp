#include "Stack.h"

Node::Node() //생성자
{
    m_pNext = nullptr;
    m_Data = 0; //변수 초기화
}

Node::~Node() //소멸자
{
}

void Node::SetData(int n) //SetData 함수
{
    m_Data = n; //m_Data에 n값 저장
}

void Node::SetNext(Node* pNext) //SetNext 함수
{
    m_pNext = pNext; //m_pNext에 pNext 저장
}

int Node::GetData() //GetData 함수
{
    return m_Data; //m_Data 반환
}

Node* Node::GetNext() //GetNext 함수
{
    return m_pNext; //m_pNext 반환
}

Stack::Stack() //생성자
{
    m_pHead = nullptr;
    m_size = 0;
    m_NumElement = 0; //변수 초기화

}
Stack::~Stack() //소멸자
{
}

void Stack::SetSize(int n) //SetSize 함수
{
    this->m_size = n; //m_size에 n값 저장
}
bool Stack::IsEmpty() //IsEmpty 함수
{
    if (this->m_NumElement == 0) //element 갯수가 0이면
        return true; //true 반환
    else //0이 아니면
        return false; //false 반환
}
bool Stack::IsFull() //IsFull 함수
{
    if (this->m_NumElement == this->m_size) //element 갯수가 size와 같다면
        return true; //true 반환
    else //그 외의 경우
        return false; //false 반환
}
bool Stack::Push(Node* pNode) //Push 함수
{
    if (IsFull()) //다 차있으면
        return false; //false 반환
    pNode->SetNext(m_pHead); //pNode의 다음 노드를 head로 설정
    m_pHead = pNode; //head가 pNode를 가리키게 설정
    m_NumElement++; //element 갯수 증가
    return true; //true 반환
}
Node* Stack::Pop()
{
    if (IsEmpty()) //비어있으면
        return nullptr; //nullptr 반환
    Node* temp = m_pHead; //temp가 head를 저장
    m_pHead = m_pHead->GetNext(); //head는 다음 노드를 가리키도록 함
    m_NumElement--; //element 갯수 감소
    return temp; //tmep 반환
}
void Stack::PrintStack(void) //PrintStack 함수
{
    for (Node* pCurrent = m_pHead; pCurrent != nullptr; pCurrent = pCurrent->GetNext()) {
        cout << pCurrent->GetData() << " "; //head부터 끝까지 출력
    }
    cout << endl;
}