#include "SortList.h"

void asscendingstr(string& str) //���ڿ��� sort�ϴ� �Լ�(��ҹ��� ���� ����)
{
    int i = 0; //�ε����� ����Ű�� ����
    int countspace = 0; //����� ���� ���� ����
    while (str[i] != '\0') //str ������
    {
        if (str[i] == ' ') //���⸦ ������
        {
            countspace++; //countspace ����
        }
        
        i++; //�ε��� ����
    }

    string seperate[100]; //���� �������� �и��ؼ� ���� string �迭 ����
    i = 0; //i �ʱ�ȭ
    int k = 0; //seperate �ε����� ����Ű�� �Լ�
    for (int j = 0; j <= countspace && str[i] != '\0'; i++) //str�� �����ų� countspace���� �ݺ�
    {
        if (str[i] == ' ') //������ ������
        {
            k++; //k ����
        }
        else //�� ���� ���
        {
            seperate[k] += str[i]; //seperate�� str ����
        }
    }
    str.clear(); //str �ʱ�ȭ
    // sort the words using strcmpi
    for (int i = 0; i < countspace; i++)
    {
        for (int j = i + 1; j <= countspace; j++)
        {
            if (_strcmpi(seperate[i].c_str(), seperate[j].c_str()) > 0)
            {
                //_strcmpi �Լ��� �̿��ؼ� seperate�� ��ҵ��� ��������
                //��ҹ��� ���о��� value�� ���Ѵ�.
                swap(seperate[i], seperate[j]);
            }
        }
    }
    for (int i = 0; i <= countspace; i++)
    {
        str += seperate[i]; //���ĵ� seperate���� str�� �ٽ� �־��ֱ�
        str += " ";
    }

}

int main()
{
    string input1, input2;
    cout << "Input list 1: ";
    getline(cin, input1);
    asscendingstr(input1);
    cout << "Input list 2: ";
    getline(cin, input2);
    asscendingstr(input2); //�� ���ڿ� �Է¹��� �� asscendingstr�� �������ֱ�
    int i = 0; //�ε����� ����Ű�� ����
    int countspace = 0; //������ ������ ���� ����
    while (input1[i] != '\0') //input1 ������
    {
        if (input1[i] == ' ') //������ ������
        {
            countspace++; //countspace ����
        }

        i++; //i ����
    }

    string seperate[100]; //�и��� �ܾ���� ���� string ����
    i = 0; //i �ʱ�ȭ
    int k = 0; //seperate�� �ε����� ���� k ����
    for (int j = 0; j <= countspace && input1[i] != '\0'; i++)
    {
        if (input1[i] == ' ') //������ ������
        {
            k++; //k ����
        }
        else //�� ���� ���
        {
            seperate[k] += input1[i]; //seperate�� input1 ����
        }
    }

    Node* p1 = new Node(); //p1 ��� ����
    p1->SetData(seperate[0]); //p1��忡 seperate[0] ���� setdata
    Node* current = p1;
    for (int i = 1; i <= countspace; i++) {
        Node* newNode = new Node();
        newNode->SetData(seperate[i]);
        current->SetNext(newNode);
        current = current->GetNext();
    } //����ؼ� seperate�� ������ ���� ����
    LinkedList list1; //list1 ����

    list1.setHead(p1); //list1�� ��带 p1���� ����

    i = 0;
    countspace = 0;
    while (input2[i] != '\0')
    {
        if (input2[i] == ' ')
        {
            countspace++;
        }

        i++;
    } //���������� input2�� ���� Ƚ���� ���

    string seperate2[100];
    i = 0;
    k = 0;
    for (int j = 0; j <= countspace && input2[i] != '\0'; i++)
    {
        if (input2[i] == ' ')
        {
            k++;
        }
        else
        {
            seperate2[k] += input2[i];
        }
    } //���� �����ϰ� seperate2�� input2�� �ܾ���� �ϳ��� ����
    Node* p2 = new Node();
    p2->SetData(seperate2[0]);
    Node* current2 = p2;
    for (int i = 1; i <= countspace; i++) {
        Node* newNode2 = new Node();
        newNode2->SetData(seperate2[i]);
        current2->SetNext(newNode2);
        current2 = current2->GetNext();
    } //���� �����ϰ� seperate2�� �ܾ���� ���� ����
    LinkedList list2;
    list2.setHead(p2); //p2�� list2�� ���� ����

    Node* p3 = new Node(); //������� ���� ��� ����

    LinkedList list3; //list3 ����
    list3.Merge_List(p1, p2, p3); //p1�� p2�� mergesort ����� p3�� ����

    list3.setHead(p3); //list3�� ��带 p3�� ����
    cout << "Result:";
    list3.printList(); //����� ���


	
	return 0; //0�� ��ȯ
}