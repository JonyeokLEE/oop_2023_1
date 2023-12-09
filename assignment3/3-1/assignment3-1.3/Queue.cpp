#include "Queue.h"

Node::Node() //������
{
	m_pNext = nullptr;
	m_Data = 0; //���� �ʱ�ȭ
}

Node::~Node() //�Ҹ���
{
}

void Node::SetData(int n) //SetData �Լ�
{
	this->m_Data = n; //m_Data�� ���� n�� ������ �����Ѵ�.
}

void Node::SetNext(Node* pNext) //SetNext �Լ�
{
	this->m_pNext = pNext; //m_pNext�� ���� pNext�� �����Ѵ�.
}

int Node::GetData() //GetData �Լ�
{
	return this->m_Data; //m_Data ��ȯ
}

Node* Node::GetNext() //GetNext �Լ�
{
	return this->m_pNext; //m_pNext ��ȯ
}

Queue::Queue() //������
{
	m_pHead = nullptr;
	m_pTail = nullptr;
	m_size = 0;
	m_NumElement = 0; //���� �ʱ�ȭ
}

Queue::~Queue() //�Ҹ���
{
}

void Queue::SetSize(int n) //SetSize �Լ�
{
	this->m_size = n; //m_size�� n���� ����
}

bool Queue::IsEmpty() //IsEmpty �Լ�
{
	if (this->m_NumElement == 0) //Element ������ 0�̸�
		return true; //true ��ȯ

	else //Element ������ 0�� �ƴϸ�
		return false; //false ��ȯ
}

bool Queue::IsFull() //IsFull �Լ�
{
	if (this->m_NumElement == this->m_size) //Element�� ������ Size�� ���ٸ�
		return true; //true ��ȯ
	else //Element�� ������ Size�� ���� �ʴٸ�
		return false; //false ��ȯ
}

bool Queue::Push(Node* pNode) //Push �Լ�
{
	if (IsFull()) //�� ��������
		return false; //false ��ȯ

	if (IsEmpty()) //���������
	{
		m_pHead = pNode;
		m_pTail = pNode; //head�� tail�� pNode�� ����
		m_NumElement++; //element ���� ����
		return true; //true ��ȯ
	}
	else //������� �ʴٸ�
	{
		m_pTail->SetNext(pNode); //tail�� ������带 pNode��
		m_pTail = pNode; //tail�� pNode�� ����
		m_NumElement++; //element ���� ����
		return true; //true ��ȯ
	}
}

Node* Queue::Pop() //Pop �Լ�
{
	if (IsEmpty()) //����ִٸ�
		return nullptr; //nullptr ��ȯ
	Node* temp = m_pHead; //�ӽ� ����� temp�� head�� ����Ű��
	m_pHead = m_pHead->GetNext(); //head�� ���� ��带 ����Ų��.
	m_NumElement--; //element ���� ����
	return temp; //temp ��ȯ
}

void Queue::PrintQueue() //PrintQueue �Լ�
{
	for (Node* pCurrent = m_pHead; pCurrent != nullptr; pCurrent = pCurrent->GetNext()) {
		cout << pCurrent->GetData() << " "; //head���� ������ ����Ѵ�.
	}
	cout << endl;
}