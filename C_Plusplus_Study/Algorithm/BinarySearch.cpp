//#include <iostream>
//#include <vector>
//#include <list>
//#include <stack>
//#include <queue>
//using namespace std;
//
//// ���� Ž�� Ʈ�� ���� �ܰ��� !
//
//// Binary search
//// ��Ȳ) �迭�� �����Ͱ� ���ĵǾ� �ִ�.
//
//// Q) 82��� ���ڰ� �迭�� �ֽ��ϱ�?
//// A) 
//// [1][8][15][23][32][44][56][63][81][91]
//
//// ���ٿ� ����
//// 81
//
//vector<int> numbers;
//
//void T(int N)
//{
//	int maxIndex = numbers.size() - 1;
//	
//	int firstIdx = 0;
//	int endIdx = maxIndex;
//	while (firstIdx <= endIdx)
//	{
//		cout << "Ž������ :" << firstIdx << "~" << endIdx << endl;
//		int compareIndex = (firstIdx + endIdx) / 2;
//
//		// �߰����� ��ǥ������ ũ�ٸ�?
//		if (numbers[compareIndex] > N)
//		{
//			cout << N << ">" << numbers[compareIndex] << endl;
//			endIdx = compareIndex - 1;
//		}
//		else if(numbers[compareIndex] < N)
//		{
//			cout << N << "<" << numbers[compareIndex] << endl;
//			firstIdx = compareIndex + 1;
//		}
//		else
//		{
//			cout << "�߰�" << endl;
//			return;
//		}
//	}
//
//	cout << "�̹߰�" << endl;
//}
//
//int main()
//{
//	numbers = vector<int>{ 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
//	T(82);
//
//	return 0;
//}