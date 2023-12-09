#include "Matrix.h"

int main()
{
    Matrix matrix1;
    Matrix matrix2; //객체 선언

    double** input1 = new double* [3];
    double** input2 = new double* [3];
    for (int i = 0; i < 3; i++)
    {
        input1[i] = new double[3];
        input2[i] = new double[3];
    } //입력받을 행렬 동적할당
    cout << "[Input Matrix 1]" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "(" << i+1 << "," << j+1 << "): ";
            cin >> input1[i][j];
        }
    }
    matrix1.setelement(input1); //행렬 1 입력받고 setelement해주기
    cout << "[Input Matrix 2]" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "(" << i+1 << "," << j+1 << "): ";
            cin >> input2[i][j];
        }
    }
    matrix2.setelement(input2); //행렬 2 입력받고 setelement해주기
    cout << endl << "[Matrix 1]" << endl;
    matrix1.printMatrix();
    cout << endl << "[Matrix 2]" << endl;
    matrix2.printMatrix();
    //입력받은 행렬 출력

    Matrix res = matrix1 * matrix2; //operater *의 결과를 위한 res 객체 선언
    cout << endl<< "[Matrix1 * Matrix2]" << endl;
    res.printMatrix();
    //operater * 결과 출력

    matrix1 += matrix2; //operater += 수행
    cout << "[Matrix1 += Matrix2]" << endl;
    matrix1.printMatrix(); //결과값 출력

    matrix1.setelement(input1); //저장해놨던 값을 다시 전달하여 복원
    matrix1 -= matrix2; //operater -= 수행
    cout << "[Matrix1 -= Matrix2]" << endl;
    matrix1.printMatrix(); //결과값 출력


    for (int i = 0; i < 3; i++)
    {
        delete[] input1[i];
        delete[] input2[i];
    }
    delete[] input1;
    delete[] input2; //동적해제

    return 0;
}
