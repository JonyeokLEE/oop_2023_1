#include "SortList.h"

Node::Node() //생성자
{
	m_pNext = nullptr;
	m_Data = ""; //변수 초기화
}

Node::~Node() //소멸자
{
}

void Node::SetData(string data) //SetData 함수
{
	m_Data = data; //m_Data에 data 복사
}

void Node::SetNext(Node* pNext) //SetNext 함수
{
	m_pNext = pNext; //m_pNext에 pNext 복사
}

string Node::GetData() const //GetData 함수
{
	return m_Data; //m_Data 반환
}

Node* Node::GetNext() const //GetNext 함수
{
	return m_pNext; //m_pNext 반환
}

LinkedList::LinkedList() //생성자
{
	m_pHead = nullptr; //변수 초기화
}

LinkedList::~LinkedList() //소멸자
{
	Node* current = m_pHead;
	while (current != nullptr) {
		Node* temp = current;
		current = current->GetNext();
		delete temp;
	} //소멸되면서 기존에 m_pHead를 시작으로 연결되어 있던 노드들 해제
}

void LinkedList::setHead(Node* pHead) //setHead 함수
{
	m_pHead = pHead; //m_pHead에 pHead 복사
}

void LinkedList::Merge_List(Node* p1, Node* p2, Node* p3) //Merge_List 함수
{
    while (p1 != nullptr && p2 != nullptr) //둘중 하나가 끝나기 전까지
    {
        if (_strcmpi(p1->GetData().c_str(), p2->GetData().c_str()) < 0)
        {
            //_strcmpi 함수를 통해 value값 비교, p1이 더 작으면
            p3->SetNext(p1); //p3에 p1 연결
            p3 = p3->GetNext();
            p1 = p1->GetNext(); //다음으로 넘어가기
        }
        else //p2가 더 작으면
        {
            p3->SetNext(p2); //p3에 p2 연결
            p3 = p3->GetNext();
            p2 = p2->GetNext(); //다음으로 넘어가기
        }
    }
    if (p1 != nullptr) //p2가 빨리 끝났으면
    {
        p3->SetNext(p1); //p1 나머지를 연결
    }
    else //p1이 빨리 끝났으면
    {
        p3->SetNext(p2); //p2 나머지를 연결
    }
}

void LinkedList::printList(void) //printList 함수
{
    while (m_pHead != nullptr)
    {
        cout << m_pHead->GetData() << " ";
        m_pHead = m_pHead->GetNext(); //m_pHead를 시작으로 끝까지 출력
    }
}
