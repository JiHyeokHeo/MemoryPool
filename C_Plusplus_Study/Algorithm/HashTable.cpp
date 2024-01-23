#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
#include <thread>

// 해시 테이블

// Q) map vs hash_map (C+11 unordered_map)

// map : Red-Black Tree
// - 추가/탐색/삭제 O(logN)

// C# dictionary = C++ unordered_map

// hash_map (unordered_map)
// - 추가/탐색/삭제 O(1)

// 메모리를 내주고 속도를 취한다.

// 아파트 우편함
// [201][202][203][204][205]
// [101][102][103][104][105]

// 1-999 user(userId=1~999)

// [1][2][3][][][][][999]

// '해시' '테이블'
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

	// 777번 유저 정보 세팅
	users[777] = User{ 777, "Tory" };

	// 777번 유저의 이름은?
	string name = users[777].username;
	cout << name << endl;

	// 테이블
	// 키를 알면, 데이터를 단번에 접근할수 있다.

	// 문제의 상황
	// 너무 많은 메모리를 할당 해야하면 그거 또한 문제가 된다.
}

// 보안
// id: tory + pw: qwer1234
// id: tory + pw: hash(qwer1234) -> asdyg@a#audsf

// DB [tory][asdyg@a#audsf]
// 비밀번호 찾기 -> 아이디 입력 폰 인증 -> 비밀번호는 ~~입니다.(과거) -> 새 비밀번호를 입력하세요.(요즘) 해쉬값만 알지 비밀번호는 모르기 때문에

void TestHash()
{
	struct User
	{
		int userId = 0; // 1~int32_max // 3억까지
		string username;
	};

	//       []
	// [][][][][][][][]
	vector<User> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000); // hash < 고유번호

	// 123456789번 유저 정보 세팅
	users[key] = User{ userId, "Tory" };

	// 123456789번 유저의 이름은?
	User& user = users[key];
	if (user.userId == userId)
	{
		string name = user.username;
		cout << name << endl;
	}

	// 충돌 문제
	// 충돌이 발생한 자리를 대신해서 다른 빈자리를 찾아나서면 된다.
	// - 선형 조사법 (linear probing)
	// hash(key)+1 -> hash(key)+2
	// - 이차 조사법 (quadratic probing)
	// hash(key)+1^2 -> hash(key)+2^2
	// - etc

	// 체이닝

}

// O(1)
void TestHashTableChaining()
{
	struct User
	{
		int userId = 0; // 1~int32_max // 3억까지
		string username;
	};

	vector<vector<User>> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000); // hash < 고유번호

	// 123456789번 유저 정보 세팅
	users[key].push_back(User{ userId, "Tory" });

	// 123456789번 유저 이름은?
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