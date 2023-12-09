#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class myMusic
{
private:
    char m_title[32]; //���� ����
    char m_singer[32]; //���� ����
    char m_album[32]; //�ٹ� ����
    int m_track_no; //Ʈ����ȣ ����
    int m_year; //���࿬�� ����

public:
    myMusic(); //�⺻ ������
    myMusic(char* title, char* singer, char* album, int year, int track_no); //�������ڰ� �ִ� ������
    ~myMusic(); //�Ҹ���

    void setTitle(char* title);
    void setSinger(char* singer);
    void setAlbum(char* album);
    void setYear(int year);
    void setTrackNo(int track_no); //���� ����, ����, �ٹ�, Ʈ����ȣ, ���࿬�� �����ϴ� �Լ�

    char* getTitle();
    char* getSinger();
    char* getAlbum();
    int getYear();
    int getTrackNo(); //���� private �������� return�ϴ� �Լ�
};
