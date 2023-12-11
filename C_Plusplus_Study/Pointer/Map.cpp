#include <iostream>
using namespace std;
#include <vector>
#include <map>
// map

class Player
{
public:
	Player()
		:_playerId(0)
	{

	}

	Player(int playerId)
		:_playerId(playerId)
	{

	}

public:
	int _playerId;
};

int main()
{
#pragma region �츮�� ���� ���� ���� ( vector�� ���� �� )
	vector<Player*> v;

	// 10���� ����
	for (int i = 0; i < 100000; i++)
	{
		Player* p = new Player(i);
		v.push_back(p);
	}

	// 5������ ����
	for (int i = 0; i < 50000; i++)
	{
		int randIndex = rand() & v.size();

		Player* p = v[randIndex];
		delete p;
		p = nullptr;

		v.erase(v.begin() + randIndex);
	}

	// (ID = 2�� �÷��̾�)�� (ID = 1�� Player)�� �����ϰ� �;��
	// Q) ID = 1���� Player�� ã���ּ���
	// A) ã�ƺ���

	// 0 1 2 5

	bool found = false;

	// ����� ��ȿ�������� �����ش�.
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->_playerId = 10000)
		{
			found = true;
			break;
		}
	}

	// vector, list�� ġ������ ����
	// -> ���ϴ� ���ǿ� �ش��ϴ� �����͸� ������ ã�� �� [����]
#pragma endregion
	
	// ���� �����̳�

	// map : ���� ���� Ʈ�� (AVL)
	// - ��� ���

	class Node
	{
	public:
		Node* _left;
		Node* _right;
		// Data
		pair<int, Player*> _data;
		//int		_key;
		//Player* _value;
	};

	// (Key, Value)
	srand(static_cast<unsigned int>(time(nullptr)));
	map<int, int>  m;

	pair<map<int, int>::iterator, bool> ok;
	// �Ȱ��� Ű�� ���ÿ� �� �� ����.
	ok = m.insert(make_pair(1, 100));
	ok = m.insert(make_pair(1, 200));

	// 10����
	for (int i = 0; i < 100000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5���� ����
	for (int i = 0; i < 50000; i++)
	{
		int randValue = rand() % 50000;

		// Erase By Key
		m.erase(randValue);
	}

	// Q) ID = 1���� Player ã�� �ʹ�!
	// A) �ſ� ������ ã�� �� ����
	unsigned int count = 0;
	count = m.erase(10000);
	count = m.erase(10000);


	map<int,int>::iterator findIt = m.find(10000);
	if (findIt != m.end())
	{
		cout << "ã��" << endl;
	}
	else
	{
		cout << "��ã��" << endl;
	}

	// map ��ȯ
	
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		pair<const int,int>&p = (*it);
		int key = (*it).first; 
		int value = (*it).second;
		
		//cout << key << " " << value << endl;
	}

	// ������ �߰�, ������ ����

	map<int, int>::iterator findIt2 = m.find(10000);
	if (findIt != m.end())
	{
		findIt2->second = 200;
	}
	else
	{
		m.insert(make_pair(10000, 200));
	}

	// ������ �߰�, ������ ���� v2
	//key  value
	m[5] = 500;

	m.clear();
	// [] ������ ����� �� ����
	// ������ ���� �ʴ��� (Key/Value) ������ �����Ͱ� �߰��ȴ�.

	// ��¸� �ϴ� ������ �̷������� �ϸ� ����ؼ� �߰��Ǵ� �ϸ� �����.
	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;
	}

	// �ְ�		(insert, [])
	// ����		(erase)
	// ã��		(find , [])
	// �ݺ���	(map::iterator) (*it) pair<key, value>&

	return 0;
}