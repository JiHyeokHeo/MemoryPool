#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

// stl 연습

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// Q1) number라는 숫자가 벡터에 체크하는 기능 (bool, 첫 등장 iterator)
	{
		int number = 50;

		bool found = false;
		vector<int>::iterator it;

		for (it = v.begin(); it != v.end(); ++it)
		{
			int& data = *it;
			if (data == number)
			{
				found = true;
				break;
			}
		}
		cout << *it << endl;
		// TODO
	}

	// Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능(bool, 첫 등장 iterator)
	{
		bool found = false;
		vector<int>::iterator it;

		for (it = v.begin(); it != v.end(); ++it)
		{
			if ((*it) % 11 == 0)
			{
				found = true;
				break;
			}
		}
		cout << *it << endl;
	}

	// Q3) 홀수인 숫자의 개수는? (count)
	{
		int count = 0;

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] % 2 == 1)
				++count;
		}
	}

	// Q4 벡터에 들어가 있는 모든 숫자들에 3을 곱해주세요!
	{
		for (int i = 0; i < v.size(); i++)
		{
			v[i] = v[i] * 3;
		}
	}



	return 0;
}