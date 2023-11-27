#include <iostream>
using namespace std;

// 연습 문제

// 문제1) 문자열 길이를 출력하는 함수
int StrLen(const char* str)
{
	// str이라는 문자열의 길이를 반환
	int cnt = 0;
	
	while (str[cnt] != '\0')
		cnt++;

	return cnt;
}

// 문제2) 문자열 복사 함수
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

char* StrCat(char* desti, const char* orig)
{
	int cnt = 0;
	while (desti[cnt] != '\0')
		cnt++;

	int origCnt = 0;
	while (orig[origCnt] != '\0')
	{
		desti[cnt] = orig[origCnt];
		origCnt++;
		cnt++;
	}

	desti[cnt] = '\0';

	return desti;
}

int StrCmp(char* a, char* b)
{
	int cnt = 0;

	while (a[cnt] != '\0' || b[cnt] != '\0')
	{
		if (a[cnt] > b[cnt])
			return 1;
		if(a[cnt] < b[cnt])
			return -1;
		cnt++;
	}
	
	return 0;
}

void ReverseStr(char* str)
{
	int cnt = 0;

	int len = StrLen(str);
	int idx = len - 1;
	while (str[cnt] != '\0')
	{
		if ((idx - cnt) == cnt)
			break;

		char temp;
		temp = str[cnt];
		str[cnt] = str[idx - cnt];
		str[idx - cnt] = temp;
		cnt++;
	}
}
#pragma warning(disable: 4996)

int main()
{
	const int BUF_SIZE = 100;

	// [H][e][l][l][o]['\0'][][][][][][][][][][][][][][][]
	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "aa";
	
	//int len = StrLen(a);
	//cout << len;

	//StrCpy(b, a);
	//StrCat(a, b);

	//StrCmp(a, b);
	ReverseStr(a);

	cout << a << endl;
	
	return 0;
}