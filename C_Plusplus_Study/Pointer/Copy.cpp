#include <iostream>
using namespace std;

// ���� ���� vs ���� ����

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}
	~Pet()
	{
		cout << "~Pet()" << endl;
	}
	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}
};

class RabbitPet : public Pet
{

};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
		cout << "Knight()" << endl;
	}
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // ���� ����
		cout << "Knight(const knight&)" << endl;
	}
	Knight& operator=(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // ���� ����
		return *this;
	}

	~Knight()
	{
		delete _pet;
		cout << "~Knight()" << endl;
	}


public:
	int _hp = 100;
	Pet* _pet = nullptr;
};

int main()
{
	Knight knight; // �⺻ ������
	knight._hp = 200;

	Knight knight2 = knight; // ���� ������
	//Knight knight3(knight);

	Knight knight3; // �⺻ ������
	knight3 = knight; // ���� ���� ������

	// [���� ������] + [���� ���� ������]
	// �� �� �ȸ�����ָ� �����Ϸ� '�Ͻ�������' ������ش�

	// �߰� ���) �����Ϸ��� �˾Ƽ� �� ������ش�?
	// �����ϼ���~ ���� ���� �Ѿ���? << NO

	// [���� ���� Shallow Copy]
	// ��� �����͸� ��Ʈ�� ������ '�Ȱ���' ���� (�޸� ���� ���� �״�� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> �ּҰ��� �Ȱ��� ���� -> ������ ��ü�� ����Ű�� ���°� ��
	// Stack : Knight1 [ hp 0x1000 ] -> Heap 0x1000 Pet[    ]
	// Stack : Knight2 [ hp 0x1000 ] 
	// Stack : Knight3 [ hp 0x1000 ] 

	// [���� ���� Deep Copy]
	// ��� �����Ͱ� ����(�ּ�) ���̶��, �����͸� ���� ������ش�. (���� ��ü�� �����ϴ� ������ ���� ���� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> ���ο� ��ü�� ���� -> ������ ��ü�� ����Ű�� ���°� ��
	// Stack : Knight1 [ hp 0x1000 ] -> Heap 0x1000 Pet[    ]
	// Stack : Knight2 [ hp 0x2000 ] -> Heap 0x2000 Pet[    ] 
	// Stack : Knight3 [ hp 0x3000 ] -> Heap 0x3000 Pet[    ]


	return 0;
}