#include "Matrix.h"

Matrix::Matrix() //생성자
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = 0;
        }
    }
    //행렬 초기화
}


Matrix::~Matrix() //소멸자
{
}

void Matrix::setelement(double** element) //setelement 함수
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = element[i][j];
        }
    }
    //전달된 행렬의 값을 복사
}

void Matrix::printMatrix() //printMatrix 함수
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    //행렬을 출력
}

Matrix& Matrix::operator+=(const Matrix& other) //operater+=
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] += other.mat[i][j];
        }
    } //동일한 위치의 원소에 대해 += 연산 수행
    return *this; //현재 객체의 참조를 반환
}

Matrix& Matrix::operator-=(const Matrix& other) //operater-=
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] -= other.mat[i][j];
        }
    } //동일한 위치의 원소에 대해 -= 연산 수행
    return *this; //현재 객체의 참조를 반환
}

Matrix Matrix::operator*(const Matrix& other) //operater*
{
    Matrix multiply; //결과값을 위한 객체 선언
    double** mul = new double* [3];
    for (int i = 0; i < 3; i++)
    {
        mul[i] = new double[3];
    } //결과값 저장할 배열 동적할당
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int r = 0; r < 3; r++)
            {
                mul[i][j] += mat[i][r] * other.mat[r][j]; //결과값 계산 (+= 연산을 이용해 결과값 누적하는 방식)
            }
        }
    }
    multiply.setelement(mul); //결과값을 세팅
    for (int i = 0; i < 3; i++)
    {
        delete[] mul[i];
    }
    delete[] mul; //동적해제
    return multiply; //결과값을 담은 객체 반환
}