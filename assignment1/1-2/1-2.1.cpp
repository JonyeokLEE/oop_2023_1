#include <iostream> //iostream ����
using namespace std; //using namespace ����

void addarr(char* a, char* b, char* ab); //�� ���ڿ��� ���ϴ� �Լ�
int getarrsize(char* arr); //���ڿ��� ���̸� ���ϴ� �Լ�
void noduplication(char* array1); //���ڿ��� �ߺ��� ������ ����� �Լ�
void countsame(char* arr1, char* arr2, int size1, int size2); //���� ���ڰ� ����� ���� �Լ�

int main() //main�Լ�
{
    char input1[1000], input2[1000], input12[2000]; //���ڿ� ����
    cin >> input1; //���ڿ� 1 �Է�
    cin >> input2; //���ڿ� 2 �Է�
    int count = 0; //count ���� ����
    int trynum = 1; //trynum ���� ����

    addarr(input1, input2, input12); //input1�� input2�� input12�� ���ϱ�

    int sizeinput = getarrsize(input12); //input12�� ���̸� sizeinput�� ����

    char nodupli[2000] = { 0, }; //�ߺ����� ���ڿ� ����
    for (int i = 0; input12[i] != '\0'; i++)
          nodupli[i] = input12[i]; //�켱 ���ڿ��� �����ϰ�
    noduplication(nodupli); //noduplication�Լ��� �־� �ߺ� ���ֱ�
    
    int sizenodupli = getarrsize(nodupli); //nodupli ���ڿ��� ���̸� sizenodupli�� ����

    countsame(nodupli, input12, sizenodupli, sizeinput); //���� ���� Ƚ�� ����

    return 0; //0�� ��ȯ
} //main�Լ��� ����

void addarr(char* a, char* b, char* ab) //addarr �Լ� ����
{
    int length1 = 0; //a ���ڿ� ���̸� ���� ���� ����
    while (a[length1] != '\0')
    {
        ab[length1] = a[length1]; //ab ���ڿ��� a ���ڿ��� ����
        length1++;
    }
    int length2 = 0; //b ���ڿ� ���̸� ���� ���� ����
    while (b[length2] != '\0')
    {
        ab[length1 + length2] = b[length2]; //ab ���ڿ����� a ���ڿ� ������ �� �ڿ� b ���ڿ� ����
        length2++;
    }
    ab[length1 + length2] = '\0'; //�������� \0 �ֱ�

    return;
} //addarr �Լ� ����

int getarrsize(char* arr) //getarrsize �Լ� ����
{
    int size = 0; //size ���� ����

    while (arr[size] != '\0') //arr�� ���� �� ����
    {
        size++; //size ����
    }
    return size; //size ��ȯ
} //getarrsize �Լ� ����

void noduplication(char* array) //noduplication �Լ� ����
{
   
    bool char_bool[3000] = { 0 }; // bool�� �迭 ����, �ʱ갪 false�� ����

    // �Էµ� ���ڿ����� �ߺ��� ���ڸ� �����Ͽ� ���ο� ���ڿ� ����
    int j = 0;
    for (int i = 0; array[i]!='\0'; i++) {
        if (char_bool[array[i]]==0) { // �ش� ���ڰ� ó�� ���� ���
            array[j] = array[i]; // ���ڿ��� �߰�
            j++;
            char_bool[array[i]] = true; // �ش� ���ڰ� ���� ������ ǥ��
        }
    }
    array[j] = '\0'; // ���ο� ���ڿ��� ���� ��Ÿ���� null ���� �߰�
    

    return;
} //noduplication �Լ� ����

void countsame(char* arr1, char* arr2, int size1, int size2) //countsame �Լ� ����
{
    for (int i = 0; i < size1; i++) 
    {
        int num = 0; //Ƚ���� �� num ����
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j]) //������
                num++; //num ����
        }
        cout << arr1[i] << num; //����� ���
    }

    return;
} //countsame�Լ��� ����