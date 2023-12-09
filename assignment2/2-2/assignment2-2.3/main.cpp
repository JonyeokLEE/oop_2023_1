#include "CSVLoader.h"
#include <iostream>

int main()
{
    CSVLoader obj1("CSVLoader_Data.txt"); //obj1�̶�� CSVLoader�� ��ü ���� �� ���� �̸��� ����
    int command = 0; //��� �׽�Ʈ�� ���� Ŀ�ǵ� ���� ����
    while (1) //���ǿ� ���� ������ ���ѹݺ�
    {
        cout << "[Command]" << endl << "1: Print Data / 2: Print Row Size / 3: Print Column Size / 4: Exit Program" << endl;
        cout << "Enter a command: "; //Ŀ�ǵ� ������ �Է��� ���� �ȳ��� ���
        cin >> command; //command�� �Է¹޴´�.
        if (command == 1) //1�� Ŀ�ǵ�
            obj1.print(); //obj1 ��ü�� print�Լ� ȣ��
        else if (command == 2) //2�� Ŀ�ǵ�
            cout << "Row size: " << obj1.getRows() << endl; //obj1 ��ü�� rows ���
        else if (command == 3) //3�� Ŀ�ǵ�
            cout << "Column size: " << obj1.getCols() << endl; //obj1 ��ü�� cols ���
        else if (command == 4) //4�� Ŀ�ǵ�
            break; //���α׷� ����
        else //�� ���� Ŀ�ǵ� �Է� ��
            cout << "Wrong Command" << endl; //�߸��� Ŀ�ǵ��� �ȳ��� ���
    } //�ݺ��� ����

    return 0; //0�� ��ȯ
}