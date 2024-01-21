#include <stdio.h>
#include <list>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;


int main(void)
{
	int row = 0;
	int col = 0;
	int sum = 0;

	int arr[10][10] = {};

	scanf_s("%d %d", &row, &col);

	// 3 4
	// 4 2 6 3
	// 7 9 3 4
	// 5 1 2 1

	for (int i = 0; i < row; i++)
	{
		int tempIdx = 1;
		for (int j = 0; j < col; j++)
		{
			scanf_s("%d", &arr[i][j]);

			if (j == tempIdx)
			{
				arr[i][0] += arr[i][tempIdx];
				tempIdx++;
			}
		}
	}

	for (int i = 0; i < row; i++)
	{
		printf("%d\n", arr[i][0]);
	}

	return 0;
}