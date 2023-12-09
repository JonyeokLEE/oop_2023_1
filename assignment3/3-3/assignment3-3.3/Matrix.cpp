#include "Matrix.h"

Matrix::Matrix() //������
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = 0;
        }
    }
    //��� �ʱ�ȭ
}


Matrix::~Matrix() //�Ҹ���
{
}

void Matrix::setelement(double** element) //setelement �Լ�
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = element[i][j];
        }
    }
    //���޵� ����� ���� ����
}

void Matrix::printMatrix() //printMatrix �Լ�
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    //����� ���
}

Matrix& Matrix::operator+=(const Matrix& other) //operater+=
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] += other.mat[i][j];
        }
    } //������ ��ġ�� ���ҿ� ���� += ���� ����
    return *this; //���� ��ü�� ������ ��ȯ
}

Matrix& Matrix::operator-=(const Matrix& other) //operater-=
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] -= other.mat[i][j];
        }
    } //������ ��ġ�� ���ҿ� ���� -= ���� ����
    return *this; //���� ��ü�� ������ ��ȯ
}

Matrix Matrix::operator*(const Matrix& other) //operater*
{
    Matrix multiply; //������� ���� ��ü ����
    double** mul = new double* [3];
    for (int i = 0; i < 3; i++)
    {
        mul[i] = new double[3];
    } //����� ������ �迭 �����Ҵ�
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int r = 0; r < 3; r++)
            {
                mul[i][j] += mat[i][r] * other.mat[r][j]; //����� ��� (+= ������ �̿��� ����� �����ϴ� ���)
            }
        }
    }
    multiply.setelement(mul); //������� ����
    for (int i = 0; i < 3; i++)
    {
        delete[] mul[i];
    }
    delete[] mul; //��������
    return multiply; //������� ���� ��ü ��ȯ
}