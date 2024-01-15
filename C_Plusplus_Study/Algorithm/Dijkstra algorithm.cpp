//#include <iostream>
//#include <vector>
//#include <list>
//#include <stack>
//#include <queue>
//#include <map>
//using namespace std;
//
//// BFS 한계는 ?
//// 모든 간선이 동일 비용이라는 가정이 들어갔기 때문이다.
//// 지하철 노선도에서는 정거장 마다 걸리는 시간, 거리가 다 다르기 때문에 실제로 최단거리는 다르게 나올 수 있다.
//
//struct Vertex
//{
//	// int data;
//};
//
//vector<Vertex> vertices;
//vector<vector<int>> adjacent; // 인정 행렬
//
//void CreateGraph()
//{
//	vertices.resize(6);
//	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
//
//	adjacent[0][1] = 15;
//	adjacent[0][3] = 35;
//	
//	adjacent[1][0] = 15;
//	adjacent[1][2] = 5;
//	adjacent[1][3] = 10;
//
//	adjacent[3][4] = 5;
//	adjacent[5][4] = 5;
//}
//
//void Dijikstra(int here)
//{
//	//std::pair<int, int> vertexCost;
//	struct VertexCost
//	{
//		int vertex;
//		int cost;
//	};
//
//	list<VertexCost> discovered; // 발견 목록
//	vector<int> best(6, INT32_MAX); // 각 정점별로 지금까지 발견한 최소 거리
//	vector<int> parent(6, -1);
//
//	discovered.push_back(VertexCost{ here , 0 });
//	best[here] = 0;
//	parent[here] = here;
//
//	while (discovered.empty() == false)
//	{
//		// 제일 좋은 후보를 찾는다
//		list<VertexCost>::iterator bestIt;
//		int bestCost = INT32_MAX;
//
//		for (auto it = discovered.begin(); it != discovered.end(); it++)
//		{
//			const int cost = it->cost;
//
//			if (cost < bestCost)
//			{
//				bestCost = cost;
//				bestIt = it;
//			}
//		}
//
//		int cost = bestIt->cost;
//		here = bestIt->vertex;
//		discovered.erase(bestIt);
//
//		// 방문? 더 짧은 경로를 뒤늦게 찾았다면 스킵
//		if (best[here] < cost)
//			continue;
//
//		// 방문!
//		
//		for (int there = 0; there < 6; there++)
//		{
//			// 연결 되지 않았으면 스킵
//			if (adjacent[here][there] == -1)
//				continue;
//
//			// 더 좋은 경로를 과거에 찾았으면 스킵.
//			int nextCost = best[here] + adjacent[here][there];
//			if (nextCost >= best[there])
//				continue;
//
//			// (3, 35) (3, 25)
//			discovered.push_back(VertexCost{ there, nextCost });
//			best[there] = nextCost;
//			parent[there] = here;
//		}
//	}
//
//
//	int a = 03;
//}
//
//int main()
//{
//	CreateGraph();
//
//	Dijikstra(0);
//
//	return 0;
//}