#include "CSVLoader.h"
#include <iostream>

int main()
{
    CSVLoader obj1("CSVLoader_Data.txt"); //obj1이라는 CSVLoader의 객체 생성 후 파일 이름을 전달
    int command = 0; //기능 테스트를 위한 커맨드 변수 선언
    while (1) //조건에 맞을 때까지 무한반복
    {
        cout << "[Command]" << endl << "1: Print Data / 2: Print Row Size / 3: Print Column Size / 4: Exit Program" << endl;
        cout << "Enter a command: "; //커맨드 설명문과 입력을 위한 안내문 출력
        cin >> command; //command를 입력받는다.
        if (command == 1) //1번 커맨드
            obj1.print(); //obj1 객체의 print함수 호출
        else if (command == 2) //2번 커맨드
            cout << "Row size: " << obj1.getRows() << endl; //obj1 객체의 rows 출력
        else if (command == 3) //3번 커맨드
            cout << "Column size: " << obj1.getCols() << endl; //obj1 객체의 cols 출력
        else if (command == 4) //4번 커맨드
            break; //프로그램 종료
        else //그 외의 커맨드 입력 시
            cout << "Wrong Command" << endl; //잘못된 커맨드라는 안내문 출력
    } //반복문 종료

    return 0; //0의 반환
}