#include <iostream> //iostream ����
#include <cstdlib> //cstdlib ����
#include <ctime> //ctime ����
using namespace std; //namespace std ����

void Sender(char* inputint); //Sender �Լ� ����
void xorgate(const char* array); //xorgate �Լ� ����
void Transmission_Channel(const char* coded_frame); //Transmission_Channel �Լ� ����
void Receiver(const char* received_frame); //Receiver �Լ� ����

const int divisor = 0b11011; //divisior ��� ����

int count(int v) //5�ڸ��� �Ƿ��� ��� shift�ؾ��ϴ��� �˷��ִ� �Լ�
{
    int num = 0; //Ƚ�� ���� ���� ����
    while (v != 0) //v�� 0�� �� ������
    {
        num++; //num�� 1 ����
        v >>= 1; //v�� ���������� shift
    }
    return 5 - num; //5���� num�� �� ���� ��ȯ
} //count�Լ� ����

int main(void) //main�Լ� ����
{
    char input[17] = { 0 }; //�������� ���� ���ڿ� ����
    cout << "Data: ";
    
    cin >> input; //12�ڸ� �ޱ�

    

    for (int i = 12; i < 16; i++)
    {
        input[i] = '0';
    } //������ �� 4�ڸ��� 0���� ä���
    input[16] = '\0'; //������ NULL ����
    Sender(input); //input �迭�� Sender�� ����

    return 0; //0�� ��ȯ
} //main�Լ� ����

int xorgate(char* array) //xorgate ������ �ϴ� �Լ�
{
    int num = 0; //������� ���� ���� ����
    int down = 4; //������ ���� �Ǻ��ϱ� ���� ���� ����

    for (int i = 0; i < 4; i++)
    {
        num <<= 1;
        num += (array[i] - '0');
    } //�ʱ� 5�ڸ��� num�� �߰�

    while (down < 16) //array�� ������ �� ������
    {
        for (int i = 0; i < count(num); i++) //count(num)��ŭ �ݺ�����
        {
            num <<= 1; //num�� �������� shift 1ȸ
            num += (array[down] - '0'); //���� ������ ���� ���ϱ�(�׸� �����δ� ���� ���� ������ ������ ����)
            down += 1; //down ����
        }
        num ^= divisor; //num�� num�� divisor�� xor������ ���̴�.
    }
    return num; //num ��ȯ
} //xorgate �Լ� ����

void Sender(char* inputint) //Sender �Լ�
{
    char senderarr[17] = { 0 }; //inputint�� �����ϱ� ���� ���ڿ� ����

    for (int i = 0; i < 16; i++)
    {
        senderarr[i] = inputint[i];
    }
    senderarr[16] = '\0'; //�����ϰ� ���� \0���� �߰� (����Ϸ�)
    int fcs = xorgate(senderarr); //senderarr�� �����Ͽ� xorgate �����Ͽ� ��ȯ���� fcs�� ����

    for (int i = 15; i > 11; i--) //fcs���� �迭 �� 4ĭ�� ����
    {
        senderarr[i] = (fcs % 2) + 48; //������ 2�� �������� �־��ش�. (+48)
        fcs /= 2; //fcs�� ���� �ֽ�ȭ
    }
    cout << "Coded frame: " << senderarr << endl;; //fcs���� ���� ���� ���
    Transmission_Channel(senderarr); //Transmission_Channel�� senderarr ����

    return;
} //Sender �Լ� ����

void Transmission_Channel(const char* coded_frame) //Transmission_Channel �Լ�
{
    char transarr[17] = { 0 }; //coded_frame ���縦 ���� ���ڿ� ����

    for (int i = 0; i < 16; i++)
    {
        transarr[i] = coded_frame[i];
    }
    transarr[16] = '\0'; //�����ϰ� ���� \0 �߰�(����Ϸ�)
    srand(time(NULL)); //srand(time(NULL)) ����

    for (int i = 0; i < 16; i++) {
        // 5%�� Ȯ���� ���ڸ� ������ŵ�ϴ�.
        if (rand() % 100 < 5) {
            // ���ڸ� ������ŵ�ϴ�.
            if (transarr[i] == '0') {
                transarr[i] = '1';
            }
            else {
                transarr[i] = '0';
            }
        }
    }
    cout << "Received frame: " << transarr << endl; //Received frame ��� 

    Receiver(transarr); //Receiver�� ����

    return;
} //Transmission_Channel �Լ� ����

void Receiver(const char* received_frame) //Receiver �Լ�
{
    char receivearr[17] = { 0 }; //received_frame�� ������ ���ڿ� ����

    for (int i = 0; i < 16; i++)
    {
        receivearr[i] = received_frame[i];
    }
    receivearr[16] = '\0'; //���� �Ϸ�



    int check = xorgate(receivearr); //Error�� detect�ϱ� ���� �迭�� �ٽ� xorgate�� �������� ��ȯ���� �ޱ�

    receivearr[12] = '\0'; //�迭�� 12�ڸ��� �����ֱ�
    cout << "Reconstructed data: " << receivearr<<endl; //Reconstruced data ���
    if (check == 0) //check�� 0�̸�
    {
        cout << "No detected error" << endl; //���� ����
    }
    else //�� ��
    {
        cout << "Receiver has detected error" << endl; //���� �߻�
    }
} //Receiver �Լ� ����