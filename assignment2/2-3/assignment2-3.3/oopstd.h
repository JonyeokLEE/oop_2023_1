#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h> //string.h ������� ����

namespace oopstd //oopstd namespace
{
	class string //string class
	{
	public: //public ����
		string();
		string(const char* s);
		string(const string& str);
		~string(); //�⺻������, �������ڰ� �ִ� ������, copy������, �Ҹ��� ����

		string& assign(const string& str); //���ڿ��� value�� �ٲٴ� �Լ�
		char& at(size_t pos); //���ڿ��� �ش� ��ġ�� ���ڸ� �������� �Լ�
		char& at2(size_t pos) const; //���� ����� �Ѵ�. const ����
		const char* c_str() const; //���ڿ� ��ü�� ��ȯ�޴� �Լ�
		void clear(); //��� ���ڿ��� ����� �Լ�
		void push_back(char c); //���ڿ� �� �ڿ� value�� �߰��ϴ� �Լ�
		int compare(const string* str) const; //���ڿ��� ���ϴ� �Լ�
		string& replace(size_t pos, size_t len, const string* str); //���ڿ��� �����ϴ� �Լ�
		string substr(size_t pos, size_t len) const; //���ڿ��� Ư�� ������ ���� ã�� �Լ�
		size_t find(const string& str, size_t pos) const; //���ϴ� ���ڿ��� �������� ã�� �Լ�
		size_t getlen() const;
		char* getS() const; //private ������ ��ȯ�ޱ� ���� �����߽��ϴ�.

	private: //private ����
		char* s; //���ڿ� s
		size_t len; //���̸� ��Ÿ���� len
		size_t npos = -1; //find �Լ��� ��ȯ�� �� �ϳ��� npos
	};

	int stoi(const string& str, size_t* idx, int base);
	float stof(const string& str, size_t* idx); //���ڿ����� ������ �Ǽ��� ã�Ƽ� ��ȯ�ϴ� �Լ�

	string to_string(int val);
	string to_string(float val); //������ �Ǽ��� ���ڿ��� �ٲٴ� �Լ�

}