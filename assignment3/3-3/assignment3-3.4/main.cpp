#include "header.h"

int main()
{
	double math = 0, english = 0, science = 0; //�Է¹��� ����
	double average = 0; //��� ����
	int command = 0; //Ŀ�ǵ带 �Է¹��� ����
	StudentScoreList obj; //��ü ����

	while (1) //�ݺ���
	{
		math = 0, english = 0, science = 0, command = 0, average = 0; //���� �ʱ�ȭ
		cout << "[Command]" << endl << "0: Insert / 1: Print / 2: Exit" << endl << "Command: "; cin >> command; //Ŀ�ǵ� ��� �� �Է¹ޱ�
		if (command == 0) //Ŀ�ǵ� 0
		{
			cout << "[Input the Score]" << endl;
			cout << "Math: "; cin >> math;
			cout << "English: "; cin >> english;
			cout << "Science: "; cin >> science; //���� �Է¹ޱ�
			average = (math + english + science) / 3; //��� ���
			cout << "Average: " << average << endl;
			Score* newavg = new Score;
			newavg->SetAvg(average); //�� Score ��带 ���� �� average���� set
			obj.insert(newavg); //�� ��带 insert
		}
		else if (command == 1) //Ŀ�ǵ� 1
		{
			cout << "1: Ascending Order / 2: Decending Order" << endl;
			cout << "Input the Order: ";
			int order = 0;
			cin >> order; //�������� / �������� �Է¹ޱ�
			if (order == 1) //���������̸�
			{
				obj.PrintList(true); //true ����
			}
			else if (order == 2) //���������̸�
			{
				obj.PrintList(false); //false ����
			}
			else
			{
				cout << "Wrong command." << endl;
			}
		}
		else if (command == 2) //Ŀ�ǵ� 2
		{
			break; //����
		}
		else if (command == 3)
		{
			obj.deleteit();
		}
		else //�� ���� Ŀ�ǵ� ����ó��
		{
			cout << "Wrong Command." << endl;
		}
	}
}