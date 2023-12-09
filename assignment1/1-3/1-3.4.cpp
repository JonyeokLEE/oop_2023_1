#include <iostream> //iostream 선언
using namespace std; //namespace std 선언

void bubbleUp(int list[], int current, int last, int* countbubble)
{
	for (int walker = last; walker > current; walker--) //맨 끝에서부터 current 전까지 탐색
	{
		(*countbubble)++; //count 증가
		if (list[walker] < list[walker - 1]) //만약 walker 인덱스가 그 전꺼보다 작으면
		{
			int temp = list[walker];
			list[walker] = list[walker - 1];
			list[walker - 1] = temp; //상호교환
		}
	}
	return;
}
void bubbleSort(int list[], int last, int* countbubble) //bubbleSort 함수
{
	for (int current = 0; current < last; current++) //current가 맨 끝까지 갈 때까지
		bubbleUp(list, current, last, countbubble); //bubbleUp을 재귀적으로 반복
	return;
}

void insertOne(int list[], int current, int* countinsertion)
{
	bool located = false; //truefalse를 0으로 초기화
	int temp = list[current]; //삽입대상
	int walker;
	for(walker = current - 1; walker >= 0 && !located;) //walker가 0보다 작거나 located가 true가 되면 for문 종료
	{	
		(*countinsertion)++; //count 증가
		if (temp < list[walker]) //current 인덱스를 복사한 temp가 walker 인덱스의 요소보다 작으면
		{
			list[walker + 1] = list[walker]; //오른쪽으로 한칸씩 밀기
			walker--; //walker 감소
		}
		else located = true; //그 외의 경우 located에 true 할당
	}
	list[walker + 1] = temp; //list[walker+1]에 temp 복사
	return;
}

void insertionSort(int list[], int last, int* countinsertion) //삽입정렬 시작
{
	for (int current = 1; current <= last; current++) //current가 맨끝까지 갈 때까지
		insertOne(list, current, countinsertion); //insertOne을 재귀적으로 반복
	return;
}

void mergeOne(int list[],int list2[], int first, int last, int* countmerge)
{
	int center = (first + last) / 2; //배열 처음과 끝 사이 중간을 center로
	int a = first, b = center + 1, c = first; //a와 b는 병합할 두 배열의 시작점, c는 정렬된 배열의 시작을 가르키기 위한 초기화

	while (((a <= center) && (b <= last))) //두 하위 배열중 하나가 처리가 끝나면
	{
		(*countmerge)++; //count 증가
		if (list[a] <= list[b]) //두 인덱스 중 더 a가 더 작으면
		{
			list2[c] = list[a]; //list2에 a를 집어넣기
			a++;
			c++; //둘 다 증가
		}
		else //b가 더 작으면
		{
			list2[c] = list[b]; //list2에 b를 집어넣기
			b++;
			c++; //둘 다 증가
		}
	}
	
	if (a > center) //만약 a 쪽 배열이 먼저 처리가 끝난거라면
	{
		for (int i = b; i <= last; i++)
		{
			list2[c] = list[i];
			c++;
		} //b쪽 배열을 나머지로 복사
	}
	else //b쪽 배열이 먼저 처리가 끝난거라면
	{
		for (int i = a; i <= center; i++)
		{

			list2[c] = list[i];
			c++;
		} //a쪽 배열을 나머지로 복사
	}
	for (int i = first; i <= last; i++) //list에 list2를 복사한다.
		list[i] = list2[i];

	return;
}


void mergesort(int list[],int list2[], int first, int last, int* countmerge)
{
	if (first == last) //분할된 배열의 요소가 하나가 되면 함수 종료
		return;

	int center = (first + last) / 2;
	mergesort(list,list2, first, center, countmerge);
	mergesort(list,list2, center + 1, last, countmerge); //center를 기준으로 나누어서 재귀적으로 호출
	mergeOne(list, list2, first, last, countmerge); //mergeOne을 호출
}


void quicksort(int list[], int first, int last, int* countquick)
{
	if (first >= last) return; //first가 last보다 크거나 같으면 배열의 길이가 1이므로 정렬이 완료되었다고 생각하고 함수 종료

	int findbig = first; //findbig에 first 값 넣기
	int findsmall = last; //findsmall에 last 값 넣기
	//즉 findbig은 정렬중인 하위배열의 첫번째 인덱스를, findbig은 마지막 인덱스를 가르킨다.

	int pivot = list[(first + last + 1) / 2]; //중간 요소를 피봇으로 설정
	while (findbig <= findsmall) //findbig이 findsmall과 서로 교차할때까지
	{
		(*countquick)++; //count 증가

		while (list[findbig] < pivot) //만약 피봇보다 findbig인덱스 값이 더 크거나 같을때까지
		{
			findbig++; //findbig 증가
		} //피봇보다 크거나 같은 값을 찾을때까지 findbig을 계속 증가시킨다

		while (list[findsmall] > pivot) //만약 피봇보다 findsmall인덱스 값이 더 작거나 같을때까지
		{
			findsmall--; //findsmall 감소
		} //피봇보다 작거나 같은 값을 찾을 때까지 findsmall을 감소시킨다

		if (findbig <= findsmall) //아직 서로 교차하지 않은 경우
		{
			int temp = list[findsmall];
			list[findsmall] = list[findbig];
			list[findbig] = temp; //findsmall과 findbig의 인덱스에 있는 값을 교환하고
			findbig++; //findbig은 증가
			findsmall--; //findsmall은 감소
		}
	}
	quicksort(list, first, findsmall, countquick); //원래 배열 시작~피봇 앞 : 피봇보다 작거나 같은 요소 포함
	quicksort(list, findbig, last, countquick); //피봇 뒤~원래 배열 마지막 : 피벗보다 크거나 같은 요소 포함

	return;
}

int main()
{
	int length = 0; //입력받을 숫자의 길이 (무조건 홀수)
	cout << "Input the number of numbers: ";
	cin >> length; //입력받기
	int* arr = new int[length]; //원본 배열
	int* arrbubble = new int[length];
	int* arrinsertion = new int[length];
	int* arrquick = new int[length];
	int* arrmerge = new int[length];
	int* arrmerge2 = new int[length]; //각 sort에 사용할 배열들까지 동적할당

	int countbubble = 0, countinsertion = 0, countquick = 0, countmerge = 0; //count 변수들 선언

	cout << "Input numbers: ";
	for (int i = 0; i < length; i++)
	{
		cin >> arr[i];
	} //원본 배열에 정렬할 숫자들 입력받기

	for (int i = 0; i < length; i++)
	{
		arrbubble[i] = arr[i];
		arrinsertion[i] = arr[i];
		arrquick[i] = arr[i];
		arrmerge[i] = arr[i];
	} //모든 배열에 원본 배열을 복사

	bubbleSort(arrbubble, length - 1, &countbubble); //버블정렬
	cout <<endl<< "Result of Bubble Sort: ";
	for (int i = 0; i < length; i++)
	{
		cout << arrbubble[i] << " ";
	} //결과 출력
	cout <<  endl << "Loop count of Bubble Sort: " << countbubble << endl << endl; //몇 번 반복했는지 출력

	insertionSort(arrinsertion, length-1, &countinsertion); //삽입정렬
	cout << "Result of Insertion Sort: ";
	for (int i = 0; i < length; i++)
	{
		cout << arrinsertion[i] << " ";
	} //결과 출력
	cout << endl << "Loop count of Insertion Sort: " << countinsertion << endl << endl; //몇 번 반복했는지 출력

	mergesort(arrmerge, arrmerge2,0, length - 1, &countmerge); //병합정렬
	cout << "Result of Merge Sort: ";
	for (int i = 0; i < length; i++)
	{
		cout << arrmerge[i] << " ";
	} //결과 출력
	cout << endl << "Loop count of Merge Sort: " << countmerge << endl << endl; //몇 번 반복했는지 출력

	quicksort(arrquick, 0, length - 1, &countquick); //퀵 정렬
	cout << "Result of Quick Sort: ";
	for (int i = 0; i < length; i++)
	{
		cout << arrquick[i] << " ";
	} //결과 출력
	cout << endl << "Loop count of Quick Sort: " << countquick << endl << endl; //몇 번 반복했는지 출력

	cout << "Median Number: " << arrquick[(length) / 2] << endl; //중간 수 출력

	delete[] arr;
	delete[] arrbubble;
	delete[] arrinsertion;
	delete[] arrquick;
	delete[] arrmerge;
	delete[] arrmerge2; //동적할당 해제
	return 0; //0의 반환
}