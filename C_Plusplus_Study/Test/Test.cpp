#include <iostream>
#include <vector>
using namespace std;



template <typename T>
class Vector
{
public:
    Vector() {};
    ~Vector()
    {
        if (_data)
            delete[] _data;
    };

    void push_back(const T& val)
    {
        if (_capacity == _size)
        {
            int newCapacity = static_cast<int>(_capacity * 1.5);
            if (newCapacity == _size)
                newCapacity++;

            reserve(newCapacity);
        }

        _data[_size] = val;
        _size++;
    }

    void reserve(int capacity)
    {
        if (capacity < _capacity)
            return;

        _capacity = capacity;

        T* newData = new T[_capacity];

        for (int i = 0; i < _size; i++)
            newData[i] = _data[i];

        delete[] _data;

        _data = newData;
    }

    T& operator[](const int& pos) { return _data[pos]; }

    int size() { return _size; }
    int capacity() { return _capacity; }

public:
    T* _data;
    int _size = 0;
    int _capacity = 0;
};


int main()
{
    Vector<int> a;

    a.push_back(5);
    a.push_back(8);
    /*for (int i = 5; i < 100; i++)
    {
        a.push_back(i);
    }*/

    //for (int i = 0; i < 95; i++)
    //{
    //    cout << a[i] << " " << a.size() << " " << a.capacity() << endl;
    //}
    cout << *(a._data + 1) << endl;

    return 0;
}