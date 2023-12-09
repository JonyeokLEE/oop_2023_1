#include "header.h"

StudentScoreList::StudentScoreList() //������
{
	m_pHead = nullptr;
	m_pTail = nullptr; //���� �ʱ�ȭ
}

StudentScoreList::~StudentScoreList() //�Ҹ���
{
}

void StudentScoreList::insert(Score* pScore) //insert �Լ�
{
	if (m_pHead == nullptr && m_pTail == nullptr) //�ƹ��� ��尡 ���� ��
	{
		m_pHead = pScore;
		m_pTail = pScore; //���ο� ��带 head �� tail�� ����
	}
	else
	{
		if (pScore->GetAvr() <= m_pHead->GetAvr()) //�� ����� ���� �� �� ����� ������ �۰ų� ������
		{
			pScore->SetNext(m_pHead); //�� ����� ���� ��带 ���� ����
			m_pHead->SetPrev(pScore); //����� �� ��带 �� ���� ����
			m_pHead = pScore; //��尡 �� ��带 ����Ű�� ����
			//��, ó�� �κп� ����
		}
		else if (pScore->GetAvr() >= m_pTail->GetAvr()) //�� ����� ���� �� �� ����� ������ ũ�ų� ������
		{
			pScore->SetPrev(m_pTail); //�� ����� �� ��带 ���Ϸ� ����
			m_pTail->SetNext(pScore); //������ ���� ��带 �� ���� ����
			m_pTail = pScore; //������ �� ��带 ����Ű�� ����
			//��, ������ �κп� ����
		}
		else //�� ���� ��� -> �߰��� ���ԵǴ� ���
		{
			Score* pCurrent = m_pHead->GetNext(); //�̵��ϸ鼭 ��ġ�� ã�� ��带 ����
			//����� �������� ����
			while (pCurrent != nullptr) //������ �ݺ�
			{
				if (pScore->GetAvr() <= pCurrent->GetAvr()) //���� �� ����� ������ ���� ����� ���� ũ�ų� ������
				{
					pScore->SetNext(pCurrent); //�� ����� ������ ���� ����
					pScore->SetPrev(pCurrent->GetPrev()); //�� ����� ������ ���� ����� �� ����
					pCurrent->GetPrev()->SetNext(pScore); //�� ����� ������ �� ����
					pCurrent->SetPrev(pScore); //���� ����� ������ �� ����
					break; //��ġ�� ã�� ���������� �ݺ��� Ż��
				}
				pCurrent = pCurrent->GetNext(); //��ġ�� ã�� ������ ��� next�� ����.
			}
		}
	}
}


void StudentScoreList::PrintList(bool isAscending) //PrintList �Լ�
{
	if (m_pHead == nullptr) //�ƹ��� ��尡 ���ٸ�
	{
		cout << "No element exists." << endl; //����ٴ� �ȳ��� ���
		return; //��ȯ
	}

	if (isAscending) //true�� ���޵Ǹ�
	{
		for (Score* current = m_pHead; current != nullptr; current = current->GetNext())
		{
			cout << current->GetAvr() << " ";
		} //head���� ���
	}
	else //false�� ���޵Ǹ�
	{
		for (Score* current = m_pTail; current != nullptr; current = current->GetPrev())
		{
			cout << current->GetAvr() << " ";
		} //tail���� ���
	}
	cout << endl;
}

void StudentScoreList::deleteit()
{
	m_pTail = m_pTail->GetPrev();
	m_pTail->SetNext(NULL);
}



Score::Score() //������
{
	m_pNext = nullptr;
	m_pPrev = nullptr;
	m_Avg = 0; //���� �ʱ�ȭ
}

Score::~Score() //�Ҹ���
{
}

void Score::SetAvg(double avg) //SetAvg �Լ�
{
	m_Avg = avg;
}

void Score::SetNext(Score* pNext) //SetNext �Լ�
{
	m_pNext = pNext;
}

void Score::SetPrev(Score* pPrev) //SetPrev �Լ�
{
	m_pPrev = pPrev;
}

double Score::GetAvr() //GetAvr �Լ�
{
	return m_Avg;
}

Score* Score::GetNext() //GetNext �Լ�
{
	return m_pNext;
}

Score* Score::GetPrev() //GetPrev �Լ�
{
	return m_pPrev;
}