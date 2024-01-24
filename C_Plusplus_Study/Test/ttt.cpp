#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

void resize(int*& arr, int size);
void resizeforD(int*& arr, int size);
struct AC
{
	AC() {};
	~AC() 
	{
		if(_data)
		delete[] _data; 
	};

	void R()
	{
		if (_size > 0)
		{
			for (int i = 0; i < _size / 2; i++)
			{
				int temp = _data[i];
				_data[i] = _data[_size - 1 - i];
				_data[_size - 1 - i] = temp;
			}
		}
		else
		{
			cout << "[]" << endl;
		}

		
	}

	void D()
	{
		if (_size >= 0)
		{
			if(_size != 0)
				resizeforD(_data, _size - 1);

			_size--;
		}

		if (_size == 0)
		{
			cout << "[]" << endl;
		}
	}

	int* _data = nullptr;
	int _size = 0;
};

void resizeforD(int*& arr, int size)
{
	int* newArr = new int[size + 1];
	for (int i = 0; i < size; i++)
		newArr[i] = arr[i + 1];

	if(arr)
		delete[] arr;

	arr = newArr;
}

void resize(int*& arr, int size)
{
	if (size <= 0)
		return;

	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}

	int* newArr = new int[size + 1];
	if (arr)
		delete[] arr;

	arr = newArr;

	string order;
	cin >> order;
	int writeIdx = 0;
	for (int i = 0; i < order.size(); i++)
	{
		int idx = i;
		if (order[i] == '[')
		{
			string temp;
			
			while (true)
			{
				idx++;
				if (order[idx] == ',' || order[idx] == ']')
					break;

				temp += order[idx];
			}
			arr[writeIdx] = stoi(temp);
			writeIdx++;
		}
		else if (order[i] == ',')
		{
			string temp;
			while (true)
			{
				idx++;
				if (order[idx] == ',' || order[idx] == ']')
					break;

				temp += order[idx];
			}
			arr[writeIdx] = stoi(temp);
			writeIdx++;
		}
	}

}

int main(void)
{
	int T;
	cin >> T;

	string name;
	int size;
	while (T > 0)
	{
		cin >> name;
		cin >> size;
		AC word;
		resize(word._data, size);
		word._size = size;
		
		for (int i = 0; i < name.size(); i++)
		{
			if (name[i] == 'D')
				word.D();
			if (name[i] == 'R')
				word.R();
		}

		if (word._size > 0)
		{
			cout << '[';
			for (int i = 0; i < word._size; i++)
			{
				cout << word._data[i];

				if(i != word._size - 1)
					cout << ',';
			}
			cout << ']' << endl;
		}

		T--;
	}

	return 0;
}