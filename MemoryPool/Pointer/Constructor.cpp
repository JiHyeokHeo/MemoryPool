//#include <iostream>
//
//using namespace std;
//
//// class�� ���赵
//class Knight
//{
//public:
//	// �⺻ ������ (���ڰ� ����)
//	Knight() 
//	{
//		cout << "Knight �⺻ ������ ȣ��" << endl;
//
//		_hp = 100;
//		_mp = 10;
//		_posX = 0;
//		_posY = 0;
//	};
//
//	// ���� ������
//	Knight(const Knight& knight)
//	{
//		cout << "Knight ���� ������ ȣ��" << endl;
//		_hp = knight._hp;
//		_mp = knight._mp;
//		_posX = knight._posX;
//		_posY = knight._posY;
//	}
//
//	// ��Ÿ ������
//
//	// ���߿��� ���ڸ� 1���� �޴� [��Ÿ ������]��
//	// [Ÿ�� ��ȯ ������]��� �θ��⵵ ��
//
//	// ������� �뵵�θ� ����� ��!
//	explicit Knight(int hp)
//	{
//		cout << "Knight ��Ÿ ������ ȣ��" << endl;
//		_hp = hp;
//		_mp = 10;
//		_posX = 0;
//		_posY = 0;
//	}
//
//	Knight(int hp, int mp, int posX, int posY)
//	{
//		_hp = hp;
//		_mp = mp;
//		_posX = posX;
//		_posY = posY;
//	}
//
//	// �Ҹ���
//	~Knight() 
//	{
//
//	};
//
//	// ����Լ�
//	void Attack();
//
//	// �������
//public:
//	int _hp;
//	int _mp;
//	int _posX;
//	int _posY;
//};
//
//void Knight::Attack()
//{
//	
//}
//
//void HelloKnight(Knight k)
//{
//	cout << "Hello Knight" << endl;
//}
//
//int main()
//{
//	Knight k1(100);
//
//	Knight k2(k1); // ���� ������
//	Knight k3 = k1; // ���� ������
//
//	Knight k4; // �⺻ ������
//	k4 = k1; 
//
//	k1.Attack();
//
//	// �Ͻ��� ����ȯ -> �����Ϸ��� �˾Ƽ� �ٲ�ġ��
//	int num = 1;
//
//	float f = (float)num; // ����� <- �츮�� �ڵ�� num�� float �ٱ��Ͽ� ������� �ֹ��ϰ� ����
//	double d = num; // �Ͻ��� << ���� ���ߴµ� �����Ϸ��� �˾Ƽ� ó���ϰ� ����
//
//	Knight k5; // Ÿ�Ժ�ȯ ������
//	k5 = (Knight)1;
//
//	HelloKnight((Knight)5);
//
//	return 0;
//}