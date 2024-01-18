#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> adjacent;
vector<bool> visited;
int computerCnt;
int connectCnt;

int result = 0;
void Find(int here)
{
	if (visited[here] == true)
		return;

	visited[here] = true;


	for (int there = 1; there <= computerCnt; there++)
	{
		if (visited[there] == true)
			continue;

		if (adjacent[here][there] == -1)
			continue;

		result++;
		Find(there);
	}

}

int main(void)
{
	cin >> computerCnt >> connectCnt;
	adjacent.assign(computerCnt + 1, vector<int>(computerCnt + 1, -1));
	visited.assign(computerCnt + 1, false);

	for (int i = 0; i < connectCnt; i++)
	{
		int tempCom1;
		int tempCom2;
		cin >> tempCom1 >> tempCom2;
		adjacent[tempCom1][tempCom2] = 1;
		adjacent[tempCom2][tempCom1] = 1;
	}

	Find(1);
	cout << result << endl;

	return 0;
}