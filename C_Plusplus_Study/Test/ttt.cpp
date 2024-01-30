#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <algorithm>
#include <basetsd.h>
using namespace std;

int arr[3] = { 1,2,3 };
int n = 3, r = 3;

void print()
{
	for (int i : arr)
		cout << i << " ";
	cout << "\n";
}

void permutation(int n, int r, int depth)
{
	if (r == depth)
	{
		print();
		return;
	}

	for (int i = depth; i < n; i++)
	{
		swap(arr[i], arr[depth]);
		permutation(n, r, depth + 1);
		swap(arr[i], arr[depth]);
	}
}

int main() 
{
	permutation(n, r, 0);
}
