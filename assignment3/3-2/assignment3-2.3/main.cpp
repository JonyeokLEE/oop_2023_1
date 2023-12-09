#include "header.h"

int main() {
    MyMusicManagementList musicList; //객체 생성
    char line[100]; //파일을 읽기 위한 변수
    ifstream file("Music_Info.txt"); //파일 스트림 생성 및 파일 열기
    if (!file) //파일 없을 때 예외처리
    {
        cout << "The file does not exist." << endl;
        return 0;
    }
    
    file.getline(line, 100); //첫줄은 읽어버리기 (artist와 song이기 떄문)
    while (!file.eof()) //한줄 씩 읽어들이기
    {
        file.getline(line, 100);
        char* artist = strtok(line, "/");
        char* song = strtok(NULL, "/"); // '/'를 기준으로 artist와 song 배열에 각각 저장
        for (int i = 0; song[i] != NULL; i++) {
            song[i] = tolower(song[i]);
        } //tolower 함수를 이용해 모두 소문자로 변환
        musicList.insertArtist(artist); //artist 삽입
        ArtistNode* Node = musicList.findArtist(artist); //아티스트 위치 찾기
        Node->insertSong(song); //해당 위치에 삽입
    }
    /*
    cout << "(컴퓨터 디스플레이가 문제가 있어서 실행 즉시 많은 양의 텍스트를 출력하면 글씨가 꺠져서 나오기 때문에 넣은 부분입니다.)" << endl;
    cout << "Input any number: ";
    int a = 0; cin >> a; */

    musicList.printList(); //결과 출력
    return 0; //0의 반환
}