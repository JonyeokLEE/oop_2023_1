#include "header.h"

int main()
{
	double math = 0, english = 0, science = 0; //입력받을 변수
	double average = 0; //평균 변수
	int command = 0; //커맨드를 입력받을 변수
	StudentScoreList obj; //객체 생성

	while (1) //반복문
	{
		math = 0, english = 0, science = 0, command = 0, average = 0; //변수 초기화
		cout << "[Command]" << endl << "0: Insert / 1: Print / 2: Exit" << endl << "Command: "; cin >> command; //커맨드 출력 및 입력받기
		if (command == 0) //커맨드 0
		{
			cout << "[Input the Score]" << endl;
			cout << "Math: "; cin >> math;
			cout << "English: "; cin >> english;
			cout << "Science: "; cin >> science; //점수 입력받기
			average = (math + english + science) / 3; //평균 계산
			cout << "Average: " << average << endl;
			Score* newavg = new Score;
			newavg->SetAvg(average); //새 Score 노드를 생성 후 average값을 set
			obj.insert(newavg); //새 노드를 insert
		}
		else if (command == 1) //커맨드 1
		{
			cout << "1: Ascending Order / 2: Decending Order" << endl;
			cout << "Input the Order: ";
			int order = 0;
			cin >> order; //오름차순 / 내림차순 입력받기
			if (order == 1) //오름차순이면
			{
				obj.PrintList(true); //true 전달
			}
			else if (order == 2) //내림차순이면
			{
				obj.PrintList(false); //false 전달
			}
			else
			{
				cout << "Wrong command." << endl;
			}
		}
		else if (command == 2) //커맨드 2
		{
			break; //종료
		}
		else if (command == 3)
		{
			obj.deleteit();
		}
		else //그 외의 커맨드 예외처리
		{
			cout << "Wrong Command." << endl;
		}
	}
}