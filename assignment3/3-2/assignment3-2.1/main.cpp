#include "header.h"

int main()
{
	LinkedList obj; //객체 obj 선언
	int nodupli[16]; //중복없는 16자리 랜덤 수를 저장할 배열
	bool isdupli = false; //중복된건지 확인할 변수
	int index = 0; //인덱스를 가리키는 변수
	int randnum = 0; //랜덤 수
	srand((unsigned int)time(NULL)); //srand 설정
	for (int i = 0; index != 16; i++) //index가 16이 되기 전까지 반복
	{
		isdupli = false; //isdupli 초기화
		randnum = rand() % 201; //0부터 200의 랜덤 수 생성
		for (int j = 0; j < index; j++) //지금까지 저장된 index까지 반복
		{
			if (nodupli[j] == randnum) //만약 중복확인되면
			{
				isdupli = true; //중복 표시
				break; //반복문 탈출
			}
		}
		if (!isdupli) //중복 표시가 없는 경우
		{
			nodupli[index] = randnum; //해당 값 저장
			index++; //index 증가
		}
	}
	//여기까지 nodupli 저장 완료(중복 없이 0부터 200 사이 랜덤 수)

	for (int i = 0; i < 16; i++) //16번 반복
	{
		Node* insertit = new Node();
		insertit->setdata(nodupli[i]);
		obj.insertNew(insertit); //하나씩 노드에 세팅한 후 obj에 연결시키기
	}

	cout << "<Random List>" << endl;
	obj.printlist(); //지금까지의 연결된 노드들을 출력
	obj.insertsort(); //insertsort하기
	cout << "<After Insertion Sort>" << endl;
	obj.printlist(); //결과 출력

	int forsearch = 0; //찾고싶은 수 선언
	cout << endl << "Input the number to search: ";
	cin >> forsearch; //입력받기

	Node* result = obj.Binary_Search(obj.getHead(), forsearch); //Binary Search의 결과값을 result 노드로 받기
	if (result->getdata() == forsearch) //만약 찾고 있는 수와 같다면
		cout << "Found: " << result->getdata(); //성공 출력
	else //못 찾았다면
		cout << "Not Found, Closest Value's Node: " << result->getdata(); //근삿값 노드 출력


	return 0;
	
}