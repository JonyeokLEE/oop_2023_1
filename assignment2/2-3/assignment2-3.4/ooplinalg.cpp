#include "ooplinalg.h" //ooplinalg ������� ����

namespace ooplinalg //ooplinalg namespace ��� ����
{
    Matrix::Matrix() //�⺻ ������
    {
        rows = 0;
        cols = 0;
        data = nullptr; //��� private ������ �ʱ�ȭ�Ѵ�.
    }

    Matrix::~Matrix() //�Ҹ���
    {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data; //�����Ҵ��ߴ� data�� delete���ش�.
    }

    Matrix::Matrix(int rows, int cols) //�������ڰ� �ִ� ������
    {
        this->rows = rows;
        this->cols = cols; //���޹��� ������ ���� rows�� cols�� �־��ش�.
        data = new float* [rows];
        for (int i = 0; i < rows; i++)
            data[i] = new float[cols]; //���޹��� rows�� cols ��ŭ data�� �����Ҵ��Ѵ�.
    }
    Matrix::Matrix(const Matrix& mat) //copy ������
    {
        rows = mat.rows;
        cols = mat.cols; //���޹��� mat�� rows�� cols�� �״�� �����Ѵ�.
        data = new float* [rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new float[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = mat.data[i][j];
        } //data�� rows�� cols ��ŭ �����Ҵ� �ϴ� ���ÿ� mat�� data�� �������ش�.
    }
    float Matrix::getElement(int row, int col) const //����� ���Ҹ� ��ȯ�ϴ� �Լ�
    {
        return data[row][col]; //�ش� ��ġ�� ���Ҹ� ��ȯ���ش�.
    }
    void Matrix::setData(const int rows, const int cols, float** data) //����� ���Ҹ� �����ϴ� �Լ�
    {
        this->rows = rows;
        this->cols = cols; //���޹��� ���� rows�� cols�� �־��ش�.
        this->data = new float* [rows];
        for (int i = 0; i < rows; i++)
        {
            this->data[i] = new float[cols];
            for (int j = 0; j < cols; j++)
                this->data[i][j] = data[i][j];
        } //data�� rows�� cols��ŭ �����Ҵ��� �ϴ� ���ÿ� ���޹��� data�� ���� �����Ѵ�.
    }
    void Matrix::setElement(const int row, const int col, float value) //����� ���Ҹ� �����ϴ� �Լ�
    {
        data[row][col] = value; //�ش� ��ġ�� value���� �־��ش�.
    }
    int Matrix::getRows() const //rows�� ��ȯ�ϴ� �Լ�
    {
        return rows; //rows�� ��ȯ�Ѵ�.
    }

    int Matrix::getCols() const //cols�� ��ȯ�ϴ� �Լ�
    {
        return cols; //cols�� ��ȯ�Ѵ�.
    }
    float** Matrix::getData()const //data�� ��ȯ�ϴ� �Լ�
    {
        return data; //data�� ��ȯ�Ѵ�.
    }
    void Matrix::setRows(const int rows) //rows�� ���� �����ϴ� �Լ�
    {
        this->rows = rows; //���޹��� ���� rows�� �־��ش�.
    }

    void Matrix::setCols(const int cols) //cols�� ���� �����ϴ� �Լ�
    {
        this->cols = cols; //���޹��� ���� cols�� �־��ش�.
    }

    float Matrix::determinant() //��İ��� ����ϴ� �Լ�
    {
        if (rows != cols) //������ĸ� ��� ����(��� ���� ũ�Ⱑ ���� ���)
            return -1; //-1�� ��ȯ

        if (rows == 1) //��� �� ũ�Ⱑ 1�̸�
            return data[0][0]; //�� ���� ��ȯ

        float res = 0; //������� ���� ���� ����
        for (int i = 0; i < cols; i++) //0���� cols���� �ݺ�
        {
            float** small = new float* [rows - 1];
            for (int j = 0; j < rows - 1; j++)
            {
                small[j] = new float[cols - 1]; //�۰� ���ҵ� �κ���� ����(��� ���� 1�� �۴�)
            }
            for (int j = 1; j < rows; j++) //j�� ���� ����� �� �ε���
            {
                for (int z = 0; z < cols; z++) //z�� ���� ����� �� �ε���
                {
                    //�κ������ ���� �����ϴ� �κ�
                    if (z < i) //z�� i���� ������
                        small[j - 1][z] = data[j][z]; //�ش� �ε����� �� ����
                    else if (z > i) //z�� i���� ũ��
                        small[j - 1][z - 1] = data[j][z]; //�ش� �ε����� �� ����
                }
                    
            }
            Matrix smallone(rows - 1, cols - 1); //�κ���� ����
            smallone.setData(rows - 1, cols - 1, small); //small ���� �κ���Ŀ� ����
            if (i % 2 == 0) //Ȧ�� ���̸�
                res += data[0][i] * smallone.determinant(); //���ϱ�
            else //¦�� ���̸�
                res -= data[0][i] * smallone.determinant(); //����

            for (int j = 0; j < rows - 1; j++)
                delete[] small[j];
            delete[] small; //�κ���� �����Ҵ� ����
        }
        return res; //����� ��ȯ
    }

    Matrix& add(Matrix& r, Matrix& a, Matrix& b) //��� �� ������ �ϴ� �Լ�
    {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
            return r; //����� ��� ���� ���� �ٸ��� r�� ��ȯ�Ѵ�.

        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) + b.getElement(i, j)); //a�� b ����� ���� ���� r�� �ִ´�.

        return r; //r ��ȯ
    }

    Matrix& sub(Matrix& r, Matrix& a, Matrix& b) //��� �� ������ �ϴ� �Լ�
    {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
            return r; //����� ��� ���� ���� �ٸ��� r�� ��ȯ�Ѵ�.
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) - b.getElement(i, j)); //a�� b ����� ���� ���� r�� �ִ´�.

        return r; //r ��ȯ
    }

    Matrix& mul(Matrix& r, Matrix& a, Matrix& b) //��� �� ������ �ϴ� �Լ�
    {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
            return r; //����� ��� ���� ���� �ٸ��� r�� ��ȯ�Ѵ�.
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) * b.getElement(i, j)); //a�� b ����� ���� ���� r�� �ִ´�.

        return r; //r ��ȯ
    }

    Matrix& elementAdd(Matrix& r, Matrix& a, float v) //��İ� ���� ������ �ϴ� �Լ�
    {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) + v); //a ��İ� v�� ���� ���� r��Ŀ� setElement ���ش�.

        return r; //r ��ȯ
    }

    Matrix& elementSub(Matrix& r, Matrix& a, float v) //��İ� ���� ������ �ϴ� �Լ�
    {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) - v); //a ��İ� v�� �� ���� r��Ŀ� setElement ���ش�.

        return r; //r ��ȯ
    }

    Matrix& elementMul(Matrix& r, Matrix& a, float v) //��İ� ���� ������ �ϴ� �Լ�
    {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) * v); //a ��İ� v�� ���� ���� r��Ŀ� setElement ���ش�.

        return r; //r ��ȯ
    }

    Matrix& elementDiv(Matrix& r, Matrix& a, float v) //��İ� ���� �������� �ϴ� �Լ�
    {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) / v); //a ��İ� v�� ���� ���� r��Ŀ� setElement ���ش�.

        return r; //r ��ȯ
    }
    Matrix& transpose(Matrix& r, Matrix& m) //Transpose ����� ���ϴ� �Լ�
    {
        r.setCols(m.getRows());
        r.setRows(m.getCols());

        for (int i = 0; i < m.getRows(); i++)
        {
            for (int j = 0; j < m.getCols(); j++)
            {
                float temp = m.getElement(i, j); //temp�� m�� �ش� �ε��� ���� �޾Ƽ�
                r.setElement(j, i, temp); //transpose�� ��ġ�� r�� ���� �־��ش�.
            }
        }

        return r; //r ��ȯ
    }

    Matrix& adjoint(Matrix& r, Matrix& m) //Adjoint ����� ���ϴ� �Լ�
    {
        Matrix seperate(m.getRows(), m.getCols()); //seperate ��� ����
        for (int i = 0; i < m.getRows(); i++) //0���� m�� row��ŭ �ݺ�
        {
            for (int j = 0; j < m.getCols(); j++) //0���� m�� col��ŭ �ݺ�
            {
                Matrix smallone(m.getRows() - 1, m.getCols() - 1); //ũ�Ⱑ 1�� ���� smallone ���
                for (int z = 0; z < m.getRows() - 1; z++) //0���� row-1 ��ŭ �ݺ�
                {
                    for (int k = 0; k < m.getCols() - 1; k++) //0���� col-1 ��ŭ �ݺ�
                    {
                        int row2;
                        if (z < i) { //z�� i���� ������
                            row2 = z; //row2�� z���� ���´�.
                        }
                        else { //�� ���� ���
                            row2 = z + 1; //row2�� z+1�� ���� ���´�.
                        }

                        int col2;
                        if (k < j) { //k�� j���� ������
                            col2 = k; //col2�� k���� ���´�.
                        }
                        else { //�� ���� ���
                            col2 = k + 1; //col2�� k+1�� ���� ���´�.
                        }
                        smallone.setElement(z, k, m.getElement(row2, col2)); //smallone�� z��, k��, �׸��� row2�� col2 ��ġ�� m ����� ���� ���� setElement�� �Ѵ�.
                    }
                }
                seperate.setElement(i, j, smallone.determinant()); //seperate�� i�� j��, smallone�� ��İ��� setElement ���ش�.
            }
        }
        Matrix res(m.getRows(), m.getCols()); //������� ���� res ��� ����
        for (int i = 0; i < m.getRows(); i++)
        {
            for (int j = 0; j < m.getCols(); j++)
            {
                float temp = seperate.getElement(i, j); //temp�� seperate�� ���� �޾��ش�.
                if ((i + j) % 2 == 1) //¦����
                {
                    temp *= (-1); //���� �ٿ��ֱ�
                }
                res.setElement(i, j, temp); //�ش簪�� res�� setElement ���ֱ�
            }
        }

        transpose(r, res); //res�� transpose ���ֱ�

        return r; //r ��ȯ
    }

    Matrix& inverse(Matrix& r, Matrix& m) //inverse matrix�� ���ϴ� �Լ�
    {

        float det = m.determinant(); //m�� ��İ��� �ޱ� ���� det ����

        Matrix adjres(m.getRows(), m.getCols()); //adjres ��� ����
        adjoint(adjres, m); //m�� adjoint ����� adjres�� ����

        elementDiv(r, adjres, det); //Inverse Matrix = adjMatrix / det(Matrix)

        return r; //r ��ȯ
    }
};