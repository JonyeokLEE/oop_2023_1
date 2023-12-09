#include "SortList.h"

void asscendingstr(string& str) //문자열을 sort하는 함수(대소문자 구분 없이)
{
    int i = 0; //인덱스를 가리키는 변수
    int countspace = 0; //띄어쓰기된 수를 세는 변수
    while (str[i] != '\0') //str 끝까지
    {
        if (str[i] == ' ') //띄어쓰기를 만나면
        {
            countspace++; //countspace 증가
        }
        
        i++; //인덱스 증가
    }

    string seperate[100]; //띄어쓰기 기준으로 분리해서 넣을 string 배열 선언
    i = 0; //i 초기화
    int k = 0; //seperate 인덱스를 가리키는 함수
    for (int j = 0; j <= countspace && str[i] != '\0'; i++) //str이 끝나거나 countspace까지 반복
    {
        if (str[i] == ' ') //공백을 만나면
        {
            k++; //k 증가
        }
        else //그 외의 경우
        {
            seperate[k] += str[i]; //seperate에 str 복사
        }
    }
    str.clear(); //str 초기화
    // sort the words using strcmpi
    for (int i = 0; i < countspace; i++)
    {
        for (int j = i + 1; j <= countspace; j++)
        {
            if (_strcmpi(seperate[i].c_str(), seperate[j].c_str()) > 0)
            {
                //_strcmpi 함수를 이용해서 seperate의 요소들을 버블정렬
                //대소문자 구분없이 value를 비교한다.
                swap(seperate[i], seperate[j]);
            }
        }
    }
    for (int i = 0; i <= countspace; i++)
    {
        str += seperate[i]; //정렬된 seperate들을 str에 다시 넣어주기
        str += " ";
    }

}

int main()
{
    string input1, input2;
    cout << "Input list 1: ";
    getline(cin, input1);
    asscendingstr(input1);
    cout << "Input list 2: ";
    getline(cin, input2);
    asscendingstr(input2); //두 문자열 입력받은 후 asscendingstr로 정렬해주기
    int i = 0; //인덱스를 가리키는 변수
    int countspace = 0; //공백의 갯수를 세는 변수
    while (input1[i] != '\0') //input1 끝까지
    {
        if (input1[i] == ' ') //공백을 만나면
        {
            countspace++; //countspace 증가
        }

        i++; //i 증가
    }

    string seperate[100]; //분리된 단어들을 담을 string 변수
    i = 0; //i 초기화
    int k = 0; //seperate의 인덱스를 위한 k 선언
    for (int j = 0; j <= countspace && input1[i] != '\0'; i++)
    {
        if (input1[i] == ' ') //공백을 만나면
        {
            k++; //k 증가
        }
        else //그 외의 경우
        {
            seperate[k] += input1[i]; //seperate에 input1 복사
        }
    }

    Node* p1 = new Node(); //p1 노드 선언
    p1->SetData(seperate[0]); //p1노드에 seperate[0] 값을 setdata
    Node* current = p1;
    for (int i = 1; i <= countspace; i++) {
        Node* newNode = new Node();
        newNode->SetData(seperate[i]);
        current->SetNext(newNode);
        current = current->GetNext();
    } //계속해서 seperate의 값들을 노드로 연결
    LinkedList list1; //list1 선언

    list1.setHead(p1); //list1의 헤드를 p1노드로 설정

    i = 0;
    countspace = 0;
    while (input2[i] != '\0')
    {
        if (input2[i] == ' ')
        {
            countspace++;
        }

        i++;
    } //마찬가지로 input2의 공백 횟수를 계산

    string seperate2[100];
    i = 0;
    k = 0;
    for (int j = 0; j <= countspace && input2[i] != '\0'; i++)
    {
        if (input2[i] == ' ')
        {
            k++;
        }
        else
        {
            seperate2[k] += input2[i];
        }
    } //위와 동일하게 seperate2에 input2의 단어들을 하나씩 저장
    Node* p2 = new Node();
    p2->SetData(seperate2[0]);
    Node* current2 = p2;
    for (int i = 1; i <= countspace; i++) {
        Node* newNode2 = new Node();
        newNode2->SetData(seperate2[i]);
        current2->SetNext(newNode2);
        current2 = current2->GetNext();
    } //위와 동일하게 seperate2의 단어들을 노드로 연결
    LinkedList list2;
    list2.setHead(p2); //p2를 list2의 헤드로 설정

    Node* p3 = new Node(); //결과값을 위한 노드 선언

    LinkedList list3; //list3 선언
    list3.Merge_List(p1, p2, p3); //p1과 p2의 mergesort 결과를 p3에 연결

    list3.setHead(p3); //list3의 헤드를 p3로 설정
    cout << "Result:";
    list3.printList(); //결과값 출력


	
	return 0; //0의 반환
}