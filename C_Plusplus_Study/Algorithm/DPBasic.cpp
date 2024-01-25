#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <Windows.h>
//#include <algorithm>
using namespace std;


// LIS (Longest Increasing Sequence)

// Seq : 1 9 2 5 7
// 부분 수열 : 일부(0개 이상) 숫자를 지우고 남은 수열
// ex) 1 2 5
// ex) 1 9 5 7
// 순 증가 부분 수열
// ex) 1 2 5

// LIS : 제일 긴 [순 증가 부분 수열]의 길이

vector<int> seq;
int cache[100];

int LIS(int pos)
{
	// 기저사항
	//if (pos == seq.size() - 1)
	//	return 1;

	// 캐시 확인
	if (cache[pos] != -1)
		return cache[pos];

	// 구하기

	// Seq : 1 9 2 5 7
	// 1 9 = 2
	// 1 2 5 7 = 4
	// 1 5 7 = 3
	// 1 7 = 2
	
	// 최소 seq[pos]는 있으니 1부터 시작
	cache[pos] = 1;

	for (int next = pos + 1; next < seq.size(); next++)
	{
		if (seq[pos] < seq[next])
			cache[pos] = max(cache[pos], 1 + LIS(next));
	}

	return cache[pos];
}

int main()
{
	::memset(cache, -1, sizeof(cache));
	seq = vector<int>{ 1,9,2,5,7 };

	int ret = 0;
	for (int pos = 0; pos < seq.size(); pos++)
	{
		ret = max(ret, LIS(pos));
	}
	return 0;
}