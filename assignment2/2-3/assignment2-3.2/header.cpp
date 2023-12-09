#include "header.h" //header ������� ����

School::School() //�⺻ ������
{
    this->student_list[100] = nullptr;
    this->size = 0; //private �������� �ʱ�ȭ
}

School::~School() //�Ҹ���
{
    for (int i = 0; i < size; i++)
    {
        delete student_list[i];
    } //���� ����
}

Student::Student() //�⺻ ������
{
    this->name = nullptr;
    this->age = 0;
    this->class_name = nullptr; //private �������� �ʱ�ȭ
}

Student::~Student() //�Ҹ���
{
    delete[] name;
    delete[] class_name; //��������
}

void Student::insert(char* name, int age, char* class_name) //�л� ������ �����ϴ� �Լ�
{
    this->name = new char[strlen(name) + 1]; //���޹��� �̸����� ��ĭ �� ���� �迭�� �����Ҵ�
    strcpy(this->name, name); //���� ���縦 ���ش�. (�������� ���� C++ ���α׷��� ����)
    this->age = age; //age�� ����
    this->class_name = new char[strlen(class_name) + 1]; //���޹��� �̸����� ��ĭ �� ���� �迭�� �����Ҵ�
    strcpy(this->class_name, class_name); //���� ���縦 ���ش�.
}

void School::new_student(char* name, int age, char* class_name) //���ο� �л��� �߰��ϴ� �Լ�
{
    student_list[size] = new Student; //size��ŭ Student Ŭ���� �迭 �����Ҵ�
    student_list[size]->insert(name, age, class_name); //�ش� �κп� �л� ���� insert
    size++; //size ����
}

void School::print_all() //��� ����ϴ� �Լ�
{
    cout << "=====print_all=====" << endl;
    for (int i = 0; i < size; i++) //size��ŭ �ݺ�
    {
        student_list[i]->print_stu(); //�ش� �ε����� ����Ű�� �κ��� ���
        cout << "---------" << endl;
    } //��� ������ش�.
}

void School::print_class(char* class_name) //�Էµ� �йݸ� ����ϴ� �Լ�
{
    int classmate = 0; //classmate ���� ����
    cout << "=====print_class=====" << endl;
    for (int i = 0; i < size; i++)
    {
        if (student_list[i]->isNameCorrect(class_name)) //class_name�� ���� �й��� ã���� ����
        {
            student_list[i]->print_stu();
            cout << "---------" << endl;
            classmate++; //�ش� �л� ���� ��� �� classmate ����
        }
    }
    cout << "Number of classmates: " << classmate << endl; //�л� �� ���
}

void Student::print_stu() //�л� ������ ����ϴ� �Լ�
{
    cout << "Name: " << this->name << endl;
    cout << "Age: " << this->age << endl;
    cout << "Country: " << this->class_name << endl; //��Ŀ� �°� �ش� ������ ����Ѵ�.
}

bool Student::isNameCorrect(char* class_name) //���� �й� �̸��� ã�� �Լ�
{
    if (!strcmp(this->class_name, class_name)) //�� �й� �̸��� ���ٸ�
        return true; //true ��ȯ
    else //���� �ʴٸ�
        return false; //false ��ȯ
}

void School::sort_by_name() //�̸��� ������������ �����ϴ� �Լ�
{
    //��������
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(student_list[i]->nameforpublic(), student_list[j]->nameforpublic()) > 0) //���� ���� �ں��� ũ��
            {
                Student* temp = student_list[i];
                student_list[i] = student_list[j];
                student_list[j] = temp; //���� ��ġ�� swap���ش�.
            }
        }
    }
}


const char* Student::nameforpublic() const //public ���� name�� �����ϱ� ���� �Լ�
{
    return name; //name�� ��ȯ
}