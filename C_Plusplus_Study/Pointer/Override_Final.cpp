#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>

// override, final

class Creature
{
public:
};

class Player : public Creature
{
public:
	virtual void Attack()
	{
		cout << "Player!" << endl;
	}

};

class Knight : public Player
{
public:
	// ÀçÁ¤ÀÇ(override)
	virtual void Attack() override
	{
		cout << "Knight!" << endl;
	}

private:
	int _stamina = 100;
};

int main()
{
	// RTTI 
	Player* player= new Knight();

	player->Attack();

	return 0;
}