//#include <iostream>
//using namespace std;
//#include <vector>
//#include <list>
//#include <deque>
//#include <map>
//#include <set>
//
//// stl ���� / �˰���
//#include <algorithm>
//
//int main()
//{
//	// �ڷᱸ�� (�����͸� �����ϴ� ����)
//	// �˰��� (�����͸� ��� ����� ���ΰ�?)
//
//	// find
//	// find_if
//	// count
//	// count_if
//	// all_of
//	// any_of
//	// none_of
//	// for_each
//	// remove
//	// remove_if
//
//	srand(static_cast<unsigned int>(time(nullptr)));
//
//	vector<int> v;
//
//	for (int i = 0; i < 100; i++)
//	{
//		int num = rand() % 100;
//		v.push_back(num);
//	}
//
//	// Q1) number��� ���ڰ� ���Ϳ� üũ�ϴ� ��� (bool, ù ���� iterator)
//	{
//		int number = 50;
//
//		bool found = false;
//		vector<int>::iterator it;
//
//		for (it = v.begin(); it != v.end(); ++it)
//		{
//			int data = *it;
//			if (data == number)
//			{
//				found = true;
//				break;
//			}
//		}
//
//		vector<int>::iterator itFind = find(v.begin(), v.end(), number);
//		if (itFind == v.end())
//		{
//			// ��ã����
//			cout << "��ã����" << endl;
//		}
//		else
//		{
//			cout << "ã����" << endl;
//		}
//	}
//
//	
//
//	// Q2) 11�� ������ ���ڰ� ���Ϳ� �ִ��� üũ�ϴ� ���(bool, ù ���� iterator)
//	{
//		bool found = false;
//		vector<int>::iterator it;
//
//		for (it = v.begin(); it != v.end(); ++it)
//		{
//			if ((*it) % 11 == 0)
//			{
//				found = true;
//				break;
//			}
//		}
//
//		struct CanDivideBy11
//		{
//			bool operator()(int n)
//			{
//				return (n % 11) == 0;
//			}
//		};
//
//		vector<int>::iterator itFind = find_if(v.begin(), v.end(), [](int n) {return (n % 11) == 0; });
//		if (itFind == v.end())
//		{
//			// ��ã����
//			cout << "��ã����" << endl;
//		}
//		else
//		{
//			cout << "ã����" << endl;
//		}
//	}
//
//	// Q3) Ȧ���� ������ ������? (count)
//	{
//		int count = 0;
//
//		for (int i = 0; i < v.size(); i++)
//		{
//			if (v[i] % 2 == 1)
//				++count;
//		}
//
//		struct IsOdd
//		{
//			bool operator()(int n)
//			{
//				return (n % 2) != 0;
//			}
//		};
//
//		int n  = count_if(v.begin(), v.end(), IsOdd());
//
//		// ��� �����Ͱ� Ȧ���Դϱ�?
//		bool b1 = std::all_of(v.begin(), v.end(), IsOdd());
//		// Ȧ���� �����Ͱ� �ϳ��� �ֽ��ϱ�?
//		bool b2 = std::any_of(v.begin(), v.end(), IsOdd());
//		// ��� �����Ͱ� Ȧ���� �ƴմϱ�?
//		bool b3 = std::none_of(v.begin(), v.end(), IsOdd());
//	}
//
//	// Q4 ���Ϳ� �� �ִ� ��� ���ڵ鿡 3�� �����ּ���!
//	{
//		for (int i = 0; i < v.size(); i++)
//		{
//			v[i] = v[i] * 3;
//		}
//
//		struct MultiplyBy3
//		{
//			void operator()(int& n)
//			{
//				n = n * 3;
//			}
//		};
//
//		std::for_each(v.begin(), v.end(), MultiplyBy3());
//	}
//
//	// Ȧ���� �����͸� �ϰ� ����
//	{
//		v.clear();
//
//		v.push_back(1);
//		v.push_back(4);
//		v.push_back(3);
//		v.push_back(5);
//		v.push_back(8);
//		v.push_back(2);
//
//		// �� ��ĵ� ������ ���� �ʴ�
//		for (vector<int>::iterator it = v.begin(); it != v.end(); )
//		{
//			if (*it % 2 != 0)
//				it = v.erase(it);
//			else
//				++it;
//		}
//
//		// 1 4 3 5 8 2
//		// 4 8 2 5 8 2
//
//		// 4 8 2 5 8 2
//
//		//std::remove(v.begin(), v.end(), 4);
//		struct IsOdd
//		{
//			bool operator()(int n)
//			{
//				return (n % 2) != 0;
//			}
//		};
//
//		//vector<int>::iterator endIt = std::remove_if(v.begin(), v.end(), IsOdd());
//		//v.erase(endIt, v.end());
//	}
//
//
//	return 0;
//}