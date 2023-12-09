#include <iostream>
#include <fstream>

using namespace std;


int sizearr(char* sentence);
bool match(char* str, char* pattern);

int main()
{
    char fname[100]; //filename input을 위한 문자열
    cout << "Input file name: ";
    cin >> fname; //filename 입력받기

    ifstream fin(fname); //입력한 파일 이름으로 ifstream 객체 생성

    if (!fin) //파일이 존재하지 않을 때 예외처리
    {
        cout << "The file does not exist." << endl;
        return 0;
    }

    int num;
    cout << "Input number of patterns: ";
    cin >> num; //Input 갯수 입력받기

    char** patterns; //패턴을 저장할 이중포인터 동적 할당
    patterns = new char* [num];
    for (int i = 0; i < num; i++)
        patterns[i] = new char[100];

    cout << "Input patterns: " << endl;
    for (int j = 0; j < num; j++)
        cin >> patterns[j]; //패턴들을 행마다 입력받기
    cout << endl;
    char sentence[100]; //파일에서 한줄 씩 읽어들일 문자 배열 선언

    while (fin.getline(sentence, 100)) //파일에서 한 줄씩 읽어들이기
    {
        for (int i = 0; i < num; i++) //입력한 패턴들을 확인
        {
            bool is_matched = match(sentence, patterns[i]); // 패턴과 문장이 일치하는지 확인
            if (is_matched) // 일치한다면
            {
                cout << patterns[i] << ": " << sentence << endl; // 패턴과 문장을 함께 출력
            }
        }
    }

    for (int i = 0; i < num; i++) //이중 포인터 동적해제
        delete[] patterns[i];
    delete[] patterns;

    fin.close(); //파일 닫기

    return 0; //0의 반환
} //main함수 종료

int sizearr(char* sentence) //배열의 길이를 구하는 함수
{
    int b = 0;

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        b++;
    }
    return b; //배열의 길이를 반환
} //sizearr 함수 종료


bool match(char* str, char* pattern) //match함수
{
    int sizestr = sizearr(str); //str의 길이를 저장
    int sizepattern = sizearr(pattern); //pattern의 길이를 저장

    int i = 0, j = 0; //두 문자열의 인덱스 초기화
    int star = -1, match = 0; //*와 매치된 문자열의 인덱스 초기화

    while (i < sizestr) //str의 끝까지 탐색
    {
        if (j < sizepattern && pattern[j] == '?')
        {   //?가 나오면
            i++;
            j++; //인덱스 증가
        }
        else if (j < sizepattern && pattern[j] == '*')
        {   //*가 나오면
            star = j;
            match = i;
            j++; //인덱스 증가
        }
        else if (j < sizepattern && pattern[j] == str[i])
        {   //두 문자가 같으면
            i++;
            j++; //인덱스 증가
        }
        else if (star != -1)
        {   //* 이후에 문자열과 일치하는 문자열을 찾기
            j = star + 1;
            match++;
            i = match;
        }
        else
            return false;
    }

    //문자열과 pattern이 일치하는 여부를 반환
    return (j == sizepattern && i == sizestr);
}

