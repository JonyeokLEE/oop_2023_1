#include "header.h"

Sale::Sale() //기본 생성자
{
    Price = 0; //초기화
}

Sale::Sale(double ThePrice) //전달인자가 있는 생성자
{
    Price = ThePrice; //Price에 ThePrice 값 저장
}

Sale::~Sale() //소멸자
{
}

double Sale::GetPrice() //GetPrice 함수
{
    return Price; //Price 반환
}

double Sale::Bill() //Bill 함수(순수 가상함수)
{
    return 0; //0 반환 
}

double Sale::Savings(Sale& Other) //Savings 함수
{
    return Bill() - Other.Bill(); //Bill과 전달된 객체의 Bill을 빼서 반환
}

bool Sale::operator<(Sale& Other) //operater<
{
    return Price < Other.GetPrice(); //Price가 Other의 Price보다 작으면 true
}

DiscountSale::DiscountSale() //기본 생성자
{
    DiscountPercent = 0; //초기화
}

DiscountSale::DiscountSale(double ThePrice, double theDiscount):Sale(ThePrice) //전달인자가 있는 생성자
{
    DiscountPercent = theDiscount; //전달된 값 저장
}

DiscountSale::~DiscountSale() //소멸자
{
}

double DiscountSale::GetDiscount() //GetDiscount 함수
{
    return DiscountPercent; //DiscountPercent 반환
}

void DiscountSale::SetDiscount(double theDiscount) //SetDiscount 함수
{
    DiscountPercent = theDiscount; //전달된 값 저장
}

double DiscountSale::Bill() //Bill 함수
{
    return GetPrice() - (GetPrice() * DiscountPercent / 100); //할인된 가격 반환
}

double DiscountSale::Savings(DiscountSale& Other) //Savings 함수
{
    double result = Bill() - Other.Bill(); //Bill과 전달된 객체의 Bill을 빼서 저장
    if (result < 0)
        result *= -1; //음수일 경우 처리
    
    return result; //result 반환
}

bool DiscountSale::operator<(DiscountSale& second) //operater<
{
    return Bill() < second.Bill(); //second의 Bill보다 Bill이 작으면 true
}