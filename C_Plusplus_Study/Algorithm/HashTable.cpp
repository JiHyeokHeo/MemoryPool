#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
#include <thread>

// �ؽ� ���̺�

// Q) map vs hash_map (C+11 unordered_map)

// map : Red-Black Tree
// - �߰�/Ž��/���� O(logN)

// C# dictionary = C++ unordered_map

// hash_map (unordered_map)
// - �߰�/Ž��/���� O(1)

// �޸𸮸� ���ְ� �ӵ��� ���Ѵ�.

// ����Ʈ ������
// [201][202][203][204][205]
// [101][102][103][104][105]

// 1-999 user(userId=1~999)

// [1][2][3][][][][][999]

// '�ؽ�' '���̺�'
// O(1)
void TestTable()
{
	struct User
	{
		int userId = 0; // 1~999
		string username;
	};

	vector<User> users;
	users.resize(1000);

	// 777�� ���� ���� ����
	users[777] = User{ 777, "Tory" };

	// 777�� ������ �̸���?
	string name = users[777].username;
	cout << name << endl;

	// ���̺�
	// Ű�� �˸�, �����͸� �ܹ��� �����Ҽ� �ִ�.

	// ������ ��Ȳ
	// �ʹ� ���� �޸𸮸� �Ҵ� �ؾ��ϸ� �װ� ���� ������ �ȴ�.
}

// ����
// id: tory + pw: qwer1234
// id: tory + pw: hash(qwer1234) -> asdyg@a#audsf

// DB [tory][asdyg@a#audsf]
// ��й�ȣ ã�� -> ���̵� �Է� �� ���� -> ��й�ȣ�� ~~�Դϴ�.(����) -> �� ��й�ȣ�� �Է��ϼ���.(����) �ؽ����� ���� ��й�ȣ�� �𸣱� ������

void TestHash()
{
	struct User
	{
		int userId = 0; // 1~int32_max // 3�����
		string username;
	};

	//       []
	// [][][][][][][][]
	vector<User> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000); // hash < ������ȣ

	// 123456789�� ���� ���� ����
	users[key] = User{ userId, "Tory" };

	// 123456789�� ������ �̸���?
	User& user = users[key];
	if (user.userId == userId)
	{
		string name = user.username;
		cout << name << endl;
	}

	// �浹 ����
	// �浹�� �߻��� �ڸ��� ����ؼ� �ٸ� ���ڸ��� ã�Ƴ����� �ȴ�.
	// - ���� ����� (linear probing)
	// hash(key)+1 -> hash(key)+2
	// - ���� ����� (quadratic probing)
	// hash(key)+1^2 -> hash(key)+2^2
	// - etc

	// ü�̴�

}

// O(1)
void TestHashTableChaining()
{
	struct User
	{
		int userId = 0; // 1~int32_max // 3�����
		string username;
	};

	vector<vector<User>> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000); // hash < ������ȣ

	// 123456789�� ���� ���� ����
	users[key].push_back(User{ userId, "Tory" });

	// 123456789�� ���� �̸���?
	vector<User>& bucket = users[key];
	for (User& user : bucket)
	{
		if (user.userId == userId)
		{
			string name = user.username;
			cout << name << endl;
		}
	}

}

int main()
{
	// TestTable();
	//TestHash();
	TestHashTableChaining();
	return 0;
}