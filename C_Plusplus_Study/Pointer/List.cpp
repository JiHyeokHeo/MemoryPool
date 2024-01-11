//#include <iostream>
//using namespace std;
//#include <list>
//
//// list
//
//// vector : 동적 배열
//// [      ]
//// 
//
//// Node [ data(4) next(4/8) ] 
//class Node
//{
//public:
//	Node*	_next;
//	Node*	_prev;
//	int		_data;
//};
//
//// 단일 / 이중 / 원형
//// list : 연결 리스트
//
//// [1]  ->  [2]  ->  [3]  ->  [4]  ->  [5]
//// [1]  <->  [2]  <->  [3]  <->  [4]  <->  [5]  <-> [ _Myhead : end() ] <->
//// [1]  <->  [2]  <->  [3]  <->  [4]  <->  [5]  <->
//
//int main()
//{
//	// list (연결 리스트)
//	// - list의 동작 원리
//	// - 중간 삽입/삭제 (GOOD / GOOD)
//	// - 처음/끝 삽입/삭제 (GOOD / GOOD)
//	// - 임의 접근 (i번째 데이터는 어디 있습니까?) (NO) li[3] 불가능
//
//	list<int> li;
//
//	list<int>::iterator itRemember;
//
//	for (int i = 0; i < 100; i++)
//	{
//		if (i == 50)
//		{
//			itRemember = li.insert(li.end(), i);
//		}
//		else
//		{
//			li.push_back(i);
//		}
//
//	}
//
//	//li.push_front(10);
//	int size = li.size();
//	//li.capacity(); // 없음
//
//	int first = li.front();
//	int last = li.back();
//
//	//li[3] = 10; // 없음
//
//	list<int>::iterator itBegin = li.begin();
//	list<int>::iterator itEnd = li.end();
//
//	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
//	{
//		cout << *it << endl;
//	}
//
//	//li.insert(itBegin, 100);
//	//li.erase(li.begin());
//	//li.pop_front();
//	//li.remove(10); // ! ! !
//
//	// * 임의 접근이 안된다
//	// * 중간 삽입/삭제 빠르다(?)
//
//	// 50번 인덱스에 있는 데이터를 삭제!
//	// 이건 엄청 비효율적
//	/*list<int>::iterator it = li.begin();
//	for (int i = 0; i < 50; i++)
//		++it;*/
//
//	// 미리 빼두고 삭제한다는게 빠르다는 것이다.
//	li.erase(itRemember);
//
//	return 0;
//}