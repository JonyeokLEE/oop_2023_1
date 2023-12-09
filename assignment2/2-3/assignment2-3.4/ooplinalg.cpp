#include "ooplinalg.h" //ooplinalg 헤더파일 선언

namespace ooplinalg //ooplinalg namespace 기능 구현
{
    Matrix::Matrix() //기본 생성자
    {
        rows = 0;
        cols = 0;
        data = nullptr; //모든 private 변수를 초기화한다.
    }

    Matrix::~Matrix() //소멸자
    {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data; //동적할당했던 data를 delete해준다.
    }

    Matrix::Matrix(int rows, int cols) //전달인자가 있는 생성자
    {
        this->rows = rows;
        this->cols = cols; //전달받은 값들을 각각 rows와 cols에 넣어준다.
        data = new float* [rows];
        for (int i = 0; i < rows; i++)
            data[i] = new float[cols]; //전달받은 rows와 cols 만큼 data를 동적할당한다.
    }
    Matrix::Matrix(const Matrix& mat) //copy 생성자
    {
        rows = mat.rows;
        cols = mat.cols; //전달받은 mat의 rows와 cols를 그대로 복사한다.
        data = new float* [rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new float[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = mat.data[i][j];
        } //data를 rows와 cols 만큼 동적할당 하는 동시에 mat의 data를 복사해준다.
    }
    float Matrix::getElement(int row, int col) const //행렬의 원소를 반환하는 함수
    {
        return data[row][col]; //해당 위치의 원소를 반환해준다.
    }
    void Matrix::setData(const int rows, const int cols, float** data) //행렬의 원소를 세팅하는 함수
    {
        this->rows = rows;
        this->cols = cols; //전달받은 값을 rows와 cols에 넣어준다.
        this->data = new float* [rows];
        for (int i = 0; i < rows; i++)
        {
            this->data[i] = new float[cols];
            for (int j = 0; j < cols; j++)
                this->data[i][j] = data[i][j];
        } //data를 rows와 cols만큼 동적할당을 하는 동시에 전달받은 data의 값을 복사한다.
    }
    void Matrix::setElement(const int row, const int col, float value) //행렬의 원소를 세팅하는 함수
    {
        data[row][col] = value; //해당 위치에 value값을 넣어준다.
    }
    int Matrix::getRows() const //rows를 반환하는 함수
    {
        return rows; //rows를 반환한다.
    }

    int Matrix::getCols() const //cols를 반환하는 함수
    {
        return cols; //cols를 반환한다.
    }
    float** Matrix::getData()const //data를 반환하는 함수
    {
        return data; //data를 반환한다.
    }
    void Matrix::setRows(const int rows) //rows의 값을 세팅하는 함수
    {
        this->rows = rows; //전달받은 값을 rows에 넣어준다.
    }

    void Matrix::setCols(const int cols) //cols의 값을 세팅하는 함수
    {
        this->cols = cols; //전달받은 값을 cols에 넣어준다.
    }

    float Matrix::determinant() //행렬값을 계산하는 함수
    {
        if (rows != cols) //정방행렬만 계산 가능(행과 열의 크기가 같은 행렬)
            return -1; //-1을 반환

        if (rows == 1) //행과 열 크기가 1이면
            return data[0][0]; //그 값을 반환

        float res = 0; //결과값을 위한 변수 선언
        for (int i = 0; i < cols; i++) //0부터 cols까지 반복
        {
            float** small = new float* [rows - 1];
            for (int j = 0; j < rows - 1; j++)
            {
                small[j] = new float[cols - 1]; //작게 분할된 부분행렬 생성(행과 열이 1씩 작다)
            }
            for (int j = 1; j < rows; j++) //j는 원래 행렬의 행 인덱스
            {
                for (int z = 0; z < cols; z++) //z는 원래 행렬의 열 인덱스
                {
                    //부분행렬의 값을 설정하는 부분
                    if (z < i) //z가 i보다 작으면
                        small[j - 1][z] = data[j][z]; //해당 인덱스에 값 복사
                    else if (z > i) //z가 i보다 크면
                        small[j - 1][z - 1] = data[j][z]; //해당 인덱스에 값 복사
                }
                    
            }
            Matrix smallone(rows - 1, cols - 1); //부분행렬 생성
            smallone.setData(rows - 1, cols - 1, small); //small 값을 부분행렬에 복사
            if (i % 2 == 0) //홀수 열이면
                res += data[0][i] * smallone.determinant(); //더하기
            else //짝수 열이면
                res -= data[0][i] * smallone.determinant(); //빼기

            for (int j = 0; j < rows - 1; j++)
                delete[] small[j];
            delete[] small; //부분행렬 동적할당 해제
        }
        return res; //결과를 반환
    }

    Matrix& add(Matrix& r, Matrix& a, Matrix& b) //행렬 간 덧셈을 하는 함수
    {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
            return r; //행렬의 행과 열이 서로 다르면 r을 반환한다.

        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) + b.getElement(i, j)); //a와 b 행렬의 덧셈 값을 r에 넣는다.

        return r; //r 반환
    }

    Matrix& sub(Matrix& r, Matrix& a, Matrix& b) //행렬 간 뺄셈을 하는 함수
    {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
            return r; //행렬의 행과 열이 서로 다르면 r을 반환한다.
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) - b.getElement(i, j)); //a와 b 행렬의 뺄셈 값을 r에 넣는다.

        return r; //r 반환
    }

    Matrix& mul(Matrix& r, Matrix& a, Matrix& b) //행렬 간 곱셈을 하는 함수
    {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
            return r; //행렬의 행과 열이 서로 다르면 r을 반환한다.
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) * b.getElement(i, j)); //a와 b 행렬의 곱셈 값을 r에 넣는다.

        return r; //r 반환
    }

    Matrix& elementAdd(Matrix& r, Matrix& a, float v) //행렬과 수의 덧셈을 하는 함수
    {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) + v); //a 행렬과 v를 더한 값을 r행렬에 setElement 해준다.

        return r; //r 반환
    }

    Matrix& elementSub(Matrix& r, Matrix& a, float v) //행렬과 수의 뺄셈을 하는 함수
    {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) - v); //a 행렬과 v를 뺀 값을 r행렬에 setElement 해준다.

        return r; //r 반환
    }

    Matrix& elementMul(Matrix& r, Matrix& a, float v) //행렬과 수의 곱셈을 하는 함수
    {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) * v); //a 행렬과 v를 곱한 값을 r행렬에 setElement 해준다.

        return r; //r 반환
    }

    Matrix& elementDiv(Matrix& r, Matrix& a, float v) //행렬과 수의 나눗셈을 하는 함수
    {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) / v); //a 행렬과 v를 나눈 값을 r행렬에 setElement 해준다.

        return r; //r 반환
    }
    Matrix& transpose(Matrix& r, Matrix& m) //Transpose 행렬을 구하는 함수
    {
        r.setCols(m.getRows());
        r.setRows(m.getCols());

        for (int i = 0; i < m.getRows(); i++)
        {
            for (int j = 0; j < m.getCols(); j++)
            {
                float temp = m.getElement(i, j); //temp에 m의 해당 인덱스 값을 받아서
                r.setElement(j, i, temp); //transpose한 위치의 r에 값을 넣어준다.
            }
        }

        return r; //r 반환
    }

    Matrix& adjoint(Matrix& r, Matrix& m) //Adjoint 행렬을 구하는 함수
    {
        Matrix seperate(m.getRows(), m.getCols()); //seperate 행렬 선언
        for (int i = 0; i < m.getRows(); i++) //0부터 m의 row만큼 반복
        {
            for (int j = 0; j < m.getCols(); j++) //0부터 m의 col만큼 반복
            {
                Matrix smallone(m.getRows() - 1, m.getCols() - 1); //크기가 1씩 작은 smallone 행렬
                for (int z = 0; z < m.getRows() - 1; z++) //0부터 row-1 만큼 반복
                {
                    for (int k = 0; k < m.getCols() - 1; k++) //0부터 col-1 만큼 반복
                    {
                        int row2;
                        if (z < i) { //z가 i보다 작으면
                            row2 = z; //row2는 z값을 갖는다.
                        }
                        else { //그 외의 경우
                            row2 = z + 1; //row2는 z+1의 값을 갖는다.
                        }

                        int col2;
                        if (k < j) { //k가 j보다 작으면
                            col2 = k; //col2는 k값을 갖는다.
                        }
                        else { //그 외의 경우
                            col2 = k + 1; //col2는 k+1의 값을 갖는다.
                        }
                        smallone.setElement(z, k, m.getElement(row2, col2)); //smallone에 z행, k행, 그리고 row2와 col2 위치의 m 행렬의 값을 갖고 setElement를 한다.
                    }
                }
                seperate.setElement(i, j, smallone.determinant()); //seperate에 i행 j열, smallone의 행렬값을 setElement 해준다.
            }
        }
        Matrix res(m.getRows(), m.getCols()); //결과값을 위한 res 행렬 선언
        for (int i = 0; i < m.getRows(); i++)
        {
            for (int j = 0; j < m.getCols(); j++)
            {
                float temp = seperate.getElement(i, j); //temp에 seperate의 값을 받아준다.
                if ((i + j) % 2 == 1) //짝수면
                {
                    temp *= (-1); //음수 붙여주기
                }
                res.setElement(i, j, temp); //해당값을 res에 setElement 해주기
            }
        }

        transpose(r, res); //res를 transpose 해주기

        return r; //r 반환
    }

    Matrix& inverse(Matrix& r, Matrix& m) //inverse matrix를 구하는 함수
    {

        float det = m.determinant(); //m의 행렬값을 받기 위한 det 선언

        Matrix adjres(m.getRows(), m.getCols()); //adjres 행렬 선언
        adjoint(adjres, m); //m의 adjoint 행렬을 adjres에 저장

        elementDiv(r, adjres, det); //Inverse Matrix = adjMatrix / det(Matrix)

        return r; //r 반환
    }
};