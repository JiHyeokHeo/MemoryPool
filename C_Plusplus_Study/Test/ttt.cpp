#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adjacent;
vector<bool> discovered;

void CreateGraph()
{
	adjacent = vector<vector<int>>(6);

	//// 인접 리스트
	//adjacent[0].push_back(1);
	//adjacent[0].push_back(3);
	//adjacent[1].push_back(0);
	//adjacent[1].push_back(2);
	//adjacent[1].push_back(3);
	//adjacent[3].push_back(4);
	//adjacent[5].push_back(4);

	// 인접 행렬
	adjacent = vector<vector<int>>
	{
		{0,1,0,1,0,0},
		{1,0,1,1,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,1,0},
		{0,0,0,0,0,0},
		{0,0,0,0,1,0},
	};
}

void BFS(int here)
{
	// 너비 기반 탐색
	
	// FIFO 처음 들어온게 먼저 나가는 구조
	queue<int> track;
	track.push(here);
	discovered[here] = 1;

	while (track.empty() == false)
	{
		int data = track.front();
		cout << data << endl;
		for (int i = 0; i < 6; i++)
		{
			if (discovered[i] == true)
				continue;

			if (adjacent[data][i] == 1) 
			{
				discovered[i] = true;
				track.push(i);
			}
		}
		track.pop();
	}


}

int main(void)  
{
	CreateGraph();

	discovered = vector<bool>(6, false);

	BFS(0);

    return 0;
}