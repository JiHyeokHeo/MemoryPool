//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//#include <algorithm>
//// ����(lambda)
//
//// �Լ� ��ü�� ������ ����� ����
//
//enum class ItemType
//{
//	None,
//	Armor,
//	Weapon,
//	Jewelry,
//	Consumable,
//};
//
//enum class Rarity
//{
//	Common,
//	Rare,
//	Unique,
//};
//
//class Item
//{
//public:
//	Item() {}
//	Item(int itemId, Rarity rarity, ItemType type)
//		: _itemId(itemId)
//		, _rarity(rarity)
//		, _type(type)
//	{
//
//	}
//
//public:
//	int _itemId = 0;
//	Rarity _rarity = Rarity::Common;
//	ItemType _type = ItemType::None;
//};
//
//
//int main()
//{
//	vector<Item> v;
//	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
//	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
//	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
//	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));
//
//	// ���� �Լ� ��ü�� �ս��� ����� ����
//	// ���� ��ü�� C++11�� '���ο�' ����� �� ���� �ƴϴ�.
//	{
//		struct FindItem
//		{
//			FindItem(int itemId, Rarity rarity, ItemType type)
//				:_itemId(itemId), _rarity(rarity), _type(type)
//			{
//
//			}
//
//			bool operator()(Item& item)
//			{
//				return item._itemId == _itemId && item._rarity == _rarity && item._type == _type;
//			}
//
//			int _itemId;
//			Rarity _rarity;
//			ItemType _type;
//		};
//#pragma region Ŭ����
//		//// Ŭ���� (closure) = ���ٿ� ���� ������� ������� ��ü
//		//auto isUniqueLambda = [](Item& item) 
//		//{
//		//	return item._rarity == Rarity::Unique;
//		//};	// ���� ǥ����(lambda expression)
//#pragma endregion
//
//		int itemId = 4;
//		Rarity rarity = Rarity::Unique;
//		ItemType type = ItemType::Weapon;
//		// [ ] ĸó(capture) : �Լ� ��ü ���ο� ������ �����ϴ� ����� ����
//		// ������ ��Ĭ [ĸó]�ϵ�.. ������ �������� ��´ٰ� ����
//		// �⺻ ĸó ��� : �� ���� ���(=) ���� ���(&)
//		// �������� ĸ�� ��带 �����ؼ� ��� ���� : �� ���(name), ���� ���(&name)
//
//		auto findByItem = [itemId, &rarity, type](Item& item)
//		{
//			return item._itemId == itemId && item._rarity == rarity && item._type == type;
//		};
//
//		itemId = 10;
//
//		auto findIt = std::find_if(v.begin(), v.end(), findByItem);
//
//		if (findIt != v.end())
//			cout << "������ ID: " << findIt->_itemId << endl;
//	}
//
//	{
//		// ���� ����
//		class Knight
//		{
//		public:
//			auto ResetHpJob()
//			{
//				auto f = [this]()
//				{
//					this->_hp = 200;
//				};
//
//				return f;
//			}
//
//		public:
//			int _hp = 100;
//		};
//
//		class Functor
//		{
//		public:
//			Functor(Knight* k)
//				:_knight(k)
//			{
//
//			}
//
//			void operator()()
//			{
//				_knight->_hp = 200;
//			}
//
//		public:
//			Knight* _knight;
//		};
//
//		Knight* k = new Knight();
//		auto job = k->ResetHpJob();
//		delete k;
//		job();
//	}
//
//	//
//	
//
//	return 0;
//}