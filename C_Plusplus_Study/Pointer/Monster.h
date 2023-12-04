#pragma once
#include "Creature.h"

enum MonsterType
{
	MT_SLIME = 1,
	MT_ORC = 2,
	MT_SKELETON = 3
};

class Monster : public Creature
{
public:
	Monster(MonsterType type)
		: Creature(CreatureType::CT_MONSTER)
		, _monsterType(type)
	{

	}
	~Monster()
	{

	}

	virtual void PrintInfo();

protected:
	MonsterType _monsterType;
};

class Slime : public Monster
{
public:
	Slime() 
		: Monster(MonsterType::MT_SLIME)
	{
		_hp = 50;
		_attack = 5;
		_defence = 2;
	}
	~Slime()
	{

	}
};

class Orc : public Monster
{
public:
	Orc() 
		: Monster(MonsterType::MT_ORC)
	{
		_hp = 80;
		_attack = 8;
		_defence = 3;
	}
	~Orc()
	{

	}
};

class Skeleton : public Monster
{
public:
	Skeleton() 
		: Monster(MonsterType::MT_SKELETON)
	{
		_hp = 50;
		_attack = 5;
		_defence = 2;
	}
	~Skeleton()
	{

	}
};
