//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//template <typename T>
//class Node
//{
//public:
//    Node() {};
//    Node(const int& data)
//        : _data(data)
//    {
//
//    }
//    ~Node() {};
//
//
//
//public:
//    Node<T>* _prev = nullptr;
//    Node<T>* _next = nullptr;
//    T _data;
//};
//
//
//template <typename T>
//class Iterator
//{
//public:
//    Iterator() {};
//    Iterator(Node<T>* node)
//        : _node(node)
//    {
//
//    }
//    ~Iterator() {};
//
//    // 전위 ++
//    Iterator& operator++ ()
//    {
//        _node = _node->_next;
//        return *this;
//    }
//
//    // 후위 ++
//    Iterator operator++(int)
//    {
//        Iterator<T> temp = *this;
//        _node = _node->_next;
//
//        return temp;
//    }
//
//    // 전위 --
//    Iterator& operator-- ()
//    {
//        _node = _node->_prev;
//        return *this;
//    }
//
//    // 후위 --
//    Iterator operator--(int)
//    {
//        Iterator<T> temp = *this;
//        _node = _node->_prev;
//
//        return temp;
//    }
//
//    T& operator*()
//    {
//        return _node->_data;
//    }
//
//    bool operator==(const Iterator& other)
//    {
//        return _node == other._node;
//    }
//
//    bool operator!=(const Iterator& other)
//    {
//        return _node != other._node;
//    }
//
//public:
//    Node<T>* _node;
//};
//
//template <typename T>
//class List
//{
//public:
//    List() 
//        :_head(new Node<T>())
//        ,_tail(new Node<T>())
//        ,_size(0)
//    {
//        _head->_next = _tail;
//        _tail->_prev = _head;
//    };
//   ~List() {};
//
//   void push_back(const int& val)
//   {
//       AddNode(_tail, val);
//   }
//
//   void pop_back()
//   {
//       RemoveNode(_tail->_prev);
//   }
//
//private:
//    Node<T>* AddNode(Node<T>* node, const int& val)
//    {
//        Node<T>* newNode = new Node<T>(val);
//        Node<T>* prevNode = node->_prev;
//
//        prevNode->_next = newNode;
//        newNode->_prev = prevNode;
//
//        node->_prev = newNode;
//        newNode->_next = node;
//        
//        _size++;
//
//        return newNode;
//    }
//    
//    Node<T>* RemoveNode(Node<T>* node)
//    {
//        Node<T>* prevNode = node->_prev;
//        Node<T>* nextNode = node->_next;
//
//        prevNode->_next = nextNode;
//        nextNode->_prev = prevNode;
//
//        delete node;
//
//        _size--;
//
//        return nextNode;
//    }
//
//public:
//    using iterator = Iterator<T>;
//
//    iterator begin()
//    {
//        return iterator(_head->_next);
//    }
//
//    iterator end()
//    {
//        return iterator(_tail);
//    }
//
//    iterator insert(iterator it, const T& val)
//    {
//        Node<T>* node = AddNode(it._node, val);
//        return iterator(node);
//    }
//
//    iterator erase(iterator it)
//    {
//        Node<T>* node = RemoveNode(it._node);
//        return iterator(node);
//    }
//
//
//private:
//    Node<T>* _head;
//    Node<T>* _tail;
//    int _size;
//};
//
//
//int main() 
//{
//	List<int> li;
//	List<int>::iterator eraseIt;
//	//[ ] <-> [ ] <-> [ ]
//
//	for (int i = 0; i < 10; i++)
//	{
//		if (i == 5)
//		{
//			eraseIt = li.insert(li.end(), i);
//		}
//		else
//		{
//			li.push_back(i);
//		}
//	}
//
//	li.pop_back();
//
//	li.erase(eraseIt);
//
//	for (List<int>::iterator it = li.begin(); it != li.end(); it++)
//	{
//		cout << (*it) << endl;
//	}
//
//
//    return 0;
//}