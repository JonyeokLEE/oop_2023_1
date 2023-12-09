#include "A.h" //A 헤더파일 선언
#include <iostream> //iostream 선언

int main() //main함수의 시작
{
	double n = 0; //입력을 받기 위한 double형 변수 n 선언
	cin >> n; //n을 입력받기
	A object(n); //클래스 A의 객체 object 생성과 동시에 n을 전달
	
	return 0; //0의 반환
} //main함수의 종료