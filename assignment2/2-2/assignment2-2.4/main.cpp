#include <iostream> //iostream ����
#include "Clock.h" //Clock.h ������� ����

using namespace std; //namespace std ����

int main() //main�Լ�
{
	cout << "Enter the second: "; //�ȳ��� ���
	Clock clock; //Clock Ŭ���� clock ��ü ����
	int input = 0; //input�� ���� ���� ����
	cin >> input; //�Է� �ޱ�
	clock.setTime(input); //�Է¹��� ���� setTime�� ����
	int command = 0; //Ŀ�ǵ� ���� ����
	while (1) //break ���� ������ ���� �ݺ�
	{
		cout << "[Command for Clock.h]" << endl;
		cout << "1: Increase Hour / 2: Increase Minute / 3: Increase Second / 4: Exit"<< endl;
		cout << "Enter the command: "; //Ŀ�ǵ� ���� �� �Է��� ���� �ȳ��� ���
		cin >> command; //Ŀ�ǵ� �Է¹ޱ�
		if (command == 1) //�ð��� �����ϴ� Ŀ�ǵ�
		{
			clock.increaseHour(); //increaseHour ����
		}
		else if (command == 2) //���� �����ϴ� Ŀ�ǵ�
		{
			clock.increaseMinute(); //increaseMinute ����
		}
		else if (command == 3) //�ʸ� �����ϴ� Ŀ�ǵ�
		{
			clock.increaseSecond(); //increaseSecond ����
		}
		else if (command == 4) //���� Ŀ�ǵ�
		{
			break; //�ݺ��� ����
		}
		else //�� �� Ŀ�ǵ�
		{
			cout << "Wrong Command" << endl; //�߸� �Է��ߴٴ� �ȳ��� ���
		}
	}

	return 0; //0�� ��ȯ
}