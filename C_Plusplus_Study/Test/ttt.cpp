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

	vector<int> dp(N + 1);

	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	cout << dp[N] << endl;

	return 0;
}