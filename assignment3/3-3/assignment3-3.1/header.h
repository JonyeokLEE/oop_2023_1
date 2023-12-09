#include <iostream>
using namespace std;

class Sale
{
private:
    double Price;

public:
    Sale(); //기본 생성자
    Sale(double ThePrice); //전달인자가 있는 생성자
    ~Sale(); //소멸자
    double GetPrice(); //Price를 반환하는 함수
    virtual double Bill(); //순수 가상함수 (정의가 없고 상속받은 클래스에서 정의)
    double Savings(Sale& Other); //값을 비교하는 함수
    bool operator<(Sale& Other); //연산자 오버로딩
};

class DiscountSale : public Sale
{
private:
    double DiscountPercent;

public:
    DiscountSale(); //기본 생성자
    DiscountSale(double ThePrice, double theDiscount); //전달인자가 있는 생성자
    ~DiscountSale(); //소멸자
    double GetDiscount(); //DiscountPercent를 반환하는 함수
    void SetDiscount(double theDiscount); //DiscountPercent를 set하는 함수
    double Bill(); //할인된 가격을 계산하는 함수
    double Savings(DiscountSale& Other); //값을 비교하는 함수 
    bool operator<(DiscountSale& second); //연산자 오버로딩
};
