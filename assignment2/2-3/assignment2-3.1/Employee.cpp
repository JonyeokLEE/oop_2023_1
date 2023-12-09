#include "Employee.h" //Employee ������� ����

Employee::Employee() //�⺻ ������
{
	this->name = nullptr;
	this->age = 0;
	this->country = nullptr;
	this->job = nullptr; //�������� ��� �ʱ�ȭ
}
Employee::Employee(char* name, int age, char* country, char* job) //�ŰԺ����� �ִ� ������
{
	this->name = new char[strlen(name) + 1]; //���޹��� name���� 1�� ũ�� �����Ҵ�
	strcpy(this->name, name); //���� ���縦 ���ش�.(�������� ���� C++ ���α׷��� ����)
	this->age = age; //age ����
	this->country = new char[strlen(country) + 1];
	strcpy(this->country, country);
	this->job = new char[strlen(job) + 1];
	strcpy(this->job, job); //country�� job�� ���� ���縦 ���ش�.
}

Employee::Employee(Employee& A) //copy ������
{
	this->name = new char[strlen(A.name) + 1];
	strcpy(this->name, A.name);
	this->age = A.age;
	this->country = new char[strlen(A.country) + 1];
	strcpy(this->country, A.country);
	this->job = new char[strlen(A.job) + 1];
	strcpy(this->job, A.job); //A ��ü�� ������ ��� �������ش�.
}

bool Employee::isNameCorrect(char* name) //�̸��� ã�� �Լ�
{
	if (!strcmp(this->name,name)) //ã�� �̸��� �߰��ϸ�
		return true; //true ��ȯ
	else //�� �ܿ���
		return false; //false ��ȯ
}

Employee::~Employee() //�Ҹ���
{
	delete[] name;
	delete[] country;
	delete[] job; //�������� ���ش�.
}

void Employee::print() //���� ������ ����ϴ� �Լ�
{
	cout << "Name: " << this->name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Country: " << this->country << endl;
	cout << "Job: " << this->job << endl; //��Ŀ� �°� ��� ����Ѵ�.
}

void Employee::change(char* name, int age, char* country, char* job) //���� ������ �����ϴ� �Լ�
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->age = age;
	this->country = new char[strlen(country) + 1];
	strcpy(this->country, country);
	this->job = new char[strlen(job) + 1];
	strcpy(this->job, job); //���޹��� �������� �������ش�.
}