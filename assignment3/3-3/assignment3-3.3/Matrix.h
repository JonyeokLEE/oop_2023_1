#include <iostream>
using namespace std;

class Matrix
{
private:
    double mat[3][3];

public:
    Matrix(); //생성자
    ~Matrix(); //소멸자

    void setelement(double** element); //3x3 행렬의 원소를 설정하는 함수
    void printMatrix(); //행렬을 출력하는 함수

    Matrix& operator+=(const Matrix& other); //operater +=
    Matrix& operator-=(const Matrix& other); //operater -=
    Matrix operator*(const Matrix& other); //operater *
};