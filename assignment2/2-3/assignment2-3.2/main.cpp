#include "header.h" //header ������� ����

int main() //main�Լ�
{
	School obj; //obj ��ü ����

	char command[100]; //Ŀ�ǵ带 ���� command ����
	int inputage = 0; //���̸� �Է��ϱ� ���� ����
	char inputname[100]; //�̸��� �Է��ϱ� ���� ����
	char inputclass[100]; //�й��� �Է��ϱ� ���� ����

	while (1) //������ �� ������ ���ѹݺ�
	{
		cin >> command; //command �Է¹ޱ�
		if (!strcmp(command, "new_student")) //command�� new_student���
		{
			cin >> inputname >> inputage >> inputclass; //�̸�, ����, �й� �Է¹ޱ�
			obj.new_student(inputname, inputage, inputclass); //new_student�� ����
		}
		else if (!strcmp(command, "sort_by_name")) //command�� sort_by_name�̶��
		{
			obj.sort_by_name(); //sort_by_name ȣ��
		}
		else if (!strcmp(command, "print_all")) //command�� print_all�̶��
		{
			obj.print_all(); //print_all ȣ��
		}
		else if (!strcmp(command, "print_class")) //command�� print_class���
		{
			cin >> inputclass; //�й� �Է¹ޱ�
			obj.print_class(inputclass); //print_class ȣ��
		}
		else if (!strcmp(command, "exit")) //command�� new_student���
		{
			break; //�ݺ��� ����
		}
		else //�� ���� �̻��� command�� �ԷµǸ�
		{
			cout << "Wrong Command. Please Enter the Command Again." << endl; //�ȳ��� ���
		}
	}

	return 0; //0�� ��ȯ
}