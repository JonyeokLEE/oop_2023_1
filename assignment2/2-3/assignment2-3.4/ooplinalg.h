#include <iostream> //iostream 선언
using namespace std; //namespace std 선언

namespace ooplinalg //namespace ooplinalg 선언
{
	class Matrix //Matrix 클래스 선언
	{
	public: //public 구역
		Matrix(); //기본 생성자
		Matrix(const Matrix& mat); //copy 생성자
		Matrix(int rows, int cols); //전달인자가 있는 생성자
		~Matrix(); //소멸자

		float getElement(int row, int col)const; //행렬의 원소를 반환하는 함수
		float** getData()const; //행렬을 반환하는 함수
		void setElement(const int row, const int col, float value); //행렬의 원소를 세팅하는 함수
		void setData(const int rows, const int cols, float** data); //행렬을 세팅하는 함수
		int getRows()const; //rows의 값을 반환하는 함수
		int getCols()const; //cols의 값을 반환하는 함수
		void setRows(const int rows); //rows의 값을 세팅하는 함수
		void setCols(const int cols); //cols의 값을 세팅하는 함수

		float determinant(); //행렬값을 계산하여 반환하는 함수

	private: //private 구역
		float** data; //행렬 변수 data
		int rows; //행을 나타내는 rows 변수
		int cols; //열을 나타내는 cols 변수
	}; //Matrix 클래스 선언 종료

	Matrix& add(Matrix& r, Matrix& a, Matrix& b); //행렬 간 덧셈을 하는 함수
	Matrix& sub(Matrix& r, Matrix& a, Matrix& b); //행렬 간 뺄셈을 하는 함수
	Matrix& mul(Matrix& r, Matrix& a, Matrix& b); //행렬 간 곱셈을 하는 함수

	Matrix& elementAdd(Matrix& r, Matrix& a, float v); //행렬과 숫자의 덧셈을 하는 함수
	Matrix& elementSub(Matrix& r, Matrix& a, float v); //행렬과 숫자의 뺄셈을 하는 함수
	Matrix& elementMul(Matrix& r, Matrix& a, float v); //행렬과 숫자의 곱셈을 하는 함수
	Matrix& elementDiv(Matrix& r, Matrix& a, float v); //행렬과 숫자의 나눗셈을 하는 함수

	Matrix& transpose(Matrix& r, Matrix& m); //Transpose 행렬을 구하는 함수
	Matrix& adjoint(Matrix& r, Matrix& m); //adjoint 행렬을 구하는 함수
	Matrix& inverse(Matrix& r, Matrix& m); //inverse 행렬을 구하는 함수
} //ooplinalg namespace 선언 종료