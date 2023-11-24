//#include <iostream>
//using namespace std;
//
//// 로또 번호 생성기
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
//// 3) 로또 번호 생성
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
//	// TODO : 랜덤으로 1~45 사이의 숫자 6개를 골라주세요! (단, 중복이 없어야함) // 정렬까지 해야한다.
//	// 42 1 3 4
//}
//
//int main()
//{
//	// 1) Swap 함수 만들기
//	int a = 1;
//	int b = 2;
//	//Swap(&a, &b);
//	Swap(a, b);
//
//	cout << a << " " << b << endl;
//
//	// 2) 정렬 함수 만들기 ( 작은 숫자가 먼저 오도록 정렬 )
//	int numbers[6] = { 1,42,3,15,5,6 };
//	Sort(numbers, sizeof(numbers) / sizeof(int));
//	
//	// 3) 로또 번호 생성기
//	ChooseLotto(numbers);
//
//	for (int i = 0; i < 6; i++)
//	{
//		cout << numbers[i] << endl;
//	}
//	return 0;
//}