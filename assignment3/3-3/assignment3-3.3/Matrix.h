#include <iostream>
using namespace std;

class Matrix
{
private:
    double mat[3][3];

public:
    Matrix(); //������
    ~Matrix(); //�Ҹ���

    void setelement(double** element); //3x3 ����� ���Ҹ� �����ϴ� �Լ�
    void printMatrix(); //����� ����ϴ� �Լ�

    Matrix& operator+=(const Matrix& other); //operater +=
    Matrix& operator-=(const Matrix& other); //operater -=
    Matrix operator*(const Matrix& other); //operater *
};