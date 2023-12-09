#include "header.h" //header 헤더파일 선언

int main() //main함수
{
	School obj; //obj 객체 선언

	char command[100]; //커맨드를 위한 command 선언
	int inputage = 0; //나이를 입력하기 위한 변수
	char inputname[100]; //이름을 입력하기 위한 변수
	char inputclass[100]; //분반을 입력하기 위한 변수

	while (1) //조건이 될 때까지 무한반복
	{
		cin >> command; //command 입력받기
		if (!strcmp(command, "new_student")) //command가 new_student라면
		{
			cin >> inputname >> inputage >> inputclass; //이름, 나이, 분반 입력받기
			obj.new_student(inputname, inputage, inputclass); //new_student로 전달
		}
		else if (!strcmp(command, "sort_by_name")) //command가 sort_by_name이라면
		{
			obj.sort_by_name(); //sort_by_name 호출
		}
		else if (!strcmp(command, "print_all")) //command가 print_all이라면
		{
			obj.print_all(); //print_all 호출
		}
		else if (!strcmp(command, "print_class")) //command가 print_class라면
		{
			cin >> inputclass; //분반 입력받기
			obj.print_class(inputclass); //print_class 호출
		}
		else if (!strcmp(command, "exit")) //command가 new_student라면
		{
			break; //반복문 종료
		}
		else //그 외의 이상한 command가 입력되면
		{
			cout << "Wrong Command. Please Enter the Command Again." << endl; //안내문 출력
		}
	}

	return 0; //0의 반환
}