#include <iostream>
using namespace std;

// ���� ����

// ����1) ���ڿ� ���̸� ����ϴ� �Լ�
int StrLen(const char* str)
{
	// str�̶�� ���ڿ��� ���̸� ��ȯ
	int cnt = 0;
	
	while (str[cnt] != '\0')
		cnt++;

	return cnt;
}

// ����2) ���ڿ� ���� �Լ�
void StrCpy(char* desti, const char* orig)
{
	int cnt = 0;
	while (orig[cnt] != '\0')
	{
		desti[cnt] = orig[cnt];
		cnt++;
	}

	desti[cnt] = '\0';
}

char* StrCat(char* dest, char* src)
{

}

#pragma warning(disable: 4996)

int main()
{
	const int BUF_SIZE = 100;

	// [H][e][l][l][o]['\0'][][][][][][][][][][][][][][][]
	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "World";
	
	//int len = StrLen(a);
	//cout << len;

	strcat(a, b);

	int c = 0;
	return 0;
}