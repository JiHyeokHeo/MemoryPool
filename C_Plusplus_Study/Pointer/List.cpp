#include <iostream>
using namespace std;
#include <list>

// list

// vector : 동적 배열
// [      ]
// 

// Node [ data(4) next(4/8) ] 
class Node
{
public:
	Node*	_next;
	Node*	_prev;
	int		_data;
};

// 단일 / 이중 / 원형
// list : 연결 리스트

// [1]  ->  [2]  ->  [3]  ->  [4]  ->  [5]
// [1]  <->  [2]  <->  [3]  <->  [4]  <->  [5]
// [1]  <->  [2]  <->  [3]  <->  [4]  <->  [5]  <->

int main()
{
	// list (연결 리스트)
	// - list의 동작 원리
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	list<int> li;

	for (int i = 0; i < 100; i++)
		li.push_back(i);

	//li.push_front(10);
	int size = li.size();
	//li.capacity(); // 없음

	int first = li.front();
	int last = li.back();

	//li[3] = 10; // 없음

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);

	li.erase(li.begin());

	li.pop_front();

	li.remove(10); // ! ! !

	return 0;
}