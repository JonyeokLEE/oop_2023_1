#include "Employee.h" //Employee ������� ����

int main(void) //main �Լ�
{
    Employee *obj[10]; //��ü ������ obj ����
    int index = 0; //������ ����Ǿ����� Ȯ���ϱ� ���� ����
    char command[100]; //Ŀ�ǵ带 ���� ����
    char inputname[100];
    char changename[100];
    char inputjob[100];
    int inputage = 0;
    char inputcountry[100]; //�Է¹��� ���� �������� ���� ����

    while (1) //������ �� ������ ���ѹݺ�
    {
        cin >> command; //command�� �Է¹޴´�.
        if (!strcmp(command, "insert")) //insert�� �ԷµǸ�
        {
            if (index == 10) //���� 10���� ������ �ԷµǸ�
            {
                cout << "You cannot insert anymore." << endl; //�ȳ��� ���
            }
            else //�� ���� ���
            {
                cin >> inputname >> inputage >> inputcountry >> inputjob; //���� ���� �Է¹��� ��
                obj[index]=new Employee(inputname, inputage, inputcountry, inputjob); //obj ����
                index++; //index ����
            }
        }
        else if (!strcmp(command, "print")) //print�� �ԷµǸ�
        {
            cout << "=====print=====" << endl;
            for (int i = 0; i < index; i++)
            {
                obj[i]->print();
                cout << "----------" << endl;
            } //index���� ���� ���� �ݺ��ؼ� ����ϱ�
        }
        else if (!strcmp(command, "find")) //find�� �ԷµǸ�
        {
            cin >> inputname; //ã�� �̸� �Է¹ް�
            cout << "=====find=====" << endl;
            for (int i = 0; i < index; i++)
            {
                if (obj[i]->isNameCorrect(inputname)) //���� �ش� �ε����� inputname�� ���ٸ�
                {
                    obj[i]->print(); //�ش� ���� ���� ���
                    cout << "----------" << endl;
                }
            }
        }
        else if (!strcmp(command, "change")) //change�� �ԷµǸ�
        {
            cin >> inputname; //�ٲ� ���� �̸� �Է¹ް�
            for (int i = 0; i < index; i++)
            {
                if (obj[i]->isNameCorrect(inputname)) //�ش� �ε��� ã��
                {
                    cin >> changename >> inputage >> inputcountry >> inputjob; //�ٲ� ���� ���� �Է�
                    obj[i]->change(changename, inputage, inputcountry, inputjob); //�������� ���
                }
            }

        }
        else if (!strcmp(command, "exit")) //exit�� �ԷµǸ�
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
