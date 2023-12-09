#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class myMusic
{
private:
    char m_title[32]; //제목 변수
    char m_singer[32]; //가수 변수
    char m_album[32]; //앨범 변수
    int m_track_no; //트랙번호 변수
    int m_year; //발행연도 변수

public:
    myMusic(); //기본 생성자
    myMusic(char* title, char* singer, char* album, int year, int track_no); //전달인자가 있는 생성자
    ~myMusic(); //소멸자

    void setTitle(char* title);
    void setSinger(char* singer);
    void setAlbum(char* album);
    void setYear(int year);
    void setTrackNo(int track_no); //각각 제목, 가수, 앨범, 트랙번호, 발행연도 설정하는 함수

    char* getTitle();
    char* getSinger();
    char* getAlbum();
    int getYear();
    int getTrackNo(); //각각 private 변수들을 return하는 함수
};
