//#include <iostream>
//
//using namespace std;
//
//// ������ ������
//
//// 1) ������ vs �迭 2ź
//// 2) ���ǻ��� (��������?)
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
//	// ���� ���� (2���� �迭 vs ���� ������)
//
//	// [1][2][3][4]
//	int arr2[2][2] = { {1,2}, {3,4} };
//
//	// �ּ�2[ ] << 4����Ʈ
//	// �ּ�1 [ �ּ�2 ]
//	// pp[ �ּ�1 ]
//
//	// TYPE name[����]
//
//	// ���������� �� �ʿ�� ����.
//	// [1] [2]
//	// [ �ּ� ]
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
//	// [�Ű�����][RET][��������] [�Ű�����][RET][��������(a)]
//	int* pointer = TestPointer();
//
//	TestWrong(pointer);
//	cout << *pointer << endl;
//
//	return 0;
//}