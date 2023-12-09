#include "Stack.h"

int main() //main�Լ� ����
{
    Stack stack; // Stack ��ü ����
    char control[300] = { 0 }; //command�� �Է¹��� control ���ڿ� ����
    int element = 0; //push�Լ��� �� ��Ҹ� ���� ���� ����
    cout << "Enter the size of Stack: ";
    int sizenum = 0;
    cin >> sizenum; //Stack�� size�� �Է¹ް�
    stack.SetSize(sizenum); //�Է¹��� ���� SetSize �Լ��� �����Ѵ�.

    while (1) //�ݺ��� (exit�� ���� ����ȴ�.)
    {
        cin >> control; //command�� �Է¹ޱ�
        if (!strcmp(control, "push")) //control�� push�� �ԷµǸ�
        {
            cin >> element; //element�� �Է¹ް�
            Node* node = new Node(); //node ��ü ���� ��
            node->SetData(element); //SetData�ϱ�(element ����)
            if (stack.Push(node)) //���� push�� �����ϸ�
                cout << "Push " << element << " Success!" << endl;
            else //���� push�� �����ϸ�
                cout << "Stack is full." << endl;

        }
        else if (!strcmp(control, "pop")) //control�� pop�� �ԷµǸ�
        {
            if (!stack.IsEmpty()) //���� Stack�� ������� ������
            {
                cout << "Pop " << stack.Pop()->GetData() << " Success!" << endl;
            }
            else //����־ ������ ���ߴٸ�
                cout << "Stack is empty." << endl;
        }
        else if (!strcmp(control, "isempty")) //control�� isempty�� �ԷµǸ�
        {
            if (stack.IsEmpty()) //true�� ��ȯ�Ǹ�
                cout << "Stack is empty." << endl;
            else //false�� ��ȯ�Ǹ�
                cout << "Stack is not empty." << endl;
        }
        else if (!strcmp(control, "isfull")) //control�� isfull�� �ԷµǸ�
        {
            if (stack.IsFull()) //true�� ��ȯ�Ǹ�
                cout << "Stack is full." << endl;
            else //false�� ��ȯ�Ǹ�
                cout << "Stack is not full." << endl;
        }
        else if (!strcmp(control, "print")) //control�� print�� �ԷµǸ�
        {
            if (stack.IsEmpty())
                cout << "Stack is empty." << endl;
            else //false�� ��ȯ�Ǹ�
                stack.PrintStack();
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