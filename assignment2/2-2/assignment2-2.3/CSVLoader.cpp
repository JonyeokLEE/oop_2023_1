#include"CSVLoader.h"

CSVLoader::CSVLoader() //CSVLoader 클래스 생성자
{
	data = nullptr; //data 초기화
	cols = 0;
	rows = 0; //rows와 cols도 초기화
}

CSVLoader::CSVLoader(const char* path) //CSVLoader 클래스 생성자(const char형 포인터 path를 전달받는다.)
{
    data = nullptr; //data 초기화
    cols = 0;
    rows = 0; //rows와 cols도 초기화
	parse(path); //parse 함수에 path를 넘겨준다.
}

CSVLoader::~CSVLoader() //CSVLoader 클래스 소멸자
{
	for (int i = 0; i < rows; i++)
		delete[] data[i];
	delete[] data; //동적할당을 했던 data의 메모리 해제
}

float** CSVLoader::getData() const //data를 반환하는 함수
{
	return data; //data 반환
}

int CSVLoader::getRows() const //rows를 반환하는 함수
{
	return rows; //rows 반환
}

int CSVLoader::getCols() const //cols를 반환하는 함수
{
	return cols; //cols 반환
}

void CSVLoader::parse(const char* path) //구문분석을 하는 함수
{
    ifstream fin; //파일을 읽기 위한 객체 fin 생성
    fin.open(path); //path에 적힌 파일을 연다.

    if (!fin) //파일이 없으면
    {
        cout << "File does not exist."; //안내문 출력
    }

    char read; //파일을 읽기 위한 문자 선언
    char read2 = 0; //파일 마지막 개행을 대비한 문자 선언
    while (fin.get(read)) //read 믄자로 파일 한 글자씩 읽는다.
    {
        if (read == ',' && rows == 0) //만약 rows가 0이고 쉼표를 만나면
            cols++; //cols를 증가시킨다.
        if (read == '\n') //개행 문자를 만나면
            rows++; //rows를 증가시킨다.
        read2 = read; //read2에 계속 read의 값을 넣어준다.
    } //파일 끝까지 다 읽으면 while문 종료
    if (read2 != '\n') //다 읽었는데 마지막이 개행 문자가 아니면
    {
        rows++; //그럴 때는 rows를 하나 더 증가
    }
    cols++; //쉼표의 개수보다 열의 개수는 하나 더 많다.

    fin.close(); //fin으로 열었던 파일 닫기
    ifstream fin2; //다시 읽기 위해 fin2 객체 생성
    fin2.open(path); //같은 방식으로 열기
    if (!fin2) //파일이 없으면
    {
        cout << "File does not exist."; //안내문 출력
    }

    data = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new float[cols];
    } //구한 행과 열의 크기만큼 data로 이차원배열 동적할당을 한다.

    char ch = 0; //파일을 읽기 위한 문자
    char buffer[MAX_BUFFER_SIZE]; //텍스트 파일을 받을 문자열 선언
    int now = 0; //현재 인덱스를 가리키는 변수 선언
    int r = 0, c = 0; //row와 column 인덱스를 위한 변수들 선언
    float result = 0; //결과값을 위한 result 선언
    while (fin2.get(ch)) //ch로 한글자씩 파일을 읽는다.
    {
        buffer[now] = ch; //buffer 문자열에 ch로 한글자씩 읽은 것을 넣어준다.
        if (ch == ',') //만약 쉼표를 만나면
        {
            buffer[now] = '\0'; //해당 인덱스에 널 문자로 넣고
            result = atof(buffer); //지금까지의 문자열을 atof을 이용해 result로 변환
            data[r][c] = result; //data 배열에 넣어준다.
            c++; //쉼표에 해당하니깐 열의 위치만 증가시켜준다.
            now = 0; //문자열의 인덱스는 다시 0으로 초기화
        }
        else if (ch == '\n') //개행 문자를 만나면
        {
            buffer[now] = '\0'; //해당 인덱스에 널 문자로 넣고
            result = atof(buffer); //지금까지의 문자열을 atof을 이용해 result로 변환
            data[r][c] = result; //data 배열에 넣어준다.
            r++; //개행에 해당하니깐 행의 위치를 증가
            c = 0; //열은 처음으로 다시 초기화
            now = 0; //문자열의 인덱스는 다시 0으로 초기화
        }
        else //쉼표나 개행 문자를 만나지 않으면
        {
            now++; //계속해서 저장하기 위해 now를 증가(인덱스)
        }
    } //파일 끝까지 다 읽으면 while문 종료
    if (now != 0) //while문이 종료되었는데도 now가 0이 아니라는 것은 마지막 텍스트가 남아있다는 것
    {
        buffer[now] = '\0'; //해당 인덱스에 널 문자로 넣고
        result = atof(buffer); //지금까지의 문자열을 atof을 이용해 result로 변환
        data[r][c] = result; //data 배열에 넣어준다.
    }
    fin2.close(); //fin2로 읽은 파일 닫기
}



void CSVLoader::print(void) //print 함수
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	} //이차원 배열의 요소들을 출력한다.
}
