#pragma once //��������� �ѹ��� ���Եǵ��� ����� ����

class Clock //Clock Ŭ����
{
private: //private ����
	void setHour(int hour); //�ð��� �����ϴ� �Լ�
	void setMinute(int minute); //���� �����ϴ� �Լ�
	void setSecond(int second); //�ʸ� �����ϴ� �Լ�

	int hour;
	int minute;
	int second; //���� �ð�, ��, �� ������

public:
	Clock(); //Ŭ���� ������
	~Clock(); //Ŭ���� �Ҹ���

	void increaseHour();
	void increaseMinute();
	void increaseSecond(); //���� �ð�, ��, �ʸ� 1�� ������Ű�� �Լ�

	void setTime(int second); //�Է¹��� second�� ��������� ��ģ �� setHour,setMinute,setSecond�� �����ϴ� �Լ�
};