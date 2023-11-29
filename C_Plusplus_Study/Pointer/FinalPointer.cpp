//#include <iostream>
//
//using namespace std;
//
//// 포인터 마무리
//
//// 1) 포인터 vs 배열 2탄
//// 2) 주의사항 (마음가짐?)
//
//int& TestRef()
//{
//	int a = 1;
//	return a;
//}
//
//void TestWrong(int* ptr)
//{
//	int a[100] = {};
//	a[99] = 0xAAAAAAAA;
//	*ptr = 0x12341234;
//}
//
//int* TestPointer()
//{
//	int a = 1;
//	return &a;
//}
//
//int main()
//{
//	int* p;
//	int arr[10] = { 1,2,3,4,5,6,7,8 };
//
//
//	p = arr;
//	//cout << p[0] << endl;
//	//cout << arr[0] << endl;
//
//	//cout << *p << endl;
//	//cout << *arr << endl;
//	//cout << *(p + 3) << endl;
//	//cout << *(arr + 3) << endl;
//
//	// 지옥 시작 (2차원 배열 vs 다중 포인터)
//
//	// [1][2][3][4]
//	int arr2[2][2] = { {1,2}, {3,4} };
//
//	// 주소2[ ] << 4바이트
//	// 주소1 [ 주소2 ]
//	// pp[ 주소1 ]
//
//	// TYPE name[개수]
//
//	// 문법적으로 알 필요는 없다.
//	// [1] [2]
//	// [ 주소 ]
//	int(*p2)[2] = arr2;
//	cout << (*p2)[0] << endl;
//	cout << (*p2)[1] << endl;
//	cout << ((*(p2 + 1))[0]) << endl;
//	cout << ((*(p2 + 1))[1]) << endl;
//	
//	cout << p2[0][0] << endl;
//	cout << p2[0][1] << endl;
//	cout << p2[1][0] << endl;
//	cout << p2[1][1] << endl;
//
//
//	// [매개변수][RET][지역변수] [매개변수][RET][지역변수(a)]
//	int* pointer = TestPointer();
//
//	TestWrong(pointer);
//	cout << *pointer << endl;
//
//	return 0;
//}