#include "header.h"

int main()
{
    double price1 = 0, price2 = 0, discount = 0; //변수 선언
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
    //가격과 할인율 입력받기

    DiscountSale obj1(price1, discount);
    DiscountSale obj2(price2, discount); //입력받은 변수를 전달인자로 갖고 객체 2개 생성

    cout << "Result:" << endl;
    if (obj1 < obj2) //operater< 로 값 비교
    {
        cout << "Discount price of item1 is cheaper." << endl;
    }
    else
    {
        cout << "Discount price of item2 is cheaper." << endl;
    }
    cout << fixed;
    cout.precision(1); //입출력 예시와 동일하게 하기 위해 사용했습니다. 소숫점 이하 1자리까지 출력
    cout << "Saving discount price is $" << obj1.Savings(obj2) << endl; //Savings 함수 값 출력

    return 0;
}
