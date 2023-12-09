#include "header.h"

int main()
{
	LinkedList obj; //��ü obj ����
	int nodupli[16]; //�ߺ����� 16�ڸ� ���� ���� ������ �迭
	bool isdupli = false; //�ߺ��Ȱ��� Ȯ���� ����
	int index = 0; //�ε����� ����Ű�� ����
	int randnum = 0; //���� ��
	srand((unsigned int)time(NULL)); //srand ����
	for (int i = 0; index != 16; i++) //index�� 16�� �Ǳ� ������ �ݺ�
	{
		isdupli = false; //isdupli �ʱ�ȭ
		randnum = rand() % 201; //0���� 200�� ���� �� ����
		for (int j = 0; j < index; j++) //���ݱ��� ����� index���� �ݺ�
		{
			if (nodupli[j] == randnum) //���� �ߺ�Ȯ�εǸ�
			{
				isdupli = true; //�ߺ� ǥ��
				break; //�ݺ��� Ż��
			}
		}
		if (!isdupli) //�ߺ� ǥ�ð� ���� ���
		{
			nodupli[index] = randnum; //�ش� �� ����
			index++; //index ����
		}
	}
	//������� nodupli ���� �Ϸ�(�ߺ� ���� 0���� 200 ���� ���� ��)

	for (int i = 0; i < 16; i++) //16�� �ݺ�
	{
		Node* insertit = new Node();
		insertit->setdata(nodupli[i]);
		obj.insertNew(insertit); //�ϳ��� ��忡 ������ �� obj�� �����Ű��
	}

	cout << "<Random List>" << endl;
	obj.printlist(); //���ݱ����� ����� ������ ���
	obj.insertsort(); //insertsort�ϱ�
	cout << "<After Insertion Sort>" << endl;
	obj.printlist(); //��� ���

	int forsearch = 0; //ã����� �� ����
	cout << endl << "Input the number to search: ";
	cin >> forsearch; //�Է¹ޱ�

	Node* result = obj.Binary_Search(obj.getHead(), forsearch); //Binary Search�� ������� result ���� �ޱ�
	if (result->getdata() == forsearch) //���� ã�� �ִ� ���� ���ٸ�
		cout << "Found: " << result->getdata(); //���� ���
	else //�� ã�Ҵٸ�
		cout << "Not Found, Closest Value's Node: " << result->getdata(); //�ٻ� ��� ���


	return 0;
	
}