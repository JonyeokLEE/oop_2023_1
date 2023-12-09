#include "ooplinalg.h" //ooplinalg ������� ����
using namespace ooplinalg; //namespace ooplinalg ����

int main() //main�Լ�
{   
    int inputrow = 0, inputcol = 0, scalar = 0; //�Է¹��� ���� ����
    cout << "Input Row size: ";
    cin >> inputrow;
    cout << "Input Column size: ";
    cin >> inputcol; //�� ����� Row�� Column�� �Է¹ޱ�
    Matrix a(inputrow, inputcol);
    Matrix b(inputrow, inputcol); //�Է¹��� size ��ŭ ��� a,b ����
    float** matA = new float* [inputrow];
    float** matB = new float* [inputrow];
    for (int i = 0; i < inputrow; i++)
    {
        matA[i] = new float[inputcol];
        matB[i] = new float[inputcol];
    } //��� a,b�� ���� �Է¹ޱ� ���� matA, matB �����Ҵ�

    cout << "Input the Element of Matrix A: " << endl;
    for (int i = 0; i < inputrow; i++)
    {
        for (int j = 0; j < inputcol; j++)
        {
            cout << "(" << i << "," << j << "): ";
            cin >> matA[i][j];
        }
    } //a ��� ���� �Է¹ޱ�
    a.setData(inputrow, inputcol, matA); //a ��� ���� �����ϱ�
    cout << "Input the Element of Matrix B: " << endl;
    for (int i = 0; i < inputrow; i++)
    {
        for (int j = 0; j < inputcol; j++)
        {
            cout << "(" << i << "," << j << "): ";
            cin >> matB[i][j];
        }
    } //b ��� ���� �Է¹ޱ�
    b.setData(inputrow, inputcol, matB); //b ��� ���� �����ϱ�
    cout << "Input the Scalar Number: ";
    cin >> scalar; //��Į�� ������ ���� ��Į�� �� �Է¹ޱ�
    cout << "Matrix A:" << endl;
    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            cout << a.getElement(i, j) << " ";
        }
        cout << endl;
    } //a ��� ���
    cout << "Matrix B:" << endl;
    for (int i = 0; i < b.getRows(); i++)
    {
        for (int j = 0; j < b.getCols(); j++)
        {
            cout << b.getElement(i, j) << " ";
        }
        cout << endl;
    } //b ��� ���

    Matrix result(inputrow, inputcol); //���� ����� ���� result ��� ����
    add(result, a, b); //result = a + b
    cout << "Sum of matrix A&B:" << endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //����� ���

    sub(result, a, b); //result = a - b
    cout << "Subtraction of matrix A&B:" << endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //����� ���

    mul(result, a, b); //result = a X b
    cout << "Multiplication of matrix A&B:" << endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //����� ���

    elementAdd(result, a, scalar); //a ��Ŀ� scalar �� ���ϱ�
    cout << "Sum of matrix A & Scalar Number" <<scalar<< endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //����� ���

    elementSub(result, a, scalar); //a ��Ŀ� scalar �� ����
    cout << "Subtraction of matrix A & Scalar Number" << scalar << endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //����� ���

    elementMul(result, a, scalar); //a ��Ŀ� scalar �� ���ϱ�
    cout << "Multiplication of matrix A & Scalar Number" << scalar << endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //����� ���

    elementDiv(result, a, scalar); //a ��Ŀ� scalar �� ������
    cout << "Divide of matrix A & Scalar Number" << scalar << endl;
    for (int i = 0; i < result.getRows(); i++)
    {
        for (int j = 0; j < result.getCols(); j++)
        {
            cout << result.getElement(i, j) << " ";
        }
        cout << endl;
    } //����� ���

    float det = a.determinant(); //det�� a����� ��İ�
    cout << "Determinant of matrix A: " << det << endl; //��İ� ���

    if (inputrow != inputcol) //���簢 ����� �ƴϸ�
    {
        cout << "Inverse & Adjoint Matrix Cannot Exist." << endl;
    }
    else
    {
        Matrix adj(inputrow, inputcol); //adjoint ����� ���� adj ��� ����
        adjoint(adj, a); //a�� adjoint ����� adj��.
        cout << "Adjoint of matrix A:" << endl;
        for (int i = 0; i < adj.getRows(); i++)
        {
            for (int j = 0; j < adj.getCols(); j++)
            {
                cout << adj.getElement(i, j) << " ";
            }
            cout << endl;
        } //����� ���
        if (det == 0) //���� ��İ��� 0�̸�
        {
            cout << "Inverse Matrix Cannot Exist" << endl; //������� �������� �ʴ´�.
        }
        else //�� ���� ���
        {
            Matrix inv(inputrow, inputcol); //inverse ����� ���� inv ���
            inverse(inv, a); //a�� inverse ����� inv��.
            cout << "Inverse of matrix A:" << endl;
            for (int i = 0; i < inv.getRows(); i++)
            {
                for (int j = 0; j < inv.getCols(); j++)
                {
                    cout << inv.getElement(i, j) << " ";
                }
                cout << endl;
            } //����� ���
        }
    }
    Matrix trans(inputcol,inputrow); //transpose ����� ���� trans ��� ����
    transpose(trans, a); //a�� transpose ����� trans��.
    cout << "Transpose of matrix A:" << endl;
    for (int i = 0; i < trans.getRows(); i++)
    {
        for (int j = 0; j < trans.getCols(); j++)
        {
            cout << trans.getElement(i, j) << " ";
        }
        cout << endl;
    } //����� ���


    for (int i = 0; i < inputrow; i++)
    {
        delete[] matA[i];
        delete[] matB[i];
    }
    delete[] matA;
    delete[] matB; //�����Ҵ� ����
    return 0;
}