#include "header.h"

Node::Node() //생성자
{
	pNext = nullptr;
	data = 0; //private 변수 초기화
}

Node::~Node() //소멸자
{
}

void Node::setdata(int n) //setdata 함수
{
	data = n; //data가 n에 값을 저장
}

void Node::setNext(Node* next) //setNext 함수
{
	pNext = next; //pNext에 next 값을 저장
}

int Node::getdata() //getdata 함수
{
	return data; //data를 반환
}

Node* Node::getNext() //getNext 함수
{
	return pNext; //pNext를 반환
}

LinkedList::LinkedList() //생성자
{
	pHead = nullptr;
	pTail = nullptr;
}

LinkedList::~LinkedList() //소멸자
{
}

Node* LinkedList::getHead() //getHead 함수
{
	return pHead; //pHead를 반환
}


void LinkedList::insertsort() //insertsort 함수
{
	if (pHead == NULL || pHead->getNext() == NULL) //pHead와 pHead 다음 노드가 NULL 일때 (즉, 노드가 없거나 하나만 있을때)
	{
		return; //return, 함수 종료
	}

	Node* sorted = NULL; //sorted 된 결과를 위한 노드 생성
	Node* cur = pHead; //cur는 헤드부터 시작한다

	while (cur != NULL) //cur이 NULL이 아닐동안 반복
	{
		Node* curnext = cur->getNext();
		if (sorted == NULL || cur->getdata() > sorted->getdata()) //sorted에 아무것도 없거나 cur이 sorted보다 큰 경우
		{
			cur->setNext(sorted); //cur 뒤에 sorted 연결
			sorted = cur; //sorted의 값을 cur로 설정
		}
		else {
			Node* temp = sorted; //temp를 sorted로 설정
			while (temp->getNext() != NULL && temp->getNext()->getdata() > cur->getdata())
			{	//temp의 다음이 NULL이 아니고, temp의 다음 노드가 cur보다 클동안 반복
				temp = temp->getNext(); //temp를 다음 노드로
			}
			cur->setNext(temp->getNext()); //cur의 다음을 temp의 다음으로 설정
			temp->setNext(cur); //temp의 다음노드를 cur로 설정
		}
		cur = curnext; //cur 이동
	}
	pHead = sorted; //sort 완료된 리스트를 pHead 로 연결
}


Node* LinkedList::Binary_Search(Node* p, int n) //Binary_Search 함수
{
	int headidx = 0, tailidx = 15; //처음과 끝 인덱스 선언
	Node* cur = nullptr; //cur은 초기화한 상태로 선언
	while (headidx <= tailidx) //head의 인덱스가 tail의 인덱스보다 작거나 같을동안 반복
	{
		Node* midNode = setMiddle(p, tailidx-headidx); //midNode를 setMiddle를 통해 구하기
		cout << midNode->getdata() << " " << endl;
		if (midNode->getdata() == n) //만약 midNode가 찾는 값과 동일하다면
		{
			return midNode; //return
		}
		else if (midNode->getdata() < n) //만약 작다면
		{
			headidx = (headidx + tailidx) / 2 + 1; //head인덱스 업데이트
		}
		else //만약 크다면
		{
			tailidx = (headidx + tailidx) / 2 - 1; //tail인덱스 업데이트
		}
	}
	//이랬는데도 return이 안되면 같은 값이 없다는 뜻이니 절대값 근사도가 높은 노드 찾기
	Node* closest = nullptr; //closest 노드 선언
	int maxone = p->getdata();
	if (maxone < n) return p; //노드의 최댓값 요소보다 n이 큰 경우 처리하는 부분
	int realdiff = abs(p->getdata() - n); //abs(절댓값 함수)를 이용해서 최소 근삿값 초기화
	while (p != nullptr) //p 노드가 끝나지 않을때까지
	{
		int diff = abs(p->getdata() - n); //단순 근삿값 계산
		if (diff < realdiff) //기존에 저장해놓은 최소 근삿값보다 지금 구한 근삿값이 더 작으면
		{
			realdiff = diff; //업데이트
			closest = p; //해당 노드를 후보로 저장
		}
		p = p->getNext(); //p는 다음 노드로 계속 이동
	}
	return closest; //최종 closest 노드 반환
}

Node* LinkedList::setMiddle(Node* start, int size) //setMiddle 함수
{
	Node* pMiddle = start; //해당 노드를 저장하고

	for (int i = 0; i < (size+1 / 2); i++) //크기에 맞게 중간을 찾아서
		pMiddle = pMiddle->getNext();
	return pMiddle; //반환
}

void LinkedList::insertNew(Node* next) //insertNew 함수
{
	if (pHead == nullptr) //아무것도 없었으면
	{
		pHead = next;
		pTail = next; //head랑 tail 둘다 해당 인덱스 가리키기
	}
	else //그 외의 경우
	{
		pTail->setNext(next); //tail의 다음 노드로 next를 설정하고
		pTail = next; //tail을 next로 설정
	}
}

void LinkedList::printlist() //printlist 함수
{
	for (Node* curr = pHead; curr != nullptr; curr=curr->getNext()) //head부터 끝까지 반복
	{
		cout << curr->getdata() << " "; //출력
	}cout << endl;
}

