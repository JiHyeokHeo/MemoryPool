#include <iostream>
using namespace std;

// �ʱ�ȭ ����Ʈ

// ��� ���� �ʱ�ȭ ? �پ��� ������ ����

// �ʱ�ȭ �� �ؾ��ұ�? ������~
// - ���� ���濡 �߿�
// -  ������ �� �ּҰ��� ����Ǿ� ���� ���

// �ʱ�ȭ ���
// - ������ ������
// - �ʱ�ȭ ����Ʈ
// - C++11 ����

// �ʱ�ȭ ����Ʈ
// - �ϴ� ��� ���迡�� ���ϴ� �θ� �����ڸ� ȣ���� �� �ʿ��ϴ�
// - ������ ������ �ʱ�ȭ vs �ʱ�ȭ ����Ʈ
// -- �Ϲ� ������ �� ���� ����
// -- ��� Ÿ���� Ŭ������ ��� ���̰� ����.
// -- �����԰� ���ÿ� �ʱ�ȭ�� �ʿ��� ��� (���� Ÿ��, const Ÿ��)

class Inventory
{
public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size) { cout << "Inventory(int size)" << endl; _size = size; }

	~Inventory() { cout << "~Inventory()" << endl; }
public:
	int _size = 10;
};

class Player
{
public:
	Player() {}
	Player(int id) {}
};

// Is-A (Knight Is-A Player? ���� �÷��̾��) OK -> ��Ӱ���
// Is-A (Knight Is-A Inventory? ���� �κ��丮��?) NO -> ��Ӱ���X
// Has-A (Knight Has-A Inventory? ���� �κ��丮�� �����ϰ� �ִ� ���� �ִ�) OK -> ���԰���

class Knight : public Player
{
public:
	Knight() : Player(1), _hp(100), _inventory(Inventory(100)), _hpRef(_hp), _hpPtr(nullptr), _hpConst(100)
		/*
		��ó�� ����

		_inventory = Inventory()

		*/
	{
		_hp = 100;
	}

public:
	int _hp;
	Inventory _inventory;

	int* _hpPtr;

	// C++ 11���� ����
	int& _hpRef = _hp;
	const int _hpConst = 100;
};

int main()
{
	Knight k;
	
	//cout << k._hp << endl;

	//if (k._hp < 0)
	//{
	//	cout << "Knight is Dead" << endl;
	//}

	return 0;
}