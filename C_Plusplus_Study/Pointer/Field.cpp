#include "Field.h"
#include "Player.h"
#include <random>
#include "Monster.h"

Field::Field()
	: _monster(nullptr)
{
}

Field::~Field()
{
	if (_monster != nullptr)
	{
		delete _monster;
		_monster = nullptr;
	}
}

void Field::Update(Player* player)
{
	if (_monster == nullptr)
		CreateMonster();

	StartBattle(player);
}

void Field::CreateMonster()
{
	int randValue = 1 + rand() % 3;

	switch (randValue)
	{
	case MonsterType::MT_SLIME:
		_monster = new Slime();
		break;
	case MonsterType::MT_ORC:
		_monster = new Orc();
		break;
	case MonsterType::MT_SKELETON:
		_monster = new Skeleton();
		break;
	default:
		break;
	}
}

void Field::StartBattle(Player* player)
{
	while (true)
	{
		player->PrintInfo();
		_monster->PrintInfo();

		// 플레이어-> 몬스터 공격
		_monster->OnAttacked(player);

		if (_monster->IsDead())
		{
			_monster->PrintInfo();
			delete _monster;
			_monster = nullptr;
			break;
		}
		
		// 몬스터-> 플레이어 공격
		player->OnAttacked(_monster);

		if (player->IsDead())
		{
			player->PrintInfo();
			break;
		}

	}
}

