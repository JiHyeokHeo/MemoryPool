//#include <iostream>
//#include <vector>
//#include <list>
//#include <stack>
//#include <queue>
//using namespace std;
//#include <thread>
//
//// 정렬
//
//// -> A* OpenList (PQ) 
//// -> C# List = c++ vector
//
//// PQ 0(logN)
//// Red-Black Tree O(logN)
//// Sorting ?
//
//// [3][J][5][K][9]
//// [3][J][5][K][9]
//
//
//// 1) 버블 정렬
//void BubbleSort(vector<int>& v)
//{
//	const int n = v.size();
//
//	// (N-1) + (N-2) + ..... 2 + 1
//	// 등차수열의 합  = N * (N-1) / 2
//	// O(N^2)
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (v[j] > v[j + 1])
//			{
//				int temp = v[j];
//				v[j] = v[j + 1];
//				v[j + 1] = temp;
//			}
//		}
//	}
//}
//
//// 2) 선택 정렬
//
//// [3][J][5][K][9]
//
//void SelectionSort(vector<int>& v)
//{
//	const int n = v.size();
//	// O(N^2)
//	for (int i = 0; i < n - 1; i++)
//	{
//		int bestIdx = i;
//		for (int j = i + 1; j < n; j++)
//		{
//			if (v[j] < v[bestIdx])
//				bestIdx = j;
//		}
//
//		int temp = v[i];
//		v[i] = v[bestIdx];
//		v[bestIdx] = temp;
//	}
//}
//
//// 3) 삽입 정렬
//// [3]
//// [5][9][J][3] [K]
//// 
////vector<int> v{ 5, 4, 1, 3, 2 };
//void InsertionSort(vector<int>& v)
//{
//	const int n = v.size();
//	// O(N^2)
//	for (int i = 1; i < n; i++)
//	{
//		int insertData = v[i];
//
//		int j;
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (v[j] > insertData)
//				v[j + 1] = v[j];
//			else
//				break;
//		}
//
//		v[j + 1] = insertData;
//	}
//}
//
//// 힙 정렬
//void HeapSort(vector<int>& v)
//{
//	priority_queue<int, vector<int>, greater<int>> pq;
//
//	// O(NlogN)
//	for (int num : v)
//		pq.push(num);
//
//	v.clear();
//	// O(NlogN)
//	while (pq.empty() == false)
//	{
//		v.push_back(pq.top());
//		pq.pop();
//	}
//}
//
//// 병합 정렬
//// 분할 정복 (Divide and Conquer)
//// - 분할 (Divide)		문제를 더 단순하게 분할한다
//// - 정복 (Conquer)		분할된 문제를 해결
//// - 결합 (Combine)		결과를 취합하여 마무리
//
//// [3][K][7][2][J][4][8][9]			8개 * 1
//// [3][K][7][2] [J][4][8][9]		4개 * 2
//// [3][K] [7][2] [J][4] [8][9]		2개 * 4
//// [3] [K] [7] [2] [J] [4] [8] [9]	1개 * 8
//// [2][3][7][K] [4][8][9][J]
////vector<int> v1{ 1, 2, 7, 8, 20 };
////vector<int> v2{ 3, 4, 6, 9, 10 };
////vector<int> Merge(vector<int> a, vector<int> b)
////{
////	vector<int> temp;
////
////	int leftVecIdx = 0;
////	int leftMaxVecIdx = a.size() - 1;
////	int rightVecIdx = 0;
////	int rightMaxVecIdx = b.size() - 1;
////
////	while (leftVecIdx <= rightMaxVecIdx && rightVecIdx <= leftMaxVecIdx)
////	{
////		if (v1[leftVecIdx] <= v2[rightVecIdx])
////		{
////			temp.push_back(v1[leftVecIdx]);
////			leftVecIdx++;
////		}
////		else
////		{
////			temp.push_back(v2[rightVecIdx]);
////			rightVecIdx++;
////		}
////	}
////
////	if (leftVecIdx > rightMaxVecIdx)
////	{
////		while (rightVecIdx <= leftMaxVecIdx)
////		{
////			temp.push_back(v2[rightVecIdx]);
////			rightVecIdx++;
////		}
////	}
////	else
////	{
////		while (leftVecIdx <= rightMaxVecIdx)
////		{
////			temp.push_back(v1[leftVecIdx]);
////			leftVecIdx++;
////		}
////	}
////
////
////	return temp;
////}
////
////std::vector<int> Merge(std::vector<int> a, std::vector<int> b);
////
////std::vector<int> MergeSort(std::vector<int> arr)
////{
////    if (arr.size() <= 1) {
////        return arr;
////    }
////
////    int middle = arr.size() / 2;
////    std::vector<int> left(arr.begin(), arr.begin() + middle);
////    std::vector<int> right(arr.begin() + middle, arr.end());
////
////    left = MergeSort(left);
////    right = MergeSort(right);
////
////    return Merge(left, right);
////}
//
//std::vector<int> Merge(std::vector<int> a, std::vector<int> b)
//{
//    std::vector<int> temp;
//
//    int leftVecIdx = 0;
//    int leftMaxVecIdx = a.size() - 1;
//    int rightVecIdx = 0;
//    int rightMaxVecIdx = b.size() - 1;
//
//    while (leftVecIdx <= leftMaxVecIdx && rightVecIdx <= rightMaxVecIdx)
//    {
//        if (a[leftVecIdx] <= b[rightVecIdx])
//        {
//            temp.push_back(a[leftVecIdx]);
//            leftVecIdx++;
//        }
//        else
//        {
//            temp.push_back(b[rightVecIdx]);
//            rightVecIdx++;
//        }
//    }
//
//    while (leftVecIdx <= leftMaxVecIdx)
//    {
//        temp.push_back(a[leftVecIdx]);
//        leftVecIdx++;
//    }
//
//    while (rightVecIdx <= rightMaxVecIdx)
//    {
//        temp.push_back(b[rightVecIdx]);
//        rightVecIdx++;
//    }
//
//    return temp;
//}
//
//void MergeResult(vector<int>& v, int left, int mid, int right)
//{	
//	// [L]              [R]
//	// [2][3][7][K]     [4][8][9][J]
//
//	int leftIdx = left;
//	int rightIdx = mid + 1;
//
//	vector<int> temp;
//	
//	while (leftIdx <= mid && rightIdx <= right)
//	{
//		if (v[leftIdx] <= v[rightIdx])
//		{
//			temp.push_back(v[leftIdx]);
//			leftIdx++;
//		}
//		else
//		{
//			temp.push_back(v[rightIdx]);
//			rightIdx++;
//		}
//	}
//
//	if (leftIdx > mid)
//	{
//		while (rightIdx <= right)
//		{
//			temp.push_back(v[rightIdx]);
//			rightIdx++;
//		}
//	}
//	else
//	{
//		while (leftIdx <= mid)
//		{
//			temp.push_back(v[leftIdx]);
//			leftIdx++;
//		}
//	}
//
//	for (int i = 0; i < temp.size(); i++)
//		v[left + i] = temp[i];
//
//}
//
//void MergeSort(vector<int>& v, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	int mid = (left + right) / 2;
//	MergeSort(v, left, mid);
//	MergeSort(v, mid + 1, right);
//
//	MergeResult(v, left, mid, right);
//}
//
//// [5][1][3][7][9][2][4][6][8]
////  p 
////    low                  high
////vector<int> v{ 5, 4, 1, 3, 2 };
//int Partition(vector<int>& v, int left, int right)
//{
//	int pivot = v[left];
//	int low = left + 1;
//	int high = right;
//
//	while (low <= high)
//	{
//		while (low <= right && pivot >= v[low])
//			low++;
//
//		while (high >= left + 1 && pivot <= v[high])
//			high--;
//
//		if (low < high)
//			swap(v[low], v[high]);
//	}
//
//	swap(v[left], v[high]);
//	return high;
//}
//
//// O(N^2) < 최악
//// O(NlogN) < 평균
//void QuickSort(vector<int>& v, int left, int right)
//{
//	if (left > right)
//		return;
//
//	int pivot = Partition(v, left, right);
//	QuickSort(v, left, pivot - 1);
//	QuickSort(v, pivot + 1, right);
//
//}
//
//int main()
//{
//	vector<int> v{5, 4, 1, 3, 2};
//
//	//std::sort(v.begin(), v.end());
//
//	//BubbleSort(v);
//	//SelectionSort(v);
//	InsertionSort(v);
//	//HeapSort(v);
//
//	//MergeSort(v, 0, v.size() - 1);
//	//vector<int> result = Merge(v1, v2);
//
//	QuickSort(v, 0, v.size() - 1);
//	return 0;
//}