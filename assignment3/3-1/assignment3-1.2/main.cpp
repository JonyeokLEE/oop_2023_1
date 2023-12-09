#include <iostream>
using namespace std;

char* my_strtok(char* str) //my_strtok �Լ�
{
	static char* start = NULL;
	static char* ptr = NULL; //static char�� ������ start�� ptr�� �ʱ�ȭ
	if (str != NULL) //str�� ���� �ƴϸ�
		ptr = str; //ptr�� str�� ����
	if (ptr == NULL || *ptr == '\0') //ptr�� ���̸�
		return NULL; //�� ��ȯ

	start = ptr; //�������� ����
	static char* end = NULL; //static char�� ������ end �ʱ�ȭ
	bool find = false; //bool�� find ���� false�� �ʱ�ȭ

	while (*ptr) //ptr�� ���� �ƴ� �� ����
	{
		if (*ptr == '@' || *ptr == '.') //����̳� ���� ������
		{
			end = ptr; //�ش� ������ ������������ ����
			find = true; //find�� true��
			break;
		}
		ptr++; //ptr ����
	}
	if (find) //ã������
	{
		*end = '\0'; //end�κ��� �� ���� �־��ֱ�
		ptr = end + 1; //ptr�� end ���� �κ����� �ʱ�ȭ
		return start; //start ��ȯ
	}
	else //�� ���� ���
	{
		ptr = NULL; //ptr�� NULL�� �ʱ�ȭ
		return start; //start ��ȯ
	}

}

int main() //main �Լ�
{
	char inputmail[300]; //mail�� �Է¹��� ���ڿ� ����
	cin >> inputmail; //�Է¹ޱ�
	
	char* result; //char ������ result ����
	result = my_strtok(inputmail); //my_strtok�� ��ȯ���� result�� ����

	while (result != NULL) //result�� NULL�� �ƴ� ������
	{
		cout << result << endl; //result ���
		result = my_strtok(NULL); //NULL�� �����ϸ� ��� �ݺ�
	}

	return 0; //0�� ��ȯ
}