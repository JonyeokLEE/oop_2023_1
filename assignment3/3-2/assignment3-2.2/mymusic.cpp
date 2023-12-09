
#include "mymusic.h"


myMusic::myMusic() //�⺻ ������
{
	m_title[32] = NULL;
	m_singer[32] = NULL;
	m_album[32] = NULL;
	m_track_no = 0;
	m_year = 0; //���� �ʱ�ȭ
}

myMusic::myMusic(char* title, char* singer, char* album, int track_no, int year) //�������ڰ� �ִ� ������
{
	setTitle(title);
	setSinger(singer);
	setAlbum(album);
	setYear(year);
	setTrackNo(track_no); //���� set�Լ���� �������ش�.
}

myMusic::~myMusic() //�Ҹ���
{
}

void myMusic::setTitle(char* title) //setTitle �Լ�
{
	strcpy(m_title, title); //������ ����
}

void myMusic::setSinger(char* singer) //setSinger �Լ�
{
	strcpy(m_singer, singer); //������ ����
}

void myMusic::setAlbum(char* album) //setAlbum �Լ�
{
	strcpy(m_album, album); //�ٹ��� ����
}

void myMusic::setYear(int year) //setYear �Լ�
{
	m_year = year; //���࿬�� ����
}

void myMusic::setTrackNo(int track_no) //setTrackNo �Լ�
{
	m_track_no = track_no; //Ʈ����ȣ ����
}

char* myMusic::getTitle() //getTitle �Լ�
{
	return m_title; //���� ��ȯ
}

char* myMusic::getSinger() //getSinger �Լ�
{
	return m_singer; //���� ��ȯ
}

char* myMusic::getAlbum() //getAlbum �Լ�
{
	return m_album; //���� ��ȯ
}

int myMusic::getYear() //getYear �Լ�
{
	return m_year; //���� ��ȯ
}

int myMusic::getTrackNo() //getTrackNo �Լ�
{
	return m_track_no; //���� ��ȯ
}


