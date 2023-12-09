#include "Queue.h"

int main() //main�Լ� ����
{
    Queue queue; //Queue ��ü ����
    char control[300] = { 0 }; //command�� �Է¹��� control ���ڿ� ����
    int element = 0; //push�Լ��� �� ��Ҹ� ���� ���� ����
    cout << "Enter the size of Queue: ";
    int sizenum = 0;
    cin >> sizenum; //Queue Size �Է¹ޱ�
    queue.SetSize(sizenum); //queue�� size setting ���ֱ�

    while (1) //�ݺ��� (exit�� ���� ����ȴ�.)
    {
        cin >> control; //command�� �Է¹ޱ�
        if (!strcmp(control, "push")) //control�� push�� �ԷµǸ�
        {
            cin >> element; //element�� �Է¹ް�
            Node* node = new Node(); //���ο� ��� ��ü ����
            node->SetData(element); //node�� element ������ data set
            if (queue.Push(node)) //Push�� �����ϸ�
                cout << "Push " << element << " Success!" << endl; //��¹� ���
            else //Push�� �����ϸ�
                cout << "Queue is full." << endl; //Queue�� Full�̹Ƿ� ��¹� ���
        }
        else if (!strcmp(control, "pop")) //control�� pop�� �ԷµǸ�
        {
            if (!queue.IsEmpty()) //���� Queue�� ������� ������
            {
                cout << "Pop "<< queue.Pop()->GetData() << " Success!" << endl;
            }   
            else //���� Queue�� ���������
                cout << "Queue is empty." << endl; //��¹� ���
        }
        else if (!strcmp(control, "isempty")) //control�� isempty�� �ԷµǸ�
        {
            if (queue.IsEmpty()) //���� ����ִٸ�
                cout << "Queue is empty." << endl; //����ִٴ� ��¹� ���
            else //���� ������� �ʴٸ�
                cout << "Queue is not empty." << endl; //������� �ʴٴ� ��¹� ���
        }
        else if (!strcmp(control, "isfull")) //control�� isfull�� �ԷµǸ�
        {
            if (queue.IsFull()) //���� �� ���ִٸ�
                cout << "Queue is full." << endl; //�� á�ٴ� ��¹� ���
            else //���� �� ������ �ʴٸ�
                cout << "Queue is not full." << endl; //�� ������ �ʴٴ� ��¹� ���
        }
        else if (!strcmp(control, "print")) //print�� �ԷµǸ�
        {
            if (queue.IsEmpty())
                cout << "Queue is empty." << endl;
            else
                queue.PrintQueue(); //Queue�� Element���� ���
        }
        else if (!strcmp(control, "exit")) //control�� exit�� �ԷµǸ�
        {
            break; //�ݺ��� ����
        }
        else //control�� �������� ���� command�� �ԷµǸ�
        {
            cout << "Wrong Command Entered. Please Try Again." << endl; //�ȳ��� ���
        }
    }
    return 0; //0�� ��ȯ
} //main�Լ� ����