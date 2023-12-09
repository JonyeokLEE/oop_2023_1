#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

#define IMG_HEIGHT 512
#define IMG_WIDTH 512

char* changename(char* str,int a)
{
	int count = 0;
	const char* horizon = "_horizontalflip.raw";
	const char* vertical = "_verticalflip.raw"; //�ڿ� �߰��� �̸���

	for (int i = 0; str[i] != '\0'; i++)
	{
		count++;
	}
	count -= 4;
	str[count] = '\0'; //�Է¹��� �̸� �� �� ".raw"�� ����� �۾�

	count = 0; //count �ٽ� �ʱ�ȭ
	if (a == 1) //�������ڰ� 1�̸�(horizontal flip)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			count++;
		} //���� ���ڿ� ������ ����
		for (int i = 0; horizon[i] !='\0'; i++)
		{
			str[count] = horizon[i];
			count++;
		} //�߰� ���ڿ� ���� ������ �ڿ� �߰�
		
	}

	else //�������ڰ� 1�� �ƴϸ�(vertical flip)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			count++;
		} //���� ���ڿ� ������ ����
		for (int i = 0; i < 20; i++)
		{
			str[count] = vertical[i];
			count++;
		} //�߰� ���ڿ� ���� ������ �ڿ� �߰�
	}

	str[count] = '\0'; //������ NULL���� �߰�
	return str; //�ٲ� str �ٽ� ��ȯ
}

uint8_t** memory_alloc2D(uint32_t height, uint32_t width) //Memory �Ҵ� ����
{
	uint8_t** ppMem2d = new uint8_t * [height];
	if (ppMem2d == 0)
		return 0;

	ppMem2d[0] = new uint8_t[height * width];
	if (ppMem2d[0] == 0)
	{
		delete[] ppMem2d;
		return 0;
	}

	for (int i = 1; i < height; i++)
		ppMem2d[i] = ppMem2d[i - 1] + width;
	return ppMem2d;
}
int memory_free2D(uint8_t** ppMemAllocated) //Memory ���� ����
{
	if (ppMemAllocated == 0)
		return -1;

	if (ppMemAllocated[0])
		delete[] ppMemAllocated[0];

	delete[] ppMemAllocated;
	return 0;
}

int main(void)
{
	FILE* Inputhorizontal = 0;
	FILE* Inputvertical = 0;
	FILE* Outputhorizontal = 0;
	FILE* Outputvertical = 0;
	uint8_t** horizontalBuffer = 0;
	uint8_t** verticalBuffer = 0; //Horizontal flip�� Vertical flip�� ���� �����ϱ� ���� �������� ���� �߰�
	cout << "Input file name: "; 
	char inputname[300] = { 0, };
	cin >> inputname; //���ϴ� ���ϸ� �Է¹ޱ�
	char inputname2[300] = { 0, };
	int null = 0;
	for (int i = 0; inputname[i] != '\0'; i++)
	{
		inputname2[i] = inputname[i];
		null++;
	}
	inputname2[null] = '\0'; //inputname2���� inputname ����
	char* IMG_NAME1 = inputname;
	char* IMG_NAME2 = inputname2;
	//�����ͷ� �ϳ��� ����Ű��
	
	//�Է����� ����
	Inputhorizontal = fopen(IMG_NAME1, "rb");
	Inputvertical = fopen(IMG_NAME2, "rb");

	//�޸� �Ҵ�
	horizontalBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);
	verticalBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);
	
	//���Ͽ��� �޸𸮷� ���� ���� �Է�
	for (int i = 0; i < IMG_HEIGHT; i++)
		fread((uint8_t*)horizontalBuffer[i], sizeof(uint8_t), IMG_WIDTH, Inputhorizontal);
	for (int i = 0; i < IMG_HEIGHT; i++)
		fread((uint8_t*)verticalBuffer[i], sizeof(uint8_t), IMG_WIDTH, Inputvertical);

	
	for (int i = 0; i < IMG_HEIGHT; i++) {
		for (int j = 0; j < IMG_WIDTH / 2; j++) {
			uint8_t temp = horizontalBuffer[i][j];
			horizontalBuffer[i][j] = horizontalBuffer[i][IMG_WIDTH - j - 1];
			horizontalBuffer[i][IMG_WIDTH - j - 1] = temp;
		}
	}
	for (int i = 0; i < IMG_HEIGHT / 2; i++) {
		for (int j = 0; j < IMG_WIDTH; j++) {
			uint8_t temp = verticalBuffer[i][j];
			verticalBuffer[i][j] = verticalBuffer[IMG_HEIGHT - i - 1][j];
			verticalBuffer[IMG_HEIGHT - i - 1][j] = temp;
		}
	}
	//swap ������� ���� ����, �������� ������

	//������ �̸��� �ٲٱ� ���� changename�� �����ϱ�
	IMG_NAME1 = changename(IMG_NAME1, 1);
	IMG_NAME2 = changename(IMG_NAME2, 2);

	//������� ����
	Outputhorizontal = fopen(IMG_NAME1, "wb");
	Outputvertical = fopen(IMG_NAME2, "wb");

	//������ ����
	for (int i = 0; i < IMG_HEIGHT; i++)
		fwrite((uint8_t*)horizontalBuffer[i], sizeof(uint8_t), IMG_WIDTH, Outputhorizontal);

	for (int i = 0; i < IMG_HEIGHT; i++)
		fwrite((uint8_t*)verticalBuffer[i], sizeof(uint8_t), IMG_WIDTH, Outputvertical);

	//�޸� ���� �� ���� �ݱ�
	memory_free2D(horizontalBuffer);
	memory_free2D(verticalBuffer);
	fclose(Inputvertical);
	fclose(Inputhorizontal);
	fclose(Outputvertical);
	fclose(Outputhorizontal);

	return 0;

}