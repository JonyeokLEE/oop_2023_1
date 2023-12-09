#include <iostream>
using namespace std;

int checklength(int e)
{
	int count = 0;
	int copy = e;
	while (copy > 0)
	{
		copy /= 10;
		count++;
	}
	return count;
}

void smaller(char* c, long double result)
{
	int minus = static_cast<int>(result);
	int count = 0;

	int k = checklength(minus) - 1; //정수부분 자릿수 구하기
	while (minus > 0)
	{
		c[k] = (minus) % 10 + '0';
		minus /= 10;
		k--;
	} // . 앞 정수 부분을 먼저 c 배열에 넣어주기
	c[checklength(static_cast<int>(result))] = '.'; //정수 뒤에 . 삽입
	k = checklength(static_cast<int>(result)) + 1; //소숫점 이하 자리들을 넣어주기 위해 k 최신화

	int minus2 = static_cast<int>(result);
	double under = result - minus2; //under는 원래 결과값에서 소수점 이하 자리로만 이루어진 수

	while (count < 10) //10번째 자리까지 넣어주기
	{
		under *= 10; //10을 곱해 자릿수를 하나 올리기
		c[k] = static_cast<int>(under) + '0'; //올린 자릿수를 정수로 바꿔서 배열에 넣기
		under = under - static_cast<int>(under); //under 최신화
		count++;
		k++;
	}
	c[k + 1] = '\0'; //마지막 널 문자 넣기

	count = 0; //count 초기화
	int index = 0, indexdot = 0; //index: 순환을 처음 시작하는 index를 가르키는 변수, indexdot: 점의 위치를 나타내는 변수
	for (int i = 0; count < 10; i++) //10번째자리까지
	{
		//계속 반복되면 그 문자를 따로 문자변수에 지정, '.'까지 출력
		if (c[i] == '.')
		{
			indexdot = i; // . 을 만나면 해당 인덱스는 indexdot로 저장
		}
		count++;
	}
	int imple = 0; //몇자리 순환소수인지 알기 위해 선언한 변수(ex. 0.9999999 -> imple = 1)

	for (int i = indexdot + 1; c[i] != '\0'; i++) //소숫점 이하 자리부터 탐색시작. 배열이 끝날 때까지
	{
		if ((c[i] == c[i + 1]) && (c[i] == c[i + 2]) && (c[i] == c[i + 3])) //1자리 순환마디
		{
			index = i; //반복 시작하는 index를 저장
			imple++; //imple = 1
			break; //찾자마자 탈출
		}
		else if ((c[i] == c[i + 2]) && (c[i] == c[i + 4]) && (c[i] == c[i + 6])) //2자리 순환마디 (ex. 0.20202020...)
		{
			index = i; //반복 시작하는 index를 저장
			imple += 2; //imple = 2
			break; //찾자마자 탈출
		}
		else if ((c[i] == c[i + 3]) && (c[i] == c[i + 6]) && (c[i] == c[i + 9])) //3자리 순환마디 (ex. 0.306306306...)
		{
			index = i; //반복 시작하는 index를 저장
			imple += 3; //imple = 3
			break; //찾자마자 탈출
		}
		else if ((c[i] == c[i + 4]) && (c[i] == c[i + 8]) && (c[i] == c[i + 12])) //4자리 순환마디
		{
			index = i; //반복 시작하는 index를 저장
			imple += 4; //imple = 4
			break; //찾자마자 탈출
		}
		else //그 외의 경우 계속 반복
		{
			imple = 0;
		}
	}
	int a = 0;

	if (index == 0) //반복이 일어나지 않으면
	{
		cout << c; //그 수 그대로 출력
	}
	else //반복이 일어난 경우
	{
		if ((c[index] == '0') && (c[index + 1] == '0') && (c[index + 2] == '0') && (c[index + 3] == '0') && (c[index + 4] == '0') && (c[index + 5] == '0')) //반복부분이 0만 반복되는 경우에
		{
			if (indexdot == index - 1) //0이 . 바로 다음에 있을 때
			{
				for (int i = 0; i < indexdot; i++) // . 전까지 출력, 즉 정수부분만 출력
				{
					cout << c[i];
				}
			}
			else // . 바로 뒤가 아닌 나중에 0만 반복될 때
			{
				for (int i = 0; i < index; i++)
				{
					cout << c[i]; //0 반복 시작 전까지 출력
				}
			}
		}
		else //반복부분이 0이 아닌 경우
		{
			if (indexdot == index - 1) // . 바로 뒤에서 반복 시작하는 경우
			{
				for (int i = 0; i <= indexdot; i++)
				{
					cout << c[i];
				} // . 까지 출력하고
				cout << "(";
				for (int i = indexdot + 1; a < imple; i++)
				{
					cout << c[i];
					a++;
				} //순환하는 부분 모두 출력
				cout << ")";
			}
			else //. 바로 뒤에서 반복이 시작되지 않는 경우
			{
				for (int i = 0; i < index; i++) //반복 전까지 출력하고
				{
					cout << c[i];
				}
				cout << "(";
				for (int i = index; a < imple; i++)
				{
					cout << c[i];
					a++;
				}//반복하는 부분 출력
				cout << ")";
			}
		}
	}
	return; //반환

} //smaller 함수 종료

long double Vout(long double Vs2, long double Rr1, long double Rr2, long double RrL, int casenum) //Vout 값을 연산하는 함수
{
	long double res = 0; //결과값을 위한 변수 선언
	if (casenum == 1) //R(Load)가 0이 아닐 때
	{
		res = (Vs2 * Rr2 * RrL) / ((Rr2 * RrL) + Rr1 * (Rr2 + RrL)); //간소화한 식을 이용해 결과값 구하기
	}
	else //R(Load)가 0일 때
	{
		res = (Vs2 * Rr2) / (Rr1 + Rr2); //간소화한 식을 이용해 결과값 구하기
	}
	return res; //결과값 반환
}





int main()
{
	long double Vs = 0, R1 = 0, R2 = 0, RL = 0, PL = 0, VL = 0, IL = 0, Ps = 0, Is = 0; //필요한 변수 선언
	char cut[300] = { 0 , }; //소숫점 처리를 위한 배열 선언 ( . 으로 인해 char형)

	cout << "Vs: ";
	cin >> Vs;
	cout << "R1: ";
	cin >> R1;
	cout << "R2: ";
	cin >> R2;
	cout << "R(Load): ";
	cin >> RL; //입력받기

	long double ratio = 0; //ratio 변수 선언

	if (RL == 0) //RL이 0일 때
	{
		cout << "Vout: " << Vs * R2 << "/" << R1 + R2 << " = "; //간소화된 식을 이용해 중간식 출력
		smaller(cut, Vout(Vs, R1, R2, RL, 0)); //smaller 함수를 이용해 소수점 반복을 처리한 후 결과값 출력
	}

	else //RL이 0이 아닐 때
	{
		ratio = (Vout(Vs, R1, R2, RL, 1) * R2) / (Vs * (R2 + RL)) * 100; //ratio 연산 후 100 곱하기
		cout << "Vout: " << Vs * R2 * RL << "/" << ((R2 * RL) + R1 * (R2 + RL)) << " = "; //간소화된 식을 이용해 중간식 출력
		smaller(cut, Vout(Vs, R1, R2, RL, 1)); //smaller 함수를 이용해 소수점 반복을 처리한 후 결과값 출력
		cout << fixed;
		cout.precision(2); //소숫점 둘째자리까지 출력
		cout << endl <<"Load power ratio: "<< ratio << "%"; //ratio 출력

	}

}