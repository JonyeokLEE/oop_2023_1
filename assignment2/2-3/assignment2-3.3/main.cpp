#include "oopstd.h"
#include <iostream>
using namespace oopstd;
using namespace std;

int main()
{	//assign 함수 테스트
	cout << "<Assign Function>" << endl;
	char inputstr[] = "Hello";
	oopstd::string str(inputstr);
	cout << "Before Assign: " << str.c_str() << endl; //원래는 Hello
	str.assign("Hi"); //assign Hi
	cout << "After Assign: " << str.c_str() << endl; //Hi 출력
	str.assign("Hello World!"); //str 재설정

	//At 함수 테스트
	cout << endl << "<At Function>" << endl;
	int inputat = 0; //입력값 선언 및 초기화
	cout << "Input the 'at' position: ";
	cin >> inputat; //입력받기
	cout << inputat << " at Str: " << str.at(inputat) << endl; //해당 위치 출력

	//c_str 함수 테스트
	cout << endl << "<C_str Function>" << endl;
	const char* c = str.c_str(); //c에 str 문자열 전체 반환받기
	cout << "By using c_str: " << c << endl; //c 문자열 출력

	//clear 함수 테스트
	cout << endl << "<Clear Function>" << endl;
	str.clear(); //str를 clear
	cout << "After Clear: " << str.c_str() << endl; //아무것도 출력되지 않는다.

	//push_back 함수 테스트
	cout << endl << "<Push Back Function>" << endl;
	str.assign("Hello World!"); //clear로 인해 비어있으니 다시 설정
	char push = 0; //입력받을 문자 선언
	cout << "Input the character that you want to push back: ";
	cin >> push; //입력받기
	str.push_back(push); //push_back 사용
	cout << "Push Back " << push << ": " << str.c_str() << endl; //결과값 출력
	str.assign("Hello"); //str 재설정

	//compare 함수 테스트
	cout << endl << "<Compare Function>" << endl;
	cout << "Input the string compare with " << str.c_str() << " : ";
	cin >> inputstr; //compare할 문자열 입력받기
	oopstd::string comparestr(inputstr); //string 클래스로 생성
	if (str.compare(&comparestr)==0) //반환값이 0이면
	{
		cout << "Same string!" << endl; //동일한 문자열
	}
	else if(str.compare(&comparestr)>0) //반환값이 양수면
	{
		cout << "Original str has bigger value" << endl; //원래 문자열이 더 value가 크다
	}
	else //반환값이 음수면
	{
		cout << "Original str has smaller value" << endl; //비교한 문자열이 더 value가 크다.
	}

	//replace 함수 테스트
	cout << endl << "<Replace Function>" << endl;
	cout << "Input the string to replace " << str.c_str() << " : ";
	cin >> inputstr; //replace 할 문자열 입력받기
	oopstd::string replacestr(inputstr);
	str.assign("Hello World!");
	str.replace(0, 5, &replacestr); //Hello 부분에 replacestr 넣어주기
	cout << str.c_str() << endl; //결과값 출력

	//substr 함수 테스트
	cout << endl << "<Substr Function>" << endl;
	str.assign("Hello World!");
	oopstd::string sub = str.substr(5, 10); //추출하고 싶은 범위 5-10
	cout << sub.c_str() << endl; //" World" 출력

	//find 함수 테스트
	cout << endl << "<Find Function>" << endl;
	str.assign("Hello World!");
	cout << str.find("World", 0) << endl; //처음(0)부터 World가 시작되는 인덱스 찾기

	//stoi 함수 테스트
	cout << endl << "<Stoi Function>" << endl;
	str.assign("10Bus"); //변환할 문자열
	size_t pos; //처음 문자가 나타나는 위치를 반환받는 변수
	cout << str.c_str() << endl;
	cout << "Number: "<< stoi(str, &pos, 10) << endl;
	cout <<"First Apearance Position of Character: "<< pos << endl; //결과값 출력

	//stof 함수 테스트
	cout << endl << "<Stof Function>" << endl;
	str.assign("1.52abcde"); //변환할 문자열
	size_t pos2; //처음 문자가 나타나는 위치를 반환받는 변수
	cout << str.c_str() << endl;
	cout << "Number: " << stof(str, &pos2) << endl;
	cout << "First Apearance Position of Character: " << pos2 << endl; //결과값 출력
	
	//to_string 함수 테스트
	cout << endl << "<To_String Function>" << endl;
	int intstr = -349; //변환할 정수
	float floatstr = 2.7; //변환할 실수
	oopstd::string res(to_string(intstr));
	cout << res.c_str() << endl;
	oopstd::string res2(to_string(floatstr));
	cout << res2.c_str() << endl; //결과값 출력

	return 0;


}