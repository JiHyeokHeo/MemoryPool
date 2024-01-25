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
// �κ� ���� : �Ϻ�(0�� �̻�) ���ڸ� ����� ���� ����
// ex) 1 2 5
// ex) 1 9 5 7
// �� ���� �κ� ����
// ex) 1 2 5

// LIS : ���� �� [�� ���� �κ� ����]�� ����

vector<int> seq;
int cache[100];

int LIS(int pos)
{
	// ��������
	//if (pos == seq.size() - 1)
	//	return 1;

	// ĳ�� Ȯ��
	if (cache[pos] != -1)
		return cache[pos];

	// ���ϱ�

	// Seq : 1 9 2 5 7
	// 1 9 = 2
	// 1 2 5 7 = 4
	// 1 5 7 = 3
	// 1 7 = 2
	
	// �ּ� seq[pos]�� ������ 1���� ����
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