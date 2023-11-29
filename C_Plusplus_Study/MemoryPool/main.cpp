#include <iostream>
#include <chrono>
#include "MemoryPool.h"
using namespace std;

class Data
{
	// 4096 바이트
	// 동적 할당 데이터
	char _data[4096];
};

void NoPool()
{
	auto start = chrono::steady_clock::now();
	// 백만번 시도
	for (unsigned int i = 0; i < 1000000; i++)
	{
		// 로컬 메모리 할당 해제
		Data* p = new Data();
		delete p;
	}
	auto end = chrono::steady_clock::now();
	cout << "Elapsed Time NoPool = " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
}

// 정적으로 할당된 고정 데이터
char buf[4096]; // 간단한 메모리풀

class SharedData
{
public:
	 

	void* operator new(size_t uiSize)
	{
		// global memory
		return (void*)buf;
	}
	void operator delete(void* p)
	{
	}
};

void SimpleMemoryPool()
{
	auto start = chrono::steady_clock::now();
	// 백만번 시도
	for (unsigned int i = 0; i < 1000000; i++)
	{
		// 로컬 메모리 할당 해제
		SharedData* p = new SharedData();
		delete p;
	}
	auto end = chrono::steady_clock::now();
	cout << "Elapsed Time MemoryPool = " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
}

int main(void)
{
	cout << "Performance Test" << endl;
	cout << "WithoutPool" << endl;
	NoPool();
	cout << "WithPool" << endl;
	SimpleMemoryPool();

	//unsigned long ulUnitNum = 4;
	//unsigned long ulUnitSize= 32;
	
	

	return 0;
}