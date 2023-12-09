#include <iostream>
#include <fstream>

using namespace std;


int sizearr(char* sentence);
bool match(char* str, char* pattern);

int main()
{
    char fname[100]; //filename input�� ���� ���ڿ�
    cout << "Input file name: ";
    cin >> fname; //filename �Է¹ޱ�

    ifstream fin(fname); //�Է��� ���� �̸����� ifstream ��ü ����

    if (!fin) //������ �������� ���� �� ����ó��
    {
        cout << "The file does not exist." << endl;
        return 0;
    }

    int num;
    cout << "Input number of patterns: ";
    cin >> num; //Input ���� �Է¹ޱ�

    char** patterns; //������ ������ ���������� ���� �Ҵ�
    patterns = new char* [num];
    for (int i = 0; i < num; i++)
        patterns[i] = new char[100];

    cout << "Input patterns: " << endl;
    for (int j = 0; j < num; j++)
        cin >> patterns[j]; //���ϵ��� �ึ�� �Է¹ޱ�
    cout << endl;
    char sentence[100]; //���Ͽ��� ���� �� �о���� ���� �迭 ����

    while (fin.getline(sentence, 100)) //���Ͽ��� �� �پ� �о���̱�
    {
        for (int i = 0; i < num; i++) //�Է��� ���ϵ��� Ȯ��
        {
            bool is_matched = match(sentence, patterns[i]); // ���ϰ� ������ ��ġ�ϴ��� Ȯ��
            if (is_matched) // ��ġ�Ѵٸ�
            {
                cout << patterns[i] << ": " << sentence << endl; // ���ϰ� ������ �Բ� ���
            }
        }
    }

    for (int i = 0; i < num; i++) //���� ������ ��������
        delete[] patterns[i];
    delete[] patterns;

    fin.close(); //���� �ݱ�

    return 0; //0�� ��ȯ
} //main�Լ� ����

int sizearr(char* sentence) //�迭�� ���̸� ���ϴ� �Լ�
{
    int b = 0;

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        b++;
    }
    return b; //�迭�� ���̸� ��ȯ
} //sizearr �Լ� ����


bool match(char* str, char* pattern) //match�Լ�
{
    int sizestr = sizearr(str); //str�� ���̸� ����
    int sizepattern = sizearr(pattern); //pattern�� ���̸� ����

    int i = 0, j = 0; //�� ���ڿ��� �ε��� �ʱ�ȭ
    int star = -1, match = 0; //*�� ��ġ�� ���ڿ��� �ε��� �ʱ�ȭ

    while (i < sizestr) //str�� ������ Ž��
    {
        if (j < sizepattern && pattern[j] == '?')
        {   //?�� ������
            i++;
            j++; //�ε��� ����
        }
        else if (j < sizepattern && pattern[j] == '*')
        {   //*�� ������
            star = j;
            match = i;
            j++; //�ε��� ����
        }
        else if (j < sizepattern && pattern[j] == str[i])
        {   //�� ���ڰ� ������
            i++;
            j++; //�ε��� ����
        }
        else if (star != -1)
        {   //* ���Ŀ� ���ڿ��� ��ġ�ϴ� ���ڿ��� ã��
            j = star + 1;
            match++;
            i = match;
        }
        else
            return false;
    }

    //���ڿ��� pattern�� ��ġ�ϴ� ���θ� ��ȯ
    return (j == sizepattern && i == sizestr);
}

