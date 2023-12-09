#include <iostream> //iostream ����
using namespace std; //namespace std ����

namespace ooplinalg //namespace ooplinalg ����
{
	class Matrix //Matrix Ŭ���� ����
	{
	public: //public ����
		Matrix(); //�⺻ ������
		Matrix(const Matrix& mat); //copy ������
		Matrix(int rows, int cols); //�������ڰ� �ִ� ������
		~Matrix(); //�Ҹ���

		float getElement(int row, int col)const; //����� ���Ҹ� ��ȯ�ϴ� �Լ�
		float** getData()const; //����� ��ȯ�ϴ� �Լ�
		void setElement(const int row, const int col, float value); //����� ���Ҹ� �����ϴ� �Լ�
		void setData(const int rows, const int cols, float** data); //����� �����ϴ� �Լ�
		int getRows()const; //rows�� ���� ��ȯ�ϴ� �Լ�
		int getCols()const; //cols�� ���� ��ȯ�ϴ� �Լ�
		void setRows(const int rows); //rows�� ���� �����ϴ� �Լ�
		void setCols(const int cols); //cols�� ���� �����ϴ� �Լ�

		float determinant(); //��İ��� ����Ͽ� ��ȯ�ϴ� �Լ�

	private: //private ����
		float** data; //��� ���� data
		int rows; //���� ��Ÿ���� rows ����
		int cols; //���� ��Ÿ���� cols ����
	}; //Matrix Ŭ���� ���� ����

	Matrix& add(Matrix& r, Matrix& a, Matrix& b); //��� �� ������ �ϴ� �Լ�
	Matrix& sub(Matrix& r, Matrix& a, Matrix& b); //��� �� ������ �ϴ� �Լ�
	Matrix& mul(Matrix& r, Matrix& a, Matrix& b); //��� �� ������ �ϴ� �Լ�

	Matrix& elementAdd(Matrix& r, Matrix& a, float v); //��İ� ������ ������ �ϴ� �Լ�
	Matrix& elementSub(Matrix& r, Matrix& a, float v); //��İ� ������ ������ �ϴ� �Լ�
	Matrix& elementMul(Matrix& r, Matrix& a, float v); //��İ� ������ ������ �ϴ� �Լ�
	Matrix& elementDiv(Matrix& r, Matrix& a, float v); //��İ� ������ �������� �ϴ� �Լ�

	Matrix& transpose(Matrix& r, Matrix& m); //Transpose ����� ���ϴ� �Լ�
	Matrix& adjoint(Matrix& r, Matrix& m); //adjoint ����� ���ϴ� �Լ�
	Matrix& inverse(Matrix& r, Matrix& m); //inverse ����� ���ϴ� �Լ�
} //ooplinalg namespace ���� ����