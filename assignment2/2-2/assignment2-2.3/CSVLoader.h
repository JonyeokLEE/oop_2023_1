#pragma once //��������� �ѹ��� �����ϵ��� ����� ����
#include <fstream> //fstream ����
#include <string> //string ����
#include <iostream> //iostream ����
using namespace std; //namespace std ����

class CSVLoader //CSVLoader Ŭ����
{
public: //public ����
	static constexpr unsigned int MAX_BUFFER_SIZE = 128; //�ִ� ���� ������ 128 ����

public: //public ����
	CSVLoader(); //CSVLoader Ŭ���� ������
	CSVLoader(const char* path); //CSVLoader Ŭ���� ������(const char�� ������ path�� ���޹޴´�.)
	~CSVLoader(); //CSVLoader Ŭ���� �Ҹ���

	float** getData() const; //data�� ��ȯ�ϴ� �Լ�
	int getRows() const; //rows�� ��ȯ�ϴ� �Լ�
	int getCols() const; //cols�� ��ȯ�ϴ� �Լ�

	void parse(const char* path); //���޹��� path ������ �ؽ�Ʈ �����͸� �����м��ϴ� �Լ�
	void print(void); //data ������ �迭�� ����ϴ� �Լ�

private: //private ����
	float** data; //float�� ���� ������ data ����
	int cols; //cols ����
	int rows; //rows ����
}; //CSVLoader Ŭ���� ���� ����