#include "Employee.h" //Employee 헤더파일 선언

Employee::Employee() //기본 생성자
{
	this->name = nullptr;
	this->age = 0;
	this->country = nullptr;
	this->job = nullptr; //변수들을 모두 초기화
}
Employee::Employee(char* name, int age, char* country, char* job) //매게변수가 있는 생성자
{
	this->name = new char[strlen(name) + 1]; //전달받은 name보다 1이 크게 동적할당
	strcpy(this->name, name); //깊은 복사를 해준다.(윤성우의 열혈 C++ 프로그래밍 참고)
	this->age = age; //age 복사
	this->country = new char[strlen(country) + 1];
	strcpy(this->country, country);
	this->job = new char[strlen(job) + 1];
	strcpy(this->job, job); //country와 job도 깊은 복사를 해준다.
}

Employee::Employee(Employee& A) //copy 생성자
{
	this->name = new char[strlen(A.name) + 1];
	strcpy(this->name, A.name);
	this->age = A.age;
	this->country = new char[strlen(A.country) + 1];
	strcpy(this->country, A.country);
	this->job = new char[strlen(A.job) + 1];
	strcpy(this->job, A.job); //A 객체의 값들을 모두 복사해준다.
}

bool Employee::isNameCorrect(char* name) //이름을 찾는 함수
{
	if (!strcmp(this->name,name)) //찾는 이름을 발견하면
		return true; //true 반환
	else //그 외에는
		return false; //false 반환
}

Employee::~Employee() //소멸자
{
	delete[] name;
	delete[] country;
	delete[] job; //동적해제 해준다.
}

void Employee::print() //직원 정보를 출력하는 함수
{
	cout << "Name: " << this->name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Country: " << this->country << endl;
	cout << "Job: " << this->job << endl; //양식에 맞게 모두 출력한다.
}

void Employee::change(char* name, int age, char* country, char* job) //직원 정보를 변경하는 함수
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->age = age;
	this->country = new char[strlen(country) + 1];
	strcpy(this->country, country);
	this->job = new char[strlen(job) + 1];
	strcpy(this->job, job); //전달받은 변수들을 복사해준다.
}