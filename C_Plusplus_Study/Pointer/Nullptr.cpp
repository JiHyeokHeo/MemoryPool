//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//
//// nullptr
//
//class Knight
//{
//public:
//	void Test()
//	{
//
//	}
//
//};
//
//Knight* FindKnight()
//{
//	// TODO
//
//	return nullptr;
//}
//
//
//void Test(int a)
//{
//	cout << "Test(int)" << endl;
//}
//
//void Test(void* ptr)
//{
//	cout << "Test(*)" << endl;
//}
//
//// NullPtr ����
//const
//class
//{
//public:
//	// �� � Ÿ���� �����Ϳ͵� ġȯ ����
//	template<typename T>
//	operator T* () const
//	{
//		return 0;
//	}
//
//	// �� �Ÿ���� ��� �����Ϳ͵� ġȯ����
//	template<typename C, typename T>
//	operator T C::* () const
//	{
//		return 0;
//	}
//
//private:
//	void operator&() const; // �ּҰ� &�� ���´�.
//} _NullPtr;
//
//int main()
//{
//	int* ptr = NULL; // 0 NULL
//
//	// 1) ������
//	Test(0);
//	Test(NULL);
//	Test(nullptr);
//	Test(_NullPtr);
//
//	// 2) ������
//	auto knight = FindKnight();
//
//	if (knight == _NullPtr)
//	{
//
//	}
//	void(Knight:: * memeFunc)();
//	memeFunc = &Knight::Test;
//
//	if (memeFunc == _NullPtr)
//	{
//
//	}
//
//	
//	//nullptr_t whoami = nullptr;
//
//	return 0;
//}