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

	int k = checklength(minus) - 1; //�����κ� �ڸ��� ���ϱ�
	while (minus > 0)
	{
		c[k] = (minus) % 10 + '0';
		minus /= 10;
		k--;
	} // . �� ���� �κ��� ���� c �迭�� �־��ֱ�
	c[checklength(static_cast<int>(result))] = '.'; //���� �ڿ� . ����
	k = checklength(static_cast<int>(result)) + 1; //�Ҽ��� ���� �ڸ����� �־��ֱ� ���� k �ֽ�ȭ

	int minus2 = static_cast<int>(result);
	double under = result - minus2; //under�� ���� ��������� �Ҽ��� ���� �ڸ��θ� �̷���� ��

	while (count < 10) //10��° �ڸ����� �־��ֱ�
	{
		under *= 10; //10�� ���� �ڸ����� �ϳ� �ø���
		c[k] = static_cast<int>(under) + '0'; //�ø� �ڸ����� ������ �ٲ㼭 �迭�� �ֱ�
		under = under - static_cast<int>(under); //under �ֽ�ȭ
		count++;
		k++;
	}
	c[k + 1] = '\0'; //������ �� ���� �ֱ�

	count = 0; //count �ʱ�ȭ
	int index = 0, indexdot = 0; //index: ��ȯ�� ó�� �����ϴ� index�� ����Ű�� ����, indexdot: ���� ��ġ�� ��Ÿ���� ����
	for (int i = 0; count < 10; i++) //10��°�ڸ�����
	{
		//��� �ݺ��Ǹ� �� ���ڸ� ���� ���ں����� ����, '.'���� ���
		if (c[i] == '.')
		{
			indexdot = i; // . �� ������ �ش� �ε����� indexdot�� ����
		}
		count++;
	}
	int imple = 0; //���ڸ� ��ȯ�Ҽ����� �˱� ���� ������ ����(ex. 0.9999999 -> imple = 1)

	for (int i = indexdot + 1; c[i] != '\0'; i++) //�Ҽ��� ���� �ڸ����� Ž������. �迭�� ���� ������
	{
		if ((c[i] == c[i + 1]) && (c[i] == c[i + 2]) && (c[i] == c[i + 3])) //1�ڸ� ��ȯ����
		{
			index = i; //�ݺ� �����ϴ� index�� ����
			imple++; //imple = 1
			break; //ã�ڸ��� Ż��
		}
		else if ((c[i] == c[i + 2]) && (c[i] == c[i + 4]) && (c[i] == c[i + 6])) //2�ڸ� ��ȯ���� (ex. 0.20202020...)
		{
			index = i; //�ݺ� �����ϴ� index�� ����
			imple += 2; //imple = 2
			break; //ã�ڸ��� Ż��
		}
		else if ((c[i] == c[i + 3]) && (c[i] == c[i + 6]) && (c[i] == c[i + 9])) //3�ڸ� ��ȯ���� (ex. 0.306306306...)
		{
			index = i; //�ݺ� �����ϴ� index�� ����
			imple += 3; //imple = 3
			break; //ã�ڸ��� Ż��
		}
		else if ((c[i] == c[i + 4]) && (c[i] == c[i + 8]) && (c[i] == c[i + 12])) //4�ڸ� ��ȯ����
		{
			index = i; //�ݺ� �����ϴ� index�� ����
			imple += 4; //imple = 4
			break; //ã�ڸ��� Ż��
		}
		else //�� ���� ��� ��� �ݺ�
		{
			imple = 0;
		}
	}
	int a = 0;

	if (index == 0) //�ݺ��� �Ͼ�� ������
	{
		cout << c; //�� �� �״�� ���
	}
	else //�ݺ��� �Ͼ ���
	{
		if ((c[index] == '0') && (c[index + 1] == '0') && (c[index + 2] == '0') && (c[index + 3] == '0') && (c[index + 4] == '0') && (c[index + 5] == '0')) //�ݺ��κ��� 0�� �ݺ��Ǵ� ��쿡
		{
			if (indexdot == index - 1) //0�� . �ٷ� ������ ���� ��
			{
				for (int i = 0; i < indexdot; i++) // . ������ ���, �� �����κи� ���
				{
					cout << c[i];
				}
			}
			else // . �ٷ� �ڰ� �ƴ� ���߿� 0�� �ݺ��� ��
			{
				for (int i = 0; i < index; i++)
				{
					cout << c[i]; //0 �ݺ� ���� ������ ���
				}
			}
		}
		else //�ݺ��κ��� 0�� �ƴ� ���
		{
			if (indexdot == index - 1) // . �ٷ� �ڿ��� �ݺ� �����ϴ� ���
			{
				for (int i = 0; i <= indexdot; i++)
				{
					cout << c[i];
				} // . ���� ����ϰ�
				cout << "(";
				for (int i = indexdot + 1; a < imple; i++)
				{
					cout << c[i];
					a++;
				} //��ȯ�ϴ� �κ� ��� ���
				cout << ")";
			}
			else //. �ٷ� �ڿ��� �ݺ��� ���۵��� �ʴ� ���
			{
				for (int i = 0; i < index; i++) //�ݺ� ������ ����ϰ�
				{
					cout << c[i];
				}
				cout << "(";
				for (int i = index; a < imple; i++)
				{
					cout << c[i];
					a++;
				}//�ݺ��ϴ� �κ� ���
				cout << ")";
			}
		}
	}
	return; //��ȯ

} //smaller �Լ� ����

long double Vout(long double Vs2, long double Rr1, long double Rr2, long double RrL, int casenum) //Vout ���� �����ϴ� �Լ�
{
	long double res = 0; //������� ���� ���� ����
	if (casenum == 1) //R(Load)�� 0�� �ƴ� ��
	{
		res = (Vs2 * Rr2 * RrL) / ((Rr2 * RrL) + Rr1 * (Rr2 + RrL)); //����ȭ�� ���� �̿��� ����� ���ϱ�
	}
	else //R(Load)�� 0�� ��
	{
		res = (Vs2 * Rr2) / (Rr1 + Rr2); //����ȭ�� ���� �̿��� ����� ���ϱ�
	}
	return res; //����� ��ȯ
}





int main()
{
	long double Vs = 0, R1 = 0, R2 = 0, RL = 0, PL = 0, VL = 0, IL = 0, Ps = 0, Is = 0; //�ʿ��� ���� ����
	char cut[300] = { 0 , }; //�Ҽ��� ó���� ���� �迭 ���� ( . ���� ���� char��)

	cout << "Vs: ";
	cin >> Vs;
	cout << "R1: ";
	cin >> R1;
	cout << "R2: ";
	cin >> R2;
	cout << "R(Load): ";
	cin >> RL; //�Է¹ޱ�

	long double ratio = 0; //ratio ���� ����

	if (RL == 0) //RL�� 0�� ��
	{
		cout << "Vout: " << Vs * R2 << "/" << R1 + R2 << " = "; //����ȭ�� ���� �̿��� �߰��� ���
		smaller(cut, Vout(Vs, R1, R2, RL, 0)); //smaller �Լ��� �̿��� �Ҽ��� �ݺ��� ó���� �� ����� ���
	}

	else //RL�� 0�� �ƴ� ��
	{
		ratio = (Vout(Vs, R1, R2, RL, 1) * R2) / (Vs * (R2 + RL)) * 100; //ratio ���� �� 100 ���ϱ�
		cout << "Vout: " << Vs * R2 * RL << "/" << ((R2 * RL) + R1 * (R2 + RL)) << " = "; //����ȭ�� ���� �̿��� �߰��� ���
		smaller(cut, Vout(Vs, R1, R2, RL, 1)); //smaller �Լ��� �̿��� �Ҽ��� �ݺ��� ó���� �� ����� ���
		cout << fixed;
		cout.precision(2); //�Ҽ��� ��°�ڸ����� ���
		cout << endl <<"Load power ratio: "<< ratio << "%"; //ratio ���

	}

}