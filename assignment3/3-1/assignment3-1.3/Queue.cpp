#include "Queue.h"

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
	this->m_Data = n; //m_Data의 값을 n의 값으로 설정한다.
}

void Node::SetNext(Node* pNext) //SetNext 함수
{
	this->m_pNext = pNext; //m_pNext의 값을 pNext로 설정한다.
}

int Node::GetData() //GetData 함수
{
	return this->m_Data; //m_Data 반환
}

Node* Node::GetNext() //GetNext 함수
{
	return this->m_pNext; //m_pNext 반환
}

Queue::Queue() //생성자
{
	m_pHead = nullptr;
	m_pTail = nullptr;
	m_size = 0;
	m_NumElement = 0; //변수 초기화
}

Queue::~Queue() //소멸자
{
}

void Queue::SetSize(int n) //SetSize 함수
{
	this->m_size = n; //m_size를 n으로 설정
}

bool Queue::IsEmpty() //IsEmpty 함수
{
	if (this->m_NumElement == 0) //Element 갯수가 0이면
		return true; //true 반환

	else //Element 갯수가 0이 아니면
		return false; //false 반환
}

bool Queue::IsFull() //IsFull 함수
{
	if (this->m_NumElement == this->m_size) //Element의 갯수가 Size와 같다면
		return true; //true 반환
	else //Element의 갯수가 Size와 같지 않다면
		return false; //false 반환
}

bool Queue::Push(Node* pNode) //Push 함수
{
	if (IsFull()) //다 차있으면
		return false; //false 반환

	if (IsEmpty()) //비어있으면
	{
		m_pHead = pNode;
		m_pTail = pNode; //head와 tail을 pNode로 설정
		m_NumElement++; //element 갯수 증가
		return true; //true 반환
	}
	else //비어있지 않다면
	{
		m_pTail->SetNext(pNode); //tail의 다음노드를 pNode로
		m_pTail = pNode; //tail을 pNode로 설정
		m_NumElement++; //element 갯수 증가
		return true; //true 반환
	}
}

Node* Queue::Pop() //Pop 함수
{
	if (IsEmpty()) //비어있다면
		return nullptr; //nullptr 반환
	Node* temp = m_pHead; //임시 노드인 temp는 head를 가리키고
	m_pHead = m_pHead->GetNext(); //head는 다음 노드를 가리킨다.
	m_NumElement--; //element 갯수 감소
	return temp; //temp 반환
}

void Queue::PrintQueue() //PrintQueue 함수
{
	for (Node* pCurrent = m_pHead; pCurrent != nullptr; pCurrent = pCurrent->GetNext()) {
		cout << pCurrent->GetData() << " "; //head부터 끝까지 출력한다.
	}
	cout << endl;
}