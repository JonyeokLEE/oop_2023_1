#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Node //Node 클래스
{
private:
	Node* pNext; //다음을 가리키는 변수
	int data; //정수형 데이터 변수

public:
	Node(); //생성자
	~Node(); //소멸자

	void setdata(int n); //data를 n으로 세팅하는 함수
	void setNext(Node* next); //다음 노드를 세팅하는 함수
	int getdata(); //data를 return하는 함수
	Node* getNext(); //pNext를 return하는 함수
};

class LinkedList //LinkedList 클래스
{
private:
	Node* pHead; //head 노드
	Node* pTail; //tail 노드

public:
	LinkedList(); //생성자
	~LinkedList(); //소멸자
	Node* getHead(); //pHead를 return하는 함수
	void insertsort(); //insertsort를 수행하는 함수
	Node* Binary_Search(Node* p, int n); //BinarySearch를 수행하는 함수
	void insertNew(Node* next); //새로운 노드를 삽입하는 함수
	void printlist(); //링크드리스트 전체를 출력하는 함수
	Node* setMiddle(Node* start, int size); //가운데 노드를 set하는 함수
};