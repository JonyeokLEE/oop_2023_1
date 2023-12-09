#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

#define IMG_HEIGHT 512
#define IMG_WIDTH 512

char* changename(char* str,int a)
{
	int count = 0;
	const char* horizon = "_horizontalflip.raw";
	const char* vertical = "_verticalflip.raw"; //뒤에 추가할 이름들

	for (int i = 0; str[i] != '\0'; i++)
	{
		count++;
	}
	count -= 4;
	str[count] = '\0'; //입력받은 이름 맨 뒤 ".raw"를 지우는 작업

	count = 0; //count 다시 초기화
	if (a == 1) //전달인자가 1이면(horizontal flip)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			count++;
		} //원래 문자열 끝까지 가서
		for (int i = 0; horizon[i] !='\0'; i++)
		{
			str[count] = horizon[i];
			count++;
		} //추가 문자열 끝날 때까지 뒤에 추가
		
	}

	else //전달인자가 1이 아니면(vertical flip)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			count++;
		} //원래 문자열 끝까지 가서
		for (int i = 0; i < 20; i++)
		{
			str[count] = vertical[i];
			count++;
		} //추가 문자열 끝날 때까지 뒤에 추가
	}

	str[count] = '\0'; //마지막 NULL문자 추가
	return str; //바뀐 str 다시 반환
}

uint8_t** memory_alloc2D(uint32_t height, uint32_t width) //Memory 할당 과정
{
	uint8_t** ppMem2d = new uint8_t * [height];
	if (ppMem2d == 0)
		return 0;

	ppMem2d[0] = new uint8_t[height * width];
	if (ppMem2d[0] == 0)
	{
		delete[] ppMem2d;
		return 0;
	}

	for (int i = 1; i < height; i++)
		ppMem2d[i] = ppMem2d[i - 1] + width;
	return ppMem2d;
}
int memory_free2D(uint8_t** ppMemAllocated) //Memory 해제 과정
{
	if (ppMemAllocated == 0)
		return -1;

	if (ppMemAllocated[0])
		delete[] ppMemAllocated[0];

	delete[] ppMemAllocated;
	return 0;
}

int main(void)
{
	FILE* Inputhorizontal = 0;
	FILE* Inputvertical = 0;
	FILE* Outputhorizontal = 0;
	FILE* Outputvertical = 0;
	uint8_t** horizontalBuffer = 0;
	uint8_t** verticalBuffer = 0; //Horizontal flip과 Vertical flip을 각각 수행하기 위해 변수들을 따로 추가
	cout << "Input file name: "; 
	char inputname[300] = { 0, };
	cin >> inputname; //원하는 파일명 입력받기
	char inputname2[300] = { 0, };
	int null = 0;
	for (int i = 0; inputname[i] != '\0'; i++)
	{
		inputname2[i] = inputname[i];
		null++;
	}
	inputname2[null] = '\0'; //inputname2에도 inputname 복사
	char* IMG_NAME1 = inputname;
	char* IMG_NAME2 = inputname2;
	//포인터로 하나씩 가르키기
	
	//입력파일 열기
	Inputhorizontal = fopen(IMG_NAME1, "rb");
	Inputvertical = fopen(IMG_NAME2, "rb");

	//메모리 할당
	horizontalBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);
	verticalBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);
	
	//파일에서 메모리로 읽은 파일 입력
	for (int i = 0; i < IMG_HEIGHT; i++)
		fread((uint8_t*)horizontalBuffer[i], sizeof(uint8_t), IMG_WIDTH, Inputhorizontal);
	for (int i = 0; i < IMG_HEIGHT; i++)
		fread((uint8_t*)verticalBuffer[i], sizeof(uint8_t), IMG_WIDTH, Inputvertical);

	
	for (int i = 0; i < IMG_HEIGHT; i++) {
		for (int j = 0; j < IMG_WIDTH / 2; j++) {
			uint8_t temp = horizontalBuffer[i][j];
			horizontalBuffer[i][j] = horizontalBuffer[i][IMG_WIDTH - j - 1];
			horizontalBuffer[i][IMG_WIDTH - j - 1] = temp;
		}
	}
	for (int i = 0; i < IMG_HEIGHT / 2; i++) {
		for (int j = 0; j < IMG_WIDTH; j++) {
			uint8_t temp = verticalBuffer[i][j];
			verticalBuffer[i][j] = verticalBuffer[IMG_HEIGHT - i - 1][j];
			verticalBuffer[IMG_HEIGHT - i - 1][j] = temp;
		}
	}
	//swap 방식으로 각자 수평, 수직으로 뒤집기

	//각각의 이름을 바꾸기 위해 changename에 전달하기
	IMG_NAME1 = changename(IMG_NAME1, 1);
	IMG_NAME2 = changename(IMG_NAME2, 2);

	//출력파일 열기
	Outputhorizontal = fopen(IMG_NAME1, "wb");
	Outputvertical = fopen(IMG_NAME2, "wb");

	//파일을 쓰기
	for (int i = 0; i < IMG_HEIGHT; i++)
		fwrite((uint8_t*)horizontalBuffer[i], sizeof(uint8_t), IMG_WIDTH, Outputhorizontal);

	for (int i = 0; i < IMG_HEIGHT; i++)
		fwrite((uint8_t*)verticalBuffer[i], sizeof(uint8_t), IMG_WIDTH, Outputvertical);

	//메모리 해제 및 파일 닫기
	memory_free2D(horizontalBuffer);
	memory_free2D(verticalBuffer);
	fclose(Inputvertical);
	fclose(Inputhorizontal);
	fclose(Outputvertical);
	fclose(Outputhorizontal);

	return 0;

}