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

void ShowConsoleCursor(bool flag)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	::GetConsoleCursorInfo(output, &cursorInfo);
	cursorInfo.bVisible = flag;
	::SetConsoleCursorInfo(output, &cursorInfo);
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

void BInarySearchTree::Print()
{ 
	::system("cls");
	ShowConsoleCursor(false);
	Print(_root, 10, 0);
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

// 먼저 BST 삭제 실행
//        [20]
// [10(B)]       [30]
//   [15(R)]   [25][40]
void BInarySearchTree::Delete(Node* node)
{
	if (node == _nil)
		return;

	if (node->left == _nil)
	{
		Color color = node->color;
		Node* right = node->right;
		Replace(node, node->right);

		if (color == Color::Black)
			DeleteFixup(right);
	}
	else if (node->right == _nil)
	{
		Color color = node->color;
		Node* left = node->left;
		Replace(node, node->left);

		if (color == Color::Black)
			DeleteFixup(left);
	}
	else
	{
		// 다음 데이터 찾기
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}

void BInarySearchTree::DeleteFixup(Node* node)
{
	Node* x = node;

	// [Case1][Case2]
	while (x != _root && x->color == Color::Black)
	{
		//         [p(B)]
		// [x(DB)]       [s(R)]
		
		//         [p(R)]
		// [x(DB)]       [s(B)]
		// 
		//               [s(B)]
		//         [p(R)]
		// [x(DB)]      [1]
		if (x == x->parent->left)
		{
			// [Case3]
			Node* s = x->parent->right;
			if (s->color == Color::Red)
			{
				s->color = Color::Black;
				x->parent->color = Color::Red;
				LeftRotate(x->parent);
				s = x->parent->right; //[1]
			}

			// [Case4]
			if (s->left->color == Color::Black && s->right->color == Color::Black)
			{
				s->color = Color::Red;
				x = x->parent;
			}
			else
			{
				//           [p]
				// [x(DB)]      [s(R)]
				//         [near(B)] [far(B)]

				//           [p]
				// [x(DB)]      [near(B)]
				//                   [s(R)]
				//                       [far(B)]
				// [Case5]
				if (s->right->color == Color::Black)
				{
					s->left->color = Color::Black;
					s->color = Color::Red;
					RightRotate(s);
					s = x->parent->right;
				}

				// [Case6]
				//           [p]
				// [x(DB)]      [s(B)]
				//                   [far(R)]
				
				s->color = x->parent->color;
				x->parent->color = Color::Black;
				s->right->color = Color::Black;
				LeftRotate(x->parent);
				x = _root;
			}
				
		}
		else
		{
			// [Case3]
			Node* s = x->parent->left;
			if (s->color == Color::Red)
			{
				s->color = Color::Black;
				x->parent->color = Color::Red;
				RightRotate(x->parent);
				s = x->parent->left; //[1]
			}

			// [Case4]
			if (s->right->color == Color::Black && s->left->color == Color::Black)
			{
				s->color = Color::Red;
				x = x->parent;
			}
			else
			{
				//           [p]
				// [x(DB)]      [s(R)]
				//         [near(B)] [far(B)]

				//           [p]
				// [x(DB)]      [near(B)]
				//                   [s(R)]
				//                       [far(B)]
				// [Case5]
				if (s->left->color == Color::Black)
				{
					s->right->color = Color::Black;
					s->color = Color::Red;
					LeftRotate(s);
					s = x->parent->left;
				}

				// [Case6]
				//           [p]
				// [x(DB)]      [s(B)]
				//                   [far(R)]

				s->color = x->parent->color;
				x->parent->color = Color::Black;
				s->left->color = Color::Black;
				RightRotate(x->parent);
				x = _root;
			}
		}
	}


	x->color = Color::Black;

}

// u 서브트리를 v서브트리로 교체
// 그리고 delete u
void BInarySearchTree::Replace(Node* u, Node* v)
{
	if (u->parent == _nil)
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
