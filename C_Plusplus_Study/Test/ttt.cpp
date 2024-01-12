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

	//// ���� ����Ʈ
	//adjacent[0].push_back(1);
	//adjacent[0].push_back(3);
	//adjacent[1].push_back(0);
	//adjacent[1].push_back(2);
	//adjacent[1].push_back(3);
	//adjacent[3].push_back(4);
	//adjacent[5].push_back(4);

	// ���� ���
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
	// �ʺ� ��� Ž��
	
	// FIFO ó�� ���°� ���� ������ ����
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