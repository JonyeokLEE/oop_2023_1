#include <iostream>
using namespace std;

class Score
{
private:
	Score* m_pNext; //다음을 가리키는 포인터
	Score* m_pPrev; //이전을 가리키는 포인터
	double m_Avg; //평균 데이터

public:
	Score(); //생성자
	~Score(); //소멸자
	void SetAvg(double avg);
	void SetNext(Score* pNext);
	void SetPrev(Score* pPrev); //Set함수들 - 전달인자를 private 변수의 값으로 저장한다.
	double GetAvr();
	Score* GetNext();
	Score* GetPrev(); //Get 함수들 - 멤버 변수를 반환한다.
};

class StudentScoreList
{
private:
	Score* m_pHead; //맨 앞 노드를 가리키는 포인터
	Score* m_pTail; //맨 뒤 노드를 가리키는 포인터

public:
	StudentScoreList(); //생성자
	~StudentScoreList(); //소멸자

	void insert(Score* pScore); //오름차순으로 노드를 삽입하고, 이중 링크드리스트로 연결하는 함수
	void PrintList(bool isAscending); //링크드리스트를 출력하는 함수
	void deleteit();
};