#include <iostream>
using namespace std;

class Sale
{
private:
    double Price;

public:
    Sale(); //�⺻ ������
    Sale(double ThePrice); //�������ڰ� �ִ� ������
    ~Sale(); //�Ҹ���
    double GetPrice(); //Price�� ��ȯ�ϴ� �Լ�
    virtual double Bill(); //���� �����Լ� (���ǰ� ���� ��ӹ��� Ŭ�������� ����)
    double Savings(Sale& Other); //���� ���ϴ� �Լ�
    bool operator<(Sale& Other); //������ �����ε�
};

class DiscountSale : public Sale
{
private:
    double DiscountPercent;

public:
    DiscountSale(); //�⺻ ������
    DiscountSale(double ThePrice, double theDiscount); //�������ڰ� �ִ� ������
    ~DiscountSale(); //�Ҹ���
    double GetDiscount(); //DiscountPercent�� ��ȯ�ϴ� �Լ�
    void SetDiscount(double theDiscount); //DiscountPercent�� set�ϴ� �Լ�
    double Bill(); //���ε� ������ ����ϴ� �Լ�
    double Savings(DiscountSale& Other); //���� ���ϴ� �Լ� 
    bool operator<(DiscountSale& second); //������ �����ε�
};
