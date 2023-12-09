#include "header.h"

int main() {
    MyMusicManagementList musicList; //��ü ����
    char line[100]; //������ �б� ���� ����
    ifstream file("Music_Info.txt"); //���� ��Ʈ�� ���� �� ���� ����
    if (!file) //���� ���� �� ����ó��
    {
        cout << "The file does not exist." << endl;
        return 0;
    }
    
    file.getline(line, 100); //ù���� �о������ (artist�� song�̱� ����)
    while (!file.eof()) //���� �� �о���̱�
    {
        file.getline(line, 100);
        char* artist = strtok(line, "/");
        char* song = strtok(NULL, "/"); // '/'�� �������� artist�� song �迭�� ���� ����
        for (int i = 0; song[i] != NULL; i++) {
            song[i] = tolower(song[i]);
        } //tolower �Լ��� �̿��� ��� �ҹ��ڷ� ��ȯ
        musicList.insertArtist(artist); //artist ����
        ArtistNode* Node = musicList.findArtist(artist); //��Ƽ��Ʈ ��ġ ã��
        Node->insertSong(song); //�ش� ��ġ�� ����
    }
    /*
    cout << "(��ǻ�� ���÷��̰� ������ �־ ���� ��� ���� ���� �ؽ�Ʈ�� ����ϸ� �۾��� ������ ������ ������ ���� �κ��Դϴ�.)" << endl;
    cout << "Input any number: ";
    int a = 0; cin >> a; */

    musicList.printList(); //��� ���
    return 0; //0�� ��ȯ
}