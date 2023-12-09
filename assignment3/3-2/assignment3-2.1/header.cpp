#include "header.h"

Node::Node() //������
{
	pNext = nullptr;
	data = 0; //private ���� �ʱ�ȭ
}

Node::~Node() //�Ҹ���
{
}

void Node::setdata(int n) //setdata �Լ�
{
	data = n; //data�� n�� ���� ����
}

void Node::setNext(Node* next) //setNext �Լ�
{
	pNext = next; //pNext�� next ���� ����
}

int Node::getdata() //getdata �Լ�
{
	return data; //data�� ��ȯ
}

Node* Node::getNext() //getNext �Լ�
{
	return pNext; //pNext�� ��ȯ
}

LinkedList::LinkedList() //������
{
	pHead = nullptr;
	pTail = nullptr;
}

LinkedList::~LinkedList() //�Ҹ���
{
}

Node* LinkedList::getHead() //getHead �Լ�
{
	return pHead; //pHead�� ��ȯ
}


void LinkedList::insertsort() //insertsort �Լ�
{
	if (pHead == NULL || pHead->getNext() == NULL) //pHead�� pHead ���� ��尡 NULL �϶� (��, ��尡 ���ų� �ϳ��� ������)
	{
		return; //return, �Լ� ����
	}

	Node* sorted = NULL; //sorted �� ����� ���� ��� ����
	Node* cur = pHead; //cur�� ������ �����Ѵ�

	while (cur != NULL) //cur�� NULL�� �ƴҵ��� �ݺ�
	{
		Node* curnext = cur->getNext();
		if (sorted == NULL || cur->getdata() > sorted->getdata()) //sorted�� �ƹ��͵� ���ų� cur�� sorted���� ū ���
		{
			cur->setNext(sorted); //cur �ڿ� sorted ����
			sorted = cur; //sorted�� ���� cur�� ����
		}
		else {
			Node* temp = sorted; //temp�� sorted�� ����
			while (temp->getNext() != NULL && temp->getNext()->getdata() > cur->getdata())
			{	//temp�� ������ NULL�� �ƴϰ�, temp�� ���� ��尡 cur���� Ŭ���� �ݺ�
				temp = temp->getNext(); //temp�� ���� ����
			}
			cur->setNext(temp->getNext()); //cur�� ������ temp�� �������� ����
			temp->setNext(cur); //temp�� ������带 cur�� ����
		}
		cur = curnext; //cur �̵�
	}
	pHead = sorted; //sort �Ϸ�� ����Ʈ�� pHead �� ����
}


Node* LinkedList::Binary_Search(Node* p, int n) //Binary_Search �Լ�
{
	int headidx = 0, tailidx = 15; //ó���� �� �ε��� ����
	Node* cur = nullptr; //cur�� �ʱ�ȭ�� ���·� ����
	while (headidx <= tailidx) //head�� �ε����� tail�� �ε������� �۰ų� �������� �ݺ�
	{
		Node* midNode = setMiddle(p, tailidx-headidx); //midNode�� setMiddle�� ���� ���ϱ�
		cout << midNode->getdata() << " " << endl;
		if (midNode->getdata() == n) //���� midNode�� ã�� ���� �����ϴٸ�
		{
			return midNode; //return
		}
		else if (midNode->getdata() < n) //���� �۴ٸ�
		{
			headidx = (headidx + tailidx) / 2 + 1; //head�ε��� ������Ʈ
		}
		else //���� ũ�ٸ�
		{
			tailidx = (headidx + tailidx) / 2 - 1; //tail�ε��� ������Ʈ
		}
	}
	//�̷��µ��� return�� �ȵǸ� ���� ���� ���ٴ� ���̴� ���밪 �ٻ絵�� ���� ��� ã��
	Node* closest = nullptr; //closest ��� ����
	int maxone = p->getdata();
	if (maxone < n) return p; //����� �ִ� ��Һ��� n�� ū ��� ó���ϴ� �κ�
	int realdiff = abs(p->getdata() - n); //abs(���� �Լ�)�� �̿��ؼ� �ּ� �ٻ� �ʱ�ȭ
	while (p != nullptr) //p ��尡 ������ ����������
	{
		int diff = abs(p->getdata() - n); //�ܼ� �ٻ� ���
		if (diff < realdiff) //������ �����س��� �ּ� �ٻ񰪺��� ���� ���� �ٻ��� �� ������
		{
			realdiff = diff; //������Ʈ
			closest = p; //�ش� ��带 �ĺ��� ����
		}
		p = p->getNext(); //p�� ���� ���� ��� �̵�
	}
	return closest; //���� closest ��� ��ȯ
}

Node* LinkedList::setMiddle(Node* start, int size) //setMiddle �Լ�
{
	Node* pMiddle = start; //�ش� ��带 �����ϰ�

	for (int i = 0; i < (size+1 / 2); i++) //ũ�⿡ �°� �߰��� ã�Ƽ�
		pMiddle = pMiddle->getNext();
	return pMiddle; //��ȯ
}

void LinkedList::insertNew(Node* next) //insertNew �Լ�
{
	if (pHead == nullptr) //�ƹ��͵� ��������
	{
		pHead = next;
		pTail = next; //head�� tail �Ѵ� �ش� �ε��� ����Ű��
	}
	else //�� ���� ���
	{
		pTail->setNext(next); //tail�� ���� ���� next�� �����ϰ�
		pTail = next; //tail�� next�� ����
	}
}

void LinkedList::printlist() //printlist �Լ�
{
	for (Node* curr = pHead; curr != nullptr; curr=curr->getNext()) //head���� ������ �ݺ�
	{
		cout << curr->getdata() << " "; //���
	}cout << endl;
}

