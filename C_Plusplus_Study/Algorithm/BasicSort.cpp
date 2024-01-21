#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
#include <thread>

// 정렬

// -> A* OpenList (PQ) 
// -> C# List = c++ vector

// PQ 0(logN)
// Red-Black Tree O(logN)
// Sorting ?

// [3][J][5][K][9]
// [3][J][5][K][9]


// 1) 버블 정렬
void BubbleSort(vector<int>& v)
{
	const int n = v.size();

	// (N-1) + (N-2) + ..... 2 + 1
	// 등차수열의 합  = N * (N-1) / 2
	// O(N^2)
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

// 2) 선택 정렬

// [3][J][5][K][9]

void SelectionSort(vector<int>& v)
{
	const int n = v.size();
	// O(N^2)
	for (int i = 0; i < n - 1; i++)
	{
		int bestIdx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[bestIdx])
				bestIdx = j;
		}

		int temp = v[i];
		v[i] = v[bestIdx];
		v[bestIdx] = temp;
	}
}

// 3) 삽입 정렬
// [3]
// [5][9][J][3] [K]
// 

void InsertionSort(vector<int>& v)
{
	const int n = v.size();
	// O(N^2)
	for (int i = 1; i < n; i++)
	{
		int insertData = v[i];

		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (v[j] > insertData)
				v[j + 1] = v[j];
			else
				break;
		}

		v[j + 1] = insertData;
	}
}

int main()
{
	vector<int> v{5, 4, 1, 3, 2};

	//std::sort(v.begin(), v.end());

	//SelectionSort(v);
	InsertionSort(v);


	return 0;
}