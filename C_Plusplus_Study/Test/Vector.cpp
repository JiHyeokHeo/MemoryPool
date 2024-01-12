//#include <iostream>
//#include <vector>
//using namespace std;
//
//template<typename T>
//class Iterator
//{
//public:
//    Iterator() {};
//    Iterator(T* data)
//        : _ptr(data)
//    {
//    };
//    ~Iterator() {};
//
//    // 전위 
//    Iterator& operator++()
//    {
//        _ptr++;
//        return *this;
//    }
//
//    // 후위 연산자
//    Iterator operator++(int)
//    {
//        Iterator temp = *this;
//        temp._ptr++;
//        return temp;
//    }
//
//    Iterator& operator--()
//    {
//        _ptr--;
//        return *this;
//    }
//
//    Iterator operator--(int)
//    {
//        Iterator temp = *this;
//        temp._ptr--;
//        return temp;
//    }
//    
//    Iterator operator+(const int& pointerMove)
//    {
//        Iterator temp = *this;
//        temp._ptr += pointerMove;
//        return temp;
//    }
//
//    T& operator *()
//    {
//        return *_ptr;
//    }
//
//    bool operator==(const Iterator& right)
//    {
//        return (_ptr == right._ptr);
//    }
//
//    bool operator!=(const Iterator& right)
//    {
//        return (_ptr != right._ptr);
//    }
//
//private:
//    T* _ptr;
//};
//
//template <typename T>
//class Vector
//{
//public:
//    Vector() {};
//    ~Vector()
//    {
//        if (_data)
//            delete[] _data;
//    };
//
//    void push_back(const T& val)
//    {
//        if (_capacity == _size)
//        {
//            int newCapacity = static_cast<int>(_capacity * 1.5);
//            if (newCapacity == _size)
//                newCapacity++;
//
//            reserve(newCapacity);
//        }
//
//        _data[_size] = val;
//        _size++;
//    }
//
//    void reserve(int capacity)
//    {
//        if (capacity < _capacity)
//            return;
//
//        _capacity = capacity;
//
//        T* newData = new T[_capacity];
//
//        for (int i = 0; i < _size; i++)
//            newData[i] = _data[i];
//
//        delete[] _data;
//
//        _data = newData;
//    }
//
//    void resize(const int& size, int initVal = 0)
//    {
//        T* newData = new T[size];
//
//        // 102 면 100으로 저장 // 용량은 100
//        // 들어온 사이즈가 기존 사이즈보다 크면 기존 사이즈로 일단 저장
//        _size = (size > _size) ? (_size) : (size);
//        _capacity = size;  // 용량은 일단 들어온 사이즈로 고정
//
//        for (int i = 0; i < _size; i++)
//            newData[i] = _data[i];
//
//        for (int i = _size; i < _capacity; i++)
//            newData[i] = initVal;
//
//        delete[] _data;
//        
//        _data = newData;
//        _size = size;
//    }
//
//    void pop_back()
//    {
//        _size = (_size > 0) ? (_size - 1) : 0;
//    }
//
//    T& front() { return _data[0]; }
//
//    T& operator[](const int& pos) { return _data[pos]; }
//
//    int size() { return _size; }
//    int capacity() { return _capacity; }
//
//
//public:
//    using iterator = Iterator<T>;
//
//    iterator begin() { return iterator(&_data[0]); }
//    iterator end() { return begin() + _size; }
//
//public:
//    T* _data = nullptr;
//    int _size = 0;
//    int _capacity = 0;
//};
//
//
//int main()
//{
//	Vector<int> v;
//
//	//v.reserve(100);
//
//	for (int i = 0; i < 100; i++)
//	{
//		v.push_back(i);
//		cout << v.size() << " " << v.capacity() << endl;
//	}
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << endl;
//	}
//
//    cout << v.front() << endl;
//    
//    v.resize(1, 1);
//
//    v.pop_back();
//
//	cout << "--------------" << endl;
//
//	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
//	{
//		cout << (*it) << endl;
//	}
//
//
//    return 0;
//}