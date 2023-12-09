
#include "mymusic.h"


myMusic::myMusic() //기본 생성자
{
	m_title[32] = NULL;
	m_singer[32] = NULL;
	m_album[32] = NULL;
	m_track_no = 0;
	m_year = 0; //변수 초기화
}

myMusic::myMusic(char* title, char* singer, char* album, int track_no, int year) //전달인자가 있는 생성자
{
	setTitle(title);
	setSinger(singer);
	setAlbum(album);
	setYear(year);
	setTrackNo(track_no); //각각 set함수들로 전달해준다.
}

myMusic::~myMusic() //소멸자
{
}

void myMusic::setTitle(char* title) //setTitle 함수
{
	strcpy(m_title, title); //제목을 복사
}

void myMusic::setSinger(char* singer) //setSinger 함수
{
	strcpy(m_singer, singer); //가수를 복사
}

void myMusic::setAlbum(char* album) //setAlbum 함수
{
	strcpy(m_album, album); //앨범을 복사
}

void myMusic::setYear(int year) //setYear 함수
{
	m_year = year; //발행연도 복사
}

void myMusic::setTrackNo(int track_no) //setTrackNo 함수
{
	m_track_no = track_no; //트랙번호 복사
}

char* myMusic::getTitle() //getTitle 함수
{
	return m_title; //제목 반환
}

char* myMusic::getSinger() //getSinger 함수
{
	return m_singer; //제목 반환
}

char* myMusic::getAlbum() //getAlbum 함수
{
	return m_album; //제목 반환
}

int myMusic::getYear() //getYear 함수
{
	return m_year; //제목 반환
}

int myMusic::getTrackNo() //getTrackNo 함수
{
	return m_track_no; //제목 반환
}


