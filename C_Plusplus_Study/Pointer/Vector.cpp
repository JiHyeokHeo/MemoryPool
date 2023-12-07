#include <iostream>
#include <vector>
using namespace std;

// vector

int main()
{
	// STL (Standard Template Library)
	// 프로그래밍할 때 필요한 자료구조/알고리즘들을
	// 템플릿으로 제공하는 라이브러리
	
	// 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)
	
	// 면접에선 주로 원리에 대한 질문이 나온다
	// vector (동적 배열) C# 에선 list
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입 삭제
	// - 임의 접근

	// 동적 배열
	// 매우 매우 중요한 개념 -> 어떤 마법을 부렸길래 배열을 '유동적으로' 사용한 것인가?

	//************* 중요********************
	// 1) (여유분을 두고) 메모리를 할당한다
	// 2) 여유분까지 꽉 찼으면, 메모리를 증설한다

	// Q1) 여유분은 얼만큼이 적당할까?
	// Q2) 증설을 얼만큼 해야 할까?
	// Q3) 기존의 데이터를 어떻게 처리할까?
	
	// [ 1 2 3 4 5 ]             // 미리 증설을 해두면 복사를 덜 해도 된다.
	// [ 1 2 3 4 5             ] // 이사비용 코스트가 쎄다.
	//int arr[100];

	//vector<int> v(1000, 0);
	//vector<int> v2 = v;

	//// [                   ]
	////v.resize(1000);
	//// size (실제 사용 데이터 개수)
	//// 1 2 3 4 5 6 7...
	// 
	////v.reserve(1000);
	//// reserve 사용시 1000부터 시작
	//// capacity (여유분을 포함한 용량 개수)
	//// 1 2 3 4 6 9 13 19 28 42 63 // 대략 1.5배 or 2배 (컴파일러 마음)


	//for (int i = 0; i < 1000; i++)
	//{
	//	v.push_back(100);
	//	cout << v.size() << " " << v.capacity() << endl;
	//}


	//v.front();
	//v.back();
	//v.pop_back();

	//v.clear();
	//vector<int>().swap(v); // 실 업무에서는 잘 안쓰인다. capacity 날리는 방식
	//cout << v.size() << " " << v.capacity() << endl;

	
	// ***************************************************************************
	// 중간 삽입 삭제
	// 반복자(iterator) : 포인터와 유사한 개념, 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로 이동가능
	vector<int> v(10);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		v[i] = i;

	vector<int>::iterator it;
	int* ptr;

	it = v.begin();
	ptr = &v[0];
	
	//cout << (*it) << endl;
	//cout << (*ptr) << endl;

	ptr++;
	++ptr;

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd= v.end();

	// 미세하게 ++it이 성능이 좋다. (참조 연산으로 인해)
	// 더 복잡해보이는데? 왜 쓰이는걸까?
	// iterator는 vector뿐 아니라, 다른 컨테이너에도 공통적으로 있는 개념
	// 다른 컨테이너로 옮기기가 편해진다.
	// 다른 컨테이너는 v[i]와 같은 인덱스 접근이 안 될 수도 있음
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}

	int* ptrBegin = &v[0]; // v.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10; // v.end()._Ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
	{
		cout << (*ptr) << endl;
	}

	// const int*;
	vector<int>::const_iterator cit1 = v.cbegin();
	//*cit1 = 100;

	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	{
		cout << (*it) << endl;
	}

	return 0;
}