//#include <iostream>
//using namespace std;
//
//// ������ �����ε�
//
//// ������ vs �Լ�
//// - �����ڴ� �ǿ������� ����/Ÿ���� �����Ǿ� ����
//
//// ������ �����ε�?
//// �ϴ�[������ �Լ�]�� �����ؾ� ��
//// �Լ��� ����Լ� vs �����Լ��� �����ϴ°�ó��, ������ �Լ��� �ΰ��� ������� ���� �� ����
//
//// - ��� ������ �Լ� version
//// -- a op b���¿��� ������ �������� ����� (a�� Ŭ������� ����, a�� '���� �ǿ�����'��� ��)
//// -- �Ѱ�) a�� Ŭ������ �ƴϸ� ��� ����
//
//// - ���� ������ �Լ� version
//// -- a op b ���¶�� a,b ��θ� ������ �Լ��� �ǿ����ڷ� ������ش�.
//
//// �׷� ������ �� ������? �׷��� ����. ������ �� �� �ϳ��� �����ϴ� ��쵵 �ֱ� ����.
//// - ��ǥ������ ���� ������ (a = b)�� ���� ������ version���� �� �����.
//
//// ���� ���� ������
//// - ���� �����ڰ� ���� �迡 [���� ���� ������]�� ���� �˾ƺ���.
//// �� �� �򰥸��� [���� ������] [���� ������] [���� ���� ������] @_@ �����������
//// - ���� ���� ������ = ���� ������ ��, �ڱ� �ڽ��� ���� Ÿ���� ���ڷ� �޴� ��
//
//// ��Ÿ
//// - ��� �����ڸ� �� �����ε� �� �� �ִ� ���� �ƴϴ� (:: . .* �̷��� �ȵ�)
//// - ��� �����ڰ� �� 2������ �ִ� �� �ƴ�. ++ --�� ��ǥ�� (���� ������)
//// - ���� ������ ++ --
//// -- ������ (++a) operator++()
//// -- ������ (a++) operator++(int)
//
//class Position
//{
//public:
//	Position operator+(const Position& arg)
//	{
//		Position pos;
//		pos._x = _x + arg._x;
//		pos._y = _y + arg._y;
//		return pos;
//	}
//
//	Position operator+(int arg)
//	{
//		Position pos;
//		pos._x = _x + arg;
//		pos._y = _y + arg;
//		return pos;
//	}
//
//	bool operator ==(const Position& arg)
//	{
//		return _x == arg._x && _y == arg._y;
//	}
//
//	Position& operator=(int arg)
//	{
//		_x = arg;
//		_y = arg;
//
//		return *this;
//	}
//
//	// [���� ������] [���� ���� ������] �� Ư�� ��츦 �޴� ������,
//	// �� �״�� ��ü�� '����' �Ǳ� ���ϴ� Ư¡ ����
//	// TODO) ���� �Ҵ� �ð��� �� �ڼ��� �˾ƺ� ��
//	Position& operator=(const Position& arg)
//	{
//		_x = arg._x;
//		_y = arg._y;
//		// Position* this = ���ڽ����ּ�
//		return *this;
//	}
//
//	Position& operator++()
//	{
//		_x++;
//		_y++;
//		return *this;
//	}
//
//	Position operator++(int)
//	{
//		Position ret = *this;
//		_x++;
//		_y++;
//		return ret;
//	}
//
//public:
//	int _x;
//	int _y;
//};
//
//Position operator+(int a, const Position& b)
//{
//	Position ret;
//	ret._x = b._x + a;
//	ret._y = b._y + a;
//	return ret;
//}
//
////void operator=(const Position&a, int arg)
////{
////	a._x = b;
////	a._y = b;
////}
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//
//	int c = a + b;
//
//	Position pos;
//	pos._x = 0;
//	pos._y = 0;
//
//
//	Position pos2;
//	pos2._x = 1;
//	pos2._y = 1;
//
//	Position pos3 = pos + pos2;
//
//	Position pos4 = 1 + pos3;
//	
//	bool isSame = (pos3 == pos4);
//
//	Position pos5;
//	pos3 = (pos5 = 5);
//	
//	// (const Pos&) ��~   (Pos) ���簪 �ٰ�~
//	// �ذ� ��� const
//	pos5 = pos3++;
//	
//	++(++pos3);
//	//pos3 = pos.operator+(pos2);
//
//
//
//	return 0;
//}