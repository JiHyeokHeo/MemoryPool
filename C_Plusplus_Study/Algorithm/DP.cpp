//#include <iostream>
//#include <vector>
//#include <list>
//#include <stack>
//#include <queue>
//#include <Windows.h>
//using namespace std;
//
//// DP
//
//// 메모이제이션
//int cache[50][50];
//
//
//int combination(int n, int r)
//{
//	// 기저 사례
//	if (r == 0 || n == r)
//		return 1;
//
//	// 이미 답을 구한 적 있으면 바로 반환
//	if (cache[n][r] != -1)
//		return cache[n][r];
//
//	// 새로 답을 구해서 캐시에 저장
//	return cache[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
//}
//
//int main()
//{
//	::memset(cache, -1, sizeof(cache));
//
//	__int64 start = GetTickCount64();
//	int lotoo = combination(45, 6);
//	__int64 end = GetTickCount64();
//
//	cout << end - start << "ms" << endl;
//	return 0;
//}