#include "header.h"

ArtistNode::ArtistNode(char* artist) //전달인자가 있는 생성자
{
    name = new char[strlen(artist) + 1];
    strcpy(name, artist); //artist 값 복사
    next = nullptr;
    songHead = nullptr; //나머지는 초기화
}

ArtistNode::~ArtistNode()
{
    delete[] name;
    delete songHead; //동적할당한 변수들 해제
}

char* ArtistNode::getName() //getName 함수
{
    return name; //name 반환
}

void ArtistNode::setNext(ArtistNode* artistnext) //setNext 함수
{
    next = artistnext; //next에 artistnext 값 저장
}

ArtistNode* ArtistNode::getNext() //getNext 함수
{
    return next; //next 반환
}

void ArtistNode::insertSong(char* songName) //insertsong 함수
{
    SongNode* newone = new SongNode(songName);
    if (songHead==nullptr || strcmp(songName, songHead->getName()) < 0)
    {   //리스트에 아무것도 없거나, songName이 songHead의 요소보다 value가 작으면
        newone->setNext(songHead); //newone의 다음을 songHead로
        songHead = newone; //songHead를 newone으로 최신화
    }
    else //그 외의 경우
    {
        SongNode* temp = songHead; //temp를 head로 초기화
        while (temp->getNext()!=nullptr && strcmp(songName, temp->getNext()->getName()) >= 0)
        { //temp의 다음 노드가 있고, songName이 temp의 다음 노드보다 value가 크거나 같으면
            temp = temp->getNext(); //temp를 다음으로 이동
        }
        newone->setNext(temp->getNext()); //newone의 다음 노드를 temp의 다음 노드로 설정
        temp->setNext(newone); //temp의 다음 노드를 newone으로 설정
    }
}

void ArtistNode::printSongs() //printSongs 함수
{
    for (SongNode* curr = songHead; curr != nullptr; curr = curr->getNext()) //head부터 끝까지 하나씩 출력
    {
        cout << "Song:" << curr->getName() << endl;
    }
}

SongNode::SongNode(char* songName) //전달인자가 있는 생성자
{
    name = new char[strlen(songName) + 1];
    strcpy(name, songName); //songName 복사
    next = nullptr; //초기화
}

SongNode::~SongNode() //소멸자
{
    delete[] name;
    delete next; //동적할당했던 변수들 해제
}

char* SongNode::getName() //getName 함수
{
    return name; //name 반환
}

void SongNode::setNext(SongNode* songnext) //setNext 함수
{
    next = songnext; //next에 songnext 저장
}

SongNode* SongNode::getNext() //getNext 함수
{
    return next; //next 반환
}

MyMusicManagementList::MyMusicManagementList() //생성자
{
    head = nullptr;
    tail = nullptr; //초기화
}

MyMusicManagementList::~MyMusicManagementList() //소멸자
{
    delete head; //head 삭제
}

ArtistNode* MyMusicManagementList::getHead() //getHead 함수
{
    return head; //head 반환
}

void MyMusicManagementList::insertArtist(char* name) //insertArtist 함수
{
    if (findArtist(name) != nullptr) //기존에 존재하는 아티스트인지 확인
    {
        return; //기존에 존재하는 아티스트면 return
    }
    ArtistNode* newone = new ArtistNode(name); //name을 저장한 노드 생성
    if (head == nullptr) //아무것도 없으면
    {
        head = newone;
        tail = newone;
        newone->setNext(newone); //head와 tail이 newone을 가리키고, newone의 다음노드 또한 newone으로 설정
    }
    else //뭐가 있는 경우
    {
        tail->setNext(newone); //tail의 다음 노드를 newone으로
        newone->setNext(head); //newone의 다음을 head로
        tail = newone; //tail은 newone을 가리키도록
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

ArtistNode* MyMusicManagementList::findArtist(char* name) //findArtist 함수
{
    ArtistNode* curr = head; //curr이 head부터 시작
    while (curr != nullptr) //끝까지 반복
    {
        if (!strcmp(curr->getName(), name)) //둘의 이름이 같으면
        {
            return curr; //curr 반환
        }
        curr = curr->getNext(); //curr은 계속해서 다음 노드로
        if (curr == head) break; // 다시 head로 돌아온 경우 반복문 종료
    }
    return nullptr; //nullptr 반환
}