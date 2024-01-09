//#include <iostream>
//#include <vector>
//#include <list>
//#include <stack>
//using namespace std;
//
//// Stack (LIFO 후입 선출)
//
//// [1][2][3][4]
//// 되돌리기 기능 (게임 내에서 Ctrl + Z)
//
//// [1]<->[2]<->[3]
//
//template <typename T, typename Container = vector<T>>
//class Stack
//{
//public:
//	Stack() {};
//	~Stack() {};
//
//	void push(const T& value)
//	{
//		_container.push_back(value);
//	}
//
//	void pop()
//	{
//		_container.pop_back();
//	}
//
//	T& top()
//	{
//		return _container.back();
//	}
//
//	bool empty() { return _container.empty(); }
//
//
//	int size() { return _container.size(); }
//
//private:
//	Container _container;
//};
//
//
//int main()
//{
//	Stack<int> s;
//	Stack<int, list<int>> b;
//	// 삽입
//	s.push(1);
//	s.push(2);
//	s.push(3);
//
//	// 비었나?
//	while (s.empty() == false)
//	{
//		// 최상위 원소
//		int data = s.top();
//		// 최상위 원소 삭제
//		s.pop();
//		
//		cout << data << endl;
//	}
//
//	int size = s.size();
//}