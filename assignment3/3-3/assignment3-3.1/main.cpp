#include "header.h"

int main()
{
    double price1 = 0, price2 = 0, discount = 0; //���� ����
    cout << "Price Compare Program" << endl;
    cout << "======================" << endl;
    cout << "Insert item1 price: $";
    cin >> price1;
    cout << "Insert item2 price: $";
    cin >> price2;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Insert discount percent: ";
    cin >> discount;
    cout << "-----------------------------------------------------------" << endl;
    //���ݰ� ������ �Է¹ޱ�

    DiscountSale obj1(price1, discount);
    DiscountSale obj2(price2, discount); //�Է¹��� ������ �������ڷ� ���� ��ü 2�� ����

    cout << "Result:" << endl;
    if (obj1 < obj2) //operater< �� �� ��
    {
        cout << "Discount price of item1 is cheaper." << endl;
    }
    else
    {
        cout << "Discount price of item2 is cheaper." << endl;
    }
    cout << fixed;
    cout.precision(1); //����� ���ÿ� �����ϰ� �ϱ� ���� ����߽��ϴ�. �Ҽ��� ���� 1�ڸ����� ���
    cout << "Saving discount price is $" << obj1.Savings(obj2) << endl; //Savings �Լ� �� ���

    return 0;
}
