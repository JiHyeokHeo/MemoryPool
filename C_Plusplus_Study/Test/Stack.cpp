//#include <iostream>
//#include <vector>
//#include <list>
//#include <stack>
//using namespace std;
//
//// Stack (LIFO ���� ����)
//
//// [1][2][3][4]
//// �ǵ����� ��� (���� ������ Ctrl + Z)
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
//	// ����
//	s.push(1);
//	s.push(2);
//	s.push(3);
//
//	// �����?
//	while (s.empty() == false)
//	{
//		// �ֻ��� ����
//		int data = s.top();
//		// �ֻ��� ���� ����
//		s.pop();
//		
//		cout << data << endl;
//	}
//
//	int size = s.size();
//}