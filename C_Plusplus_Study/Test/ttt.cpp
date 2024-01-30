#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <algorithm>
#include <basetsd.h>
using namespace std;

vector<string> split(string input, string delimiter)
{
	vector<string> ret;
	long long pos;
	string temp = " ";

	while ((pos = input.find(delimiter)) != string::npos)
	{
		temp = input.substr(0, pos);
		ret.push_back(temp);
		input.erase(0, pos + delimiter.length());
	}

	ret.push_back(input);
	return ret;
}

int main() 
{
	string test = "³ª´Â ¹ä¿À", d = " ";

	vector<string> answer = split(test, d);

	for (string i : answer)
	{
		cout << i << "\n";
	}

	

}
