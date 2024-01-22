//#include <iostream>
//#include <vector>
//#include <list>
//#include <stack>
//#include <queue>
//using namespace std;
//
// // DFS (Depth First Search) ���� �켱 Ž��
// // BFS (Breadth First Search) �ʺ� �켱 Ž��
//
//struct Vertex
//{
//	// int data;
//};
//
//vector<Vertex> vertices;
//vector<vector<int>> adjacent;
//
//vector<bool> visited;
//void CreateGraph()
//{
//	vertices.resize(6);
//	adjacent = vector<vector<int>>(6);
//
//	//// ���� ����Ʈ
//	//adjacent[0].push_back(1);
//	//adjacent[0].push_back(3);
//	//adjacent[1].push_back(0);
//	//adjacent[1].push_back(2);
//	//adjacent[1].push_back(3);
//	//adjacent[3].push_back(4);
//	//adjacent[5].push_back(4);
//
//	// ���� ���
//	adjacent = vector<vector<int>>
//	{
//		{0,1,0,1,0,0},
//		{1,0,1,1,0,0},
//		{0,0,0,0,0,0},
//		{0,0,0,0,1,0},
//		{0,0,0,0,0,0},
//		{0,0,0,0,1,0},
//	};
//}
//
//void DFS(int here)
//{
//	// �湮!
//	visited[here] = true;
//	cout << "Visited : " << here << endl;
//
//	//// ���� ����Ʈ version
//	//// ��� ���� ������ ��ȸ�Ѵ�.
//	//for(int i =0; i< adjacent[here].size(); i++)
//	//{
//	//	int there = adjacent[here][i];
//	//	if (visited[there] == false)
//	//		DFS(there);
//	//}
//
//	// ���� ��� version
//	// ��� ���� ������ ��ȸ�Ѵ�.
//	for (int there = 0; there < 6; there++)
//	{
//		if (adjacent[here][there] == 0)
//			continue;
//
//		// ���� �湮���� �ʴ� ���� ������ �湮�Ѵ�
//		if (visited[there] == false)
//			DFS(there);
//	}
//}
//
//void DFSAll()
//{
//	visited = vector<bool>(6, false);
//
//	for (int i = 0; i < 6; i++)
//	{
//		if (visited[i] == false)
//			DFS(i);
//	}
//}
//
//int main()
//{
//	CreateGraph();
//
//	//visited = vector<bool>(6, false);
//
//	//DFS(0);
//
//	DFSAll();
//	return 0;
//}