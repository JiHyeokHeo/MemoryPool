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
//vector<bool> discoverd;
//
//void CreateGraph()
//{
//	vertices.resize(6);
//	adjacent = vector<vector<int>>(6);
//
//	// ���� ����Ʈ
//	adjacent[0].push_back(1);
//	adjacent[0].push_back(3);
//	adjacent[1].push_back(0);
//	adjacent[1].push_back(2);
//	adjacent[1].push_back(3);
//	adjacent[3].push_back(4);
//	adjacent[5].push_back(4);
//
//	//// ���� ���
//	//adjacent = vector<vector<int>>
//	//{
//	//	{0,1,0,1,0,0},
//	//	{1,0,1,1,0,0},
//	//	{0,0,0,0,0,0},
//	//	{0,0,0,0,1,0},
//	//	{0,0,0,0,0,0},
//	//	{0,0,0,0,1,0},
//	//};
//}
//
//void BFS(int here)
//{
//	// ������ ���� �߰� �Ǿ�����?
//	vector<int> parent(6, -1);
//	// ���������� ��ŭ ������ �ִ���?
//	vector<int> distance(6, -1);
//
//	queue<int> q;
//	q.push(here);
//	discoverd[here] = true;
//	
//	parent[here] = here;
//	distance[here] = 0;
//
//	// 3  q[   , 2 ]
//
//	while (q.empty() == false)
//	{
//		here = q.front();
//		q.pop();
//
//		cout << "Visited : " << here << endl;
//
//		for (int there : adjacent[here])
//		{
//			if (discoverd[there])
//				continue;
//
//			q.push(there);
//			discoverd[there] = true;
//
//			parent[there] = here;
//			distance[there] = distance[here] + 1;
//		}
//	}
//
//	int a = 0;
//}
//
//void BFSAll()
//{
//	for (int i = 0; i < 6; i++)
//		if (discoverd[i] == false)
//			BFS(i);
//}
//
//int main()
//{
//	CreateGraph();
//
//	discoverd = vector<bool>(6, false);
//
//	BFS(0);
//	
//	return 0;
//}