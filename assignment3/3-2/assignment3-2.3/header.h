#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class SongNode
{
private:
    SongNode* next; //다음 노드를 위한 변수
    char* name; //노래 이름 변수

public:
    SongNode(char* songName); //전달인자가 있는 생성자
    ~SongNode(); //소멸자
    char* getName(); //name을 반환하는 함수
    void setNext(SongNode* songnext); //다음 노드를 설정하는 함수
    SongNode* getNext(); //next를 반환하는 함수
};

class ArtistNode
{
private:
    ArtistNode* next; //다음 노드를 위한 변수
    SongNode* songHead; //song 리스트의 헤드를 가리키는 노드
    char* name; //가수 이름 변수

public:
    ArtistNode(char* artist); //전달인자가 있는 생성자
    ~ArtistNode(); //소멸자
    char* getName(); //name을 반환하는 함수
    void setNext(ArtistNode* artistnext); //다음 노드를 설정하는 함수
    ArtistNode* getNext(); //next를 반환하는 함수
    void insertSong(char* songName); //노래 노드를 삽입하는 함수
    void printSongs(); //노래를 출력하는 함수
};


class MyMusicManagementList
{
private:
    ArtistNode* head; //head 노드
    ArtistNode* tail; //tail 노드

public:
    MyMusicManagementList(); //생성자
    ~MyMusicManagementList(); //소멸자
    ArtistNode* getHead(); //head를 반환하는 함수
    void insertArtist(char* name); //가수 노드를 삽입하는 함수
    void printList(); //리스트를 출력하는 함수
    ArtistNode* findArtist(char* name); //가수를 찾는 함수
};
