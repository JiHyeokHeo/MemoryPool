#include <iostream>
#include <vector>
using namespace std;

// vector

int main()
{
	// STL (Standard Template Library)
	// ���α׷����� �� �ʿ��� �ڷᱸ��/�˰������
	// ���ø����� �����ϴ� ���̺귯��
	
	// �����̳�(Container) : �����͸� �����ϴ� ��ü (�ڷᱸ�� Data Structure)
	
	// �������� �ַ� ������ ���� ������ ���´�
	// vector (���� �迭) C# ���� list
	// - vector�� ���� ���� (size/capacity)
	// - �߰� ����/����
	// - ó��/�� ���� ����
	// - ���� ����

	// ���� �迭
	// �ſ� �ſ� �߿��� ���� -> � ������ �ηȱ淡 �迭�� '����������' ����� ���ΰ�?

	//************* �߿�********************
	// 1) (�������� �ΰ�) �޸𸮸� �Ҵ��Ѵ�
	// 2) �����б��� �� á����, �޸𸮸� �����Ѵ�

	// Q1) �������� ��ŭ�� �����ұ�?
	// Q2) ������ ��ŭ �ؾ� �ұ�?
	// Q3) ������ �����͸� ��� ó���ұ�?
	
	// [ 1 2 3 4 5 ]             // �̸� ������ �صθ� ���縦 �� �ص� �ȴ�.
	// [ 1 2 3 4 5             ] // �̻��� �ڽ�Ʈ�� ���.
	//int arr[100];

	//vector<int> v(1000, 0);
	//vector<int> v2 = v;

	//// [                   ]
	////v.resize(1000);
	//// size (���� ��� ������ ����)
	//// 1 2 3 4 5 6 7...
	// 
	////v.reserve(1000);
	//// reserve ���� 1000���� ����
	//// capacity (�������� ������ �뷮 ����)
	//// 1 2 3 4 6 9 13 19 28 42 63 // �뷫 1.5�� or 2�� (�����Ϸ� ����)


	//for (int i = 0; i < 1000; i++)
	//{
	//	v.push_back(100);
	//	cout << v.size() << " " << v.capacity() << endl;
	//}


	//v.front();
	//v.back();
	//v.pop_back();

	//v.clear();
	//vector<int>().swap(v); // �� ���������� �� �Ⱦ��δ�. capacity ������ ���
	//cout << v.size() << " " << v.capacity() << endl;

	
	// ***************************************************************************
	// �߰� ���� ����
	// �ݺ���(iterator) : �����Ϳ� ������ ����, �����̳��� ����(������)�� ����Ű��, ����/���� ���ҷ� �̵�����
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

	// �̼��ϰ� ++it�� ������ ����. (���� �������� ����)
	// �� �����غ��̴µ�? �� ���̴°ɱ�?
	// iterator�� vector�� �ƴ϶�, �ٸ� �����̳ʿ��� ���������� �ִ� ����
	// �ٸ� �����̳ʷ� �ű�Ⱑ ��������.
	// �ٸ� �����̳ʴ� v[i]�� ���� �ε��� ������ �� �� ���� ����
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