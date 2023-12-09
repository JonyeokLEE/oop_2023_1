#include <iostream> //iostream 선언
#include <cstdlib> //cstdlib 선언
#include <ctime> //ctime 선언
using namespace std; //namespace std 선언

void Sender(char* inputint); //Sender 함수 선언
void xorgate(const char* array); //xorgate 함수 선언
void Transmission_Channel(const char* coded_frame); //Transmission_Channel 함수 선언
void Receiver(const char* received_frame); //Receiver 함수 선언

const int divisor = 0b11011; //divisior 상수 선언

int count(int v) //5자리가 되려면 몇번 shift해야하는지 알려주는 함수
{
    int num = 0; //횟수 세는 변수 선언
    while (v != 0) //v가 0이 될 때까지
    {
        num++; //num은 1 증가
        v >>= 1; //v는 오른쪽으로 shift
    }
    return 5 - num; //5에서 num을 뺀 값을 반환
} //count함수 종료

int main(void) //main함수 시작
{
    char input[17] = { 0 }; //이진수를 받을 문자열 선언
    cout << "Data: ";
    
    cin >> input; //12자리 받기

    

    for (int i = 12; i < 16; i++)
    {
        input[i] = '0';
    } //나머지 뒤 4자리는 0으로 채우기
    input[16] = '\0'; //끝에는 NULL 문자
    Sender(input); //input 배열을 Sender로 전달

    return 0; //0의 반환
} //main함수 종료

int xorgate(char* array) //xorgate 연산을 하는 함수
{
    int num = 0; //결과값을 위한 변수 선언
    int down = 4; //연산의 끝을 판별하기 위한 변수 선언

    for (int i = 0; i < 4; i++)
    {
        num <<= 1;
        num += (array[i] - '0');
    } //초기 5자리를 num에 추가

    while (down < 16) //array의 끝까지 갈 때까지
    {
        for (int i = 0; i < count(num); i++) //count(num)만큼 반복동작
        {
            num <<= 1; //num을 왼쪽으로 shift 1회
            num += (array[down] - '0'); //다음 이진수 값을 더하기(그림 상으로는 다음 값을 밑으로 내리는 과정)
            down += 1; //down 증가
        }
        num ^= divisor; //num은 num과 divisor을 xor연산한 값이다.
    }
    return num; //num 반환
} //xorgate 함수 종료

void Sender(char* inputint) //Sender 함수
{
    char senderarr[17] = { 0 }; //inputint를 복사하기 위한 문자열 선언

    for (int i = 0; i < 16; i++)
    {
        senderarr[i] = inputint[i];
    }
    senderarr[16] = '\0'; //복사하고 끝에 \0까지 추가 (복사완료)
    int fcs = xorgate(senderarr); //senderarr을 전달하여 xorgate 연산하여 반환값을 fcs에 저장

    for (int i = 15; i > 11; i--) //fcs값을 배열 끝 4칸에 저장
    {
        senderarr[i] = (fcs % 2) + 48; //나누기 2의 나머지를 넣어준다. (+48)
        fcs /= 2; //fcs도 값을 최신화
    }
    cout << "Coded frame: " << senderarr << endl;; //fcs까지 붙인 값을 출력
    Transmission_Channel(senderarr); //Transmission_Channel로 senderarr 전송

    return;
} //Sender 함수 종료

void Transmission_Channel(const char* coded_frame) //Transmission_Channel 함수
{
    char transarr[17] = { 0 }; //coded_frame 복사를 위한 문자열 선언

    for (int i = 0; i < 16; i++)
    {
        transarr[i] = coded_frame[i];
    }
    transarr[16] = '\0'; //복사하고 끝에 \0 추가(복사완료)
    srand(time(NULL)); //srand(time(NULL)) 선언

    for (int i = 0; i < 16; i++) {
        // 5%의 확률로 문자를 반전시킵니다.
        if (rand() % 100 < 5) {
            // 문자를 반전시킵니다.
            if (transarr[i] == '0') {
                transarr[i] = '1';
            }
            else {
                transarr[i] = '0';
            }
        }
    }
    cout << "Received frame: " << transarr << endl; //Received frame 출력 

    Receiver(transarr); //Receiver로 전달

    return;
} //Transmission_Channel 함수 종료

void Receiver(const char* received_frame) //Receiver 함수
{
    char receivearr[17] = { 0 }; //received_frame을 복사할 문자열 선언

    for (int i = 0; i < 16; i++)
    {
        receivearr[i] = received_frame[i];
    }
    receivearr[16] = '\0'; //복사 완료



    int check = xorgate(receivearr); //Error를 detect하기 위해 배열을 다시 xorgate로 돌려보고 반환값을 받기

    receivearr[12] = '\0'; //배열을 12자리로 끊어주기
    cout << "Reconstructed data: " << receivearr<<endl; //Reconstruced data 출력
    if (check == 0) //check가 0이면
    {
        cout << "No detected error" << endl; //오류 없음
    }
    else //그 외
    {
        cout << "Receiver has detected error" << endl; //오류 발생
    }
} //Receiver 함수 종료