#include "header.h"

Sale::Sale() //�⺻ ������
{
    Price = 0; //�ʱ�ȭ
}

Sale::Sale(double ThePrice) //�������ڰ� �ִ� ������
{
    Price = ThePrice; //Price�� ThePrice �� ����
}

Sale::~Sale() //�Ҹ���
{
}

double Sale::GetPrice() //GetPrice �Լ�
{
    return Price; //Price ��ȯ
}

double Sale::Bill() //Bill �Լ�(���� �����Լ�)
{
    return 0; //0 ��ȯ 
}

double Sale::Savings(Sale& Other) //Savings �Լ�
{
    return Bill() - Other.Bill(); //Bill�� ���޵� ��ü�� Bill�� ���� ��ȯ
}

bool Sale::operator<(Sale& Other) //operater<
{
    return Price < Other.GetPrice(); //Price�� Other�� Price���� ������ true
}

DiscountSale::DiscountSale() //�⺻ ������
{
    DiscountPercent = 0; //�ʱ�ȭ
}

DiscountSale::DiscountSale(double ThePrice, double theDiscount):Sale(ThePrice) //�������ڰ� �ִ� ������
{
    DiscountPercent = theDiscount; //���޵� �� ����
}

DiscountSale::~DiscountSale() //�Ҹ���
{
}

double DiscountSale::GetDiscount() //GetDiscount �Լ�
{
    return DiscountPercent; //DiscountPercent ��ȯ
}

void DiscountSale::SetDiscount(double theDiscount) //SetDiscount �Լ�
{
    DiscountPercent = theDiscount; //���޵� �� ����
}

double DiscountSale::Bill() //Bill �Լ�
{
    return GetPrice() - (GetPrice() * DiscountPercent / 100); //���ε� ���� ��ȯ
}

double DiscountSale::Savings(DiscountSale& Other) //Savings �Լ�
{
    double result = Bill() - Other.Bill(); //Bill�� ���޵� ��ü�� Bill�� ���� ����
    if (result < 0)
        result *= -1; //������ ��� ó��
    
    return result; //result ��ȯ
}

bool DiscountSale::operator<(DiscountSale& second) //operater<
{
    return Bill() < second.Bill(); //second�� Bill���� Bill�� ������ true
}