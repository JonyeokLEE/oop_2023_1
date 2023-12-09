#include <iostream> //iostream ����
using namespace std; //namespace std ����

void bubbleUp(int list[], int current, int last, int* countbubble)
{
	for (int walker = last; walker > current; walker--) //�� ���������� current ������ Ž��
	{
		(*countbubble)++; //count ����
		if (list[walker] < list[walker - 1]) //���� walker �ε����� �� �������� ������
		{
			int temp = list[walker];
			list[walker] = list[walker - 1];
			list[walker - 1] = temp; //��ȣ��ȯ
		}
	}
	return;
}
void bubbleSort(int list[], int last, int* countbubble) //bubbleSort �Լ�
{
	for (int current = 0; current < last; current++) //current�� �� ������ �� ������
		bubbleUp(list, current, last, countbubble); //bubbleUp�� ��������� �ݺ�
	return;
}

void insertOne(int list[], int current, int* countinsertion)
{
	bool located = false; //truefalse�� 0���� �ʱ�ȭ
	int temp = list[current]; //���Դ��
	int walker;
	for(walker = current - 1; walker >= 0 && !located;) //walker�� 0���� �۰ų� located�� true�� �Ǹ� for�� ����
	{	
		(*countinsertion)++; //count ����
		if (temp < list[walker]) //current �ε����� ������ temp�� walker �ε����� ��Һ��� ������
		{
			list[walker + 1] = list[walker]; //���������� ��ĭ�� �б�
			walker--; //walker ����
		}
		else located = true; //�� ���� ��� located�� true �Ҵ�
	}
	list[walker + 1] = temp; //list[walker+1]�� temp ����
	return;
}

void insertionSort(int list[], int last, int* countinsertion) //�������� ����
{
	for (int current = 1; current <= last; current++) //current�� �ǳ����� �� ������
		insertOne(list, current, countinsertion); //insertOne�� ��������� �ݺ�
	return;
}

void mergeOne(int list[],int list2[], int first, int last, int* countmerge)
{
	int center = (first + last) / 2; //�迭 ó���� �� ���� �߰��� center��
	int a = first, b = center + 1, c = first; //a�� b�� ������ �� �迭�� ������, c�� ���ĵ� �迭�� ������ ����Ű�� ���� �ʱ�ȭ

	while (((a <= center) && (b <= last))) //�� ���� �迭�� �ϳ��� ó���� ������
	{
		(*countmerge)++; //count ����
		if (list[a] <= list[b]) //�� �ε��� �� �� a�� �� ������
		{
			list2[c] = list[a]; //list2�� a�� ����ֱ�
			a++;
			c++; //�� �� ����
		}
		else //b�� �� ������
		{
			list2[c] = list[b]; //list2�� b�� ����ֱ�
			b++;
			c++; //�� �� ����
		}
	}
	
	if (a > center) //���� a �� �迭�� ���� ó���� �����Ŷ��
	{
		for (int i = b; i <= last; i++)
		{
			list2[c] = list[i];
			c++;
		} //b�� �迭�� �������� ����
	}
	else //b�� �迭�� ���� ó���� �����Ŷ��
	{
		for (int i = a; i <= center; i++)
		{

			list2[c] = list[i];
			c++;
		} //a�� �迭�� �������� ����
	}
	for (int i = first; i <= last; i++) //list�� list2�� �����Ѵ�.
		list[i] = list2[i];

	return;
}


void mergesort(int list[],int list2[], int first, int last, int* countmerge)
{
	if (first == last) //���ҵ� �迭�� ��Ұ� �ϳ��� �Ǹ� �Լ� ����
		return;

	int center = (first + last) / 2;
	mergesort(list,list2, first, center, countmerge);
	mergesort(list,list2, center + 1, last, countmerge); //center�� �������� ����� ��������� ȣ��
	mergeOne(list, list2, first, last, countmerge); //mergeOne�� ȣ��
}


void quicksort(int list[], int first, int last, int* countquick)
{
	if (first >= last) return; //first�� last���� ũ�ų� ������ �迭�� ���̰� 1�̹Ƿ� ������ �Ϸ�Ǿ��ٰ� �����ϰ� �Լ� ����

	int findbig = first; //findbig�� first �� �ֱ�
	int findsmall = last; //findsmall�� last �� �ֱ�
	//�� findbig�� �������� �����迭�� ù��° �ε�����, findbig�� ������ �ε����� ����Ų��.

	int pivot = list[(first + last + 1) / 2]; //�߰� ��Ҹ� �Ǻ����� ����
	while (findbig <= findsmall) //findbig�� findsmall�� ���� �����Ҷ�����
	{
		(*countquick)++; //count ����

		while (list[findbig] < pivot) //���� �Ǻ����� findbig�ε��� ���� �� ũ�ų� ����������
		{
			findbig++; //findbig ����
		} //�Ǻ����� ũ�ų� ���� ���� ã�������� findbig�� ��� ������Ų��

		while (list[findsmall] > pivot) //���� �Ǻ����� findsmall�ε��� ���� �� �۰ų� ����������
		{
			findsmall--; //findsmall ����
		} //�Ǻ����� �۰ų� ���� ���� ã�� ������ findsmall�� ���ҽ�Ų��

		if (findbig <= findsmall) //���� ���� �������� ���� ���
		{
			int temp = list[findsmall];
			list[findsmall] = list[findbig];
			list[findbig] = temp; //findsmall�� findbig�� �ε����� �ִ� ���� ��ȯ�ϰ�
			findbig++; //findbig�� ����
			findsmall--; //findsmall�� ����
		}
	}
	quicksort(list, first, findsmall, countquick); //���� �迭 ����~�Ǻ� �� : �Ǻ����� �۰ų� ���� ��� ����
	quicksort(list, findbig, last, countquick); //�Ǻ� ��~���� �迭 ������ : �ǹ����� ũ�ų� ���� ��� ����

	return;
}

int main()
{
	int length = 0; //�Է¹��� ������ ���� (������ Ȧ��)
	cout << "Input the number of numbers: ";
	cin >> length; //�Է¹ޱ�
	int* arr = new int[length]; //���� �迭
	int* arrbubble = new int[length];
	int* arrinsertion = new int[length];
	int* arrquick = new int[length];
	int* arrmerge = new int[length];
	int* arrmerge2 = new int[length]; //�� sort�� ����� �迭����� �����Ҵ�

	int countbubble = 0, countinsertion = 0, countquick = 0, countmerge = 0; //count ������ ����

	cout << "Input numbers: ";
	for (int i = 0; i < length; i++)
	{
		cin >> arr[i];
	} //���� �迭�� ������ ���ڵ� �Է¹ޱ�

	for (int i = 0; i < length; i++)
	{
		arrbubble[i] = arr[i];
		arrinsertion[i] = arr[i];
		arrquick[i] = arr[i];
		arrmerge[i] = arr[i];
	} //��� �迭�� ���� �迭�� ����

	bubbleSort(arrbubble, length - 1, &countbubble); //��������
	cout <<endl<< "Result of Bubble Sort: ";
	for (int i = 0; i < length; i++)
	{
		cout << arrbubble[i] << " ";
	} //��� ���
	cout <<  endl << "Loop count of Bubble Sort: " << countbubble << endl << endl; //�� �� �ݺ��ߴ��� ���

	insertionSort(arrinsertion, length-1, &countinsertion); //��������
	cout << "Result of Insertion Sort: ";
	for (int i = 0; i < length; i++)
	{
		cout << arrinsertion[i] << " ";
	} //��� ���
	cout << endl << "Loop count of Insertion Sort: " << countinsertion << endl << endl; //�� �� �ݺ��ߴ��� ���

	mergesort(arrmerge, arrmerge2,0, length - 1, &countmerge); //��������
	cout << "Result of Merge Sort: ";
	for (int i = 0; i < length; i++)
	{
		cout << arrmerge[i] << " ";
	} //��� ���
	cout << endl << "Loop count of Merge Sort: " << countmerge << endl << endl; //�� �� �ݺ��ߴ��� ���

	quicksort(arrquick, 0, length - 1, &countquick); //�� ����
	cout << "Result of Quick Sort: ";
	for (int i = 0; i < length; i++)
	{
		cout << arrquick[i] << " ";
	} //��� ���
	cout << endl << "Loop count of Quick Sort: " << countquick << endl << endl; //�� �� �ݺ��ߴ��� ���

	cout << "Median Number: " << arrquick[(length) / 2] << endl; //�߰� �� ���

	delete[] arr;
	delete[] arrbubble;
	delete[] arrinsertion;
	delete[] arrquick;
	delete[] arrmerge;
	delete[] arrmerge2; //�����Ҵ� ����
	return 0; //0�� ��ȯ
}