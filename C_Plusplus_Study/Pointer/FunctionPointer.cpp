#include <iostream>
using namespace std;

// �Լ� ������

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{
public:
	Item() :_itemId(0), _rarity(0), _ownerId(0)
	{

	}
	~Item()
	{

	}

public:
	int _itemId; // �������� �����ϱ� ���� ID
	int _rarity; // ��͵�
	int _ownerId; // ������ ID
};

typedef bool(ITEM_SELECTOR)(Item* item);

Item* FindItem(Item item[], int itemCount, ITEM_SELECTOR* selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* it = &item[i];
		if(selector(item))
			return it;
	}

	return nullptr;
}

bool IsRareItem(Item* item)
{
	return item->_rarity >= 2;
}

bool IsOwnerItem(Item* item, int ownerId)
{
	return item->_ownerId == ownerId;
}

int main()
{
	int a = 10;

	// �ٱ��� �ּ�
	// pointer[ �ּ� ]    ->     �ּ�[      ] 
	
	typedef int Data;

	// 1) ������		 *
	// 2) �����̸�		pointer
	// 3) ������ Ÿ��	int
	int* pointer = &a;
	Data* t = &a;

	// �Լ�
	typedef int(FUNC_TYPE)(int, int);
	//using FUNC_TYPE = int(int a, int b);

	// 1) ������		*
	// 2) �����̸�		fn
	// 3) ������ Ÿ��	�Լ� (���ڴ� int, int ��ȯ�� int)
	FUNC_TYPE* fn;
	
	fn = Add;

	// �Լ��� �̸��� �Լ��� ���� �ּ� (�迭�� ����)
	int result = fn(1, 2); // �⺻ ����
	cout << result << endl;

	int result2 = (*fn)(1, 2); // �Լ� �����ʹ� *(���� ������) �پ �Լ� �ּ�!
	cout << result2 << endl;
	
	Item items[10] = {};
	items[3]._rarity = 2; // RARE
	Item* rareItem = FindItem(items, 10, IsRareItem);
	
	int ttt = 0;
	return 0;
}