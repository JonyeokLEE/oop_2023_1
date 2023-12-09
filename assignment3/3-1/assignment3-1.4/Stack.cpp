#include "Stack.h"

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
    m_Data = n; //m_Data�� n�� ����
}

void Node::SetNext(Node* pNext) //SetNext �Լ�
{
    m_pNext = pNext; //m_pNext�� pNext ����
}

int Node::GetData() //GetData �Լ�
{
    return m_Data; //m_Data ��ȯ
}

Node* Node::GetNext() //GetNext �Լ�
{
    return m_pNext; //m_pNext ��ȯ
}

Stack::Stack() //������
{
    m_pHead = nullptr;
    m_size = 0;
    m_NumElement = 0; //���� �ʱ�ȭ

}
Stack::~Stack() //�Ҹ���
{
}

void Stack::SetSize(int n) //SetSize �Լ�
{
    this->m_size = n; //m_size�� n�� ����
}
bool Stack::IsEmpty() //IsEmpty �Լ�
{
    if (this->m_NumElement == 0) //element ������ 0�̸�
        return true; //true ��ȯ
    else //0�� �ƴϸ�
        return false; //false ��ȯ
}
bool Stack::IsFull() //IsFull �Լ�
{
    if (this->m_NumElement == this->m_size) //element ������ size�� ���ٸ�
        return true; //true ��ȯ
    else //�� ���� ���
        return false; //false ��ȯ
}
bool Stack::Push(Node* pNode) //Push �Լ�
{
    if (IsFull()) //�� ��������
        return false; //false ��ȯ
    pNode->SetNext(m_pHead); //pNode�� ���� ��带 head�� ����
    m_pHead = pNode; //head�� pNode�� ����Ű�� ����
    m_NumElement++; //element ���� ����
    return true; //true ��ȯ
}
Node* Stack::Pop()
{
    if (IsEmpty()) //���������
        return nullptr; //nullptr ��ȯ
    Node* temp = m_pHead; //temp�� head�� ����
    m_pHead = m_pHead->GetNext(); //head�� ���� ��带 ����Ű���� ��
    m_NumElement--; //element ���� ����
    return temp; //tmep ��ȯ
}
void Stack::PrintStack(void) //PrintStack �Լ�
{
    for (Node* pCurrent = m_pHead; pCurrent != nullptr; pCurrent = pCurrent->GetNext()) {
        cout << pCurrent->GetData() << " "; //head���� ������ ���
    }
    cout << endl;
}