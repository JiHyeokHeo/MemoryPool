//#include <iostream>
//using namespace std;
//
//// Ŭ���� ���ø�
//
//// typename T�� ���̸� '��Ŀī��' (� Ÿ�Ե� �� ���� �� ����)
//// �׷��� ������ typename�� �ٿ��� �ϴ� ���� �ƴϴ�.
//// template < > �ȿ� ���°� [������ �ϴ� ���]�̶�� �� �� ����.
//template<typename T, int SIZE = 10>
//class RandomBox
//{
//public:
//	T GetRandomData()
//	{
//		int idx = rand() % 10;
//		return _data[idx];
//	}
//
//public:
//	T _data[SIZE];
//};
//
//// ���ø� Ư��ȭ
//template<int SIZE>
//class RandomBox<double, SIZE>
//{
//public:
//	double GetRandomData()
//	{
//		cout << "RandomBox Double" << endl;
//		int idx = rand() % 10;
//		return _data[idx];
//	}
//
//public:
//	double _data[SIZE];
//};
//
//int main()
//{
//	srand(static_cast<unsigned int>(time(nullptr)));
//
//	RandomBox<int, 10> rb1;
//	for (int i = 0; i < 10; i++)
//	{
//		rb1._data[i] = i;
//	}
//	int value1 = rb1.GetRandomData();
//	cout << value1 << endl;
//
//	RandomBox<double, 20> rb2;
//	for (int i = 0; i < 20; i++)
//	{
//		rb2._data[i] = i * 0.5;
//	}
//	int value2 = rb2.GetRandomData();
//	cout << value2 << endl;
//
//	return 0;
//}