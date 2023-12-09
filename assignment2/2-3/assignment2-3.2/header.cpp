#include "header.h" //header 헤더파일 선언

School::School() //기본 생성자
{
    this->student_list[100] = nullptr;
    this->size = 0; //private 변수들을 초기화
}

School::~School() //소멸자
{
    for (int i = 0; i < size; i++)
    {
        delete student_list[i];
    } //동적 해제
}

Student::Student() //기본 생성자
{
    this->name = nullptr;
    this->age = 0;
    this->class_name = nullptr; //private 변수들을 초기화
}

Student::~Student() //소멸자
{
    delete[] name;
    delete[] class_name; //동적해제
}

void Student::insert(char* name, int age, char* class_name) //학생 정보를 삽입하는 함수
{
    this->name = new char[strlen(name) + 1]; //전달받은 이름보다 한칸 더 많은 배열을 동적할당
    strcpy(this->name, name); //깊은 복사를 해준다. (윤성우의 열혈 C++ 프로그래밍 참고)
    this->age = age; //age값 복사
    this->class_name = new char[strlen(class_name) + 1]; //전달받은 이름보다 한칸 더 많은 배열을 동적할당
    strcpy(this->class_name, class_name); //깊은 복사를 해준다.
}

void School::new_student(char* name, int age, char* class_name) //새로운 학생을 추가하는 함수
{
    student_list[size] = new Student; //size만큼 Student 클래스 배열 동적할당
    student_list[size]->insert(name, age, class_name); //해당 부분에 학생 정보 insert
    size++; //size 증가
}

void School::print_all() //모두 출력하는 함수
{
    cout << "=====print_all=====" << endl;
    for (int i = 0; i < size; i++) //size만큼 반복
    {
        student_list[i]->print_stu(); //해당 인덱스가 가리키는 부분을 출력
        cout << "---------" << endl;
    } //모두 출력해준다.
}

void School::print_class(char* class_name) //입력된 분반만 출력하는 함수
{
    int classmate = 0; //classmate 변수 선언
    cout << "=====print_class=====" << endl;
    for (int i = 0; i < size; i++)
    {
        if (student_list[i]->isNameCorrect(class_name)) //class_name과 같은 분반을 찾았을 때만
        {
            student_list[i]->print_stu();
            cout << "---------" << endl;
            classmate++; //해당 학생 정보 출력 후 classmate 증가
        }
    }
    cout << "Number of classmates: " << classmate << endl; //학생 수 출력
}

void Student::print_stu() //학생 정보를 출력하는 함수
{
    cout << "Name: " << this->name << endl;
    cout << "Age: " << this->age << endl;
    cout << "Country: " << this->class_name << endl; //양식에 맞게 해당 정보를 출력한다.
}

bool Student::isNameCorrect(char* class_name) //같은 분반 이름을 찾는 함수
{
    if (!strcmp(this->class_name, class_name)) //두 분반 이름이 같다면
        return true; //true 반환
    else //같지 않다면
        return false; //false 반환
}

void School::sort_by_name() //이름을 오름차순으로 정렬하는 함수
{
    //버블정렬
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(student_list[i]->nameforpublic(), student_list[j]->nameforpublic()) > 0) //만약 앞이 뒤보다 크면
            {
                Student* temp = student_list[i];
                student_list[i] = student_list[j];
                student_list[j] = temp; //서로 위치를 swap해준다.
            }
        }
    }
}


const char* Student::nameforpublic() const //public 변수 name에 접근하기 위한 함수
{
    return name; //name을 반환
}