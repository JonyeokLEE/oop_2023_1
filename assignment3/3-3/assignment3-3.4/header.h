#include <iostream>
using namespace std;

class Score
{
private:
	Score* m_pNext; //������ ����Ű�� ������
	Score* m_pPrev; //������ ����Ű�� ������
	double m_Avg; //��� ������

public:
	Score(); //������
	~Score(); //�Ҹ���
	void SetAvg(double avg);
	void SetNext(Score* pNext);
	void SetPrev(Score* pPrev); //Set�Լ��� - �������ڸ� private ������ ������ �����Ѵ�.
	double GetAvr();
	Score* GetNext();
	Score* GetPrev(); //Get �Լ��� - ��� ������ ��ȯ�Ѵ�.
};

class StudentScoreList
{
private:
	Score* m_pHead; //�� �� ��带 ����Ű�� ������
	Score* m_pTail; //�� �� ��带 ����Ű�� ������

public:
	StudentScoreList(); //������
	~StudentScoreList(); //�Ҹ���

	void insert(Score* pScore); //������������ ��带 �����ϰ�, ���� ��ũ�帮��Ʈ�� �����ϴ� �Լ�
	void PrintList(bool isAscending); //��ũ�帮��Ʈ�� ����ϴ� �Լ�
	void deleteit();
};