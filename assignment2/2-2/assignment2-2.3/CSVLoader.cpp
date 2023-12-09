#include"CSVLoader.h"

CSVLoader::CSVLoader() //CSVLoader Ŭ���� ������
{
	data = nullptr; //data �ʱ�ȭ
	cols = 0;
	rows = 0; //rows�� cols�� �ʱ�ȭ
}

CSVLoader::CSVLoader(const char* path) //CSVLoader Ŭ���� ������(const char�� ������ path�� ���޹޴´�.)
{
    data = nullptr; //data �ʱ�ȭ
    cols = 0;
    rows = 0; //rows�� cols�� �ʱ�ȭ
	parse(path); //parse �Լ��� path�� �Ѱ��ش�.
}

CSVLoader::~CSVLoader() //CSVLoader Ŭ���� �Ҹ���
{
	for (int i = 0; i < rows; i++)
		delete[] data[i];
	delete[] data; //�����Ҵ��� �ߴ� data�� �޸� ����
}

float** CSVLoader::getData() const //data�� ��ȯ�ϴ� �Լ�
{
	return data; //data ��ȯ
}

int CSVLoader::getRows() const //rows�� ��ȯ�ϴ� �Լ�
{
	return rows; //rows ��ȯ
}

int CSVLoader::getCols() const //cols�� ��ȯ�ϴ� �Լ�
{
	return cols; //cols ��ȯ
}

void CSVLoader::parse(const char* path) //�����м��� �ϴ� �Լ�
{
    ifstream fin; //������ �б� ���� ��ü fin ����
    fin.open(path); //path�� ���� ������ ����.

    if (!fin) //������ ������
    {
        cout << "File does not exist."; //�ȳ��� ���
    }

    char read; //������ �б� ���� ���� ����
    char read2 = 0; //���� ������ ������ ����� ���� ����
    while (fin.get(read)) //read ���ڷ� ���� �� ���ھ� �д´�.
    {
        if (read == ',' && rows == 0) //���� rows�� 0�̰� ��ǥ�� ������
            cols++; //cols�� ������Ų��.
        if (read == '\n') //���� ���ڸ� ������
            rows++; //rows�� ������Ų��.
        read2 = read; //read2�� ��� read�� ���� �־��ش�.
    } //���� ������ �� ������ while�� ����
    if (read2 != '\n') //�� �о��µ� �������� ���� ���ڰ� �ƴϸ�
    {
        rows++; //�׷� ���� rows�� �ϳ� �� ����
    }
    cols++; //��ǥ�� �������� ���� ������ �ϳ� �� ����.

    fin.close(); //fin���� ������ ���� �ݱ�
    ifstream fin2; //�ٽ� �б� ���� fin2 ��ü ����
    fin2.open(path); //���� ������� ����
    if (!fin2) //������ ������
    {
        cout << "File does not exist."; //�ȳ��� ���
    }

    data = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new float[cols];
    } //���� ��� ���� ũ�⸸ŭ data�� �������迭 �����Ҵ��� �Ѵ�.

    char ch = 0; //������ �б� ���� ����
    char buffer[MAX_BUFFER_SIZE]; //�ؽ�Ʈ ������ ���� ���ڿ� ����
    int now = 0; //���� �ε����� ����Ű�� ���� ����
    int r = 0, c = 0; //row�� column �ε����� ���� ������ ����
    float result = 0; //������� ���� result ����
    while (fin2.get(ch)) //ch�� �ѱ��ھ� ������ �д´�.
    {
        buffer[now] = ch; //buffer ���ڿ��� ch�� �ѱ��ھ� ���� ���� �־��ش�.
        if (ch == ',') //���� ��ǥ�� ������
        {
            buffer[now] = '\0'; //�ش� �ε����� �� ���ڷ� �ְ�
            result = atof(buffer); //���ݱ����� ���ڿ��� atof�� �̿��� result�� ��ȯ
            data[r][c] = result; //data �迭�� �־��ش�.
            c++; //��ǥ�� �ش��ϴϱ� ���� ��ġ�� ���������ش�.
            now = 0; //���ڿ��� �ε����� �ٽ� 0���� �ʱ�ȭ
        }
        else if (ch == '\n') //���� ���ڸ� ������
        {
            buffer[now] = '\0'; //�ش� �ε����� �� ���ڷ� �ְ�
            result = atof(buffer); //���ݱ����� ���ڿ��� atof�� �̿��� result�� ��ȯ
            data[r][c] = result; //data �迭�� �־��ش�.
            r++; //���࿡ �ش��ϴϱ� ���� ��ġ�� ����
            c = 0; //���� ó������ �ٽ� �ʱ�ȭ
            now = 0; //���ڿ��� �ε����� �ٽ� 0���� �ʱ�ȭ
        }
        else //��ǥ�� ���� ���ڸ� ������ ������
        {
            now++; //����ؼ� �����ϱ� ���� now�� ����(�ε���)
        }
    } //���� ������ �� ������ while�� ����
    if (now != 0) //while���� ����Ǿ��µ��� now�� 0�� �ƴ϶�� ���� ������ �ؽ�Ʈ�� �����ִٴ� ��
    {
        buffer[now] = '\0'; //�ش� �ε����� �� ���ڷ� �ְ�
        result = atof(buffer); //���ݱ����� ���ڿ��� atof�� �̿��� result�� ��ȯ
        data[r][c] = result; //data �迭�� �־��ش�.
    }
    fin2.close(); //fin2�� ���� ���� �ݱ�
}



void CSVLoader::print(void) //print �Լ�
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	} //������ �迭�� ��ҵ��� ����Ѵ�.
}
