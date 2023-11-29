//#include <iostream>
//
//using namespace std;
//
//// class는 설계도
//class Knight
//{
//public:
//	// 기본 생성자 (인자가 없음)
//	Knight() 
//	{
//		cout << "Knight 기본 생성자 호출" << endl;
//
//		_hp = 100;
//		_mp = 10;
//		_posX = 0;
//		_posY = 0;
//	};
//
//	// 복사 생성자
//	Knight(const Knight& knight)
//	{
//		cout << "Knight 복사 생성자 호출" << endl;
//		_hp = knight._hp;
//		_mp = knight._mp;
//		_posX = knight._posX;
//		_posY = knight._posY;
//	}
//
//	// 기타 생성자
//
//	// 이중에서 인자를 1개만 받는 [기타 생성자]를
//	// [타입 변환 생성자]라고 부르기도 함
//
//	// 명시적인 용도로만 사용할 것!
//	explicit Knight(int hp)
//	{
//		cout << "Knight 기타 생성자 호출" << endl;
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
//	// 소멸자
//	~Knight() 
//	{
//
//	};
//
//	// 멤버함수
//	void Attack();
//
//	// 멤버변수
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
//	Knight k2(k1); // 복사 생성자
//	Knight k3 = k1; // 복사 생성자
//
//	Knight k4; // 기본 생성자
//	k4 = k1; 
//
//	k1.Attack();
//
//	// 암시적 형변환 -> 컴파일러가 알아서 바꿔치기
//	int num = 1;
//
//	float f = (float)num; // 명시적 <- 우리가 코드로 num을 float 바구니에 넣으라고 주문하고 있음
//	double d = num; // 암시적 << 별말 안했는데 컴파일러가 알아서 처리하고 있음
//
//	Knight k5; // 타입변환 생성자
//	k5 = (Knight)1;
//
//	HelloKnight((Knight)5);
//
//	return 0;
//}