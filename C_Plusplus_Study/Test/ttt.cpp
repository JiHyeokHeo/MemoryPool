#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
using namespace std;

// DFS
vector<vector<int>> adjacent;
vector<bool> visited;

// BFS
vector<vector<int>> adjacent2;
vector<bool> discovered;

int N, M, V;

void DFS(int here)
{
	// 방문했으면 되돌리고
	if (visited[here])
		return;

	visited[here] = true;
	cout << here << " ";

	for (int there = 1; there <= N; there++)
	{
		// 연결이 안되어있으면 넘기고
		if (adjacent[here][there] == -1)
			continue;

		// 방문을 안한곳만 검색
		if (visited[there] == false)
			DFS(there);
	}

}

void BFS(int here)
{
	// 선입 선출
	queue<int> q;

	q.push(here);
	discovered[here] = true;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		cout << here << " ";
		for (int there = 1; there <= N; there++)
		{
			// 연결 x 넘기기
			if (adjacent2[here][there] == -1)
				continue;
			// 만약 이미 발견된 곳이라면 넘기기
			if (discovered[there] == true)
				continue;

			q.push(there);
			discovered[there] = true;
		}

	}

}

int main(void)
{
	cin >> N >> M >> V;

	// DFS
	adjacent = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
	visited = vector<bool>(N + 1, false);

	// BFS 자료구조
	adjacent2 = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
	discovered = vector<bool>(N + 1, false);
	for (int i = 0; i < M; i++)
	{
		int tempY;
		int tempX;
		cin >> tempY >> tempX;
		adjacent[tempY][tempX] = 1;
		adjacent[tempX][tempY] = 1;
		adjacent2[tempY][tempX] = 1;
		adjacent2[tempX][tempY] = 1;
	}

	DFS(V);
	cout << endl;
	BFS(V);

	return 0;
}