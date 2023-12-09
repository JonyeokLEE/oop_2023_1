#include "header.h"

StudentScoreList::StudentScoreList() //생성자
{
	m_pHead = nullptr;
	m_pTail = nullptr; //변수 초기화
}

StudentScoreList::~StudentScoreList() //소멸자
{
}

void StudentScoreList::insert(Score* pScore) //insert 함수
{
	if (m_pHead == nullptr && m_pTail == nullptr) //아무런 노드가 없을 때
	{
		m_pHead = pScore;
		m_pTail = pScore; //새로운 노드를 head 및 tail로 설정
	}
	else
	{
		if (pScore->GetAvr() <= m_pHead->GetAvr()) //새 노드의 값이 맨 앞 노드의 값보다 작거나 같으면
		{
			pScore->SetNext(m_pHead); //새 노드의 다음 노드를 헤드로 설정
			m_pHead->SetPrev(pScore); //헤드의 전 노드를 새 노드로 설정
			m_pHead = pScore; //헤드가 새 노드를 가리키게 설정
			//즉, 처음 부분에 삽입
		}
		else if (pScore->GetAvr() >= m_pTail->GetAvr()) //새 노드의 값이 맨 뒤 노드의 값보다 크거나 같으면
		{
			pScore->SetPrev(m_pTail); //새 노드의 전 노드를 테일로 설정
			m_pTail->SetNext(pScore); //테일의 다음 노드를 새 노드로 설정
			m_pTail = pScore; //테일이 새 노드를 가리키게 설정
			//즉, 마지막 부분에 삽입
		}
		else //그 외의 경우 -> 중간에 삽입되는 경우
		{
			Score* pCurrent = m_pHead->GetNext(); //이동하면서 위치를 찾을 노드를 선언
			//헤드의 다음부터 시작
			while (pCurrent != nullptr) //끝까지 반복
			{
				if (pScore->GetAvr() <= pCurrent->GetAvr()) //만약 새 노드의 값보다 현재 노드의 값이 크거나 같으면
				{
					pScore->SetNext(pCurrent); //새 노드의 다음을 현재 노드로
					pScore->SetPrev(pCurrent->GetPrev()); //새 노드의 이전을 현재 노드의 앞 노드로
					pCurrent->GetPrev()->SetNext(pScore); //앞 노드의 다음을 새 노드로
					pCurrent->SetPrev(pScore); //현재 노드의 이전을 새 노드로
					break; //위치를 찾아 삽입했으니 반복문 탈출
				}
				pCurrent = pCurrent->GetNext(); //위치를 찾을 때까지 계속 next로 간다.
			}
		}
	}
}


void StudentScoreList::PrintList(bool isAscending) //PrintList 함수
{
	if (m_pHead == nullptr) //아무런 노드가 없다면
	{
		cout << "No element exists." << endl; //비었다는 안내문 출력
		return; //반환
	}

	if (isAscending) //true가 전달되면
	{
		for (Score* current = m_pHead; current != nullptr; current = current->GetNext())
		{
			cout << current->GetAvr() << " ";
		} //head부터 출력
	}
	else //false가 전달되면
	{
		for (Score* current = m_pTail; current != nullptr; current = current->GetPrev())
		{
			cout << current->GetAvr() << " ";
		} //tail부터 출력
	}
	cout << endl;
}

void StudentScoreList::deleteit()
{
	m_pTail = m_pTail->GetPrev();
	m_pTail->SetNext(NULL);
}



Score::Score() //생성자
{
	m_pNext = nullptr;
	m_pPrev = nullptr;
	m_Avg = 0; //변수 초기화
}

Score::~Score() //소멸자
{
}

void Score::SetAvg(double avg) //SetAvg 함수
{
	m_Avg = avg;
}

void Score::SetNext(Score* pNext) //SetNext 함수
{
	m_pNext = pNext;
}

void Score::SetPrev(Score* pPrev) //SetPrev 함수
{
	m_pPrev = pPrev;
}

double Score::GetAvr() //GetAvr 함수
{
	return m_Avg;
}

Score* Score::GetNext() //GetNext 함수
{
	return m_pNext;
}

Score* Score::GetPrev() //GetPrev 함수
{
	return m_pPrev;
}