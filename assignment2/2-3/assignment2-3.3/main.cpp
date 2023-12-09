#include "oopstd.h"
#include <iostream>
using namespace oopstd;
using namespace std;

int main()
{	//assign �Լ� �׽�Ʈ
	cout << "<Assign Function>" << endl;
	char inputstr[] = "Hello";
	oopstd::string str(inputstr);
	cout << "Before Assign: " << str.c_str() << endl; //������ Hello
	str.assign("Hi"); //assign Hi
	cout << "After Assign: " << str.c_str() << endl; //Hi ���
	str.assign("Hello World!"); //str �缳��

	//At �Լ� �׽�Ʈ
	cout << endl << "<At Function>" << endl;
	int inputat = 0; //�Է°� ���� �� �ʱ�ȭ
	cout << "Input the 'at' position: ";
	cin >> inputat; //�Է¹ޱ�
	cout << inputat << " at Str: " << str.at(inputat) << endl; //�ش� ��ġ ���

	//c_str �Լ� �׽�Ʈ
	cout << endl << "<C_str Function>" << endl;
	const char* c = str.c_str(); //c�� str ���ڿ� ��ü ��ȯ�ޱ�
	cout << "By using c_str: " << c << endl; //c ���ڿ� ���

	//clear �Լ� �׽�Ʈ
	cout << endl << "<Clear Function>" << endl;
	str.clear(); //str�� clear
	cout << "After Clear: " << str.c_str() << endl; //�ƹ��͵� ��µ��� �ʴ´�.

	//push_back �Լ� �׽�Ʈ
	cout << endl << "<Push Back Function>" << endl;
	str.assign("Hello World!"); //clear�� ���� ��������� �ٽ� ����
	char push = 0; //�Է¹��� ���� ����
	cout << "Input the character that you want to push back: ";
	cin >> push; //�Է¹ޱ�
	str.push_back(push); //push_back ���
	cout << "Push Back " << push << ": " << str.c_str() << endl; //����� ���
	str.assign("Hello"); //str �缳��

	//compare �Լ� �׽�Ʈ
	cout << endl << "<Compare Function>" << endl;
	cout << "Input the string compare with " << str.c_str() << " : ";
	cin >> inputstr; //compare�� ���ڿ� �Է¹ޱ�
	oopstd::string comparestr(inputstr); //string Ŭ������ ����
	if (str.compare(&comparestr)==0) //��ȯ���� 0�̸�
	{
		cout << "Same string!" << endl; //������ ���ڿ�
	}
	else if(str.compare(&comparestr)>0) //��ȯ���� �����
	{
		cout << "Original str has bigger value" << endl; //���� ���ڿ��� �� value�� ũ��
	}
	else //��ȯ���� ������
	{
		cout << "Original str has smaller value" << endl; //���� ���ڿ��� �� value�� ũ��.
	}

	//replace �Լ� �׽�Ʈ
	cout << endl << "<Replace Function>" << endl;
	cout << "Input the string to replace " << str.c_str() << " : ";
	cin >> inputstr; //replace �� ���ڿ� �Է¹ޱ�
	oopstd::string replacestr(inputstr);
	str.assign("Hello World!");
	str.replace(0, 5, &replacestr); //Hello �κп� replacestr �־��ֱ�
	cout << str.c_str() << endl; //����� ���

	//substr �Լ� �׽�Ʈ
	cout << endl << "<Substr Function>" << endl;
	str.assign("Hello World!");
	oopstd::string sub = str.substr(5, 10); //�����ϰ� ���� ���� 5-10
	cout << sub.c_str() << endl; //" World" ���

	//find �Լ� �׽�Ʈ
	cout << endl << "<Find Function>" << endl;
	str.assign("Hello World!");
	cout << str.find("World", 0) << endl; //ó��(0)���� World�� ���۵Ǵ� �ε��� ã��

	//stoi �Լ� �׽�Ʈ
	cout << endl << "<Stoi Function>" << endl;
	str.assign("10Bus"); //��ȯ�� ���ڿ�
	size_t pos; //ó�� ���ڰ� ��Ÿ���� ��ġ�� ��ȯ�޴� ����
	cout << str.c_str() << endl;
	cout << "Number: "<< stoi(str, &pos, 10) << endl;
	cout <<"First Apearance Position of Character: "<< pos << endl; //����� ���

	//stof �Լ� �׽�Ʈ
	cout << endl << "<Stof Function>" << endl;
	str.assign("1.52abcde"); //��ȯ�� ���ڿ�
	size_t pos2; //ó�� ���ڰ� ��Ÿ���� ��ġ�� ��ȯ�޴� ����
	cout << str.c_str() << endl;
	cout << "Number: " << stof(str, &pos2) << endl;
	cout << "First Apearance Position of Character: " << pos2 << endl; //����� ���
	
	//to_string �Լ� �׽�Ʈ
	cout << endl << "<To_String Function>" << endl;
	int intstr = -349; //��ȯ�� ����
	float floatstr = 2.7; //��ȯ�� �Ǽ�
	oopstd::string res(to_string(intstr));
	cout << res.c_str() << endl;
	oopstd::string res2(to_string(floatstr));
	cout << res2.c_str() << endl; //����� ���

	return 0;


}