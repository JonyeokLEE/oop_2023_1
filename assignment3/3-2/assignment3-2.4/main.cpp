#include <iostream>
#include <string>
#include"header.h"
using namespace std;

void readit(string s, int coeff[], int exp[], int& index,char&returnit)
{
    s += '+'; //������ �� ó���� ���� ���� + �ޱ�
    int sign = 1; //��ȣ
    string num = ""; //����

    for (int i = 0; i < s.size(); i++) //'+' �Ǵ� '-'�� ���
    {
        if (s[i] == '+' || s[i] == '-')
        {
            if (!num.empty()) // ������ ���� ���ڰ� �ִٸ�
            {
                coeff[index] = sign * stoi(num); // ����� �߰�
                exp[index] = 0; //0���� ����
                index++;
            }
            num = ""; //�ʱ�ȭ
            sign = (s[i] == '+') ? 1 : -1; //+�� sign�� 1, �ƴϸ� -1�� ����
        }
        else if ((s[i] >= 'a') && (s[i] <= 'z') || (s[i] >= 'A') && (s[i] <= 'Z') || s[i] == '-')
        {   //������ ���
            returnit = s[i]; //�ش� ���ڸ� returnit�� ���� -> � ���ڰ� �ԷµǾ����� �� �� �ִ�.
            if (num.empty()) //������ ���� ���ڰ� ���ٸ�(����� 1�� ���)
            {
                coeff[index] = sign; 
            }
            else //������ ���� ���ڰ� �ִٸ�
            {
                coeff[index] = sign * stoi(num); //num�� ���ڷ� �ٲ㼭 sign�� ���� ���� ����
            }
            num = ""; //num �ʱ�ȭ
            if (s[i + 1] == '^') //���� ���ڰ� ������ �����̸�
            {
                i += 2; //2 �����ؼ� �Ѿ��
                int expSign = 1; //���� ��ȣ
                if (s[i] == '-')
                {
                    expSign = -1; //������ -1�� ����
                    i++; //i����
                }
                while (i < s.size() && isdigit(s[i])) //������ ��� ���ڸ� �б�
                {
                    num += s[i]; //num�� �߰�
                    i++; //i ����
                }
                exp[index] = expSign * stoi(num); //���� ������ ����
                num = ""; //�ʱ�ȭ
                i--; //1 ���ҽ�Ű�� �ݺ����� �ݺ��ɶ� ������ ��ġ�� �� �� �ִ�. ���� +2 ���
            }
            else //������ 1�̸�
            {
                exp[index] = 1; //������ 1 ����
            }
            index++; //index ����
        }
        else //����� ó��
        {
            num += s[i]; //num�� �߰�
        }
    }
}

int main() {
    string s;
    cout << "Input equation 1: ";
    cin >> s;
    string s2;
    cout << "Input equation 2: ";
    cin >> s2; //�� �� �Է¹ޱ�
    int coeff[100];
    int exp[100]; //����� ������ ������ �迭 ����
    int index = 0; //�󸶳� ����Ǿ����� �˱� ���ؼ� ����
    char c = 0; //� ���ڰ� ���Ǿ����� �����ϱ� ���� ����
    readit(s, coeff, exp, index,c); //readit �Լ��� ���� �� �迭�� ������ ����� �����ϰ�, ���ڵ� ����
    Polynomial equ1;
    equ1.setvarible(c); //c�� equ1�� ���ڷ� ����

    for (int i = 0; i < index; i++) //index���� �ݺ�
    {
        Term* node = new Term;
        node->SetCoeff(coeff[i]);
        node->SetExponent(exp[i]);
        equ1.Insert(node); //����� ������ node�� �־ equ1 ����Ʈ�� ����
    }
    cout << endl;
    index = 0;
    c = 0; //���� �ʱ�ȭ ��
    readit(s2, coeff, exp, index,c); //�ι�° �ĵ� �����ϰ� ����
    
    Polynomial equ2;
    equ2.setvarible(c);

    for (int i = 0; i < index; i++)
    {
        Term* node2 = new Term;
        node2->SetCoeff(coeff[i]);
        node2->SetExponent(exp[i]);
        equ2.Insert(node2);
    } //�ι�° �ĵ� �����ϰ� �����ؼ� ����Ʈ ����

    Polynomial save; //�ѹ� �����ϰ� ���� �� 1�� ���� ���󰡹����⿡ �����س��� ���ؼ� ����
    save = equ1; //��1�� ���� ����

    cout << "Equation 1: ";
    equ1.PrintList();
    cout << endl;
    cout << "Equation 2: ";
    equ2.PrintList();
    cout << endl; //�� ���� ���� ���
    
    equ1.Add(equ2);
    cout << "Add result: ";
    equ1.PrintList(); //equ1�� equ1+equ2 ���� ����Ǿ� ���
    cout << endl;
    equ1 = save; //equ1�� save�س��� ������ �ٽ� ����
    equ1.Sub(equ2);
    cout << "Sub result: ";
    equ1.PrintList(); //equ1�� equ1-equ2 ���� ����Ǿ� ���


    return 0;
}