//#include <iostream>
//using namespace std;
//
//// �Լ�������
//
//// typedef�� ����
//// typedef ���� ������ -> ������ (Ŀ���� Ÿ�� ����)
//
//// ��Ȯ���� ����/������ ������ �ƴ϶�,
//// [���� ����]���� typedef�� �տ��� ���̴� ��
//
//class Knight
//{
//public:
//	static void HelloKnight()
//	{
//		cout << "HelloKnight()" << endl;
//	}
//
//	int GetHp(int, int)
//	{
//		cout << "GetHp()" << endl;
//		return _hp;
//	}
//
//public:
//	int _hp = 100;
//};
//
//typedef int INTEGER;
//typedef int* POINTER;
//typedef int FUNC(int, int);
//typedef int ARRAY[20];
//typedef int (*PFUNC)(int, int);
//typedef int (Knight::* PMEMFUNC)(int, int);
//
//int Test(int a, int b)
//{
//	cout << "Test" << endl;
//	return a + b;
//}
//
//int main()
//{
//	// �Լ�������
//	// 1) ������		*
//	// 2) ������ �̸�	fn
//	// 3) Ÿ��			�Լ�(���ڸ� int 2���� �ް� int1���� ��ȯ)
//	//int(*fn)(int, int);
//
//	//typedef int(FUNC_TYPE)(int, int);
//	//FUNC_TYPE* fn;
//	FUNC* fn;
//	
//	PFUNC fn2 = &Test;
//	fn2(1, 2);
//
//	fn = &Test;   // & ���� ���� (C��� ȣȯ�� ����)
//
//	fn(1, 2);
//	(*fn)(1, 2);
//
//	// �� �������� [���� �Լ�/ ���� �Լ�]�� ���� �� �ִ� (ȣ�� �Ծ��� ������ �ֵ�)
//	//fn = &Knight::GetHp; // �Ұ���
//
//	Test(1, 2);
//
//	Knight k1;
//	k1.GetHp(1, 1);
//
//	PMEMFUNC mfn;
//	mfn = &Knight::GetHp;
//	(k1.*mfn)(1, 1);
//	
//	Knight* k2 = new Knight();
//	((*k2).*mfn)(1, 1);
//	(k2->*mfn)(1, 1);
//	delete k2;
//
//	return 0;
//}