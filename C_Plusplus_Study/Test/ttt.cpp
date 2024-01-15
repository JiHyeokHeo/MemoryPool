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
	// �湮������ �ǵ�����
	if (visited[here])
		return;

	visited[here] = true;
	cout << here << " ";

	for (int there = 1; there <= N; there++)
	{
		// ������ �ȵǾ������� �ѱ��
		if (adjacent[here][there] == -1)
			continue;

		// �湮�� ���Ѱ��� �˻�
		if (visited[there] == false)
			DFS(there);
	}

}

void BFS(int here)
{
	// ���� ����
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
			// ���� x �ѱ��
			if (adjacent2[here][there] == -1)
				continue;
			// ���� �̹� �߰ߵ� ���̶�� �ѱ��
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

	// BFS �ڷᱸ��
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