#pragma once
#include "Creature.h"

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

class Player : public Creature
{
public:
	Player(PlayerType playerType) 
		: _playerType(playerType)
		, Creature(CreatureType::CT_PLAYER)
	{

	}
	virtual ~Player()
	{

	}
	virtual void PrintInfo();

protected:
	PlayerType _playerType;
};

class Knight : public Player
{
public:
	Knight() : Player(PlayerType::PT_Knight)
	{
		_hp = 150;
		_attack = 10;
		_defence = 5;
	}
};

class Archer : public Player
{
public:
	Archer() : Player(PlayerType::PT_Archer)
	{
		_hp = 80;
		_attack = 15;
		_defence = 3;
	}
};

class Mage : public Player
{
public:
	Mage() : Player(PlayerType::PT_Mage)
	{
		_hp = 50;
		_attack = 25;
		_defence = 0;
	}
};
