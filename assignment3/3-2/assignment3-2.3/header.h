#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class SongNode
{
private:
    SongNode* next; //���� ��带 ���� ����
    char* name; //�뷡 �̸� ����

public:
    SongNode(char* songName); //�������ڰ� �ִ� ������
    ~SongNode(); //�Ҹ���
    char* getName(); //name�� ��ȯ�ϴ� �Լ�
    void setNext(SongNode* songnext); //���� ��带 �����ϴ� �Լ�
    SongNode* getNext(); //next�� ��ȯ�ϴ� �Լ�
};

class ArtistNode
{
private:
    ArtistNode* next; //���� ��带 ���� ����
    SongNode* songHead; //song ����Ʈ�� ��带 ����Ű�� ���
    char* name; //���� �̸� ����

public:
    ArtistNode(char* artist); //�������ڰ� �ִ� ������
    ~ArtistNode(); //�Ҹ���
    char* getName(); //name�� ��ȯ�ϴ� �Լ�
    void setNext(ArtistNode* artistnext); //���� ��带 �����ϴ� �Լ�
    ArtistNode* getNext(); //next�� ��ȯ�ϴ� �Լ�
    void insertSong(char* songName); //�뷡 ��带 �����ϴ� �Լ�
    void printSongs(); //�뷡�� ����ϴ� �Լ�
};


class MyMusicManagementList
{
private:
    ArtistNode* head; //head ���
    ArtistNode* tail; //tail ���

public:
    MyMusicManagementList(); //������
    ~MyMusicManagementList(); //�Ҹ���
    ArtistNode* getHead(); //head�� ��ȯ�ϴ� �Լ�
    void insertArtist(char* name); //���� ��带 �����ϴ� �Լ�
    void printList(); //����Ʈ�� ����ϴ� �Լ�
    ArtistNode* findArtist(char* name); //������ ã�� �Լ�
};
