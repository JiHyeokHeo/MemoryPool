//#include <iostream>
//using namespace std;
//
//// ĳ���� (Ÿ�� ��ȯ)
//
//// 1) static_cast
//// 2) dynamic_cast
//// 3) const_cast
//// 4) reinterpret_cast
//
//class Player
//{
//public:
//	virtual ~Player() {}
//};
//
//class Knight : public Player
//{
//public:
//};
//
//class Archer : public Player
//{
//public:
//};
//
//class Dog
//{
//
//};
//
//void PrintName(char* str)
//{
//	cout << str << endl;
//}
//
//int main()
//{
//	// (int) �̷��� C��Ÿ�� ĳ��Ʈ�� �����ϴ� ��
//	
//	// static_cast : Ÿ�� ��Ģ�� ���纼 �� ������� ĳ���ø� ������ش�.
//	// 1) int <-> float
//	// 2) Player* -> Knight* �θ𿡼� �ڽ����� ��ȯ�Ҷ� (�ٿ�ĳ����) << ��, ������ ���� ����
//
//	int hp = 100;
//	int maxHp = 200;
//	float ratio = static_cast<float>(hp) / maxHp;
//
//	// �θ�->�ڽ�, �ڽ�->�θ�
//	Player* player = new Archer();
//	Knight* k1 = static_cast<Knight*>(player);
//
//	// dyanmic_cast : ��� ���迡���� ���� ����ȯ
//	// RTTI (RunTime Type Information)
//	// �������� Ȱ���ϴ� ���
//	// - virtual �Լ��� �ϳ��� �����, ��ü�� �޸𸮿� ���� �Լ� ���̺� (vftable) �ּҰ� ���Եȴ�
//	// - ���� �߸��� Ÿ������ ĳ������ ������, nullptr ��ȯ ***************
//	// �̸� �̿��ؼ� �´� Ÿ������ ĳ������ �ߴ��� Ȯ���� �����ϴ�.
//	Knight* k2 = dynamic_cast<Knight*>(player);
//	
//	
//	// const_cast : const�� ���̰ų� ���ų�~
//	PrintName(const_cast<char*>("Tory"));
//
//	// reinterpret_cast 
//	// ���� �����ϰ� ������ ������ ĳ����
//	// 're-interpret' : �ٽ�-�����ϴ�/�����ϴ�
//	// - �����Ͷ� ���� ������� �ٸ� Ÿ�� ��ȯ ��
//	__int64 address = reinterpret_cast<__int64>(k1);
//
//	Dog* dog = reinterpret_cast<Dog*>(k1);
//
//	void* p = malloc(1000);
//	Dog* dog2 = reinterpret_cast<Dog*>(p);
//
//	return 0;
//}