#include "mymusic.h"

int main(void) //main 함수
{
    myMusic* obj[5]; //객체 포인터 obj 선언, 임의로 5개까지로 제한을 했습니다.
    int index = 0; //인덱스를 나타내는 변수
    char command[32]; //명령어 입력하는 변수
    char seperate[100]; //쉼표를 기준으로 분리할 변수
    char title[32];
    char singer[32];
    char album[32];
    int trackno = 0;
    int year = 0; //각각의 정보들을 입력하기 위한 변수

    while (1)
    {
        cout << "[COMMAND]" << endl << "insert / print / exit" << endl;
        cin >> command; //명령어 입력
        cin.ignore(); //개행문자 제거
        if (!strcmp(command, "insert")) //insert 입력시
        {
            if (index == 5) //5개의 정보가 들어갔으면
                cout << "You cannot insert anymore" << endl; //안내문 출력
            else //그 외의 경우
            {
                cout << "Input 'title,singer,album,trackno,year'" << endl;
                cin >> seperate; //입력받기
                char* ptr = strtok(seperate, ",");
                strcpy(title, ptr);
                ptr = strtok(NULL, ",");
                strcpy(singer, ptr);
                ptr = strtok(NULL, ",");
                strcpy(album, ptr);
                ptr = strtok(NULL, ",");
                trackno = atoi(ptr);
                ptr = strtok(NULL, ",");
                year = atoi(ptr); //strtok를 사용해서 문자열 분리하고 strcpy와 atoi를 이용해 각 변수로 저장
                obj[index] = new myMusic(title, singer, album, trackno, year); //myMusic 생성자로 전달
                index++; //인덱스 증가
            }
        }
        else if (!strcmp(command, "print")) //print 입력 시
        {
            if (index == 0)
                cout << "No Information exists." << endl;
            cout << "=====print=====" << endl;
            for (int i = 0; i < index; i++)
            {
                cout << "Title: " << obj[i]->getTitle() << endl;
                cout << "Singer: " << obj[i]->getSinger() << endl;
                cout << "Album: " << obj[i]->getAlbum() << endl;
                cout << "Track Number: " << obj[i]->getTrackNo() << endl;
                cout << "Year: " << obj[i]->getYear() << endl;
                cout << "----------" << endl;
            } //해당 값들을 get 함수들을 이용해 출력
        }
        else if (!strcmp(command, "exit")) //exit 입력 시
        {
            break; //종료
        }
        else //이상한 커맨드 입력 시
        {
            cout << "Wrong Command. Try again." << endl; //안내문 출력
        }
    }

    return 0; //0의 반환
}