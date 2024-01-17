#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector<int> value(N + 1, -1);
	vector<int> dp(N + 1, -1);
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		value[i] = temp;
	}

	int result = 0;
	
	// 0은 시작
	// 0->1
	dp[1] = value[1];
	// 0->2 or 0->1->2
	dp[2] = max(value[2], value[1] + value[2]);
	// 0->2->3 or 0->1->3
	dp[3] = max(value[2] + value[3], value[1] + value[3]);

	// 점화식으로 나타낸다면?
	// dp[4] ? -> 0-1-2-4 or 0-1-3-4 
	// dp[2] + value[4] or dp[1] + value[3] + value[4]; // 이 두녀석의 최대값을 비교
	for (int i = 4; i <= N; i++)
	{
		dp[i] = max(dp[i - 2] + value[i], dp[i - 3] + value[i - 1] + value[i]);
	}

	cout << dp[N];

	return 0;
}