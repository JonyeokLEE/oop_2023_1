#include "ooplinalg.h" //ooplinalg 헤더파일 선언
using namespace ooplinalg; //namespace ooplinalg 선언

int main() //main함수
{   
    int inputrow = 0, inputcol = 0, scalar = 0; //입력받을 수들 선언
    cout << "Input Row size: ";
    cin >> inputrow;
    cout << "Input Column size: ";
    cin >> inputcol; //두 행렬의 Row와 Column을 입력받기
    Matrix a(inputrow, inputcol);
    Matrix b(inputrow, inputcol); //입력받은 size 만큼 행렬 a,b 선언
    float** matA = new float* [inputrow];
    float** matB = new float* [inputrow];
    for (int i = 0; i < inputrow; i++)
    {
        matA[i] = new float[inputcol];
        matB[i] = new float[inputcol];
    } //행렬 a,b의 값을 입력받기 위해 matA, matB 동적할당

    cout << "Input the Element of Matrix A: " << endl;
    for (int i = 0; i < inputrow; i++)
    {
        for (int j = 0; j < inputcol; j++)
        {
            cout << "(" << i << "," << j << "): ";
            cin >> matA[i][j];
        }
    } //a 행렬 원소 입력받기
    a.setData(inputrow, inputcol, matA); //a 행렬 원소 세팅하기
    cout << "Input the Element of Matrix B: " << endl;
    for (int i = 0; i < inputrow; i++)
    {
        for (int j = 0; j < inputcol; j++)
        {
            cout << "(" << i << "," << j << "): ";
            cin >> matB[i][j];
        }
    } //b 행렬 원소 입력받기
    b.setData(inputrow, inputcol, matB); //b 행렬 원소 세팅하기
    cout << "Input the Scalar Number: ";
    cin >> scalar; //스칼라 연산을 위한 스칼라 수 입력받기
    cout << "Matrix A:" << endl;
    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            cout << a.getElement(i, j) << " ";
        }
        cout << endl;
    } //a 행렬 출력
    cout << "Matrix B:" << endl;
    for (int i = 0; i < b.getRows(); i++)
    {
        for (int j = 0; j < b.getCols(); j++)
        {
            cout << b.getElement(i, j) << " ";
        }
        cout << endl;
    } //b 행렬 출력

    Matrix result(inputrow, inputcol); //연산 결과를 위한 result 행렬 선언
    add(result, a, b); //result = a + b
    cout << "Sum of matrix A&B:" << endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //결과값 출력

    sub(result, a, b); //result = a - b
    cout << "Subtraction of matrix A&B:" << endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //결과값 출력

    mul(result, a, b); //result = a X b
    cout << "Multiplication of matrix A&B:" << endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //결과값 출력

    elementAdd(result, a, scalar); //a 행렬에 scalar 값 더하기
    cout << "Sum of matrix A & Scalar Number" <<scalar<< endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //결과값 출력

    elementSub(result, a, scalar); //a 행렬에 scalar 값 빼기
    cout << "Subtraction of matrix A & Scalar Number" << scalar << endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //결과값 출력

    elementMul(result, a, scalar); //a 행렬에 scalar 값 곱하기
    cout << "Multiplication of matrix A & Scalar Number" << scalar << endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //결과값 출력

    elementDiv(result, a, scalar); //a 행렬에 scalar 값 나누기
    cout << "Divide of matrix A & Scalar Number" << scalar << endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //결과값 출력

    float det = a.determinant(); //det는 a행렬의 행렬값
    cout << "Determinant of matrix A: " << det << endl; //행렬값 출력

    if (inputrow != inputcol) //정사각 행렬이 아니면
    {
        cout << "Inverse & Adjoint Matrix Cannot Exist." << endl;
    }
    else
    {
        Matrix adj(inputrow, inputcol); //adjoint 행렬을 위한 adj 행렬 선언
        adjoint(adj, a); //a의 adjoint 행렬은 adj다.
        cout << "Adjoint of matrix A:" << endl;
        for (int i = 0; i < adj.getRows(); i++)
        {
            for (int j = 0; j < adj.getCols(); j++)
            {
                cout << adj.getElement(i, j) << " ";
            }
            cout << endl;
        } //결과값 출력
        if (det == 0) //만약 행렬값이 0이면
        {
            cout << "Inverse Matrix Cannot Exist" << endl; //역행렬은 존재하지 않는다.
        }
        else //그 외의 경우
        {
            Matrix inv(inputrow, inputcol); //inverse 행렬을 위한 inv 출력
            inverse(inv, a); //a의 inverse 행렬은 inv다.
            cout << "Inverse of matrix A:" << endl;
            for (int i = 0; i < inv.getRows(); i++)
            {
                for (int j = 0; j < inv.getCols(); j++)
                {
                    cout << inv.getElement(i, j) << " ";
                }
                cout << endl;
            } //결과값 출력
        }
    }
    Matrix trans(inputcol,inputrow); //transpose 행렬을 위한 trans 행렬 선언
    transpose(trans, a); //a의 transpose 행렬은 trans다.
    cout << "Transpose of matrix A:" << endl;
    for (int i = 0; i < trans.getRows(); i++)
    {
        for (int j = 0; j < trans.getCols(); j++)
        {
            cout << trans.getElement(i, j) << " ";
        }
        cout << endl;
    } //결과값 출력


    for (int i = 0; i < inputrow; i++)
    {
        delete[] matA[i];
        delete[] matB[i];
    }
    delete[] matA;
    delete[] matB; //동적할당 해제
    return 0;
}