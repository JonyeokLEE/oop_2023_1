#include "oopstd.h"
namespace oopstd
{
	string::string() //기본 생성자
	{
		s = nullptr;
		len = 0; //변수 초기화
	}

	string::string(const char* s) //전달인자가 있는 생성자
	{
		this->len = strlen(s); //s의 길이를 저장
		this->s = new char[len + 1]; //s의 길이를 기준으로 동적할당
		strcpy(this->s, s); //전달받은 값들을 copy한다
	}

	string::string(const string& str) //copy 생성자
	{
		this->len = strlen(str.s); //str의 s의 길이를 저장
		this->s = new char[len + 1]; //s의 길이를 기준으로 동적할당
		strcpy(this->s, str.s); //str의 s를 s로 copy한다.
	}

	string::~string() //소멸자
	{
		delete[] s; //동적해제
	}

	string& string::assign(const string& str) //assign 함수
	{
		delete[] s; //기존 내용을 삭제 후
		this->len = strlen(str.s); //str의 s의 길이를 저장
		s = new char[len + 1]; //그 길이를 기준으로 s 동적할당
		strcpy(this->s, str.s); //str의 s의 내용을 copy
		return *this; //반환
	}

	char& string::at(size_t pos) //at 함수
	{
		return s[pos]; //pos인덱스의 값을 반환
	}


	const char* string::c_str() const //c_str 함수
	{
		return s; //문자열 전체를 반환
	}

	void string::clear() //clear 함수
	{
		delete[] s;
		s = new char[1]; //존재는 해야하니 한칸짜리로 줄인다.
		s[0] = '\0';
		len = 0; //모두 초기화
	}

	void string::push_back(char c) //push_back 함수
	{
		char* pushback = new char[len + 2]; //뒤에 붙이는 거니 +2만큼 더 동적할당
		for (int i = 0; i < len; i++)
			pushback[i] = s[i]; //s의 내용을 copy
		pushback[len] = c; //c를 맨 뒤에 붙인다.
		pushback[len + 1] = '\0'; //nulll추가

		delete[]s; //s 삭제
		s = new char[len + 2];
		strcpy(this->s, pushback); //pushback의 값을 다시 s로 copy
		len++; //한글자 추가 되었으니 len 추가
	}

	int string::compare(const string* str) const //compare 함수
	{
		return strcmp(this->s, str->s); //두 문자열의 strcmp 반환값을 반환
	}

	string& string::replace(size_t pos, size_t len, const string* str) //replace 함수
	{
		size_t replacelen = 0;
		replacelen = this->len - len + str->len; //새로운 문자열의 길이
		//this->len 원래 문자열의 길이/ len은 교체할 문자 수 / str->len은 교체할 문자열의 길이
		char* replacestr = new char(replacelen + 1); //새로운 문자열 동적할당

		memcpy(replacestr, s, pos);//원래 문자열의 pos까지를 복사
		memcpy(replacestr + pos, str->s, str->len); //교체할 문자열을 복사
		memcpy(replacestr + pos + str->len, s + pos + len, this->len - pos - len); //교체한 다음부분부터 끝까지 복사

		replacestr[replacelen] = '\0';

		delete[] s; //s 삭제
		s = new char[replacelen + 1];
		strcpy(this->s, replacestr); //s에 replacestr을 복사
		this->len = replacelen; //len도 복사

		return *this; //반환
	}

	string string::substr(size_t pos, size_t len) const //substr 함수
	{
		string smallone;
		smallone.s = new char[(len)+1]; //결과를 받을 문자열
		memcpy(smallone.s, s + pos, len); //정해진 범위에 맞게 복사
		smallone.s[len] = '\0';
		smallone.len = len; //len값 복사
		return smallone; //반환
	}

	size_t string::find(const string& str, size_t pos) const //find 함수
	{	//pos는 찾는것을 시작하는 위치
		for (size_t i = pos; i <= len - str.len; ++i) {
			size_t j = 0;
			for (; j < str.len; ++j)
				if (s[i + j] != str.s[j]) //만약 두 문자가 다르면
					break; //반복문 종료
			if (j == str.len) //만약 j가 str.len과 같다면
				return i; //현재 위치인 i를 반환
		}
		return npos; //match가 없으면 npos 반환
	}

	char& string::at2(size_t pos) const //at2 함수
	{
		return s[pos]; //pos 인덱스의 값을 반환
	}

	int oopstd::stoi(const string& str, size_t* idx, int base) //stoi 함수
	{
		int result = 0; //결과값 변수
		size_t i = 0;
		while (i < str.getlen() && str.at2(i) >= '0' && str.at2(i) <= '9') //i가 문자열의 길이를 초과하지 않고, 숫자를 만나면
		{
			result = result * base + (str.at2(i) - '0'); //해당 수를 정수로 변환해서 result에 저장
			++i;
		}
		if (idx != nullptr) //idx가 널이 아니면
		{
			*idx = i; //해당 위치를 저장해서 변환된 문자의 개수를 저장
		}
		return result; //결과값 반환
	}

	float oopstd::stof(const string& str, size_t* idx) //stof 함수
	{
		float result = 0;
		size_t i = 0;
		while (i < str.getlen() && str.at2(i) >= '0' && str.at2(i) <= '9') {
			result = result * 10 + (str.at2(i) - '0');
			++i;
		} //앞에 숫자를 동일하게 처리
		if (i < str.getlen() && str.at2(i) == '.') //소수점을 만나면
		{
			++i; //skip하고
			float sosoo = 1;
			while (i < str.getlen() && str.at2(i) >= '0' && str.at2(i) <= '9') {
				sosoo /= 10;
				result += sosoo * (str.at2(i) - '0');
				++i; //계속해서 숫자일 때동안 소숫점 이하 자리들 처리
			}
		}
		if (idx != nullptr) //idx가 널이 아니면
		{

			*idx = i; //해당 위치를 저장해서 변환된 문자의 개수를 저장
		}
		return result; //결과값 반환
	}

	string to_string(int val) //to_string 함수
	{
		bool negative = false; //음수 초기화
		if (val < 0) //음수면
		{
			negative = true; //true로 하고
			val = -val; //양수로 만들기
		}
		string copy;
		while(val>0) //val이 양수일때동안 진행
		{
			copy.push_back('0' + val % 10); //현재 자리의 수를 문자로 변환해서 copy에 추가
			val /= 10; //val 최신화
		}
		
		if (negative) //음수라면
			copy.push_back('-'); //-붙여주기
		string result;
		for (int i = copy.getlen() - 1; i >= 0; i--)
			result.push_back(copy.at2(i)); //copy의 역순으로 result 받기
		return result; //result 반환
	}

	string to_string(float val) //to_string 함수
	{
		bool negative = false; //음수 초기화
		if (val < 0) //음수라면
		{
			negative = true; //true로 하고
			val = -val; //양수로 만들기
		}
		int int_part = (int)val;
		float float_part = val - int_part; //실수와 정수 부분을 저장하기
		
		string int_str = to_string(int_part); //정수부분은 to_string을 이용해 변환 후 int_str에 저장
		string float_str; //실수 부분을 저장할 문자열
		int again = 0; //소숫점 이하 자리들을 세는 변수
		while (float_part > 0) //양수일동안 반복
		{
			if (again == 6) //원래 함수도 소숫점 이하 6자리 까지 출력하기에 흡사한 구현을 위해 조건을 걸었습니다.
				break;
			float_part *= 10; //10을 곱해서 소수점 이상 자리로 올리고
			float_str.push_back('0' + (int)float_part); //해당 부분을 맨 뒤로 추가
			float_part -= (int)float_part; //float_part 최신화
			again++; //소숫점 이하 자리 증가
		}
		string result; //결과값을 위한 문자열
		if (negative) //음수라면
			result.push_back('-'); //- 붙여주기
		for (int i = 0; i < int_str.getlen(); i++)
			result.push_back(int_str.at2(i)); //정수부분을 그대로 옮겨주기
		result.push_back('.'); //정수가 끝나면 . 추가
		for (int i = 0; i < float_str.getlen(); i++)
			result.push_back(float_str.at2(i)); //소수점 부분은 float_str의 역순으로 받아주기 
		return result; //result 반환
	}

	size_t string::getlen() const //len을 반환하는 함수
	{
		return len;
	}

	char* string::getS() const //s를 반환하는 함수
	{
		return s;
	}

}