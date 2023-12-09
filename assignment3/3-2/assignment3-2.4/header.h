#pragma once
#include <iostream>
using namespace std;

class Term
{
private:
	int m_Coefficient; //계수
	int m_Exponent; //지수
	Term* m_pNext; //다음 노드를 위한 변수

public:
	Term(); //생성자
	~Term(); //소멸자

	void SetCoeff(int coeff); //계수를 설정하는 함수
	void SetExponent(int exponent); //지수를 설정하는 함수
	int GetCoeff(); //계수를 반환하는 함수
	int GetExponent(); //지수를 반환하는 함수
	void SetNext(Term* pNext); //다음 노드를 세팅하는 함수
	Term* GetNext(); //m_pNext를 반환하는 함수
};


class Polynomial
{
private:
	Term* m_pHead; //헤드 노드
	char varible; //문자 변수

public:
	Polynomial(); //생성자
	~Polynomial(); //소멸자

	void Insert(Term* pTerm); //노드를 삽입하는 함수
	void PrintList(); //리스트를 출력하는 함수
	void setvarible(char set); //문자를 세팅하는 함수
	void Add(Polynomial& poly);
	void Sub(Polynomial& poly); //더하기와 빼기 함수
};
