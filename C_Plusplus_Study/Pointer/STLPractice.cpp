#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

// stl ����

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// Q1) number��� ���ڰ� ���Ϳ� üũ�ϴ� ��� (bool, ù ���� iterator)
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

	// Q2) 11�� ������ ���ڰ� ���Ϳ� �ִ��� üũ�ϴ� ���(bool, ù ���� iterator)
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

	// Q3) Ȧ���� ������ ������? (count)
	{
		int count = 0;

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] % 2 == 1)
				++count;
		}
	}

	// Q4 ���Ϳ� �� �ִ� ��� ���ڵ鿡 3�� �����ּ���!
	{
		for (int i = 0; i < v.size(); i++)
		{
			v[i] = v[i] * 3;
		}
	}



	return 0;
}