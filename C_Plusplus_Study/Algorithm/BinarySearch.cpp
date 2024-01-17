//#include <iostream>
//#include <vector>
//#include <list>
//#include <stack>
//#include <queue>
//using namespace std;
//
//// 이진 탐색 트리 면접 단골문제 !
//
//// Binary search
//// 상황) 배열에 데이터가 정렬되어 있다.
//
//// Q) 82라는 숫자가 배열에 있습니까?
//// A) 
//// [1][8][15][23][32][44][56][63][81][91]
//
//// 업다운 게임
//// 81
//
//vector<int> numbers;
//
//void T(int N)
//{
//	int maxIndex = numbers.size() - 1;
//	
//	int firstIdx = 0;
//	int endIdx = maxIndex;
//	while (firstIdx <= endIdx)
//	{
//		cout << "탐색범위 :" << firstIdx << "~" << endIdx << endl;
//		int compareIndex = (firstIdx + endIdx) / 2;
//
//		// 중간값이 목표값보다 크다면?
//		if (numbers[compareIndex] > N)
//		{
//			cout << N << ">" << numbers[compareIndex] << endl;
//			endIdx = compareIndex - 1;
//		}
//		else if(numbers[compareIndex] < N)
//		{
//			cout << N << "<" << numbers[compareIndex] << endl;
//			firstIdx = compareIndex + 1;
//		}
//		else
//		{
//			cout << "발견" << endl;
//			return;
//		}
//	}
//
//	cout << "미발견" << endl;
//}
//
//int main()
//{
//	numbers = vector<int>{ 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
//	T(82);
//
//	return 0;
//}