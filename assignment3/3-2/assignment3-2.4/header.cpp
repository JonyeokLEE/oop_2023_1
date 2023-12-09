#include "header.h"

Term::Term() //생성자
{
	m_Coefficient = 0;
	m_Exponent = 0;
	m_pNext = nullptr; //변수 초기화
}

Term::~Term() //소멸자
{
}

void Term::SetCoeff(int coeff) //SetCoeff 함수
{
	m_Coefficient = coeff; //coeff를 저장
}

void Term::SetExponent(int exponent) //SetExponent 함수
{
	m_Exponent = exponent; //exponent를 저장
}

int Term::GetCoeff() //GetCoeff 함수
{
	return m_Coefficient; //계수 반환
}

int Term::GetExponent() //GetExponent 함수
{
	return m_Exponent; //지수 반환
}

void Term::SetNext(Term* pNext) //SetNext 함수
{
	m_pNext = pNext; //pNext 저장
}

Term* Term::GetNext() //GetNext 함수
{
	return m_pNext; //m_pNext 반환
}

Polynomial::Polynomial()
{
	m_pHead = nullptr;
	varible = 0; //변수 초기화
}

Polynomial::~Polynomial() //소멸자
{
}

void Polynomial::Insert(Term* pTerm) //Insert 함수
{
	if (m_pHead == nullptr || m_pHead->GetExponent() < pTerm->GetExponent())
	{	//리스트에 아무것도 없거나 head의 지수가 새 노드의 지수보다 작으면
		pTerm->SetNext(m_pHead); //새 노드의 다음 노드를 head로
		m_pHead = pTerm; //head는 pTerm을 가리킨다.
		//즉 리스트 맨 앞에 삽입하는 과정!
	}
	else //그 외의 경우
	{	//알맞는 자리를 찾는 과정
		Term* curr = m_pHead; //head부터 시작
		while (curr->GetNext() != nullptr && curr->GetNext()->GetExponent() > pTerm->GetExponent())
			curr = curr->GetNext(); //curr의 다음노드가 있거나, 그 다음 노드의 지수가 새 노드의 지수보다 클 동안 계속 이동
		pTerm->SetNext(curr->GetNext()); //pTerm의 다음 노드를 curr의 다음 노드로 설정
		curr->SetNext(pTerm); //curr의 다음 노드를 pTerm으로 설정
	}
}

void Polynomial::PrintList() //PrintList 함수
{
	for (Term* curr = m_pHead; curr != nullptr; curr = curr->GetNext())
	{	//처음부터 끝까지 출력
		cout << curr->GetCoeff() << varible << "^" << curr->GetExponent(); //r계수와 변수와 지수 출력
		if ((curr->GetNext() != nullptr)&&(curr->GetNext()->GetCoeff()>0))//뒤에가 끝이 아니고 다음 요소가 양수라면
		{
				cout << "+"; //+출력
		}
	}
	cout << endl;
}

void Polynomial::setvarible(char set) //setvarible 함수
{
	varible = set; //set 저장
}

void Polynomial::Add(Polynomial& poly) //Add 함수
{
	Term* curr1 = m_pHead; //curr1은 식 1의 head
	Term* curr2 = poly.m_pHead; //curr2는 식 2의 head에서 시작
	Polynomial result; //결과값을 받는 함수

	while (curr1 != nullptr && curr2 != nullptr) //둘 중 하나라도 끝나기 전까지
	{
		if (curr1->GetExponent() == curr2->GetExponent()) //둘의 지수가 같으면
		{
			int add = curr1->GetCoeff() + curr2->GetCoeff(); //두 계수를 더한 값을 저장
			if (add != 0) //더한 값이 0이 아니면
			{
				Term* temp = new Term; //새 노드 생성
				temp->SetCoeff(add); //더한 값을 계수로 설정
				temp->SetExponent(curr1->GetExponent()); //지수는 원래꺼 그대로 세팅
				result.Insert(temp); //temp를 result로 넣기
			}
			curr1 = curr1->GetNext();
			curr2 = curr2->GetNext(); //둘다 다음 노드로
		}
		else if (curr1->GetExponent() > curr2->GetExponent()) //만약 curr1의 지수가 더 크면
		{
			Term* temp = new Term; //새 노드 생성
			temp->SetCoeff(curr1->GetCoeff());
			temp->SetExponent(curr1->GetExponent()); //curr1의 값을 받기
			result.Insert(temp); //temp를 result에 삽입
			curr1 = curr1->GetNext(); //다음 노드로
		}
		else
		{
			Term* temp = new Term; //새 노드 생성
			temp->SetCoeff(curr2->GetCoeff());
			temp->SetExponent(curr2->GetExponent()); //curr2의 값을 받기
			result.Insert(temp); //temp를 result에 삽입
			curr2 = curr2->GetNext(); //다음 노드로
		}
	}

	while (curr1 != nullptr) //curr1이 아직 남았으면
	{
		Term* temp = new Term; //새 노드 생성
		temp->SetCoeff(curr1->GetCoeff());
		temp->SetExponent(curr1->GetExponent()); //curr1의 값을 받기
		result.Insert(temp); //temp를 result에 삽입
		curr1 = curr1->GetNext(); //다음 노드로
	}

	while (curr2 != nullptr) //curr2이 아직 남았으면
	{
		Term* temp = new Term; //새 노드 생성
		temp->SetCoeff(curr2->GetCoeff());
		temp->SetExponent(curr2->GetExponent()); //curr2의 값을 받기
		result.Insert(temp); //temp를 result에 삽입
		curr2 = curr2->GetNext(); //다음 노드로
	}

	m_pHead = result.m_pHead; //result head를 저장
}

void Polynomial::Sub(Polynomial& poly)
{
	Term* curr1 = m_pHead; //curr1은 식 1의 head
	Term* curr2 = poly.m_pHead; //curr2는 식 2의 head에서 시작
	Polynomial result; //결과값을 받는 함수

	while (curr1 != nullptr && curr2 != nullptr) //둘 중 하나라도 끝나기 전까지
	{
		if (curr1->GetExponent() == curr2->GetExponent()) //둘의 지수가 같으면
		{
			int sub = curr1->GetCoeff() - curr2->GetCoeff(); //두 계수를 더한 값을 저장
			if (sub != 0) //더한 값이 0이 아니면
			{
				Term* temp = new Term; //새 노드 생성
				temp->SetCoeff(sub); //더한 값을 계수로 설정
				temp->SetExponent(curr1->GetExponent()); //지수는 원래꺼 그대로 세팅
				result.Insert(temp); //temp를 result로 넣기
			}
			curr1 = curr1->GetNext();
			curr2 = curr2->GetNext(); //둘다 다음 노드로
		}
		else if (curr1->GetExponent() > curr2->GetExponent()) //만약 curr1의 지수가 더 크면
		{
			Term* temp = new Term; //새 노드 생성
			temp->SetCoeff(curr1->GetCoeff());
			temp->SetExponent(curr1->GetExponent()); //curr1의 값을 받기
			result.Insert(temp); //temp를 result에 삽입
			curr1 = curr1->GetNext(); //다음 노드로
		}
		else
		{
			Term* temp = new Term; //새 노드 생성
			temp->SetCoeff(-1*curr2->GetCoeff()); //2번 식을 빼는 것이니 음수 붙이기
			temp->SetExponent(curr2->GetExponent()); //curr2의 값을 받기
			result.Insert(temp); //temp를 result에 삽입
			curr2 = curr2->GetNext(); //다음 노드로
		}
	}

	while (curr1 != nullptr) //curr1이 아직 남았으면
	{
		Term* temp = new Term; //새 노드 생성
		temp->SetCoeff(curr1->GetCoeff());
		temp->SetExponent(curr1->GetExponent()); //curr1의 값을 받기
		result.Insert(temp); //temp를 result에 삽입
		curr1 = curr1->GetNext(); //다음 노드로
	}

	while (curr2 != nullptr) //curr2이 아직 남았으면
	{
		Term* temp = new Term; //새 노드 생성
		temp->SetCoeff(-1*curr2->GetCoeff()); //2번 식을 빼는 것이니 음수 붙이기
		temp->SetExponent(curr2->GetExponent()); //curr2의 값을 받기
		result.Insert(temp); //temp를 result에 삽입
		curr2 = curr2->GetNext(); //다음 노드로
	}

	m_pHead = result.m_pHead; //result head를 저장
}
