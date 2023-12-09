#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node //Node 클래스
{
private:
    Node* m_pNext; //다음 노드를 위한 변수
    string m_Data; //문자열을 위한 변수

public:
    Node(); //생성자
    ~Node(); //소멸자

    void SetData(string data); //전달받은 문자열을 저장하는 함수
    void SetNext(Node* pNext); //다음 노드를 가리키기 위한 함수
    string GetData() const; //m_Data를 반환하는 함수
    Node* GetNext() const; //m_pNext를 반환하는 함수
};

class LinkedList //LinkedList 클래스
{
private:
    Node* m_pHead; //head를 나타내는 변수

public:
    LinkedList(); //생성자
    ~LinkedList(); //소멸자
    void setHead(Node* pHead); //head를 설정하는 함수
    void Merge_List(Node* p1, Node* p2, Node* p3); //Merge_Sort를 구현한 함수
    void printList(void); //List를 출력하는 함수
};