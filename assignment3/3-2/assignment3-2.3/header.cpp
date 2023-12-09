#include "header.h"

ArtistNode::ArtistNode(char* artist) //�������ڰ� �ִ� ������
{
    name = new char[strlen(artist) + 1];
    strcpy(name, artist); //artist �� ����
    next = nullptr;
    songHead = nullptr; //�������� �ʱ�ȭ
}

ArtistNode::~ArtistNode()
{
    delete[] name;
    delete songHead; //�����Ҵ��� ������ ����
}

char* ArtistNode::getName() //getName �Լ�
{
    return name; //name ��ȯ
}

void ArtistNode::setNext(ArtistNode* artistnext) //setNext �Լ�
{
    next = artistnext; //next�� artistnext �� ����
}

ArtistNode* ArtistNode::getNext() //getNext �Լ�
{
    return next; //next ��ȯ
}

void ArtistNode::insertSong(char* songName) //insertsong �Լ�
{
    SongNode* newone = new SongNode(songName);
    if (songHead==nullptr || strcmp(songName, songHead->getName()) < 0)
    {   //����Ʈ�� �ƹ��͵� ���ų�, songName�� songHead�� ��Һ��� value�� ������
        newone->setNext(songHead); //newone�� ������ songHead��
        songHead = newone; //songHead�� newone���� �ֽ�ȭ
    }
    else //�� ���� ���
    {
        SongNode* temp = songHead; //temp�� head�� �ʱ�ȭ
        while (temp->getNext()!=nullptr && strcmp(songName, temp->getNext()->getName()) >= 0)
        { //temp�� ���� ��尡 �ְ�, songName�� temp�� ���� ��庸�� value�� ũ�ų� ������
            temp = temp->getNext(); //temp�� �������� �̵�
        }
        newone->setNext(temp->getNext()); //newone�� ���� ��带 temp�� ���� ���� ����
        temp->setNext(newone); //temp�� ���� ��带 newone���� ����
    }
}

void ArtistNode::printSongs() //printSongs �Լ�
{
    for (SongNode* curr = songHead; curr != nullptr; curr = curr->getNext()) //head���� ������ �ϳ��� ���
    {
        cout << "Song:" << curr->getName() << endl;
    }
}

SongNode::SongNode(char* songName) //�������ڰ� �ִ� ������
{
    name = new char[strlen(songName) + 1];
    strcpy(name, songName); //songName ����
    next = nullptr; //�ʱ�ȭ
}

SongNode::~SongNode() //�Ҹ���
{
    delete[] name;
    delete next; //�����Ҵ��ߴ� ������ ����
}

char* SongNode::getName() //getName �Լ�
{
    return name; //name ��ȯ
}

void SongNode::setNext(SongNode* songnext) //setNext �Լ�
{
    next = songnext; //next�� songnext ����
}

SongNode* SongNode::getNext() //getNext �Լ�
{
    return next; //next ��ȯ
}

MyMusicManagementList::MyMusicManagementList() //������
{
    head = nullptr;
    tail = nullptr; //�ʱ�ȭ
}

MyMusicManagementList::~MyMusicManagementList() //�Ҹ���
{
    delete head; //head ����
}

ArtistNode* MyMusicManagementList::getHead() //getHead �Լ�
{
    return head; //head ��ȯ
}

void MyMusicManagementList::insertArtist(char* name) //insertArtist �Լ�
{
    if (findArtist(name) != nullptr) //������ �����ϴ� ��Ƽ��Ʈ���� Ȯ��
    {
        return; //������ �����ϴ� ��Ƽ��Ʈ�� return
    }
    ArtistNode* newone = new ArtistNode(name); //name�� ������ ��� ����
    if (head == nullptr) //�ƹ��͵� ������
    {
        head = newone;
        tail = newone;
        newone->setNext(newone); //head�� tail�� newone�� ����Ű��, newone�� ������� ���� newone���� ����
    }
    else //���� �ִ� ���
    {
        tail->setNext(newone); //tail�� ���� ��带 newone����
        newone->setNext(head); //newone�� ������ head��
        tail = newone; //tail�� newone�� ����Ű����
    }
}

void MyMusicManagementList::printList()
{
    for (ArtistNode* curr = head; curr->getNext() != head; curr = curr->getNext())
    {
        cout << curr->getName() << endl;
        curr->printSongs();
        cout << endl;
    }
}

ArtistNode* MyMusicManagementList::findArtist(char* name) //findArtist �Լ�
{
    ArtistNode* curr = head; //curr�� head���� ����
    while (curr != nullptr) //������ �ݺ�
    {
        if (!strcmp(curr->getName(), name)) //���� �̸��� ������
        {
            return curr; //curr ��ȯ
        }
        curr = curr->getNext(); //curr�� ����ؼ� ���� ����
        if (curr == head) break; // �ٽ� head�� ���ƿ� ��� �ݺ��� ����
    }
    return nullptr; //nullptr ��ȯ
}