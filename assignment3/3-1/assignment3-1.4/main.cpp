#include "Stack.h"

int main() //main함수 시작
{
    Stack stack; // Stack 객체 생성
    char control[300] = { 0 }; //command를 입력받을 control 문자열 선언
    int element = 0; //push함수에 들어갈 요소를 위한 변수 선언
    cout << "Enter the size of Stack: ";
    int sizenum = 0;
    cin >> sizenum; //Stack의 size를 입력받고
    stack.SetSize(sizenum); //입력받은 값을 SetSize 함수에 전달한다.

    while (1) //반복문 (exit에 의해 종료된다.)
    {
        cin >> control; //command를 입력받기
        if (!strcmp(control, "push")) //control에 push가 입력되면
        {
            cin >> element; //element를 입력받고
            Node* node = new Node(); //node 객체 생성 후
            node->SetData(element); //SetData하기(element 전달)
            if (stack.Push(node)) //만약 push에 성공하면
                cout << "Push " << element << " Success!" << endl;
            else //만약 push에 실패하면
                cout << "Stack is full." << endl;

        }
        else if (!strcmp(control, "pop")) //control에 pop이 입력되면
        {
            if (!stack.IsEmpty()) //만약 Stack이 비어있지 않으면
            {
                cout << "Pop " << stack.Pop()->GetData() << " Success!" << endl;
            }
            else //비어있어서 성공을 못했다면
                cout << "Stack is empty." << endl;
        }
        else if (!strcmp(control, "isempty")) //control에 isempty가 입력되면
        {
            if (stack.IsEmpty()) //true가 반환되면
                cout << "Stack is empty." << endl;
            else //false가 반환되면
                cout << "Stack is not empty." << endl;
        }
        else if (!strcmp(control, "isfull")) //control에 isfull가 입력되면
        {
            if (stack.IsFull()) //true가 반환되면
                cout << "Stack is full." << endl;
            else //false가 반환되면
                cout << "Stack is not full." << endl;
        }
        else if (!strcmp(control, "print")) //control에 print가 입력되면
        {
            if (stack.IsEmpty())
                cout << "Stack is empty." << endl;
            else //false가 반환되면
                stack.PrintStack();
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