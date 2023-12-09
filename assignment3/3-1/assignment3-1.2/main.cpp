#include <iostream>
using namespace std;

char* my_strtok(char* str) //my_strtok 함수
{
	static char* start = NULL;
	static char* ptr = NULL; //static char형 포인터 start와 ptr을 초기화
	if (str != NULL) //str이 널이 아니면
		ptr = str; //ptr에 str을 저장
	if (ptr == NULL || *ptr == '\0') //ptr이 널이면
		return NULL; //널 반환

	start = ptr; //시작점을 복사
	static char* end = NULL; //static char형 포인터 end 초기화
	bool find = false; //bool형 find 변수 false로 초기화

	while (*ptr) //ptr이 널이 아닐 때 까지
	{
		if (*ptr == '@' || *ptr == '.') //골뱅이나 점을 만나면
		{
			end = ptr; //해당 지점을 종료지점으로 저장
			find = true; //find를 true로
			break;
		}
		ptr++; //ptr 증가
	}
	if (find) //찾았으면
	{
		*end = '\0'; //end부분을 널 문자 넣어주기
		ptr = end + 1; //ptr은 end 다음 부분으로 초기화
		return start; //start 반환
	}
	else //그 외의 경우
	{
		ptr = NULL; //ptr을 NULL로 초기화
		return start; //start 반환
	}

}

int main() //main 함수
{
	char inputmail[300]; //mail을 입력받을 문자열 선언
	cin >> inputmail; //입력받기
	
	char* result; //char 포인터 result 선언
	result = my_strtok(inputmail); //my_strtok의 반환값을 result에 저장

	while (result != NULL) //result가 NULL이 아닐 때까지
	{
		cout << result << endl; //result 출력
		result = my_strtok(NULL); //NULL을 전달하며 계속 반복
	}

	return 0; //0의 반환
}