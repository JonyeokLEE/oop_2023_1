#include "Queue.h"

int main() //main함수 시작
{
    Queue queue; //Queue 객체 선언
    char control[300] = { 0 }; //command를 입력받을 control 문자열 선언
    int element = 0; //push함수에 들어갈 요소를 위한 변수 선언
    cout << "Enter the size of Queue: ";
    int sizenum = 0;
    cin >> sizenum; //Queue Size 입력받기
    queue.SetSize(sizenum); //queue에 size setting 해주기

    while (1) //반복문 (exit에 의해 종료된다.)
    {
        cin >> control; //command를 입력받기
        if (!strcmp(control, "push")) //control에 push가 입력되면
        {
            cin >> element; //element를 입력받고
            Node* node = new Node(); //새로운 노드 객체 생성
            node->SetData(element); //node에 element 전달해 data set
            if (queue.Push(node)) //Push를 성공하면
                cout << "Push " << element << " Success!" << endl; //출력문 출력
            else //Push를 실패하면
                cout << "Queue is full." << endl; //Queue가 Full이므로 출력문 출력
        }
        else if (!strcmp(control, "pop")) //control에 pop이 입력되면
        {
            if (!queue.IsEmpty()) //만약 Queue가 비어있지 않으면
            {
                cout << "Pop "<< queue.Pop()->GetData() << " Success!" << endl;
            }   
            else //만약 Queue가 비어있으면
                cout << "Queue is empty." << endl; //출력문 출력
        }
        else if (!strcmp(control, "isempty")) //control에 isempty가 입력되면
        {
            if (queue.IsEmpty()) //만약 비어있다면
                cout << "Queue is empty." << endl; //비어있다는 출력문 출력
            else //만약 비어있지 않다면
                cout << "Queue is not empty." << endl; //비어있지 않다는 출력문 출력
        }
        else if (!strcmp(control, "isfull")) //control에 isfull가 입력되면
        {
            if (queue.IsFull()) //만약 다 차있다면
                cout << "Queue is full." << endl; //꽉 찼다는 출력문 출력
            else //만약 다 차있지 않다면
                cout << "Queue is not full." << endl; //다 차있지 않다는 출력문 출력
        }
        else if (!strcmp(control, "print")) //print가 입력되면
        {
            if (queue.IsEmpty())
                cout << "Queue is empty." << endl;
            else
                queue.PrintQueue(); //Queue의 Element들을 출력
        }
        else if (!strcmp(control, "exit")) //control에 exit가 입력되면
        {
            break; //반복문 종료
        }
        else //control에 정해지지 않은 command가 입력되면
        {
            cout << "Wrong Command Entered. Please Try Again." << endl; //안내문 출력
        }
    }
    return 0; //0의 반환
} //main함수 종료