#include <iostream>
using namespace std;

// 상속성

// 객체지향 OOP
// - 상속성
// - 은닉성
// - 다형성

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// 메모리

//[ [ Player ] ] 
//[   Knight   ]

// 상속(Inheritance) ? 부모 -> 자식에게 유산을 물려주는 것

// 생성자(N)/소멸자(1)

// 생성자는 탄생을 기념해서 호출되는 함수?
// - Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 솔로몬의 선택 ! 그냥 둘 다 호출하자 !	

class Player
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player int hp 생성자 호출" << endl;
	}

	~Player()
	{
		cout << "~Player 소멸자 호출" << endl;
	}

	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }

public:
	int _hp;
	int _attack;
	int _defence;
};

// class는 설계도
class Knight : public Player
{
public:
	Knight() 
	/*
		선처리 영역
		- 여기서 Player() 생성자를 호출
	*/
	{
		_stamina = 100;
		cout << "Knight 기본 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100)
		/*
			선처리 영역
			- 여기서 Player(int hp) 생성자를 호출
		*/
	{
		_stamina = stamina;
		cout << "Knight int stamina 생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "~Knight 소멸자 호출" << endl;
	}
	/*
		후처리 영역
		- 여기서 ~Player() 소멸자를 호출
	*/

	// 재정의 : 부모님의 유산을 거부하고 새로운 이름으로 만든
	void Move() { cout << "Knight Move 호출" << endl; }


public:
	int _stamina;
};

class Mage : public Player
{
public:


public:
	int _mp;
};

int main()
{
	Knight k;

	k._hp = 100;
	k._attack= 10;
	k._defence = 5;
	k._stamina = 50;
	
	//k.Attack();
	//k.Move();
	
	
	return 0;
}