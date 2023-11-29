//#include <iostream>
//#include <chrono>
//using namespace std;
//using namespace chrono;
//// 포인터 실습
//
//system_clock::time_point start, finish;
//
//struct StatInfo
//{
//	int hp; // + 0
//	int attack; // + 4
//	int defence; // + 8
//};
//
//void EnterLobby();
//StatInfo CreatePlayer();
//void CreateMonster(StatInfo* info);
//// 플레이어 승리 시 true, 아니면 false
//bool StartBattle(StatInfo* player, StatInfo* monster);
//
//int main()
//{
//	EnterLobby();
//	return 0;
//}
//
//void EnterLobby()
//{
//	cout << "로비에 입장 했습니다" << endl;
//	nanoseconds  duration;
//
//	StatInfo player;
//	player.hp = 0xbbbbbbbb;
//	player.attack= 0xbbbbbbbb;
//	player.defence= 0xbbbbbbbb;
//
//	// 임시 저장소를 매개변수로 넘겨줘서 작업을함
//	// [매개변수][RET][지역변수(temp(100,10,2), player(b,b,b))] [매개변수(&temp)][RET][지역변수(ret(b,b,b))]
//	start = system_clock::now();
//	player = CreatePlayer();
//	finish = system_clock::now();
//	duration = (finish - start);
//	cout << "포인터 사용 x : " << duration.count() << "나노초 ns" << endl;
//
//	StatInfo monster;
//	monster.hp = 0xbbbbbbbb;
//	monster.attack = 0xbbbbbbbb;
//	monster.defence = 0xbbbbbbbb; 
//
//	// [매개변수][RET][지역변수(monster(40, 8 , 1))] [매개변수(&monster)][RET][지역변수()]
//	start = system_clock::now();
//	CreateMonster(&monster);
//	finish = system_clock::now();
//	duration = (finish - start);
//	cout << "포인터 사용 o : " << duration.count() << "나노초 ns" << endl;
//
//	// 번외편 구조체끼리 복사할 때 무슨일이 벌어질까?
//	//player = monster;
//	bool victory = StartBattle(&player, &monster);
//
//	if (victory)
//		cout << "승리!" << endl;
//	else
//		cout << "패배!" << endl;
//}
//
//StatInfo CreatePlayer()
//{
//	StatInfo ret;
//
//	cout << "플레이어 생성" << endl;
//
//	ret.hp = 100;
//	ret.attack = 10;
//	ret.defence = 2;
//
//	return ret;
//}
//
//void CreateMonster(StatInfo* info)
//{
//	cout << "몬스터 생성" << endl;
//	
//	info->hp = 40;
//	info->attack = 8;
//	info->defence = 1;
//}
//
//bool StartBattle(StatInfo* player, StatInfo* monster)
//{
//	while (true)
//	{
//		int damage = player->attack - monster->defence;
//		if (damage < 0)
//			damage = 0;
//
//		monster->hp -= damage;
//		if (monster->hp < 0)
//			monster->hp = 0;
//
//		cout << "몬스터 HP : " << monster->hp << endl;
//
//		if (monster->hp == 0)
//			return true;
//
//
//		damage = monster->attack - player->defence;
//		
//		if (damage < 0)
//			damage = 0;
//	
//		player->hp -= damage;
//		if (player->hp < 0)
//			player->hp = 0;
//
//		cout << "플레이어 HP : " << player->hp << endl;
//
//		if (player->hp == 0)
//			return false;
//	}
//}