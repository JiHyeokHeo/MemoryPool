#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <algorithm>
#include <basetsd.h>
using namespace std;

vector<int> arr = { 1,2,3 };

int main() 
{

	do
	{
		for (int i : arr)
			cout << i << " ";

		cout << "\n";
	} while (next_permutation(arr.begin(), arr.end()));


}
