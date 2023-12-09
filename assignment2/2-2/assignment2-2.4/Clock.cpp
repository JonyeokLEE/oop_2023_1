#include "Clock.h" //Clock.h ������� ����
#include <iostream> //iostream ����
using namespace std; //namespace std ����

Clock::Clock() //Ŭ���� ������
{
	hour = 0;
	minute = 0;
	second = 0; //������ �������� �ʱ�ȭ
}

Clock::~Clock() //Ŭ���� �Ҹ���
{
	hour = 0;
	minute = 0;
	second = 0; //������ �������� �ʱ�ȭ
}

void Clock::increaseHour() //�ð��� ������Ű�� �Լ�
{
	hour++; //�ð��� 1 ����
	if (hour == 24) //���� �ð��� 24�� �Ǹ�
	{
		hour = 0; //0���� �ʱ�ȭ
	}
	setHour(hour); //��ȭ�� �ð��� �ٽ� setHour�� ����

	cout << hour << ":" << minute << ":" << second << endl; //��ȭ�� �ð��� ���
}

void Clock::increaseMinute() //���� ������Ű�� �Լ�
{
	minute++; //���� 1 ����
	if (minute == 60) //���� ���� 60�� �Ǹ�
	{
		minute = 0; //���� 0���� �ʱ�ȭ
		increaseHour(); //�׿� ���� �ð��� ����
	}
	setMinute(minute); //��ȭ�� ���� �ٽ� setMinute���� ����

	cout << hour << ":" << minute << ":" << second << endl; //��ȭ�� �ð��� ���
}

void Clock::increaseSecond() //�ʸ� ������Ű�� �Լ�
{
	second++; //�ʸ� 1 ����
	if (second == 60) //���� �ʰ� 60�� �Ǹ�
	{
		second = 0; //�ʸ� 0���� �ʱ�ȭ
		increaseMinute(); //�׿� ���� �е� ����
	}
	setSecond(second); //��ȭ�� �ʸ� �ٽ� setSecond�� ����

	cout << hour << ":" << minute << ":" << second << endl; //��ȭ�� �ð��� ���
}

void Clock::setTime(int second) //���޹��� second�� �� �Լ��� �������ִ� ����
{
	setHour(second / 3600); //second�� 3600���� ���� ���� setHour�� ����
	second %= 3600; //second�� 3600���� ���� ������������ ��ȭ
	setMinute(second / 60); //second�� 60���� ���� ���� setMinute�� ����
	second %= 60; //second�� 60���� ���� ������������ ��ȭ
	setSecond(second); //second�� setSecond�� ����

	cout << hour << ":" << minute << ":" << second << endl; //��ȯ�� �ð� ���
}

void Clock::setHour(int hour) //�ð� ������ �����ϴ� �Լ�
{
	if (hour > 24) //���� 24���� ũ��
		hour %= 24; //24�� ���� ������ ���� hour
	this->hour = hour; //��� ������ �����ϱ� ���� this ������ ���
}

void Clock::setMinute(int minute) //�� ������ �����ϴ� �Լ�
{
	if (minute > 60) //���� 60���� ũ��
		minute %= 60; //60���� ���� ������ ���� minute
	this->minute = minute; //��� ������ �����ϱ� ���� this ������ ���
}

void Clock::setSecond(int second) //�� ������ �����ϴ� �Լ�
{
	if (second > 60) //���� 60���� ũ��
		second %= 60; //60���� ���� ������ ���� second
	this->second = second; //��� ������ �����ϱ� ���� this ������ ���
}
