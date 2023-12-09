#include "mymusic.h"

int main(void) //main �Լ�
{
    myMusic* obj[5]; //��ü ������ obj ����, ���Ƿ� 5�������� ������ �߽��ϴ�.
    int index = 0; //�ε����� ��Ÿ���� ����
    char command[32]; //��ɾ� �Է��ϴ� ����
    char seperate[100]; //��ǥ�� �������� �и��� ����
    char title[32];
    char singer[32];
    char album[32];
    int trackno = 0;
    int year = 0; //������ �������� �Է��ϱ� ���� ����

    while (1)
    {
        cout << "[COMMAND]" << endl << "insert / print / exit" << endl;
        cin >> command; //��ɾ� �Է�
        cin.ignore(); //���๮�� ����
        if (!strcmp(command, "insert")) //insert �Է½�
        {
            if (index == 5) //5���� ������ ������
                cout << "You cannot insert anymore" << endl; //�ȳ��� ���
            else //�� ���� ���
            {
                cout << "Input 'title,singer,album,trackno,year'" << endl;
                cin >> seperate; //�Է¹ޱ�
                char* ptr = strtok(seperate, ",");
                strcpy(title, ptr);
                ptr = strtok(NULL, ",");
                strcpy(singer, ptr);
                ptr = strtok(NULL, ",");
                strcpy(album, ptr);
                ptr = strtok(NULL, ",");
                trackno = atoi(ptr);
                ptr = strtok(NULL, ",");
                year = atoi(ptr); //strtok�� ����ؼ� ���ڿ� �и��ϰ� strcpy�� atoi�� �̿��� �� ������ ����
                obj[index] = new myMusic(title, singer, album, trackno, year); //myMusic �����ڷ� ����
                index++; //�ε��� ����
            }
        }
        else if (!strcmp(command, "print")) //print �Է� ��
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
            } //�ش� ������ get �Լ����� �̿��� ���
        }
        else if (!strcmp(command, "exit")) //exit �Է� ��
        {
            break; //����
        }
        else //�̻��� Ŀ�ǵ� �Է� ��
        {
            cout << "Wrong Command. Try again." << endl; //�ȳ��� ���
        }
    }

    return 0; //0�� ��ȯ
}