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

int n = 3, k = 2;

void print(vector<int> b)
{
	for (int i : b)
		cout << i << " ";
	cout << "\n";
}

void combi(int start, vector<int> b)
{
	if (b.size() == k)
	{
		print(b);
		return;
	}

	for (int i = start + 1; i < n; i++)
	{
		b.push_back(arr[i]);
		combi(i, b);
		b.pop_back();
	}
}

int main() 
{
	vector<int> b;

	combi(-1, b);
}
