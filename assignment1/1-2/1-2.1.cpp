#include <iostream> //iostream 선언
using namespace std; //using namespace 선언

void addarr(char* a, char* b, char* ab); //두 문자열을 더하는 함수
int getarrsize(char* arr); //문자열의 길이를 구하는 함수
void noduplication(char* array1); //문자열이 중복이 없도록 만드는 함수
void countsame(char* arr1, char* arr2, int size1, int size2); //같은 문자가 몇개인지 세는 함수

int main() //main함수
{
    char input1[1000], input2[1000], input12[2000]; //문자열 선언
    cin >> input1; //문자열 1 입력
    cin >> input2; //문자열 2 입력
    int count = 0; //count 정수 선언
    int trynum = 1; //trynum 정수 선언

    addarr(input1, input2, input12); //input1과 input2를 input12로 더하기

    int sizeinput = getarrsize(input12); //input12의 길이를 sizeinput에 저장

    char nodupli[2000] = { 0, }; //중복없는 문자열 선언
    for (int i = 0; input12[i] != '\0'; i++)
          nodupli[i] = input12[i]; //우선 문자열을 복사하고
    noduplication(nodupli); //noduplication함수에 넣어 중복 없애기
    
    int sizenodupli = getarrsize(nodupli); //nodupli 문자열의 길이를 sizenodupli에 저장

    countsame(nodupli, input12, sizenodupli, sizeinput); //같은 문자 횟수 세기

    return 0; //0의 반환
} //main함수의 종료

void addarr(char* a, char* b, char* ab) //addarr 함수 시작
{
    int length1 = 0; //a 문자열 길이를 위한 변수 선언
    while (a[length1] != '\0')
    {
        ab[length1] = a[length1]; //ab 문자열에 a 문자열을 복사
        length1++;
    }
    int length2 = 0; //b 문자열 길이를 위한 변수 선언
    while (b[length2] != '\0')
    {
        ab[length1 + length2] = b[length2]; //ab 문자열에서 a 문자열 복사한 것 뒤에 b 문자열 복사
        length2++;
    }
    ab[length1 + length2] = '\0'; //마지막에 \0 넣기

    return;
} //addarr 함수 종료

int getarrsize(char* arr) //getarrsize 함수 시작
{
    int size = 0; //size 변수 선언

    while (arr[size] != '\0') //arr이 끝날 때 까지
    {
        size++; //size 증가
    }
    return size; //size 반환
} //getarrsize 함수 종료

void noduplication(char* array) //noduplication 함수 시작
{
   
    bool char_bool[3000] = { 0 }; // bool형 배열 선언, 초깃값 false로 설정

    // 입력된 문자열에서 중복된 문자를 제거하여 새로운 문자열 생성
    int j = 0;
    for (int i = 0; array[i]!='\0'; i++) {
        if (char_bool[array[i]]==0) { // 해당 문자가 처음 나온 경우
            array[j] = array[i]; // 문자열에 추가
            j++;
            char_bool[array[i]] = true; // 해당 문자가 나온 것으로 표시
        }
    }
    array[j] = '\0'; // 새로운 문자열의 끝을 나타내는 null 문자 추가
    

    return;
} //noduplication 함수 종료

void countsame(char* arr1, char* arr2, int size1, int size2) //countsame 함수 시작
{
    for (int i = 0; i < size1; i++) 
    {
        int num = 0; //횟수를 셀 num 선언
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j]) //같으면
                num++; //num 증가
        }
        cout << arr1[i] << num; //결과값 출력
    }

    return;
} //countsame함수의 종료