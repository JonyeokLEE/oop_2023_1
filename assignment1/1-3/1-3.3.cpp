#include <iostream>
using namespace std;
/*
�뷫���� ���̵��: 10������ �ٸ� ������ ��ȯ�ϱ� �����, �켱 ������ 10������ ��ȯ�ϰ� �� ���� ������ ��ȯ�ϱ�!
*/

int getarrsize(char* arr) //getarrsize �Լ� ����
{
	int size = 0; //size ���� ����

	while (arr[size] != '\0') //arr�� ���� �� ����
	{
		size++; //size ����
	}
	return size; //size ��ȯ
} //getarrsize �Լ� ����


int transferto10(char* before, int specbase) //�Է°��� 10������ �ٲٴ� �Լ�
{
    int res = 0; //����� ����
    int plus = 0; //����������� �ѹ��� ��Ƽ� ���ϱ� ���� ����
    if (specbase == 16) //16������ ��
    {
        for (int i = 0; i < getarrsize(before); i++) //������ ���̸�ŭ �ݺ�
        {
            plus = 0;
            if (before[i] >= '0' && before[i] <= '9') //���ڷ� �̷���� ���� ����
            {
                plus = before[i] - '0'; //'0'�� ���� plus�� ����
            }
            else if (before[i] >= 'A' && before[i] <= 'F') //�빮�� A B C D E F �� ���
            {
                plus = before[i] - 'A' + 10; //'A'�� ���� 10�� ���ϱ�
            }
            else if (before[i] >= 'a' && before[i] <= 'f') //�ҹ��� a b c d e f �� ���
            {
                plus = before[i] - 'a' + 10; //'a'�� ���� 10�� ���ϱ�
            }
            else
            {
                return -1; //������ �ʰ��� ��� -1�� ��ȯ
            }
            res = res * specbase + plus; //������� ����ؼ� �ֽ�ȭ�ϱ�
        }
    }
    else if (specbase == 8) //8������ ���
    {
        for (int i = 0; i < getarrsize(before); i++) //������ ���̸�ŭ �ݺ�
        {
            plus = 0;
            if (before[i] >= '0' && before[i] <= '7') //8���� ���� �ȿ� ������
            {
                plus = before[i] - '0'; //'0'�� ���� plus�� ����
            }
            else //������ �ʰ��� ��� -1�� ��ȯ
                return -1;
            res = res * specbase + plus; //������� ����ؼ� �ֽ�ȭ�ϱ�
        }
    }
    else if (specbase == 2) //2������ ���
    {
        for (int i = 0; i < getarrsize(before); i++) //������ ���̸�ŭ �ݺ�
        {
            plus = 0;
            if (before[i] >= '0' && before[i] <= '1') //2���� ���� �ȿ� ������
            {
                plus = before[i] - '0'; //'0'�� ���� plus�� ����
            }
            else //������ �ʰ��� ��� -1�� ��ȯ
                return -1;
            res = res * specbase + plus; //������� ����ؼ� �ֽ�ȭ�ϱ�
        }
    }
    else if (specbase == 10) //10������ ���
    {
        for (int i = 0; i < getarrsize(before); i++) //������ ���̸�ŭ �ݺ�
        {
            res = res * 10 + (before[i] - 48); //������ �ٲ��ִ� �۾�
        }
    }
    
    else //�� ���� ��� -1�� ��ȯ
        return -1;

    return res; //������� ��ȯ
}

int count(int a, int divide) //10�������� �ٸ� ������ ��ȯ�ϴ� �������� ��� Ƚ���� �ݺ��ؾ��ϴ��� ����ϴ� �Լ�
{
    int countnum = 0;
    while (a != 0) //a�� 0�� �ƴ� ������
    {
        a /= divide; //�ش� ������ �������ش�
        countnum++; //�� Ƚ���� ����
    }
    return countnum; //�� Ƚ���� ��ȯ
}

void transferfrom10(int beforenum, int newbase, char* resarr) //10�������� �ٸ� ������ ��ȯ�ϴ� �Լ�
{
    for (int i = count(beforenum, newbase); beforenum != 0; i--) //beforenum�� 0�� �ɶ����� i�� ��� �����Ѵ�.
    {
       
        if ((beforenum % newbase) < 10) //���� ������ ���� 0 ~ 9�� ��
        {
            resarr[i - 1] = (beforenum % newbase) + '0'; //'0'�� ���� �� resarr�� ����
        }
        else //�� �̻��� ��쿡��
        {
            resarr[i - 1] = (beforenum % newbase) - 10 + 'A'; //���ڸ� ���ĺ����� ��ȯ�ؼ� �����Ѵ�.
        }
        beforenum /= newbase; //beforenum�� ����ؼ� �ֽ�ȭ
    }
    return;
}




int main()
{
	char original[300] = {0,}; //ó�� ���� �Է¹��� �迭
	int formerform = 0; //�Է� ���� ����
	int afterform = 0; //�ٲ� ����
    int num = 0; //�Է� ���� 10������ �ٲ� ���¸� ������ ����
    char after[300] = { 0, }; //������� ��� �迭

	cout << "Original Number: ";
	cin >> original;
	cout << "Specific base of Original Number: ";
	cin >> formerform;
	cout << "Desired base of Original Number: ";
    cin >> afterform;
    //�Է¹ޱ�


	num = transferto10(original, formerform); //10������ ��ȯ�ϱ�
    transferfrom10(num, afterform,after); //���ϴ� ������ �ٲٱ�

    cout << endl << "Result: " << after << endl; //����� ���

	
	return 0;
}