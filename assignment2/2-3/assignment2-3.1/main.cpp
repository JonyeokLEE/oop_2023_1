#include "Employee.h" //Employee 헤더파일 선언

int main(void) //main 함수
{
    Employee *obj[10]; //객체 포인터 obj 선언
    int index = 0; //어디까지 저장되었는지 확인하기 위한 변수
    char command[100]; //커맨드를 위한 변수
    char inputname[100];
    char changename[100];
    char inputjob[100];
    int inputage = 0;
    char inputcountry[100]; //입력받을 직원 정보들을 위한 변수

    while (1) //조건이 될 때까지 무한반복
    {
        cin >> command; //command를 입력받는다.
        if (!strcmp(command, "insert")) //insert가 입력되면
        {
            if (index == 10) //만약 10명의 정보가 입력되면
            {
                cout << "You cannot insert anymore." << endl; //안내문 출력
            }
            else //그 외의 경우
            {
                cin >> inputname >> inputage >> inputcountry >> inputjob; //직원 정보 입력받은 후
                obj[index]=new Employee(inputname, inputage, inputcountry, inputjob); //obj 생성
                index++; //index 증가
            }
        }
        else if (!strcmp(command, "print")) //print가 입력되면
        {
            cout << "=====print=====" << endl;
            for (int i = 0; i < index; i++)
            {
                obj[i]->print();
                cout << "----------" << endl;
            } //index까지 직원 정보 반복해서 출력하기
        }
        else if (!strcmp(command, "find")) //find가 입력되면
        {
            cin >> inputname; //찾을 이름 입력받고
            cout << "=====find=====" << endl;
            for (int i = 0; i < index; i++)
            {
                if (obj[i]->isNameCorrect(inputname)) //만약 해당 인덱스가 inputname과 같다면
                {
                    obj[i]->print(); //해당 직원 정보 출력
                    cout << "----------" << endl;
                }
            }
        }
        else if (!strcmp(command, "change")) //change가 입력되면
        {
            cin >> inputname; //바꿀 직원 이름 입력받고
            for (int i = 0; i < index; i++)
            {
                if (obj[i]->isNameCorrect(inputname)) //해당 인덱스 찾기
                {
                    cin >> changename >> inputage >> inputcountry >> inputjob; //바뀔 직원 정보 입력
                    obj[i]->change(changename, inputage, inputcountry, inputjob); //직원정보 등록
                }
            }

        }
        else if (!strcmp(command, "exit")) //exit가 입력되면
        {
            break; //반복문 종료
        }
        else //그 외의 이상한 command가 입력되면
        {
            cout << "Wrong Command. Please Enter the Command Again." << endl; //안내문 출력
        }
    }

    return 0; //0의 반환
}
