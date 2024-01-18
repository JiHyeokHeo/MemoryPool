#include "BInarySearchTree.h"
#include <iostream>
#include <Windows.h>
using namespace std;

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,
};

void SetCursorColor(ConsoleColor color)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(output, static_cast<SHORT>(color));
}

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

BInarySearchTree::BInarySearchTree()
{
	_nil = new Node();
	_root = _nil;
}

BInarySearchTree::~BInarySearchTree()
{
	delete _nil;
}

void BInarySearchTree::Print(Node* node, int x, int y)
{
	if (node == _nil)
		return;

	SetCursorPosition(x, y);

	if (node->color == Color::Black)
		SetCursorColor(ConsoleColor::BLUE);
	else
		SetCursorColor(ConsoleColor::RED);

	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);

	SetCursorColor(ConsoleColor::WHITE);
}

void BInarySearchTree::Print_Inorder(Node* node)
{
	// 전위 순회 (preorder traverse)
	// 중위 순회 (inorder)
	// 후위 순회 (postorder)

	if (node == nullptr)
		return;

	// 전위 : [중]이 앞에 온다
	// 중위 : [중]이 중간에 온다
	// 후위 : [중]이 마지막에 온다

	// 전위 예시
	cout << node->key << endl;
	Print_Inorder(node->left);
	Print_Inorder(node->right);
}

Node* BInarySearchTree::Search(Node* node, int key)
{
	if (node == nullptr || key == node->key)
		return node;

	if (key < node->key)
		return Search(node->left, key);
	else
		return Search(node->right, key);

	return nullptr;
}

//Node* BInarySearchTree::Search2(Node* node, int key)
//{
//	while (node && key != node->key)
//	{
//		if (key < node->key)
//			node = node->left;
//		else
//			node = node->right;
//	}
//
//	return node;
//}

Node* BInarySearchTree::Min(Node* node)
{
	while (node->left != _nil)
		node = node->left;

	return node;
}

Node* BInarySearchTree::Max(Node* node)
{
	while (node->right != _nil)
		node = node->right;

	return node;
}

Node* BInarySearchTree::Next(Node* node)
{
	if (node->right != _nil)
		return Min(node->right);

	Node* parent = node->parent;

	while (parent != _nil && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}

	return parent;
}

void BInarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	Node* node = _root;
	Node* parent = _nil;

	while (node != _nil)
	{
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	
	newNode->parent = parent;

	if (parent == _nil)
		_root = newNode;
	else if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
	
	// 검사
	newNode->left = _nil;
	newNode->right = _nil;
	newNode->color = Color::Red;

	InsertFixup(newNode);
}

void BInarySearchTree::InsertFixup(Node* node)
{
	// 1) p = red, uncle = red
	// -> p = black, uncle = black, pp = red
	// 2) p = red, unclde = black (triangle)
	// -> 회전을 통해 case 3으로 바꿈
	// 3) p = red, uncle = black (list)
	// -> 색상 변경 + 회전
	
	while (node->parent->color == Color::Red)
	{
		if (node->parent == node->parent->parent->left)
		{		//	[pp(B)]
				// [p(R)]  [u(R)]
				//  [n(R)]
			Node* uncle = node->parent->parent->right;
			if (uncle->color == Color::Red)
			{
				node->parent->color = Color::Black; // p
				uncle->color = Color::Black; // u
				node->parent->parent->color = Color::Red;
				node = node->parent->parent;
			}
			else
			{
				//	[pp(B)]
				// [p(R)]  [u(B)]
				//  [n(R)]

				//		[pp(B)]
				//  [p(R)]  [u(B)]
				//[n(R)] 
				if (node == node->parent->right) // Triangle 타입
				{
					node = node->parent;
					LeftRotate(node);
				}
				//		[pp(R)]
				//  [p(B)]  [u(B)]
				//[n(R)] 
				// 
				//		[p(B)]
				//  [n(R)]  [pp(R)]
				//              [u(B)]
				// List 타입
				node->parent->color = Color::Black;
				node->parent->parent->color = Color::Red;
				RightRotate(node->parent->parent);
			}
		}
		else

		{		//  	[pp(B)]
				// [u(R)]     [p(R)] 
				//                [n(R)]
			Node* uncle = node->parent->parent->left;
			if (uncle->color == Color::Red)
			{
				node->parent->color = Color::Black; // p
				uncle->color = Color::Black; // u
				node->parent->parent->color = Color::Red;
				node = node->parent->parent;
			}
			else
			{
				//  	[pp(B)]
				// [u(B)]     [p(R)] 
				//          [n(R)]
				if (node == node->parent->left) // Triangle 타입
				{
					node = node->parent;
					RightRotate(node);
				}
				//  	[pp(B)]
				// [u(B)]     [p(R)] 
				//                [n(R)]

				// List 타입

				//  	 [p(R)] 
				//   [pp(R)]   [n(R)] 
				// [u(B)]               
				node->parent->color = Color::Black;
				node->parent->parent->color = Color::Red;
				LeftRotate(node->parent->parent);
			}
		}
	}

	_root->color = Color::Black;
}

void BInarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BInarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->left == nullptr)
		Replace(node, node->right);
	else if (node->right == nullptr)
		Replace(node, node->left);
	else
	{
		// 다음 데이터 찾기
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}

// u 서브트리를 v서브트리로 교체
// 그리고 delete u
void BInarySearchTree::Replace(Node* u, Node* v)
{
	if (u->parent == nullptr)
		_root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	if (v)
		v->parent = u->parent;

	delete u;

}

// 오른쪽 회전 (위에서 아래)
// 왼쪽 회전 (아래에서 위)
//		[y]
//	  [x] [3]
//   [1][2]

//	  [x] 
//  [1] [y]
//     [2][3]

void BInarySearchTree::LeftRotate(Node* x)
{
	Node* y = x->right;

	x->right = y->left; // [2] 회전하는 코드..ㅋㅋ
	
	if(y->left != _nil)
		y->left->parent = x;

	y->parent = x->parent;

	if (x->parent == _nil)
		_root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

// 오른쪽 회전 (위에서 아래)
// 왼쪽 회전 (아래에서 위)
//		[y]
//	  [x] [3]
//   [1][2]

//	  [x] 
//  [1] [y]
//     [2][3]

void BInarySearchTree::RightRotate(Node* y)
{
	Node* x = y->left;

	y->left = x->right;

	if (x->right != _nil)
		x->right->parent = y;

	x->parent = y->parent;

	if (x->parent == _nil)
		_root = x;
	else if (y == y->parent->left)
		x->parent->left = x;
	else
		x->parent->right = x;

	x->right = y;
	y->parent = x;
}
