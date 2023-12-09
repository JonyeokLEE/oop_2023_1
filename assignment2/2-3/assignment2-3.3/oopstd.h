#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h> //string.h 헤더파일 선언

namespace oopstd //oopstd namespace
{
	class string //string class
	{
	public: //public 구역
		string();
		string(const char* s);
		string(const string& str);
		~string(); //기본생성자, 전달인자가 있는 생성자, copy생성자, 소멸자 선언

		string& assign(const string& str); //문자열의 value를 바꾸는 함수
		char& at(size_t pos); //문자열의 해당 위치의 글자를 가져오는 함수
		char& at2(size_t pos) const; //같은 기능을 한다. const 전용
		const char* c_str() const; //문자열 전체를 반환받는 함수
		void clear(); //모든 문자열을 지우는 함수
		void push_back(char c); //문자열 맨 뒤에 value를 추가하는 함수
		int compare(const string* str) const; //문자열을 비교하는 함수
		string& replace(size_t pos, size_t len, const string* str); //문자열을 수정하는 함수
		string substr(size_t pos, size_t len) const; //문자열의 특정 범위의 값을 찾는 함수
		size_t find(const string& str, size_t pos) const; //원하는 문자열의 시작점을 찾는 함수
		size_t getlen() const;
		char* getS() const; //private 변수를 반환받기 위해 선언했습니다.

	private: //private 구역
		char* s; //문자열 s
		size_t len; //길이를 나타내는 len
		size_t npos = -1; //find 함수의 반환값 중 하나인 npos
	};

	int stoi(const string& str, size_t* idx, int base);
	float stof(const string& str, size_t* idx); //문자열에서 정수와 실수를 찾아서 변환하는 함수

	string to_string(int val);
	string to_string(float val); //정수나 실수를 문자열로 바꾸는 함수

}