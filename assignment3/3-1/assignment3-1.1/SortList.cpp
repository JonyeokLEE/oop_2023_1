#include "SortList.h"

Node::Node() //������
{
	m_pNext = nullptr;
	m_Data = ""; //���� �ʱ�ȭ
}

Node::~Node() //�Ҹ���
{
}

void Node::SetData(string data) //SetData �Լ�
{
	m_Data = data; //m_Data�� data ����
}

void Node::SetNext(Node* pNext) //SetNext �Լ�
{
	m_pNext = pNext; //m_pNext�� pNext ����
}

string Node::GetData() const //GetData �Լ�
{
	return m_Data; //m_Data ��ȯ
}

Node* Node::GetNext() const //GetNext �Լ�
{
	return m_pNext; //m_pNext ��ȯ
}

LinkedList::LinkedList() //������
{
	m_pHead = nullptr; //���� �ʱ�ȭ
}

LinkedList::~LinkedList() //�Ҹ���
{
	Node* current = m_pHead;
	while (current != nullptr) {
		Node* temp = current;
		current = current->GetNext();
		delete temp;
	} //�Ҹ�Ǹ鼭 ������ m_pHead�� �������� ����Ǿ� �ִ� ���� ����
}

void LinkedList::setHead(Node* pHead) //setHead �Լ�
{
	m_pHead = pHead; //m_pHead�� pHead ����
}

void LinkedList::Merge_List(Node* p1, Node* p2, Node* p3) //Merge_List �Լ�
{
    while (p1 != nullptr && p2 != nullptr) //���� �ϳ��� ������ ������
    {
        if (_strcmpi(p1->GetData().c_str(), p2->GetData().c_str()) < 0)
        {
            //_strcmpi �Լ��� ���� value�� ��, p1�� �� ������
            p3->SetNext(p1); //p3�� p1 ����
            p3 = p3->GetNext();
            p1 = p1->GetNext(); //�������� �Ѿ��
        }
        else //p2�� �� ������
        {
            p3->SetNext(p2); //p3�� p2 ����
            p3 = p3->GetNext();
            p2 = p2->GetNext(); //�������� �Ѿ��
        }
    }
    if (p1 != nullptr) //p2�� ���� ��������
    {
        p3->SetNext(p1); //p1 �������� ����
    }
    else //p1�� ���� ��������
    {
        p3->SetNext(p2); //p2 �������� ����
    }
}

void LinkedList::printList(void) //printList �Լ�
{
    while (m_pHead != nullptr)
    {
        cout << m_pHead->GetData() << " ";
        m_pHead = m_pHead->GetNext(); //m_pHead�� �������� ������ ���
    }
}
