#include <iostream>
using namespace std;

// ������

// ������(Polymorphism) = ���� �Ȱ�����, ����� �ٸ��� �����Ѵ�
// - �����ε�(Overloading) = �Լ� �ߺ� ���� = �Լ� �̸��� ����
// - �������̵�(Overrideing) = ������ = �θ� Ŭ������ �Լ��� �ڽ� Ŭ�������� ������

// ���ε�(Binding) = ���´�
// - ���� ���ε�(Static Binding) : ������ ������ ����
// - ���� ���ε�(Dynamic Binding) : ���� ������ ����

// �Ϲ� �Լ��� ���� ���ε��� ���
// ���� ���ε��� ���Ѵٸ�? -> ���� �Լ� (virtual function)

// �׷��� ���� ��ü�� � Ÿ������ ��� �˰� �־ �����Լ��� ȣ�����ذɱ�?
// - �����Լ� ���̺� (vftable)

// .vftable [] 4����Ʈ(32) 8����Ʈ(64)
// [Move] [Die]

// ���� ���� �Լ� : ������ ���� '�������̽�'�� �����ϴ� �뵵�� ����ϰ� ���� ���
// �߻� Ŭ���� : ���� ���� �Լ��� 1�� �̻� ���ԵǸ� �ٷ� Ŭ������ ����
// - ���������� ��ü�� ���� �� ���� ��

class Player
{
public:
	Player()
	{
		_hp = 100;
	}
	virtual void Move() { cout << "Move Player" << endl; }
	virtual void Die() { cout << "Die Player" << endl; }
	//void Move(int a) { cout << "Move Player (int)!" << endl; }
	
	// ���� ���� �Լ�
	virtual void Attack() = 0;


public:
	int _hp;
};

class Knight : public Player
{
public:
	Knight()
	{
		_stamina = 100;
	}
	// �����Լ��� �����Ǹ� �ϴ��� ���� �Լ���!
	virtual void Move() override { cout << "Move Knight" << endl; }
	virtual void Die() { cout << "Die Knight" << endl; }
	virtual void Attack() { cout << "Attack Knight" << endl; }

public:
	int _stamina;
};

class Mage : public Player
{
public:
	void Move() { cout << "Move Mage" << endl; }
public:
	int _mp;
};

void MovePlayer(Player* player)
{
	player->Move();
	player->Die();
}

int main()
{
	//Player p;
	//MovePlayer(&p); // �÷��̾�� �÷��̾��? YES
	//MoveKnight(&p); // �÷��̾�� ����? // NO

	Knight k;
	MovePlayer(&k); // ���� �÷��̾��? YES

	return 0;
}