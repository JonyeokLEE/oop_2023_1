#include "oopstd.h"
namespace oopstd
{
	string::string() //�⺻ ������
	{
		s = nullptr;
		len = 0; //���� �ʱ�ȭ
	}

	string::string(const char* s) //�������ڰ� �ִ� ������
	{
		this->len = strlen(s); //s�� ���̸� ����
		this->s = new char[len + 1]; //s�� ���̸� �������� �����Ҵ�
		strcpy(this->s, s); //���޹��� ������ copy�Ѵ�
	}

	string::string(const string& str) //copy ������
	{
		this->len = strlen(str.s); //str�� s�� ���̸� ����
		this->s = new char[len + 1]; //s�� ���̸� �������� �����Ҵ�
		strcpy(this->s, str.s); //str�� s�� s�� copy�Ѵ�.
	}

	string::~string() //�Ҹ���
	{
		delete[] s; //��������
	}

	string& string::assign(const string& str) //assign �Լ�
	{
		delete[] s; //���� ������ ���� ��
		this->len = strlen(str.s); //str�� s�� ���̸� ����
		s = new char[len + 1]; //�� ���̸� �������� s �����Ҵ�
		strcpy(this->s, str.s); //str�� s�� ������ copy
		return *this; //��ȯ
	}

	char& string::at(size_t pos) //at �Լ�
	{
		return s[pos]; //pos�ε����� ���� ��ȯ
	}


	const char* string::c_str() const //c_str �Լ�
	{
		return s; //���ڿ� ��ü�� ��ȯ
	}

	void string::clear() //clear �Լ�
	{
		delete[] s;
		s = new char[1]; //����� �ؾ��ϴ� ��ĭ¥���� ���δ�.
		s[0] = '\0';
		len = 0; //��� �ʱ�ȭ
	}

	void string::push_back(char c) //push_back �Լ�
	{
		char* pushback = new char[len + 2]; //�ڿ� ���̴� �Ŵ� +2��ŭ �� �����Ҵ�
		for (int i = 0; i < len; i++)
			pushback[i] = s[i]; //s�� ������ copy
		pushback[len] = c; //c�� �� �ڿ� ���δ�.
		pushback[len + 1] = '\0'; //nulll�߰�

		delete[]s; //s ����
		s = new char[len + 2];
		strcpy(this->s, pushback); //pushback�� ���� �ٽ� s�� copy
		len++; //�ѱ��� �߰� �Ǿ����� len �߰�
	}

	int string::compare(const string* str) const //compare �Լ�
	{
		return strcmp(this->s, str->s); //�� ���ڿ��� strcmp ��ȯ���� ��ȯ
	}

	string& string::replace(size_t pos, size_t len, const string* str) //replace �Լ�
	{
		size_t replacelen = 0;
		replacelen = this->len - len + str->len; //���ο� ���ڿ��� ����
		//this->len ���� ���ڿ��� ����/ len�� ��ü�� ���� �� / str->len�� ��ü�� ���ڿ��� ����
		char* replacestr = new char(replacelen + 1); //���ο� ���ڿ� �����Ҵ�

		memcpy(replacestr, s, pos);//���� ���ڿ��� pos������ ����
		memcpy(replacestr + pos, str->s, str->len); //��ü�� ���ڿ��� ����
		memcpy(replacestr + pos + str->len, s + pos + len, this->len - pos - len); //��ü�� �����κк��� ������ ����

		replacestr[replacelen] = '\0';

		delete[] s; //s ����
		s = new char[replacelen + 1];
		strcpy(this->s, replacestr); //s�� replacestr�� ����
		this->len = replacelen; //len�� ����

		return *this; //��ȯ
	}

	string string::substr(size_t pos, size_t len) const //substr �Լ�
	{
		string smallone;
		smallone.s = new char[(len)+1]; //����� ���� ���ڿ�
		memcpy(smallone.s, s + pos, len); //������ ������ �°� ����
		smallone.s[len] = '\0';
		smallone.len = len; //len�� ����
		return smallone; //��ȯ
	}

	size_t string::find(const string& str, size_t pos) const //find �Լ�
	{	//pos�� ã�°��� �����ϴ� ��ġ
		for (size_t i = pos; i <= len - str.len; ++i) {
			size_t j = 0;
			for (; j < str.len; ++j)
				if (s[i + j] != str.s[j]) //���� �� ���ڰ� �ٸ���
					break; //�ݺ��� ����
			if (j == str.len) //���� j�� str.len�� ���ٸ�
				return i; //���� ��ġ�� i�� ��ȯ
		}
		return npos; //match�� ������ npos ��ȯ
	}

	char& string::at2(size_t pos) const //at2 �Լ�
	{
		return s[pos]; //pos �ε����� ���� ��ȯ
	}

	int oopstd::stoi(const string& str, size_t* idx, int base) //stoi �Լ�
	{
		int result = 0; //����� ����
		size_t i = 0;
		while (i < str.getlen() && str.at2(i) >= '0' && str.at2(i) <= '9') //i�� ���ڿ��� ���̸� �ʰ����� �ʰ�, ���ڸ� ������
		{
			result = result * base + (str.at2(i) - '0'); //�ش� ���� ������ ��ȯ�ؼ� result�� ����
			++i;
		}
		if (idx != nullptr) //idx�� ���� �ƴϸ�
		{
			*idx = i; //�ش� ��ġ�� �����ؼ� ��ȯ�� ������ ������ ����
		}
		return result; //����� ��ȯ
	}

	float oopstd::stof(const string& str, size_t* idx) //stof �Լ�
	{
		float result = 0;
		size_t i = 0;
		while (i < str.getlen() && str.at2(i) >= '0' && str.at2(i) <= '9') {
			result = result * 10 + (str.at2(i) - '0');
			++i;
		} //�տ� ���ڸ� �����ϰ� ó��
		if (i < str.getlen() && str.at2(i) == '.') //�Ҽ����� ������
		{
			++i; //skip�ϰ�
			float sosoo = 1;
			while (i < str.getlen() && str.at2(i) >= '0' && str.at2(i) <= '9') {
				sosoo /= 10;
				result += sosoo * (str.at2(i) - '0');
				++i; //����ؼ� ������ ������ �Ҽ��� ���� �ڸ��� ó��
			}
		}
		if (idx != nullptr) //idx�� ���� �ƴϸ�
		{

			*idx = i; //�ش� ��ġ�� �����ؼ� ��ȯ�� ������ ������ ����
		}
		return result; //����� ��ȯ
	}

	string to_string(int val) //to_string �Լ�
	{
		bool negative = false; //���� �ʱ�ȭ
		if (val < 0) //������
		{
			negative = true; //true�� �ϰ�
			val = -val; //����� �����
		}
		string copy;
		while(val>0) //val�� ����϶����� ����
		{
			copy.push_back('0' + val % 10); //���� �ڸ��� ���� ���ڷ� ��ȯ�ؼ� copy�� �߰�
			val /= 10; //val �ֽ�ȭ
		}
		
		if (negative) //�������
			copy.push_back('-'); //-�ٿ��ֱ�
		string result;
		for (int i = copy.getlen() - 1; i >= 0; i--)
			result.push_back(copy.at2(i)); //copy�� �������� result �ޱ�
		return result; //result ��ȯ
	}

	string to_string(float val) //to_string �Լ�
	{
		bool negative = false; //���� �ʱ�ȭ
		if (val < 0) //�������
		{
			negative = true; //true�� �ϰ�
			val = -val; //����� �����
		}
		int int_part = (int)val;
		float float_part = val - int_part; //�Ǽ��� ���� �κ��� �����ϱ�
		
		string int_str = to_string(int_part); //�����κ��� to_string�� �̿��� ��ȯ �� int_str�� ����
		string float_str; //�Ǽ� �κ��� ������ ���ڿ�
		int again = 0; //�Ҽ��� ���� �ڸ����� ���� ����
		while (float_part > 0) //����ϵ��� �ݺ�
		{
			if (again == 6) //���� �Լ��� �Ҽ��� ���� 6�ڸ� ���� ����ϱ⿡ ����� ������ ���� ������ �ɾ����ϴ�.
				break;
			float_part *= 10; //10�� ���ؼ� �Ҽ��� �̻� �ڸ��� �ø���
			float_str.push_back('0' + (int)float_part); //�ش� �κ��� �� �ڷ� �߰�
			float_part -= (int)float_part; //float_part �ֽ�ȭ
			again++; //�Ҽ��� ���� �ڸ� ����
		}
		string result; //������� ���� ���ڿ�
		if (negative) //�������
			result.push_back('-'); //- �ٿ��ֱ�
		for (int i = 0; i < int_str.getlen(); i++)
			result.push_back(int_str.at2(i)); //�����κ��� �״�� �Ű��ֱ�
		result.push_back('.'); //������ ������ . �߰�
		for (int i = 0; i < float_str.getlen(); i++)
			result.push_back(float_str.at2(i)); //�Ҽ��� �κ��� float_str�� �������� �޾��ֱ� 
		return result; //result ��ȯ
	}

	size_t string::getlen() const //len�� ��ȯ�ϴ� �Լ�
	{
		return len;
	}

	char* string::getS() const //s�� ��ȯ�ϴ� �Լ�
	{
		return s;
	}

}