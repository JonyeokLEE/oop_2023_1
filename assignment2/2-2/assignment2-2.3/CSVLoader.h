#pragma once //헤더파일을 한번만 포함하도록 만드는 선언
#include <fstream> //fstream 선언
#include <string> //string 선언
#include <iostream> //iostream 선언
using namespace std; //namespace std 선언

class CSVLoader //CSVLoader 클래스
{
public: //public 구역
	static constexpr unsigned int MAX_BUFFER_SIZE = 128; //최대 버퍼 사이즈 128 선언

public: //public 구역
	CSVLoader(); //CSVLoader 클래스 생성자
	CSVLoader(const char* path); //CSVLoader 클래스 생성자(const char형 포인터 path를 전달받는다.)
	~CSVLoader(); //CSVLoader 클래스 소멸자

	float** getData() const; //data를 반환하는 함수
	int getRows() const; //rows를 반환하는 함수
	int getCols() const; //cols를 반환하는 함수

	void parse(const char* path); //전달받은 path 파일의 텍스트 데이터를 구문분석하는 함수
	void print(void); //data 이차원 배열을 출력하는 함수

private: //private 구역
	float** data; //float형 이중 포인터 data 선언
	int cols; //cols 선언
	int rows; //rows 선언
}; //CSVLoader 클래스 선언 종료