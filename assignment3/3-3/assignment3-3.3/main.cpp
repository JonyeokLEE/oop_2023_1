#include "Matrix.h"

int main()
{
    Matrix matrix1;
    Matrix matrix2; //��ü ����

    double** input1 = new double* [3];
    double** input2 = new double* [3];
    for (int i = 0; i < 3; i++)
    {
        input1[i] = new double[3];
        input2[i] = new double[3];
    } //�Է¹��� ��� �����Ҵ�
    cout << "[Input Matrix 1]" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "(" << i+1 << "," << j+1 << "): ";
            cin >> input1[i][j];
        }
    }
    matrix1.setelement(input1); //��� 1 �Է¹ް� setelement���ֱ�
    cout << "[Input Matrix 2]" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "(" << i+1 << "," << j+1 << "): ";
            cin >> input2[i][j];
        }
    }
    matrix2.setelement(input2); //��� 2 �Է¹ް� setelement���ֱ�
    cout << endl << "[Matrix 1]" << endl;
    matrix1.printMatrix();
    cout << endl << "[Matrix 2]" << endl;
    matrix2.printMatrix();
    //�Է¹��� ��� ���

    Matrix res = matrix1 * matrix2; //operater *�� ����� ���� res ��ü ����
    cout << endl<< "[Matrix1 * Matrix2]" << endl;
    res.printMatrix();
    //operater * ��� ���

    matrix1 += matrix2; //operater += ����
    cout << "[Matrix1 += Matrix2]" << endl;
    matrix1.printMatrix(); //����� ���

    matrix1.setelement(input1); //�����س��� ���� �ٽ� �����Ͽ� ����
    matrix1 -= matrix2; //operater -= ����
    cout << "[Matrix1 -= Matrix2]" << endl;
    matrix1.printMatrix(); //����� ���


    for (int i = 0; i < 3; i++)
    {
        delete[] input1[i];
        delete[] input2[i];
    }
    delete[] input1;
    delete[] input2; //��������

    return 0;
}
