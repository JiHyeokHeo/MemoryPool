//#include <iostream>
//using namespace std;
//
//// �ζ� ��ȣ ������
//
//void Swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Sort(int numbers[], int count)
//{
//	for (int i = 0; i < count; i++)
//	{
//		for (int j = i + 1; j < count; j++)
//		{
//			if (numbers[i] > numbers[j])
//			{
//				Swap(numbers[i], numbers[j]);
//			}
//		}
//	}
//}
//
//// 3) �ζ� ��ȣ ����
//void ChooseLotto(int numbers[])
//{
//	srand((unsigned)time(0));
//
//	int temp[6] = {};
//	for (int i = 0; i < 6; i++)
//	{
//		numbers[i] = 1 + (rand() % 45);
//
//		for (int j = 0; j < 6; j++)
//		{
//			if (numbers[i] == temp[j])
//				i--;
//		}
//
//		temp[i] = numbers[i];
//	}
//	Sort(numbers, 6);
//
//	// TODO : �������� 1~45 ������ ���� 6���� ����ּ���! (��, �ߺ��� �������) // ���ı��� �ؾ��Ѵ�.
//	// 42 1 3 4
//}
//
//int main()
//{
//	// 1) Swap �Լ� �����
//	int a = 1;
//	int b = 2;
//	//Swap(&a, &b);
//	Swap(a, b);
//
//	cout << a << " " << b << endl;
//
//	// 2) ���� �Լ� ����� ( ���� ���ڰ� ���� ������ ���� )
//	int numbers[6] = { 1,42,3,15,5,6 };
//	Sort(numbers, sizeof(numbers) / sizeof(int));
//	
//	// 3) �ζ� ��ȣ ������
//	ChooseLotto(numbers);
//
//	for (int i = 0; i < 6; i++)
//	{
//		cout << numbers[i] << endl;
//	}
//	return 0;
//}